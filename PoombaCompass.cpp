#include "PoombaCompass.h"

const unsigned long int PoombaCompass::BAUD_RATE = 9600;
const unsigned int PoombaCompass::CALIBRATE_DELAY = 450;

const unsigned int PoombaCompass::GET_ANGLE_16 = 0x13;

void PoombaCompass::setup(unsigned long int baudRate) {
  Serial3.begin(baudRate);
}

float PoombaCompass::getAngle() {
  delay(PoombaCompass::CALIBRATE_DELAY); // Needed to recalibrate the compass
  byte getAngle16Msg [] = {
    PoombaCompass::GET_ANGLE_16
  };
  Serial3.write(getAngle16Msg, sizeof(getAngle16Msg));

  while(Serial3.available() < 2);
  long result = Serial3.read() << 8;
  result += Serial3.read();

  return result / 10;
}

float PoombaCompass::getDifference(float start, float stop, int direction) {
  if (direction == 0) {
    if (start <= stop) {
      return stop - start;
    } else {
      return 360 - (start - stop);
    }
  } else {
    if (start >= stop) {
      return start - stop;
    } else {
      return 360 - (stop - start);
    }
  }
}
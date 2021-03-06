#ifndef POOMBA_COMPASS_H
#define POOMBA_COMPASS_H

#include "Arduino.h"

class PoombaCompass
{
public:
  void setup(unsigned long int = PoombaCompass::BAUD_RATE); /** Setup the serial port */

  float getAngle();                                             /** Return the current angle */
  float getDifference(float start, float stop, int direction);  /** Calculate the difference between 2 angles
                                                                    direction value is 0 for clockwise, 1 otherwise */

private:
  /** Generics constants */
  static const unsigned long int BAUD_RATE;
  static const unsigned int CALIBRATE_DELAY;

  /** Engines data */
  static const unsigned int GET_ANGLE_16;
};

#endif
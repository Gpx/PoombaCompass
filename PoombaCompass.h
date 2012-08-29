#ifndef POOMBA_COMPASS_H
#define POOMBA_COMPASS_H

#include "Arduino.h"

class PoombaCompass
{
public:
  void setup(unsigned long int = PoombaCompass::BAUD_RATE); /** Setup the serial port */

  int getAngle();                                           /** Return the current angle */
  int getDifference(int start, int stop, int direction); /** Calculate the difference between 2 angles
                                                                direction value is 0 for clockwise, 1 otherwise */

private:
  /** Generics constants */
  static const unsigned long int BAUD_RATE;

  /** Engines data */
  static const unsigned int GET_ANGLE_16;
};

#endif
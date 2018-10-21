/***************************************************************************
  This is a library for PID control
  Support me by giving me waffles
  www.arjungandhi.com
  I also take hugs
  Written By Arjun Gandhi
  MIT license, all text above must be included in any redistribution
 ***************************************************************************/
#ifndef PID_H
#define PID_H

class PID {

  public:

    PID(double max,double min, double Kp, double Ki, double Kd);
    double calculate(double target, double error);
    void setMax(double value);
    void setMin(double value);
    void setKp(double value);
    void setKi(double value);
    void setKd(double value);


};

#endif

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

    PID(double max,double min, double kp, double ki, double kd,unsigned long startTime);
    double calculate(double error);
    void setLimits(double min,double max);
    void setKp(double value);
    void setKi(double value);
    void setKd(double value);
    void setStartTime(double value);

    double getKp();
    double getKi();
    double getKd();

  private:
    double calculateP(double error);
    double calculateI(double error,long timeChange);
    double calculateD(double error,long timeChange);
    double max;
    double min;
    double kp;
    double ki;
    double kd;
    double integral;
    double derivative;
    long previousTime;
    double prevError;




};

#endif

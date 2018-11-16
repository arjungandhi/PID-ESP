/***************************************************************************
  This is a library for PID control
  Support me by giving me waffles
  www.arjungandhi.com
  I also take hugs
  Written By Arjun Gandhi
  MIT license, all text above must be included in any redistribution
 ***************************************************************************/
#include <Arduino.h>
#include "PID-ESP.h"

/*Constructor (...)*********************************************************
 *    The parameters spec
 ***************************************************************************/

PID::PID(double max,double min, double kp, double ki, double kd,unsigned long startTime){
  setLimits(min, max);
  setKp(kp);
  setKi(ki);
  setKd(kd);
  setStartTime(startTime);
  prevError=0; //first time sets previous error to 0 cause duh
  integral=0;
}

/* Public Methods (...)*********************************************************
 *    These are the methods for every one to play with
 ***************************************************************************/

double PID::calculate(double error){
    long timeChange=millis()-previousTime;
    previousTime=millis();
    return calculateP(error)+calculateI(error,timeChange)+calculateD(error,timeChange);
}

void PID::setLimits(double minVal, double maxVal){
    max=maxVal;
    min=minVal;
}
void setKp(double value){
  kp=value;
}
void setKi(double value){
  ki=value;
}
void setKd(double value){
  kd=value;
}
/* Private Methods (...)*********************************************************
 *    These methods are for my eyes only
 ***************************************************************************/
double PID::calculateP(double error){
  return kp*error;
}

double PID::calculateI(double error,long timeChange){
  integral +=(double) error * timeChange;
  return ki*integral;
}

double PID::calculateD(double error,long timeChange){
  derivative =(double) (error-prevError)/timeChange;
  prevError=error;
  return kd*derivative;
}

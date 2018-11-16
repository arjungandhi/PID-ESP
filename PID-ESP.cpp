#include "Arduino.h"
#include "PID-ESP.h"

public PID::PID(int kp, int ki, int kd, int maxSpeed, int minSpeed){
  this.kp = kp;
  this.ki = ki;
  this.kd = kd;
  this.maxSpeed = maxSpeed;
  this.minSpeed = minSpeed;
  this.startTime = millis();
  oldError = 0;
  integralVal = 0;
  lastTime = startTime;
}

public double PIDCalculate(double error)}
return PCalc(error)+ICalc(error)+DCalc(error);
lastTime=millis();
oldError=error;
}

public void setKP(int newKP){
  PID.this.kp = newKP;
}

public void setKI(int newKI){
  PID.this.ki = newKi;
}

public void setKD(int newKD){
  PID.this.kd = newKD;
}

private double PCalc(double error){
  return kp*error;
}

private double ICalc(double error){
  integralVal+=(error*(millis()-lastTime));
  return kI*(integralVal);
}

private double DCalc(double error){
  return kD*((error-oldError)/(millis()-lastTime));
}

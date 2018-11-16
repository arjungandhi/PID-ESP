#ifndef PID_H
#define PID_H

class PID {

  public:

int kp;
int ki;
int kd;
int maxSpeed;
int minSpeed;
double oldError;
double integralVal;
unsigned long startTime;
unsigned long lastTime;

double PIDCalculate(double error);
void setKP(int newKP);
void setKI(int newKI);
void setKD(int newKD);

private:
  double PCalc(double error);
  double ICalc(double error);
  double DCalc(double error);

};

#endif

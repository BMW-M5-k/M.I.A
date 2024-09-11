class PID{
  private:
  float kp, ki, kd;
  float prevError;
  float integral;
  unsigned long time;
  public:
  PID(float KP, float KI, float KD){ //setter for proportional, integral, and differential constants
    kp = KP;
    ki = KI;
    kd = KD;
    prevError = 0;
    integral = 0;
    time = millis();
  }
  float error(float setpoint, float actual){
    float error = setpoint - actual; //calculating error
    unsigned long newTime = millis(); //for calculating the change in time
    float dTime = (newTime - time) / 1000.0; //delta time
    integral += error * dTime; //integral factor
    float dByDt = (error - prevError) / dTime; // derivative factor
    
    float pidOutput = kp * error + ki * integral + kd * dByDt;
    prevError = error;
    time = newTime;
  }
};
const int motorPin = 8;
const float smoothingFactor = 0.3;
float smoothingOut = 0;
PID motor(0.6,0.2,0.7);

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  float setpoint = 100;
  float realSpeed = readMotor(); //function to read motor speed (irrelevant for this task)
  float controlledOutput = motor.error(setpoint, realSpeed);
  smoothingOut = smoothingFactor * controlledOutput + (1 - smoothingFactor) * smoothingOut; //exponential smoothing filter
  analogWrite(motorPin, (int)smoothingOut);
}
float readMotor(){
  return analogRead(A0);
}
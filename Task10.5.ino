#include <Wire.h>
#define IMU_ADDR  0x68
#define Z_Rotation  0x47
void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(IMU_ADDR);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();


}

void loop() {
  int rawvalue = readZRotation();
  float yaw_to_dps = rawvalue / 131.0;
  Serial.print("Yaw is ");
  Serial.print(yaw_to_dps);
  Serial.println(" degrees/second");

}
int16_t readZRotation(){
  int16_t Z_gyro;
  Wire.beginTransmission(IMU_ADDR);
  Wire.write(Z_Rotation);
  Wire.endTransmission(false);
  Wire.requestFrom(IMU_ADDR, 2, true);
  Z_gyro = Wire.read() << 8 | Wire.read();
  return Z_gyro;
}

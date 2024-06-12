#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)


void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  
  pwm.begin();
  
  pwm.setPWMFreq(60);
  m_close();  // Analog servos run at ~60 Hz updates
}

// the code inside loop() has been updated by Robojax
void loop() {
  m_close();
  delay(1000);
  aieh();
  delay(10);
  m_close();
  delay(400);
  bmp_th();
  delay(10);
  m_close();
  delay(400);
  bmp_th();
  gkxyjr();
  m_close();
}



 
void m_open(){
  pwm.setPWM(6, 0, angleToPulse(45));
  pwm.setPWM(7, 0, angleToPulse(135));
  pwm.setPWM(8, 0, angleToPulse(135));
  pwm.setPWM(9, 0, angleToPulse(45));
  pwm.setPWM(10, 0, angleToPulse(45));
  pwm.setPWM(11, 0, angleToPulse(135));
}


void m_close(){
  pwm.setPWM(6, 0, angleToPulse(0));
  pwm.setPWM(7, 0, angleToPulse(180));
  pwm.setPWM(8, 0, angleToPulse(0));
  pwm.setPWM(9, 0, angleToPulse(180));
  pwm.setPWM(10, 0, angleToPulse(180));
  pwm.setPWM(11, 0, angleToPulse(0));
}
/*

// left lower 3
// left upper 2
// right lower 5
// right upper 4
 * angleToPulse(int ang)
 * gets angle in degree and returns the pulse width
 * also prints the value on seial monitor
 * written by Ahmad Nejrabi for Robojax, Robojax.com
 */
int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}

void aieh(){
  pwm.setPWM(6, 0, angleToPulse(31));
  pwm.setPWM(7, 0, angleToPulse(94));
  pwm.setPWM(8, 0, angleToPulse(94));
  pwm.setPWM(9, 0, angleToPulse(31));
  pwm.setPWM(10, 0, angleToPulse(31));
  pwm.setPWM(11, 0, angleToPulse(94));
}

void bmp_th(){
  pwm.setPWM(6, 0, angleToPulse(22));
  pwm.setPWM(7, 0, angleToPulse(67));
  pwm.setPWM(8, 0, angleToPulse(67));
  pwm.setPWM(9, 0, angleToPulse(22));
  pwm.setPWM(10, 0, angleToPulse(22));
  pwm.setPWM(11, 0, angleToPulse(67));
}

void gkxyjr(){
  pwm.setPWM(6, 0, angleToPulse(18));
  pwm.setPWM(7, 0, angleToPulse(54));
  pwm.setPWM(8, 0, angleToPulse(54));
  pwm.setPWM(9, 0, angleToPulse(18));
  pwm.setPWM(10, 0, angleToPulse(18));
  pwm.setPWM(11, 0, angleToPulse(54));
}

void ouw(){
  pwm.setPWM(6, 0, angleToPulse(40));
  pwm.setPWM(7, 0, angleToPulse(121));
  pwm.setPWM(8, 0, angleToPulse(121));
  pwm.setPWM(9, 0, angleToPulse(40));
  pwm.setPWM(10, 0, angleToPulse(40));
  pwm.setPWM(11, 0, angleToPulse(121));
}




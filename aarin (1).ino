#include <Adafruit_PWMServoDriver.h>

#include <Wire.h>



Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  140 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  520 // this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;

//Servo x, y;
int width = 640, height = 480;  // total resolution of the video
int xpos = 30, ypos = 100;  //30 initial positions of both Servos
const int angle = 2;   // degree of increment or decrement

int xval;
int yval;

int sensorValue = 0;
unsigned long previousMillis = 0;
const unsigned long interval = 2000;


void setup() {
  Serial.begin(31250);
  pwm.begin();
  pwm.setPWMFreq(60);
  Serial.setTimeout(10);
  pwm.setPWM(0,0,angleToPulse(xpos));
  pwm.setPWM(1,0,angleToPulse(ypos));
  startup();
  m_close();
}

void loop() {
unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        blink();
    }
eyeTrack();
delay(5000);
imcat(); 
delay(5000);

}

void eyeTrack() {
  if (Serial.available() > 0)
  {
    int x_mid, y_mid;
    if (Serial.read() == 'X')
    {
      x_mid = Serial.parseInt(); }
       // read center x-coordinate
    if (Serial.read() == 'Y'){
        y_mid = Serial.parseInt(); // read center y-coordinate
    }

    if (x_mid > width / 2 + 10)
      xpos += angle;
    if (x_mid < width / 2 - 10)
      xpos -= angle;
    if (y_mid < height / 2 + 10)
      ypos += angle;
    if (y_mid > height / 2 - 10)
      ypos -= angle;

    // if the servo degree is outside its range
    if (xpos >= 100)
      xpos = 100;
    else if (xpos <= 0)
      xpos = 0;
    if (ypos >= 130)
      ypos = 130;
    else if (ypos <= 85)
      ypos = 85;

    pwm.setPWM(0,0,angleToPulse(xpos));
    pwm.setPWM(1,0,angleToPulse(ypos));
  }
}

int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX); 
   Serial.println("Angle: ");Serial.print(ang);
   Serial.println(" pulse: ");Serial.println(pulse);
   return pulse;
}

void open(){
  pwm.setPWM(2, 0, angleToPulse(90));
  pwm.setPWM(3, 0, angleToPulse(50));
  pwm.setPWM(4, 0, angleToPulse(50));
  pwm.setPWM(5, 0, angleToPulse(140));
}

void lwink(){
  pwm.setPWM(2, 0, angleToPulse(90));
  pwm.setPWM(3, 0, angleToPulse(50));
  pwm.setPWM(4, 0, angleToPulse(0));
  pwm.setPWM(5, 0, angleToPulse(180));
}

void rwink(){
  pwm.setPWM(2, 0, angleToPulse(180));
  pwm.setPWM(3, 0, angleToPulse(0));
  pwm.setPWM(4, 0, angleToPulse(50));
  pwm.setPWM(5, 0, angleToPulse(140));
}

void close(){
  pwm.setPWM(2, 0, angleToPulse(180));
  pwm.setPWM(3, 0, angleToPulse(0));
  pwm.setPWM(4, 0, angleToPulse(0));
  pwm.setPWM(5, 0, angleToPulse(180));
}

void startup(){
  close();
  delay(2000);
  open();
  delay(1000);
  lwink();
  delay(500);
  rwink();
  delay(500);
  open();
}

void blink(){
  close();
  delay(100);
  open();
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

void imcat(){
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
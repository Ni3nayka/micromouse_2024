#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor motor_left(0x0A);
iarduino_I2C_Motor motor_right(0x0B);

#include <SoftwareSerial.h>
SoftwareSerial bluetooth(4, 5); // RX, TX

void motor(int left_speed=0, int right_speed=0) {
  motor_left.setSpeed(left_speed, MOT_PWM);
  motor_right.setSpeed(right_speed, MOT_PWM);
}

void setup() {
  delay(500);
  bluetooth.begin(9600);
  motor_left.begin();
  motor_right.begin();
  motor_left.setDirection(false);
  motor_right.setDirection(true); 
  // motor(100,100);
  // delay(1000);
  // motor(100,0);
  // delay(1000);
  // motor();
  // for (int i = 0; i<12; i++) right(); //left();
  // forward();
  waitStart();
  test();
} 

void waitStart() {
  bool flag = 1;
  while(flag) {
    if (bluetooth.available()) {
      char f = bluetooth.read();
      if (f=='W') flag = 0;
    }
  }
}

void test1() {
  forward();
  forward();
  left();
  forward();
  forward();
  forward();
  forward();
  right();
  forward();
  forward();
}

void test() {
  forward();
  forward();
  left();
  forward();
  left();
  forward();
  forward();
  right();
  forward();
  forward();
  right();
  forward();
  left();
  left();
  forward();
  right();
  forward();
  left();
  left();
  forward();
  forward();
  forward();
  left();
  forward();
  forward();
  left();
  forward();
  forward();
  forward();
  left();
  forward();
  left();
  left();
  forward();
  forward();
  forward();
}

void loop() {
}

void left() {
  motor(-100,100);
  delay(705);
  motor(100,-100);
  delay(20);
  motor();
  // delay(500);
}

void right() {
  motor(100,-100);
  delay(705);
  motor(-100,100);
  delay(20);
  motor();
}

void forward() {
  while (bluetooth.available()) bluetooth.read();
  motor(100,100);
  for (unsigned long int t = millis()+1290; t>millis();) {
    if (bluetooth.available()) {
      char f = bluetooth.read();
      if (f=='R') motor(100,70);
      if (f=='L') motor(70,100);
      if (f=='S') motor(100,100);
    }
  }
  // delay(1310);
  motor(-100,-100);
  delay(20);
  motor();
}
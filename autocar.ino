

#include <Ultrasonic.h>


Ultrasonic ultrasonic(12,13); // (Trig PIN,Echo PIN)

const byte LEFT1 = 8;  //IN1
const byte LEFT2 = 9;  //IN2
const byte LEFT_PWM = 10;

const byte RIGHT1 = 7;  //IN3
const byte RIGHT2 = 6;  //IN4
const byte RIGHT_PWM = 5;


byte motorSpeed = 1000;

void forward() { 
  
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, motorSpeed);
  
 
  digitalWrite(RIGHT1, LOW);
  digitalWrite(RIGHT2, HIGH);

  analogWrite(RIGHT_PWM, motorSpeed);
}

void backward() { 
  digitalWrite(LEFT1, LOW);
  digitalWrite(LEFT2, HIGH);
  analogWrite(LEFT_PWM, motorSpeed);

  digitalWrite(RIGHT1, HIGH);
  digitalWrite(RIGHT2, LOW);
  analogWrite(RIGHT_PWM, motorSpeed);
}

void turnLeft() { 
  
  analogWrite(LEFT_PWM, 0);

  digitalWrite(RIGHT1, LOW);
  digitalWrite(RIGHT2, HIGH);
  analogWrite(RIGHT_PWM, motorSpeed);
}

void turnRight() {  

  
  digitalWrite(LEFT1, HIGH);
  digitalWrite(LEFT2, LOW);
  analogWrite(LEFT_PWM, motorSpeed);
  
  analogWrite(RIGHT_PWM, 0);
}

void stopMotor() { 
  
  analogWrite(LEFT_PWM, 0);

  analogWrite(RIGHT_PWM, 0);
}

void setup() {
  
  pinMode(LEFT1, OUTPUT);
  pinMode(LEFT2, OUTPUT);
  pinMode(LEFT_PWM, OUTPUT);
  pinMode(RIGHT1, OUTPUT);
  pinMode(RIGHT2, OUTPUT);
  pinMode(RIGHT_PWM, OUTPUT);

  
  
}

void loop() {
 
  
  int dis = ultrasonic.read();
    
  if(dis<15){
      turnRight();
      delay(200);
      stopMotor();
  }else{
      forward();
  }
  
}

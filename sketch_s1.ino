
#include <SoftwareSerial.h>
#include <Servo.h>
#define trigpin1 12
#define echopin1 13
#define led1 5
#define led2 6
#define led3 7
#define led4 8


Servo tap_servo;

int sensor_pin =3;
int tap_servo_pin =4;
int val;




SoftwareSerial Gsm(2, 3);
Servo Servo1;
int pirPin = 4;
int pirState = 0;
int calibrationTime = 30;
const unsigned long eventTime_1 = 1000;
const unsigned long eventTime_2 = 5000;

unsigned long previousTime_1 = 0;
unsigned long previousTime_2 = 0;
void setup() {
  
  Serial.begin(9600);
  Gsm.begin(9600);
  Servo1.attach(9);
  delay(1000);
  Servo1.write(0);
  delay(1000);
  Servo1.detach();
  pinMode(trigpin1, OUTPUT);
  pinMode(echopin1, INPUT);
  pinMode(pirPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(calibrationTime * 1000);   
  Serial.println("SMART DUSTBIN IS Ready TO WORK");
  Servo1.attach(9);


 pinMode(sensor_pin,INPUT);
  tap_servo.attach(tap_servo_pin);

  
}

bool flag = false;
bool flag1 = false;
long Distance1, Duration1;

void loop() {
  
  unsigned long currentTime = millis();

  if ( currentTime - previousTime_1 >= eventTime_1 )
  {
    Serial.println("PIR");
    pirState = digitalRead(pirPin);
    if (pirState == HIGH)
    {
      Servo1.attach(9);
      Serial.println("OPEN LID");
      Servo1.write(100);
      flag1 = true; 
    }
    else if (pirState == LOW) {
      Serial.println("Close LID");
      if(flag1 == false)
      {
        Servo1.detach();
        delay(15);
      }
      else if(flag1 == true)
      {
      Servo1.write(0);
      delay(15);
      flag1 = false;
      }
    }
    previousTime_1 = currentTime;
  }


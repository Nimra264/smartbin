  if ( currentTime - previousTime_2 >= eventTime_2 )
  {

    Serial.println("Ultrasonic");
    digitalWrite(trigpin1, LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin1, LOW);
    Duration1 = pulseIn(echopin1, HIGH);
    Distance1 = (Duration1 / 2) / 29.1;
    Serial.print("Distance:");
    Serial.println(Distance1);

    if ((Distance1 >= 21) && (Distance1 <= 28))
    {
      Serial.println("level 1");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      flag = false;
    }
    else if ((Distance1 >= 15) && (Distance1 <= 20))
    {
      Serial.println("level 2");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
    }
    else if ((Distance1 >= 7) && (Distance1 <= 14) )
    {
      Serial.println("level 3");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
    }
    else if ((Distance1 >= 0) && (Distance1 <= 6) )
    {
      Serial.println("level 4");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      if ( flag == false )
      {
        send_msg();
        flag = true;
      }
    }
    else
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
    }

    previousTime_2 = currentTime;
  }


  val = digitalRead(sensor_pin);

  if (val==0)
  {tap_servo.write(0);
  }
  if (val==1)
  {tap_servo.write(180);
    }

}


void send_msg()
{
  Servo1.detach();
  delay(100);
  Gsm.println("AT+CMGF=1");    
  delay(1000);  
  Gsm.println("AT+CMGS=\"+91xxxxxxxxxx\"\r"); 
  delay(1000);
  Gsm.println("DUST BIN IS FULL");
  delay(100);
  Gsm.println((char)26);
  delay(1000);
  Servo1.attach(9);


}
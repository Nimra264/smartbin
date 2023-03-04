# Smartbin
**Introduction:**

Smart bin is an automatic dustbin. It works like when you will come in front of the bin it will open and close automatically with the help of servo motor. Sensor will detect the object in front of the dustbin. According to garbage level, the corresponding LED will blink. This bin has the sorting mechanism to sort metal material so it can recycle. Purpose of smart dustbin project is to create an environment which is cleaner, safer, more hygienic. This system helps to enhanced the operational efficiency while reducing management costs, resources, and road side emissions.

**Component:**

•	Arduino UNO

•	Servo Motor

•	HCSR04 Ultrasonic Sensor

•	PIR Sensor

•	4 LEDs

•	Inductive Proximity Sensor

•	Bread Board

**Methodology:**

We are proposing a smart dustbin with IoT notification. In this system, a dustbin is working as an intelligent node. 
HCSR04 Ultrasonic Sensors: 

**The HCSR04 Ultrasonic Sensors:**

is attached inside the dustbin to detect the trash-level. LEDs are connected correspond to this ultrasonic sensor. When HCSR04 will detect the level-1 of dustbin, corresponding LED-1 will turn on and when it will detect the level-2 of dustbin, corresponding LED-2 will turn on. The VCC (Voltage Collector) of this ultrasonic sensor is connected to the VCC of Arduino and its Trig, which is a pin connected with 12th digital pin of Arduino. It contains an Echo pin that is connected with 13th digital pin of Arduino. And its ground is connected with the ground of Arduino. 

**PIR Sensor:**

Which detects a living ting. It has a zone, when a thing enters this zone, the lid of dustbin will be opened. Servo motor is directly connected with this PIR sensor. As soon as PIR sensor will detect a thing, servo motor will turn on, which leads the gate of dustbin to be opened automatically. The VCC of this PIR sensor is connected with the VCC of the Arduino. And its ground is connected with ground of Arduino. The output pin of PIR sensor is connected with 04th digital pin of Arduino.

**LEDs:**

LEDs are connected with ultrasonic sensor. When sensor will detect a level of dustbin, its corresponding LED will be turn on. As LEDs have two wires, one is anode and other is cathode. The anode of LED-1, LED-2, LED-3 and LED-4 is connected to the 5th, 6th, 7th and 8th digital-pins of Arduino respectively. And cathode of all of these LEDs are connects together. Servo Motor: That is connected with PIR sensor. When PIR sensor will sense something, lid of dustbin will be opened. It contains three wires, one is VCC that is connected with power pin of Arduino and the ground of power pin is connected with the ground of Arduino. And its output is connected with 9th -digital pin of Arduino.

**Code:**

•	For lid opening

•	For Metal Detection

**Software:**

Arduino IDE is used for uploading the code

**Servo motor**

Two servo motors are used
•	One for lid opening

•	Second for sorting metal from trash

**Inductive Proximity Sensor:**

E2E-X5ME1 Inductive proximity sensor is used which is attached with servo motor to detect and sort metal.



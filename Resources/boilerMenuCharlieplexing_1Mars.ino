/* Charliplexing 6 LEDs
--------------------------------------------------------------------------------
Row 1 (R1): Arduino Pin 13
Row 2 (R2): Arduino Pin 12
Row 3 (R3): Arduino Pin 11
--------------------------------------------------------------------------------
variable    pinMode      state
 L           OUTPUT       LOW 
 H           OUTPUT       HIGH
 Z           INPUT        LOW
---------------------------------------------------------------------------------
     R1 (Pin 13)      R2 (Pin 12)     R3 (Pin 11)
L1    L                 H                Z
L2    H                 L                Z
L3    Z                 L                H
L4    Z                 H                L
L5    L                 Z                H
L6    H                 Z                L 
-----------------------------------------------------------------------------------
LED    Cathode      Anode
1         R2          R1
2         R1          R2
3         R3          R2
4         R2          R3
5         R3          R1
6         R1          R3 
---------------------------------------------------------------------------------
*/
#include <SoftwareSerial.h>


const int LED_1 = 13;     //LED row 1
const int LED_2 = 12;     //LED row 2    
const int LED_3 = 11;     //LED row 3

const int sten_1 = 7;     //LED row 1
const int sten_2 = 6;     //LED row 2    
const int sten_3 = 5;     //LED row 3

#define rxPin 0
#define txPin 1

// Set up a new SoftwareSerial object
SoftwareSerial mySerial (rxPin, txPin);

void setup() 
{
  Serial.begin(9600); //init communication over USB
  Serial1.begin(9600); //communication over RX/TX pins
}

void loop()
{
  //turn on LED L1
  while (Serial.available() > 0) {
  Serial.pinMode(LED_1, OUTPUT);     //row 1
  Serial.digitalWrite(LED_1, LOW);
  Serial.pinMode(LED_2, OUTPUT);     //row 2
  Serial.digitalWrite(LED_2, HIGH);  
  Serial.pinMode(LED_3, INPUT);      //row 3
  Serial.digitalWrite(LED_3, LOW);
  }

  pinMode(sten_1, OUTPUT);     //row 1
  digitalWrite(sten_1, LOW);
  pinMode(sten_2, OUTPUT);     //row 2
  digitalWrite(sten_2, HIGH);  
  pinMode(sten_3, INPUT);      //row 3
  digitalWrite(sten_3, LOW);
  
  delay(1000);
  
  //turn on LED L2
  pinMode(LED_1, OUTPUT);     //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, OUTPUT);     //row 2
  digitalWrite(LED_2, LOW);   
  pinMode(LED_3, INPUT);      //row 3
  digitalWrite(LED_3, LOW);

  pinMode(sten_1, OUTPUT);     //row 1
  digitalWrite(sten_1, HIGH);
  pinMode(sten_2, OUTPUT);     //row 2
  digitalWrite(sten_2, LOW);   
  pinMode(sten_3, INPUT);      //row 3
  digitalWrite(sten_3, LOW);
  
  delay(1000);
  
  //turn on LED L3
  pinMode(LED_1, INPUT);      //row 1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);     //row 2
  digitalWrite(LED_2, LOW);  
  pinMode(LED_3, OUTPUT);     //row 3
  digitalWrite(LED_3, HIGH);
  
  pinMode(sten_1, INPUT);      //row 1
  digitalWrite(sten_1, LOW);
  pinMode(sten_2, OUTPUT);     //row 2
  digitalWrite(sten_2, LOW);  
  pinMode(sten_3, OUTPUT);     //row 3
  digitalWrite(sten_3, HIGH);

  delay(1000);
  
  //turn on LED L4
  pinMode(LED_1, INPUT);     //row 1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);    //row 2
  digitalWrite(LED_2, HIGH);  
  pinMode(LED_3, OUTPUT);    //row 3
  digitalWrite(LED_3, LOW);
  
  pinMode(sten_1, INPUT);     //row 1
  digitalWrite(sten_1, LOW);
  pinMode(sten_2, OUTPUT);    //row 2
  digitalWrite(sten_2, HIGH);  
  pinMode(sten_3, OUTPUT);    //row 3
  digitalWrite(sten_3, LOW);

  delay(1000);

  //turn on LED L5
  pinMode(LED_1, OUTPUT);    //row 1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);     //row 2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, OUTPUT);    //row3
  digitalWrite(LED_3, HIGH);

pinMode(sten_1, OUTPUT);    //row 1
  digitalWrite(sten_1, LOW);
  pinMode(sten_2, INPUT);     //row 2
  digitalWrite(sten_2, LOW);
  pinMode(sten_3, OUTPUT);    //row3
  digitalWrite(sten_3, HIGH);
  delay(1000);
}
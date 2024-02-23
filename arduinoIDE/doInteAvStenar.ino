//RIGHT/LEFT interrupt
//

const int RIGHTInterruptPin = __; //Right-button pin
const int LEFTInterruptPin = __; //Right-button pin

void setup() {
  pinMode(RIGHTInterruptPin, INPUT);
  pinMode(LEFTInterruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(RIGHTInterruptPin), handleRIGHTInterrupt, RISING); 
  attachInterrupt(digitalPinToInterrupt(LEFTInterruptPin), handleLEFTInterrupt, RISING); 
}

void loop() {
  //Function loop

}

void handleRIGHTInterrupt() {
  //Update position in player row
  //Move position one step to the right
}

void handleLEFTInterrupt() {
  //Update position in player row
  //Move position one step to the right
}

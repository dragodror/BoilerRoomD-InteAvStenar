// Master
int tmp = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  int light = (tmp % 5) + 1;
  
  //int tmp = random(1, 5);
  
  
  
  Serial.write(light);
  tmp++;
  delay(1000);
}
//Slave

const byte rowIn1[3]{ 13, 12, 11 };

void turnOnLED(const byte row[], int LEDon) {
  switch (LEDon) {
    case 1:
      {
        pinMode(row[0], OUTPUT);
        digitalWrite(row[0], LOW);
        pinMode(row[1], OUTPUT);
        digitalWrite(row[1], HIGH);
        pinMode(row[2], INPUT);
        digitalWrite(row[2], LOW);
        
        Serial.println("case 1\n");
        
        break;
      }
    case 2:
      {
        pinMode(row[0], OUTPUT);
        digitalWrite(row[0], HIGH);
        pinMode(row[1], OUTPUT);
        digitalWrite(row[1], LOW);
        pinMode(row[2], INPUT);
        digitalWrite(row[2], LOW);
        
        Serial.println("case 2\n");
        
        break;
      }

    case 3:
      {
        pinMode(row[0], INPUT);
        digitalWrite(row[0], LOW);
        pinMode(row[1], OUTPUT);
        digitalWrite(row[1], LOW);
        pinMode(row[2], OUTPUT);
        digitalWrite(row[2], HIGH);
        
        Serial.println("case 3\n");
        
        break;
      }

    case 4:
      {
        pinMode(row[0], INPUT);
        digitalWrite(row[0], LOW);
        pinMode(row[1], OUTPUT);
        digitalWrite(row[1], HIGH);
        pinMode(row[2], OUTPUT);
        digitalWrite(row[2], LOW);
        
        Serial.println("case 4\n");
        
        break;
      }

    case 5:
      {
        pinMode(row[0], OUTPUT);
        digitalWrite(row[0], LOW);
        pinMode(row[1], INPUT);
        digitalWrite(row[1], LOW);
        pinMode(row[2], OUTPUT);
        digitalWrite(row[2], HIGH);
        
        Serial.println("case 5\n");
        
        break;
      }
  }
}


void setup() {
  Serial.begin(9600);
}

void loop() {
  int tmp{};
  if (Serial.available()) {
    tmp = Serial.read();
    turnOnLED(rowIn1, tmp);
  }
}
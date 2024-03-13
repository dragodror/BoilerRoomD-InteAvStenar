//Sub
//The sub-unit gets one input witch is the position of the new 'stone' in row one.
// It spawns a 'stone' in that position and then updates the rows accordingly.  


//Constants for elecronics

const byte rowIn1[3]{13, 11, 12};  //Pins in for charlieplexing in row n
const byte rowIn2[3]{10,8,9};
const byte rowIn3[3]{7,5,6};
const byte rowIn4[3]{4,2,3};
const byte rowIn5[3]{A5,A4,A3};
const byte rowIn6[3]{A2,A1,A0};



//Variables for electonics

int row1Pos{};    //Position for the stone in each row
int row2Pos{};
int row3Pos{};
int row4Pos{};
int row5Pos{};
int row6Pos{};


//Function to turn on specific LED in specific row
void turnOnLED(const byte row[], int LEDon) {
  switch (LEDon) {
    case 1:
      {
        pinMode(row[0], INPUT);
        digitalWrite(row[0], LOW);
        pinMode(row[1], OUTPUT);
        digitalWrite(row[1], LOW);
        pinMode(row[2], OUTPUT);
        digitalWrite(row[2], HIGH);
        
        break;
      }
    case 2:
      {
        pinMode(row[0], OUTPUT);
        digitalWrite(row[0], HIGH);
        pinMode(row[1], INPUT);
        digitalWrite(row[1], LOW);
        pinMode(row[2], OUTPUT);
        digitalWrite(row[2], LOW);
        
        break;
      }

    case 3:
      {
        pinMode(row[0], OUTPUT);
        digitalWrite(row[0], LOW);
        pinMode(row[1], INPUT);
        digitalWrite(row[1], LOW);
        pinMode(row[2], OUTPUT);
        digitalWrite(row[2], HIGH);
        
        break;
      }

    case 4:
      {
        pinMode(row[0], OUTPUT);
        digitalWrite(row[0], LOW);
        pinMode(row[1], OUTPUT);
        digitalWrite(row[1], HIGH);
        pinMode(row[2], INPUT);
        digitalWrite(row[2], LOW);
        
        break;
      }

    case 5:
      {
        pinMode(row[0], OUTPUT);
        digitalWrite(row[0], HIGH);
        pinMode(row[1], OUTPUT);
        digitalWrite(row[1], LOW);
        pinMode(row[2], INPUT);
        digitalWrite(row[2], LOW);
        
        break;
      }
  }
}
void turnOnLEDAnalog(const byte row[], int LEDon) {
  switch (LEDon) {
    case 1:
      {
        pinMode(row[0], INPUT);
        digitalWrite(row[0], 0);
        pinMode(row[1], OUTPUT);
        digitalWrite(row[1], 1023);
        pinMode(row[2], OUTPUT);
        digitalWrite(row[2], 0);
        
        break;
      }
    case 2:
      {
        pinMode(row[0], OUTPUT);
        digitalWrite(row[0], 1023);
        pinMode(row[1], OUTPUT);
        digitalWrite(row[1], 0);
        pinMode(row[2], INPUT);
        digitalWrite(row[2], 0);
        
        break;
      }

    case 3:
      {
        pinMode(row[0], OUTPUT);
        digitalWrite(row[0], 0);
        pinMode(row[1], OUTPUT);
        digitalWrite(row[1], 1023);
        pinMode(row[2], INPUT);
        digitalWrite(row[2], 0);
        
        break;
      }

    case 4:
      {
        pinMode(row[0], OUTPUT);
        digitalWrite(row[0], 1023);
        pinMode(row[1], INPUT);
        digitalWrite(row[1], 0);
        pinMode(row[2], OUTPUT);
        digitalWrite(row[2], 0);
        
        break;
      }

    case 5:
      {
        pinMode(row[0], OUTPUT);
        digitalWrite(row[0], 0);
        pinMode(row[1], INPUT);
        digitalWrite(row[1], 0);
        pinMode(row[2], OUTPUT);
        digitalWrite(row[2], 1023);
        
        break;
      }
  }
}


//Function to update the grid to the new positions once a new stone is 
// spawned and the position of that stone is sent to the sub-arduino
void updateGrid(int newStonePos)
{
  turnOnLEDAnalog(rowIn6, row5Pos);
  row6Pos = row5Pos;
  turnOnLEDAnalog(rowIn5, row4Pos);
  row5Pos = row4Pos;
  turnOnLED(rowIn4, row3Pos);
  row4Pos = row3Pos;
  turnOnLED(rowIn3, row2Pos);
  row3Pos = row2Pos;
  turnOnLED(rowIn2, row1Pos);
  row2Pos = row1Pos;
  turnOnLED(rowIn1, newStonePos);
  row1Pos = newStonePos;
}


void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    int newStone = Serial.read();
    updateGrid(newStone);
  }
}

//Constants for Electronics

const int RIGHTInterruptPin = __;  //Right-button pin
const int LEFTInterruptPin = __;   //Left-button pin

const byte rowIn1[3]{};  //Pins in for charlieplexing in row n
const byte rowIn2[3]{};
const byte rowIn3[3]{};
const byte rowIn4[3]{};
const byte rowIn5[3]{};
const byte rowIn6[3]{};
const byte rowPlayer[3]{};



//Variales for electronics

//Positions of 'stone in row'
int row1Pos{};
int row2Pos{};
int row3Pos{};
int row4Pos{};
int row5Pos{};
int row6Pos{};




//Variables for game logic

byte rad1[5] = { 0, 0, 0, 0, 0 };
byte rad2[5] = { 0, 0, 0, 0, 0 };
byte rad3[5] = { 0, 0, 0, 0, 0 };
byte rad4[5] = { 0, 0, 0, 0, 0 };
byte rad5[5] = { 0, 0, 0, 0, 0 };
byte rad6[5] = { 0, 0, 0, 0, 0 };
byte player[5] = { 0, 0, 1, 0, 0 };

//int points = 0;
int currentPlayerPos = 2;  //Also used for elecronic logic
int life = 3;

void setup() {
  pinMode(RIGHTInterruptPin, INPUT);
  pinMode(LEFTInterruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(RIGHTInterruptPin), handleRIGHTInterrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(LEFTInterruptPin), handleLEFTInterrupt, RISING);
}

void loop() {
  //Function loop
  //Skapa function som lägger in stenar(efter antal ms) samt kollar fter kollision
}
void checkCollision() {
  if (rad6[currentPlayerPos] == 1)  //Skada
    life--;                         //Lägg till bool för game over
}

void updateGrid() {
  //Randomise a new stone for the first row
  int newStonePos = random(0, 4);

  //Update game logic
  for (int i = 0; i < 5; i++)  // Stenposition
  {
    rad6[i] = rad5[i];
    rad5[i] = rad4[i];
    rad4[i] = rad3[i];
    rad3[i] = rad2[i];
    rad2[i] = rad1[i];
    rad1[i] = 0;
  }

  //Update stone position in row 1
  rad1[newStonePos] = 1;  //new stone

  //Update electronics
  turnOnLED(row6, row5Pos);
  row6Pos = row5Pos;
  turnOnLED(row5, row4Pos);
  row5Pos = row4Pos;
  turnOnLED(row4, row3Pos);
  row4Pos = row3Pos;
  turnOnLED(row3, row2Pos);
  row3Pos = row2Pos;
  turnOnLED(row2, row1Pos);
  row2Pos = row1Pos;
  turnOnLED(row1, newStonePos);

  turnOnLED(rowPlayer, currentPlayerPos);
}

void handleRIGHTInterrupt() {
  //Move position one step to the right

  //Add debouncing______
  if (currentPlayerPos < 4) {
    player[currentPlayerPos] = 0;
    currentPlayerPos++;
    player[currentPlayerPos] = 1;
  } else {
    player[currentPlayerPos] = 1;
  }
  //Update position in player row
  turnOnLED(rowPlayer, currentPlayerPos);
}

void handleLEFTInterrupt() {
  //Move position one step to the left

  //Add debouncing_____
  if (currentPlayerPos > 0) {
    player[currentPlayerPos] = 0;
    currentPlayerPos--;
    player[currentPlayerPos] = 1;
  } else {
    player[currentPlayerPos] = 1;
  }
  //Update position in player row
  turnOnLED(rowPlayer, currentPlayerPos);
}


void turnOnLED(const byte[3] & row, int LEDon) {
  switch (LEDon) {
    case 1:
      {
        pinMode(row[1], OUTPUT);
        digitalWrite(row[1], LOW);
        pinMode(row[2], OUTPUT);
        digitalWrite(row[2], HIGH);
        pinMode(row[3], INPUT);
        digitalWrite(row[3], LOW);
        break;
      }
    case 2:
      {
        pinMode(row[1], OUTPUT);
        digitalWrite(row[1], HIGH);
        pinMode(row[2], OUTPUT);
        digitalWrite(row[2], LOW);
        pinMode(row[3], INPUT);
        digitalWrite(row[3], LOW);
        break;
      }

    case 3:
      {
        pinMode(row[1], INPUT);
        digitalWrite(row[1], LOW);
        pinMode(row[2], OUTPUT);
        digitalWrite(row[2], LOW);
        pinMode(row[3], OUTPUT);
        digitalWrite(row[3], HIGH);
        break;
      }

    case 4:
      {
        pinMode(row[1], INPUT);
        digitalWrite(row[1], LOW);
        pinMode(row[2], OUTPUT);
        digitalWrite(row[2], HIGH);
        pinMode(row[3], OUTPUT);
        digitalWrite(row[3], LOW);
        break;
      }

    case 5:
      {
        pinMode(row[1], OUTPUT);
        digitalWrite(row[1], LOW);
        pinMode(row[2], INPUT);
        digitalWrite(row[2], LOW);
        pinMode(row[3], OUTPUT);
        digitalWrite(row[3], HIGH);
        break;
      }

    case 6:
      {
        pinMode(row[1], OUTPUT);
        digitalWrite(row[1], HIGH);
        pinMode(row[2], INPUT);
        digitalWrite(row[2], LOW);
        pinMode(row[3], OUTPUT);
        digitalWrite(row[3], LOW);
        break;
      }
  }
}

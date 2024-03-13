//Dom
//The dom-unit



//Constants for Electronics

const int RIGHTInterruptPin = 9;  //Right-button pin (WHITE)
const int LEFTInterruptPin = 8;   //Left-button pin (GREY)

//player pins
const byte rowPlayer[3]{ 13, 12, 11 };


//Variables for game logic

byte rad1[5] = { 0, 0, 0, 0, 0 };
byte rad2[5] = { 0, 0, 0, 0, 0 };
byte rad3[5] = { 0, 0, 0, 0, 0 };
byte rad4[5] = { 0, 0, 0, 0, 0 };
byte rad5[5] = { 0, 0, 0, 0, 0 };
byte rad6[5] = { 0, 0, 0, 0, 0 };
byte player[5] = { 0, 0, 1, 0, 0 };

//nya
int row1Pos{};    //Position for the stone in each row
int row2Pos{};
int row3Pos{};
int row4Pos{};
int row5Pos{};
int row6Pos{};

//int points = 0;

int currentPlayerPos = 3;  //Also used for elecronic logic
int life = 3;

//byte checkInterruptLeft = LOW;
//byte checkInterruptRight = LOW;

//Variables constants for time management
int updateFrequency = 800;  //starting speed for the game
int lastUpdate{};
int gameEsculate = 50;

bool first = true;


void setup() {
  pinMode(RIGHTInterruptPin, INPUT);
  pinMode(LEFTInterruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(RIGHTInterruptPin), handleRIGHTInterrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(LEFTInterruptPin), handleLEFTInterrupt, RISING);
  Serial.begin(9600);
}

void loop() {
  //Function loop
  /*
  byte readLeft = digitalRead(RIGHTInterruptPin);
  byte readRight = digitalRead(LEFTInterruptPin);

  if(readLeft == HIGH)
    handleRIGHTInterrupt();

  else if(readRight == HIGH)
    handleLEFTInterrupt();
    */

  if (first) {
    turnOnLED(rowPlayer, currentPlayerPos);
    first = false;
  }


  int currentTime = millis();
  //Checking if it's been more time than 'updateFrequency' since last update
  if (currentTime - lastUpdate > updateFrequency) {
    if (checkCollision()) {
      life--;
    }

    updateGrid();
    lastUpdate = millis();
    if (updateFrequency < 300)
      updateFrequency = updateFrequency - gameEsculate;
  }
}

//Function that checks if player is hit by a stone
bool checkCollision() {
  if (currentPlayerPos == row6Pos)
    return true;
  return false;
}


//Function for spawning a new stone and then updates the grid accordingly
void updateGrid() {
  //Randomise a position for new stone for the first row
  int newStonePos = random(0, 6);

  //Update game logic
  for (int i = 0; i < 5; i++) {
    rad6[i] = rad5[i];
    rad5[i] = rad4[i];
    rad4[i] = rad3[i];
    rad3[i] = rad2[i];
    rad2[i] = rad1[i];
    rad1[i] = 0;
  }
  row6Pos = row5Pos;
  row5Pos = row4Pos;
  row4Pos = row3Pos;
  row3Pos = row2Pos;
  row2Pos = row1Pos;
  row1Pos = newStonePos;

  //Send info about new stone position to the sub-unit to update the electronics
  Serial.write(newStonePos);

  //Update stone position in row 1 for game logic
  rad1[newStonePos] = 1;
}

void handleRIGHTInterrupt() {
  //Move position one step to the right

  //Add debouncing______!!!!!!!!


  if (currentPlayerPos < 5) {
    //Uppdatera spellogiken
    player[currentPlayerPos] = 0;
    currentPlayerPos++;
    player[currentPlayerPos] = 1;
  }

  //Update electronics with new player position
  turnOnLED(rowPlayer, currentPlayerPos);
}

void handleLEFTInterrupt() {
  //Move position one step to the left

  //Add debouncing_____!!!!!!!

  //Uppdatera spellogiken
  if (currentPlayerPos > 1) {
    player[currentPlayerPos] = 0;
    currentPlayerPos--;
    player[currentPlayerPos] = 1;
  }

  //Update electronics with new player position
  turnOnLED(rowPlayer, currentPlayerPos);
}


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

        Serial.println("case 1\n");

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

        Serial.println("case 2\n");

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

        Serial.println("case 3\n");

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

        Serial.println("case 4\n");

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

        Serial.println("case 5\n");

        break;
      }
  }
}
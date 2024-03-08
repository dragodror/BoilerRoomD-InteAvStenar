//Dom
//The dom-unit 



//Constants for Electronics

  const int RIGHTInterruptPin = 2;  //Right-button pin
  const int LEFTInterruptPin = 3;   //Left-button pin

  const byte rowPlayer[3]{};


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

  //Variables constants for time management
  int updateFrequency{}; //starting speed for the game
  int lastUpdate{};


void setup() {
  pinMode(RIGHTInterruptPin, INPUT);
  pinMode(LEFTInterruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(RIGHTInterruptPin), handleRIGHTInterrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(LEFTInterruptPin), handleLEFTInterrupt, RISING);
  Serial.begin(9600);
}

void loop() {
  //Function loop

  if(checkCollision())
  {
    //Loose one life or end game if lives are zero.
  }

  int currentTime = millis();
  //Checking if it's been more time than 'updateFrequency' since last update
  if(currentTime - lastUpdate > updateFrequency)
  {
    updateGrid();
    lastUpdate = millis();
  }
}

//Function that checks if player is hit by a stone
bool checkCollision() {
  if (rad6[currentPlayerPos] == 1)  
      return true;                      
  return false;
}


//Function for spawning a new stone and then updates the grid accordingly
void updateGrid() {
  //Randomise a position for new stone for the first row
  int newStonePos = random(0, 4);

  //Update game logic
  for (int i = 0; i < 5; i++)
  {
    rad6[i] = rad5[i];
    rad5[i] = rad4[i];
    rad4[i] = rad3[i];
    rad3[i] = rad2[i];
    rad2[i] = rad1[i];
    rad1[i] = 0;
  }

  //Send info about new stone position to the sub-unit to update the electronics
  Serial.write(newStonePos);

  //Update stone position in row 1 for game logic
  rad1[newStonePos] = 1;
}

void handleRIGHTInterrupt() {
  //Move position one step to the right

  //Add debouncing______!!!!!!!!


  if (currentPlayerPos < 4) {
    player[currentPlayerPos] = 0;
    currentPlayerPos++;
    player[currentPlayerPos] = 1;
  } else {
    player[currentPlayerPos] = 1;
  }

  //Update electronics with new player position
  turnOnLED(rowPlayer, currentPlayerPos);
}

void handleLEFTInterrupt() {
  //Move position one step to the left

  //Add debouncing_____!!!!!!!


  if (currentPlayerPos > 0) {
    player[currentPlayerPos] = 0;
    currentPlayerPos--;
    player[currentPlayerPos] = 1;
  } else {
    player[currentPlayerPos] = 1;
  }

  //Update electronics with new player position  
  turnOnLED(rowPlayer, currentPlayerPos);
}


void turnOnLED(const byte row[], int LEDon) {
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

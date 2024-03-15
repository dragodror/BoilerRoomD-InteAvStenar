//Dom
//The dom-unit



//Constants for Electronics

const int buttonPin1 = 9;  //Right-button pin (WHITE)
const int buttonPin2 = 8;  //Left-button pin (GREY)

//player pins
const byte rowPlayer[3]{ 13, 12, 11 };
//analog pin to get a radnom value
byte randomPin = A0;




//Variables

//Row positions
int row1Pos{};  //Position for the stone in each row
int row2Pos{};
int row3Pos{};
int row4Pos{};
int row5Pos{};
int row6Pos{};

bool dead = false;


int currentPlayerPos = 3;  //Also used for elecronic logic
int life = 3;


//Variables constants for time management
int updateFrequency = 800;  //starting speed for the game
int lastUpdate{};
int gameEsculate = 200;
int updates{ 1 };

bool first = true;


//Debouncing variables

const unsigned long debounceDelay = 50;

byte lastButtonState1 = LOW;
byte buttonState1 = LOW;
unsigned long lastDebounceTime1 = 0;

byte lastButtonState2 = LOW;
byte buttonState2 = LOW;
unsigned long lastDebounceTime2 = 0;


void turnOnLED(const byte row[], int LEDon) {
  switch (LEDon) {
    case 0:
    {
        pinMode(row[0], INPUT);
        digitalWrite(row[0], 0);
        pinMode(row[1], OUTPUT);
        digitalWrite(row[1], 0);
        pinMode(row[2], OUTPUT);
        digitalWrite(row[2], 0);

        break;
    }
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


void moveRight() {
  //Move position one step to the right

  if (currentPlayerPos < 5) {
    currentPlayerPos++;
  }

  //Update electronics with new player position
  turnOnLED(rowPlayer, currentPlayerPos);
}

void moveLeft() {
  //Move position one step to the left

  if (currentPlayerPos > 1) {
    currentPlayerPos--;
  }

  //Update electronics with new player position
  turnOnLED(rowPlayer, currentPlayerPos);
}

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  Serial.begin(9600);
}


void loop() {
  //Function loop

  if (dead) {
    int score = millis();
    //TODO: Skriv in score till en textfil
    //TODO: GÖR NÅGOT, loopa lampor typ
    //TODO: GÖR EN LEDSEN GUBBE
    Serial.write(0);
    turnOnLED(rowPlayer,0);
  }

  //Reading and debouncing right button
  byte reading = digitalRead(buttonPin1);

  if (reading != lastButtonState1) {
    lastDebounceTime1 = millis();
  }

  if ((millis() - lastDebounceTime1) > debounceDelay) {
    if (reading != buttonState1) {
      buttonState1 = reading;

      if (HIGH == buttonState1) {
        moveRight();
      }
    }
  }

  lastButtonState1 = reading;


  //Reading and debouncing left button
  reading = digitalRead(buttonPin2);

  if (reading != lastButtonState2) {
    lastDebounceTime2 = millis();
  }

  if ((millis() - lastDebounceTime2) > debounceDelay) {
    if (reading != buttonState2) {
      buttonState2 = reading;

      if (HIGH == buttonState2) {
        moveLeft();
      }
    }
  }

  lastButtonState2 = reading;


  //Special case to turn on the player row at the beginning before first movement
  if (first) {
    turnOnLED(rowPlayer, currentPlayerPos);
    int randomValue = analogRead(randomPin);
    randomSeed(randomValue);
    first = false;
  }


  //Checking if it's been more time than 'updateFrequency' since last update
  int currentTime = millis();
  if (currentTime - lastUpdate > updateFrequency) {
    if (checkCollision()) {
      life--;
      //TODO: Sänk livlampa
      if(life == 0)
      {
        dead = true;
      }
    }

    updateGrid();
    lastUpdate = millis();
  }

  if (millis() > (updates * 5000)){
      if (updateFrequency > 300) {
        updateFrequency = updateFrequency - gameEsculate;
      }
      updates++;
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

  row6Pos = row5Pos;
  row5Pos = row4Pos;
  row4Pos = row3Pos;
  row3Pos = row2Pos;
  row2Pos = row1Pos;
  row1Pos = newStonePos;

  //Send info about new stone position to the sub-unit to update the electronics
  Serial.write(newStonePos);

}

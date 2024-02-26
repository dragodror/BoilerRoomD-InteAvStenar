
//Konstanter för elektronik
const int RIGHTInterruptPin = __; //Right-button pin
const int LEFTInterruptPin = __; //Left-button pin

//Variabler för elektroniken

//Variabler för spellogiken
  byte rad1[5] = {0,0,0,0,0};
  byte rad2[5] = {0,0,0,0,0};
	byte rad3[5] = {0,0,0,0,0};
	byte rad4[5] = {0,0,0,0,0};
	byte rad5[5] = {0,0,0,0,0};
	byte rad6[5] = {0,0,0,0,0};
	byte player[5] = { 0,0,1,0,0 };
	//int points = 0;
	int currentPlayerPos = 2;
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
void checkCollision()
{
  if (rad6[currentPlayerPos] == 1) //Skada
			life--;//Lägg till bool för game over
}

void updateGrid()
{
  int newStonePos = random(0, 4);

  for (int i = 0; i < 5; i++)// Stenposition
		{
			rad6[i] = rad5[i];
			rad5[i] = rad4[i];
			rad4[i] = rad3[i];
			rad3[i] = rad2[i];
			rad2[i] = rad1[i];
			rad1[i] = 0;
		}
    rad1[newStonePos] = 1;	//ny sten
}

void handleRIGHTInterrupt() {
  //Update position in player row
  //Move position one step to the right
  if (currentPlayerPos < 4)
			{
				player[currentPlayerPos] = 0;
				currentPlayerPos++;
				player[currentPlayerPos] = 1;
			}
			else
				player[currentPlayerPos] = 1;
}

void handleLEFTInterrupt() {
  //Update position in player row
  //Move position one step to the left
  if (currentPlayerPos > 0) 
			{
				player[currentPlayerPos] = 0;
				currentPlayerPos--;
				player[currentPlayerPos] = 1;
			}
			else
				player[currentPlayerPos] = 1;
}

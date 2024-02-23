#include <iostream>
#include <conio.h>
			
void gameGrid(int arr1[5], int arr2[5], int arr3[5], int arr4[5], int arr5[5], int arr6[5], int player[5]) 
{
	system("cls");
	printf("%d || %d | %d | %d | %d | %d | %d\n", player[0], arr1[0], arr2[0], arr3[0], arr4[0], arr5[0], arr6[0]);
	printf("_____________________\n");
	printf("%d || %d | %d | %d | %d | %d | %d\n", player[1], arr1[1], arr2[1], arr3[1], arr4[1], arr5[1], arr6[1]);
	printf("_____________________\n");
	printf("%d || %d | %d | %d | %d | %d | %d\n", player[2], arr1[2], arr2[2], arr3[2], arr4[2], arr5[2], arr6[2]);
	printf("_____________________\n");
	printf("%d || %d | %d | %d | %d | %d | %d\n", player[3], arr1[3], arr2[3], arr3[3], arr4[3], arr5[3], arr6[3]);
	printf("_____________________\n");
	printf("%d || %d | %d | %d | %d | %d | %d\n", player[4], arr1[4], arr2[4], arr3[4], arr4[4], arr5[4], arr6[4]);
	

}
int main()
{
	int rad1[5] = {0,0,0,0,0};
	int rad2[5] = {0,0,0,0,0};
	int rad3[5] = {0,0,0,0,0};
	int rad4[5] = {0,0,0,0,0};
	int rad5[5] = {0,0,0,0,0};
	int rad6[5] = {0,0,0,0,0};
	int player[5] = { 0,0,1,0,0 };
	int points = 0;
	int currentPlayerPos = 2;

	int life = 3;

	srand(time(0));
	while (life > 0)
	{
		int randNum = rand() % 5;
		int playerPos = rand() % 2;

		for (int i = 0; i < 5; i++)// Stenposition
		{
			player[i] = 0;
			rad6[i] = rad5[i];
			rad5[i] = rad4[i];
			rad4[i] = rad3[i];
			rad3[i] = rad2[i];
			rad2[i] = rad1[i];
			rad1[i] = 0;
		}

		if (playerPos == 1) //Move right
		{
			if (currentPlayerPos < 4)
			{
				player[currentPlayerPos] = 0;
				currentPlayerPos++;
				player[currentPlayerPos] = 1;
			}
			else
				player[currentPlayerPos] = 1;
		}

		if (playerPos == 0)  //Move left
		{
			if (currentPlayerPos > 0) 
			{
				player[currentPlayerPos] = 0;
				currentPlayerPos--;
				player[currentPlayerPos] = 1;
			}
			else
				player[currentPlayerPos] = 1;
		}
		rad1[randNum] = 1;

		if (rad6[currentPlayerPos] == 1) //Skada
			life--;

		gameGrid(rad6, rad5, rad4, rad3, rad2, rad1, player);
		
		
		
		std::cout <<"HP: " << life << "\tPoints: " << points;
		char hej = _getch();
		points++;
	}
}
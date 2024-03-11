#include <iostream>
#include <fstream>
#include <string>


//Highscore is saved on the form "LLL TTTT"      
// LLL = name of the player
// TTTT = time in seconds


bool checkHighscore(int time)
{
	std::ifstream file("highscore.txt");

	do
	{
		std::string line;

		std::string scoreStr;
		int scoreInt;

		getline(file, line);
		scoreStr = line[4] + line[5] + line[6] + line[7];
		scoreInt = std::stoi(scoreStr);

		if (time > scoreInt)	//If the time input is larger than a score
		{						// the function returns true
			return true;
		}
	} while (!file.eof());

	return false;				//The time wasn't larger than any of the highscores
}

void addHighsore(int time)
{
	std::ofstream file("highscore.txt");

	//Three letter identifier
	char inputName[3]{};






}

void printHighscore()
{
	std::ifstream file("highscore.txt");


}


int main()
{


}
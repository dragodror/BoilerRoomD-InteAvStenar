#include <iostream>
#include <fstream>
#include <string>
#include <vector>


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
			file.close();
			return true;
		}
	} while (!file.eof());

	file.close();
	return false;				//The time wasn't larger than any of the highscores
}


void addHighsore(int time)
{
	std::ifstream infile("highscore.txt");
	

	//Saves the current highscores in a vector
	// and adding the new highscore at it's correct spot
	std::vector<std::string> lines;

	do
	{
		std::string line;
		std::string scoreStr;
		int scoreInt;

		getline(infile, line);

		scoreStr = line[4] + line[5] + line[6] + line[7];
		scoreInt = std::stoi(scoreStr);
		
		if (scoreInt < time)	//If two highscores are the same the first one to
		{						// get to that score should e first (därav <, inte <=)
			
			//Three letter identifier for new highscore
			char inputName[3]{};

			std::cout << "Write your identifier, three letters" << std::endl;

			std::cin >> inputName;
			
			std::string newLine = inputName + ' ' + time;

			lines.push_back(newLine);
		}

		lines.push_back(line);

	} while (!infile.eof());

	infile.close();

	//Writing the first five highscores to the file

	std::ofstream outfile("highscore.txt");
	
	for (auto i : {0,1,2,3,4})
	{
		outfile << lines[i];
	}

	outfile.close();

	return;

}


void printHighscore()
{
	std::ifstream file("highscore.txt");
	
	for (int i : {0,1,2,3,4})
	{
		std::string line{};
		getline(file, line);
		std::cout << i+1 << ": " << line;
	} 

	return;
}


int main()
{


}
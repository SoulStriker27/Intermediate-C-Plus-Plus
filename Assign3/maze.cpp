/****************************************************************
FILE: Maze.cpp
AUTHOR: Eduardo Leanos

PURPOSE: Make a functional running maze using these definitions
 *****************************************************************/

#include "maze.h"

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

/***************************************************************
Function: readMaze
Parameters: const string& fileName, a refrence to an input file that coannot be changed
Returns: Nothing
Notes:
 ***************************************************************/ 

void Maze::readMaze(const string& fileName){
	string temp; // The temporary string to put the file into
	ifstream inFile; 
	inFile.open(fileName); //Open the fileName parameter
	if(!inFile){ //Test wheter it opens
		cout << "There has been an error opening the file, please check your work." << endl;
		exit(1);
	};
	inFile >> validWidth; //Transfer in width
	inFile >> validHeight; //Transfer in height
	for(int i = 0; i < validHeight; i++){ //For loop to get data inFile to maze[][].type
		inFile >> temp; 
		for(int j = 0; j < validWidth; j++){
			maze[i][j].type = (SquareType) temp.c_str()[j]; //Set maze[i][j] to the (string --> char array of temp) with teh help of .c_str()
			if(maze[i][j].type == START){ //If START is found, set it to the start.xpos and start.ypos
				start.xpos = i;
				start.ypos = j;
			}
			if(maze[i][j].type == END){ //If End is found, set it to the end.xpos and start.ypos
				end.xpos = i;
				end.ypos = j;
			}
		}
	}
	inFile.close();	//Close the file
}

/***************************************************************
Function: printMaze
Parameters:Nothing
Returns:Nothing
Notes:Prints the maze
 ***************************************************************/ 

void Maze::printMaze() const{ //Prints out the maze using the 2 dimensional object maze
	cout << "The labyrinth of Csci 241:" << endl << endl;
	for(int i = 0; i < validHeight; i++){ //Nested for loops to the the row and put in all options into that row and then move into the next row
		for( int j = 0; j < validWidth; j++){
			cout << (char)maze[i][j].type; //Typecast  maze[][] to a char to be able to print out
		}
		cout << endl;
	}
}	

/***************************************************************
Function: clearPath
Parameters: None
Returns: Nothing
Notes: Clears the board
 ***************************************************************/ 

void Maze::clearPath(){ //Clear the path everytime the readAndCheckPath is called
	for(int i = 0; i < validHeight; i++){
		for( int j = 0; j < validWidth; j++){ //Go through all parts of the maze and set the maze[][].visited to false
			maze[i][j].visited = false;
		}   
	}
}	

/***************************************************************
Function: readAndCheckPath
Parameters: const string& fileName, a refrence to the input file that cannot be changed
Returns: bool, true or false
Notes:
 ***************************************************************/ 

bool Maze::readAndCheckPath(const string& fileName){
	clearPath(); //Call clearPath to remove visited = true from all maze[][] objects 
	int i = 0;
	int j = 0;
	char direction; //Temporary char variable to put in the data
	ifstream inFile;
	inFile.open(fileName); //Open file
	if(!inFile){ //Test wheter or not it opens
		cout << "You weren't able to open the file? How were you able to get past the first catcher?\
			Oh well, theres seem to be a problem opening the file. Good luck" << endl;
		exit(1);
	}
	i = start.xpos; //Set the start of the maze to start.xpos and start.ypos
	j = start.ypos;
	maze[i][j].visited = true;
	while(inFile >> direction){ //While you can put data into the file
		if(direction == NORTH){ //Test for NORTH and then subtract 1 from i to go up
			i--;
		}
		if(direction == SOUTH){ //Test for SOUTH and then add 1 to i to go down
			i++;
		}
		if(direction == EAST){ //Test for EAST and then add 1 to j to go right
			j++;
		}
		if(direction == WEST){ //Test for WEST and then subtract 1 from j to go left
			j--;
		}
		if(maze[i][j].type == WALL || maze[i][j].visited == true ||j >  validWidth || i >  validHeight ){
			inFile.close(); //Test for their a tile that matches #,visited==true, or larger than maze borders to flag as false
			return false; //Close file
		}
		maze[i][j].visited = true;//Once a tile is visited, mark it as true so you cannot retrace your steps
		if(maze[i][j].type == END){; //If anyof the tiles matches up with the END/e then go ahead and return true and end the maze try as a success
			inFile.close(); //Close file
			return true;
		}
	}
	inFile.close();// Make sure that you close the file if they somehow get of of the while loop
	return false; //Close file
}

/****************************************************************
FILE: Maze.h
AUTHOR: Eduardo Leanos

PURPOSE: The header file for the Maze.cpp
*****************************************************************/

#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;

enum SquareType{   //The enumeration of all valid maze tiles
        WALL = '#',
        SPACE = '.',
        START = 's',
        END = 'e'
};

enum PathType{   //The enumeration of valid maze directions
	NORTH = 'n',
	SOUTH = 's',
	EAST = 'e',
	WEST = 'w'
};

struct MazePos{ //Positions pertaining to height and width coordinates 
        int xpos;
        int ypos;
};

struct MazeSquare{ //Each tile of the maze has 2 settings, its type of and if it was visited or not
	SquareType type;
        bool visited;
};

class Maze{
	private:
		MazeSquare maze[25][25]; //A set of 2 dimentional rays of MazeSquare objects
		int validWidth; //The valid width of the maze
		int validHeight; //The valid height of the maze
		MazePos start; //The starting position of the maze
		MazePos end; //The ending position of the maze
	public:
		void readMaze(const string&);
		void printMaze() const;	
		void clearPath();
		bool readAndCheckPath(const string&);
};

#endif

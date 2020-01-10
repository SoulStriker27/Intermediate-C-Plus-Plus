/***********************************************************
Progammer: Eduardo Leanos

Purpose:This assignment is an exercise in writing, compiling,
and executing a C++ program on the departmental UNIX system.
It also covers the manipulation of C strings.
************************************************************/ 
#include <iostream>
#include "maze.h"

using std::cout;
using std::endl;

int main()
   {
   Maze m;

   m.readMaze("maze1.txt");

   m.printMaze();

   cout << endl;

   // Test with invalid path that hits a wall
   if (m.readAndCheckPath("badpath1.txt"))
      cout << "Valid path / incorrect\n";
   else
      cout << "Invalid path / correct\n";

   // Test with invalid path that doubles back
   if (m.readAndCheckPath("badpath2.txt"))
      cout << "Valid path / incorrect\n";
   else
      cout << "Invalid path / correct\n";

   // Test with invalid path that stops short of the end
   if (m.readAndCheckPath("badpath3.txt"))
      cout << "Valid path / incorrect\n";
   else
      cout << "Invalid path / correct\n";

   // Test with invalid path that travels outside the maze boundaries
   if (m.readAndCheckPath("badpath4.txt"))
      cout << "Valid path / incorrect\n";
   else
      cout << "Invalid path / correct\n";

   // Test with valid path
   if (m.readAndCheckPath("goodpath.txt"))
      cout << "Valid path / correct\n";
   else
      cout << "Invalid path / incorrect\n";

   return 0;
   }

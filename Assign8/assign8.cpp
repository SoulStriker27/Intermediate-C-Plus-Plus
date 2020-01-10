/***********************************************************

Progammer: Eduardo Leanos

Purpose:This assignment is an exercise in writing, compiling,
and executing a C++ program on the departmental UNIX system.
It also covers the manipulation of C strings.
************************************************************/

#include <iostream>
#include <string>
#include "maze.h"

using std::cout;
using std::endl;
using std::to_string;

int main()
   {
   Maze m;

   for (int i = 1; i <= 3; ++i)
      {
      m.readMaze("maze" + to_string(i) + ".txt");

      m.printMaze();

      cout << endl;

      // Test with invalid path that hits a wall
      if (m.solveMaze())
         {
         cout << "Valid path: ";
         m.printPath();
         cout << endl;
         }
      else
         cout << "There is no valid path through this maze.\n";
      }

   return 0;
   }

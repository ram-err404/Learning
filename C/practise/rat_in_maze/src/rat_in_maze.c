#include <maze.h>

int main() {
  int maze[N][N] = {{1, 0, 0, 1, 1, 1},
                    {1, 1, 0, 1, 0, 1},
                    {0, 1, 1, 1, 0, 1},
                    {0, 0, 0, 1, 0, 1},
                    {0, 0, 0, 1, 1, 1},
                    {0, 1, 1, 1, 0, 1}};
  printMaze(maze);
  solveMaze(maze, 0, 0);
  return 0;
}

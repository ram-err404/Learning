#include <maze.h>

void  printMaze(int maze[N][N]) {
  printf("\n");
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++)
      printf("%d ", maze[i][j]);
    printf("\n");
  }
  printf("\n");
}

bool_t isSafe(int maze[N][N], int x, int y) {
  if(x>=0 && y>=0 && x<N && y<N && maze[x][y]==1)
    return TRUE;
  return FALSE;
}

bool_t solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
  

  if(x==N-1 && y==N-1) {  /*Make this as 1*/
    sol[x][y] = 1;
    return TRUE;
  }
  
  if(TRUE == isSafe(maze, x, y)) {
    sol[x][y] = 1;
    
    if(TRUE == solveMazeUtil(maze, x, y+1, sol)) {
      return TRUE;
    }
    if(TRUE == solveMazeUtil(maze, x+1, y, sol)) {
      return TRUE;
    }
    sol[x][y] = 0;  /*Backtrack from here*/
    return FALSE;
  }
  return FALSE;
}

status_t solveMaze(int maze[N][N], int x, int y) {
  int sol[N][N] = {{0}, {0}, {0}, {0}};
  
  if(FALSE == solveMazeUtil(maze, x, y, sol)) {
    printf("\nSolution doesn't exists\n");
    return FAILURE;
  }
  printMaze(sol);
  return SUCCESS;
}


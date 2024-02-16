#ifndef __MAZE_H__
#define __MAZE_H__

#include <stdio.h>

#define N 6

typedef enum {
  SUCCESS,
  FAILURE
} status_t;

typedef enum {
  FALSE,
  TRUE
} bool_t;

extern bool_t     isSafe(int maze[N][N], int x, int y);
extern bool_t     solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);
extern status_t   solveMaze(int maze[N][N], int x, int y);
extern void       printMaze(int maze[N][N]);

#endif

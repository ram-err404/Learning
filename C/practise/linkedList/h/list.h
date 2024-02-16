#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
  int data;
  struct NODE* link;
}node_t;

typedef enum status{
  SUCCESS = 0,
  FAILURE
}status_t;

extern node_t*   create(int val);
extern status_t  insert(node_t *ptr);
extern void      disp();

#endif

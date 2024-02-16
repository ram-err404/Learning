#ifndef __DLL_H__
#define __DLL_H__

#include  <stdio.h>
#include  <stdlib.h>

typedef enum status{
  SUCCESS,
  FAILURE
}status_t;

typedef struct DLL_NODE {
  int           data;
  struct DLL_NODE   *prev;
  struct DLL_NODE   *next; 
}dll_node_t;

extern dll_node_t*   create(int  val);
extern status_t      insert(dll_node_t   *ptr);
extern void          disp();

#endif

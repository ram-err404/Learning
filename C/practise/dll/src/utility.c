#include <dll.h>

dll_node_t  *head = NULL;

dll_node_t*   create(int val) {
  dll_node_t  *ptr = NULL;

  ptr = (dll_node_t*) malloc(sizeof(dll_node_t));
  if (ptr == NULL) {
    printf("Memory allocation failed. Aborting !!!");
    exit(0); 
  }
  ptr->data = val;
  ptr->prev = NULL;
  ptr->next = NULL;

  return ptr;
}

/*Insert in accending order*/
status_t    insert(dll_node_t   *ptr) {
  dll_node_t  *traverse = head;
  status_t    ret_val = SUCCESS;

  if (ptr == NULL) {
    printf("inserting node should not be null");
    ret_val = FAILURE;
  }
  if (head == NULL) {
    /* This is the first Node */
    head = ptr;
  } else {
    while (traverse->next != NULL) {
      traverse = traverse->next;
    }
    traverse->next  = ptr;
    ptr->prev       = traverse;
  }
  return ret_val;
}

void    disp() {
  dll_node_t  *traverse = head;
  
  printf("\nnull");
  while(traverse != NULL) {
    printf("<-- %d -->", traverse->data);
    traverse = traverse->next;
  }
  printf("null\n");
}

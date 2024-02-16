#include <list.h>

node_t *head = NULL;

node_t* create(int val) {
  node_t  *ptr  = NULL;
  ptr = (node_t*) malloc(sizeof(node_t));
  if (ptr == NULL) {
    printf("Memory allocation failed. Aborting!!!");
    exit(0);
  }
  ptr->data = val;
  ptr->link = NULL;
  return ptr;
}

status_t  insert(node_t *ptr) {
  status_t  ret_val = SUCCESS;
  node_t    *traverse = head;
  if (ptr == NULL) {
    printf("Node to be inserted should not be null");
    ret_val = FAILURE;
  }
  
  if (head == NULL) {
    /* This is the first node */
    head = ptr;
  } else {
    while (traverse->link != NULL)
      traverse = traverse->link;
    traverse->link = ptr; 
  }
  return ret_val;
}

void disp() {
  node_t  *traverse = head;
  while (traverse != NULL) {
    printf("%d --> ", traverse->data);
    traverse = traverse->link;
  }
  printf("null\n"); 
}

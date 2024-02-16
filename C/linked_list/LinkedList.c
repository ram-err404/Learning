#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

typedef enum{
  SUCCESS = 0,
  FAILURE = 1
} return_t;

typedef enum {
  INSERTION = 1,
  DELETION,
  DISPLAY
}choices;

typedef struct NODE{
  int data;
  struct NODE *link;
} node_t;

node_t  *head = NULL;

return_t  insert(node_t **ptr);
return_t  delete();
void      display();

int main(void)
{
  node_t  *ptr;
  char    choice = 'y';
  int     ch, data;

  ptr   = (node_t *) malloc(sizeof(node_t));
  if (ptr == NULL) {
    printf("Memory Allocation Failed");
    exit(EXIT_FAILURE);
  }
  ptr->data = 0;
  ptr->link = NULL;

  while (choice == 'Y' || choice == 'y') {
    printf("****** MENU *********\n"
           "\t 1. INSERTION \n"
           "\t 2. DELETION \n"
           "\t 3. DISPLAY \n"
           "*********************\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);

    switch (ch) {
      case INSERTION:
        insert( &ptr );
        break;

      case DELETION:
        delete();
        break;

      case DISPLAY:
        display();
        break;

      default: 
        printf("Invalid choice");
    }

    printf("Display menu again (y/n) :");
    scanf("%c", &choice);  
  }
  return 0;
}

return_t  insert(node_t **ptr)
{
  int     data;
  node_t  *traverse = NULL;
  printf("Enter data: ");
  scanf("%d", &data);

  (*ptr)->data = data;
  
  if (head == NULL) {
    head = *ptr;
    return SUCCESS;
  }
  else {
    (*ptr)->link = head;
    head = *ptr;
    return SUCCESS;
  }
  return FAILURE;
}

return_t  delete()
{
  int data;
  node_t  *traverse;
  printf("Enter value to delete : ");
  scanf("%d", &data);

  if (head == NULL) {
    printf("Underflow");
    return FAILURE;
  }
  traverse = head;
  while ( (traverse->data != data) && (traverse->link != NULL) ) {
    
  }


}
void      display()
{

}

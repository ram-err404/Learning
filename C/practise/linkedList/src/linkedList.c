#include <list.h>

int main() {
  int     val     = 0;
  char    choice  = 'y';
  node_t  *nptr   = NULL;
  
  while (choice == 'y' || choice == 'Y') {
    printf("Enter val to create a node: ");
    scanf("%d", &val);
    nptr  = create(val);

    if (FAILURE == insert(nptr)) {
      printf("Failed to insert");
    }
    printf("Want to enter more nodes (y/n): ");
    getchar();
    choice = getchar();
  }
  disp();
  return SUCCESS;
}

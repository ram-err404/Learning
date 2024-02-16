#include <dll.h>

int main() {
  char        choice  = 'y';
  int         val     = 0;
  dll_node_t  *ptr    = NULL;
  
  while (choice == 'y' || choice == 'Y') {
    printf("Enter val to create node and insert in dll: ");
    scanf("%d", &val);
    ptr = create(val);

    if(FAILURE == insert(ptr)) {
      printf("Failed to insert");
    }
    printf("Want to enter more nodes (y/n): ");
    getchar();
    choice = getchar();
  }
  disp();
  return SUCCESS;
}

#include <head.h>

int main() {
  int n,k;
  printf("\nEnter n and k");
  scanf("%d%d", &n, &k);

  printf("\nThe choosen position will be: %d", josephus(n, k));
  return 0;
}

#include <stdio.h>
#include <time.h>

int main() {
  // 1
  int ARR_SIZE = 10;
  int arr1[ARR_SIZE];
  // 2
  arr1[0] = 0;
  printf("Value of arr1[0]: %d\n", arr1[0]);
  // 3, 4
  srand(time(NULL));
  for (int i = 1; i < 10; i++) {
    int x = rand();
    arr1[i] = x;
    printf("Value of arr1[%d]: %d\n", i, arr1[i]);
  }
  printf("\n");
  // 5
  int arr2[ARR_SIZE];
  // 6
  int *ptr1 = arr1;
  int *ptr2 = arr2;
  // 7
  for (int i = 0; i < 10; i++) {
    *(ptr2 + i) = *(ptr1 + 9 - i);
    printf("Value of arr2[%d]: %d\n", i, arr2[i]);
  }
  printf("\n");
  // clear array
  for (int i = 0; i < 10; i++) {
    *(ptr2 + i) = 0;
  }
  for (int i = 0; i < 10; i++) {
    ptr2[i] = ptr1[9 - i];
    printf("Value of arr2[%d]: %d\n", i, arr2[i]);
  }
  return 0;
}

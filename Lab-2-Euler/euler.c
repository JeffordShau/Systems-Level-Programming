#include <stdio.h>
#include "euler.h"

int problem1(int num) {
  int sum = 0;
  num -= 1;
  while (num > 0) {
    if (num % 5 == 0 || num % 3 == 0) {
      sum += num;
    }
    num -= 1;
  }
  printf("Euler01,%d\n", sum);
  return 0;
}

// int problem5(int num) {
//   int product = 1;
//   int counter = 1;
//   while (counter < num) {
//     if (product % counter != 0) {
//       product *= counter;
//     }
//     counter += 1;
//   }
//   printf("Euler05,%d\n", product);
//   return 0;
// }

int problem6(int num) {
  int sumSquare = 0;
  int squareSum = 0;
  while (num > 0) {
    sumSquare += num * num;
    squareSum += num;
    num -= 1;
  }
  squareSum *= squareSum;
  // printf("%d\n", squareSum);
  // printf("%d\n", sumSquare);
  printf("Euler06,%d\n", squareSum - sumSquare);
  return 0;
}

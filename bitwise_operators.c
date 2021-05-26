#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef unsigned char bitmap8;

void setBool(char* arr, int index, int boolValue) {

  // Step 1: Set the mask
  int maskIndex = index % 8;
  int arrIndex = index/8;
  if (maskIndex > 0) {
    arrIndex++;
  }

  bitmap8 mask = boolValue << maskIndex;

  // Step 2: Set value at index using mask
  arr[arrIndex] |= mask;

}


int getBool(char* arr, int index) {

  // Step 1: Set the mask
  int maskIndex = index % 8;
  int arrIndex = index/8;
  if (maskIndex > 0) {
    arrIndex++;
  }

  bitmap8 mask = 1 << maskIndex;

  if (arr[arrIndex] & mask) {
    return 1;
  } else {
    return 0;
  }
}


int main(void) {
  char arr[10];
  memset(arr, 0, 10);         // Initialize all bytes to 0
  setBool(arr, 78, 1);
  setBool(arr, 40, 0);
  int b78 = getBool(arr, 78); // b78 is 1
  printf("b78: %d\n", b78);
  int b40 = getBool(arr, 40); // b40 is 0
  printf("b40: %d\n", b40);
  return 0;
}

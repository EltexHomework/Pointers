#include <stdio.h>

#define SIZE 10

void init_array(int size, int* arr);

void print_array(int size, int* arr);

int main(void) {
  int arr[SIZE];

  init_array(SIZE, arr);

  printf("Array contains: ");
  print_array(SIZE, arr); 
  printf("\n");

  return 0;
}

void init_array(int size, int* arr) {
  for (int i = 0; i < size; i++) {
    *arr = i + 1;
    arr++;
  }   
}

void print_array(int size, int* arr) {
  for (int i = 0; i < size; i++) {
    printf("%d ", *arr);
    arr++;
  }
}

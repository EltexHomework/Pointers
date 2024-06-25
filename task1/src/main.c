#include <stdio.h>

int read_value();

unsigned char read_third_byte();

void replace_third_byte(int *value, unsigned char* byte);

int get_leftmost_bit(int value);

void print_binary(int value);

int main(void) {
  int value = read_value(); 
  unsigned char third_byte = read_third_byte();
  
  printf("Value in binary: ");
  print_binary(value);
  printf("\n");
  
  replace_third_byte(&value, &third_byte);

  printf("Value in binary after replacement: ");
  print_binary(value);
  printf("\n");
  return 0;
}

int read_value() {
  int value;
    
  do {
    printf("Enter value: ");
    if (scanf("%d", &value) == 0) {
      printf("Error occured");
      return -1;
    }
    if (value < 0) {
      printf("Wrong number");
    }
  } while (value < 0);

  return value;
}

unsigned char read_third_byte() {
 unsigned char value;
  
  do {
    printf("Enter third_byte: ");
    if (scanf("%hhu", &value) == 0) {
      printf("Error occured");
      return -1;
    }
    if (value < 0 || value > 255) {
      printf("Wrong number");
    }
  } while (value < 0);

  return value;
  
}

// Cast pointer to uchar (1 byte) and move it by 2 to point to third byte
void replace_third_byte(int *value, unsigned char* byte) {
  unsigned char* third_byte = ((unsigned char*) value + 2);
  *third_byte = *byte; 
}

int get_leftmost_bit(int value) {
  int bits_count = sizeof(value) * 8;
  return (value >> (bits_count - 1)) & 1;
}

void print_binary(int value) {
  int bits_count = sizeof(value) * 8;
  for (int i = 0; i < bits_count; i++) {
    printf("%d", get_leftmost_bit(value));
    value = value << 1;
  }
}

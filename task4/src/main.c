#include <stdio.h>
#include <string.h>

#define STR_SIZE 100

int read_str(char str[STR_SIZE]);

char* find_substring(char str[STR_SIZE], char sub_str[STR_SIZE]);

void print_result(char* string);

int main(void) {
  char str[STR_SIZE];
  char sub_str[STR_SIZE];

  if (!read_str(str)) {
    printf("Error occured!");
    return 0;
  }
  
  if (!read_str(sub_str)) {
    printf("Error occured!");
    return 0;
  }
  
  char* string = find_substring(str, sub_str);
  print_result(string);

  return 0;
}

int read_str(char str[STR_SIZE]) {
  printf("Enter string (max length - 100): ");
  
  if (scanf("%s", str) == 0) {
    return 0;
  }

  return 1;
}

char* find_substring(char str[STR_SIZE], char sub_str[STR_SIZE]) {
  int str_len = strlen(str);
  int sub_str_len = strlen(sub_str);
  char * str_ptr = str;
  int j;

  for (int i = 0; i < str_len; i++) {
    for (j = 0; j < sub_str_len; j++) {
      if (str[i + j] != sub_str[j])
        break;
    }

    if (j == sub_str_len) {
      return str_ptr; 
    }
    str_ptr++;
  }

  return NULL;
}

void print_result(char* string) {
  if (string != NULL)
    printf("String after substring was found: %s\n", string);
  else
    printf("Substring not found\n");
}

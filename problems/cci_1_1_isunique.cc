/*
  Determine if a string has all unique characters
*/
#include <iostream>

int char_to_int(char c) {
  return (int)c;
}

bool IsUnique(const char str[], int n) {
	if (n < 2) return true;
  
  bool lookup[128] = {};
  for (int i = 0; i < 128; i++)
    lookup[i] = false;
  
  for (int i = 0; i < n; i++) {
    int index = char_to_int(str[i]);
    if (lookup[index]) return false;
    lookup[index] = true;
  }
  return true;
}

int main() {
	char str[] = {'a', 'b', 'z', 'd', 'z'};
  int n = sizeof(str) / sizeof(char);
  
  std::cout << n << std::endl;
  std::cout << char_to_int('A') << std::endl;
  
  if (IsUnique(str, n)) std::cout << "Unique";
  else std::cout << "Dup found";
  std::cout << std::endl;
}
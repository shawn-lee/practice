#include <iostream>

int main() {
  int x = 2;
  int y = 4;
  int val = x ^ y;
  int count = 0;
  while (val != 0) {
    val = val & (val - 1);
    count++;
  }
  
  std::cout << count << std::endl;
}

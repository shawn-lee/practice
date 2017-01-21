#include <iostream>

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  int x = 10;
  int y = 20;
  
  std::cout << x << ", " << y << std::endl;
  swap(x, y);
  std::cout << x << ", " << y << std::endl;
  
}

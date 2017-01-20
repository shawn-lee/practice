#include <iostream>
#include <vector>


int main() {
  int n = 5;
  int array[n] = {};
  int* d_array = new int[n];
  std::vector<int> vec(n);
  
  for (int i = 0; i < n; i++) {
    array[i] = i;
    d_array[i] = i;
    vec[i] = i;
  }
  
  for (int i = 0; i < n; i++)
    std::cout << array[i];
  std::cout << std::endl;
  
  for (int i = 0; i < n; i++)
    std::cout << d_array[i];
  std::cout << std::endl;
  
  for (int i = 0; i < n; i++)
    std::cout << vec[i];
  std::cout << std::endl;
  
}

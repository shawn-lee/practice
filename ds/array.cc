#include <iostream>
#include <stdlib>


int main() {
  int n = 5;
  int fixed_array[n] = {};
  int* dynamic_array = new int[n];
  std::vector<int> vec = new std::vector<int>(n); 
  
  for (int i = 0; i < n; i++) {
    fixed_array[i] = i;
    dynamic_array[i] = i;
    vec.add(i);
  }
}

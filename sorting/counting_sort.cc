#include <iostream>

void PrintArray(const int* arr, int n) {
  std::cout << "{";
  for (int i = 0; i < n; i++)
    std::cout << arr[i] << ",";
  std::cout << "}" << std::endl;
}

void CountingSort(int* arr, int n, int k) {
  int counter[k] = {};
  for (int i = 0; i < k; i++)
    counter[i] = 0;
  for (int i = 0; i < n; i++)
    counter[arr[i]]++;
  for (int i = 1; i < k; i++)
    counter[i] += counter[i-1];
  
  int temp[n] = {};
  for (int i = 0; i < n; i++)
    temp[i] = arr[i];
  for (int i = n - 1; i >= 0; i--) {
    int index = --counter[temp[i]];
    arr[index] = temp[i];
  }
}

int main() {
  int n = 5;
  int* arr = new int[n];
  arr[0] = 3;
  arr[1] = 5;
  arr[2] = 1;
  arr[3] = 9;
  arr[4] = 2;
  
  int k = 10;
  PrintArray(arr, n);
  CountingSort(arr, n, k);
  PrintArray(arr, n);
}

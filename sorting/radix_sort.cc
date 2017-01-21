#include <iostream>

void PrintArray(const int* arr, int n) {
  std::cout << "{";
  for (int i = 0; i < n; i++)
    std::cout << arr[i] << ",";
  std::cout << "}" << std::endl;
}

void CountingSort(int* arr, int n, int k, int exp) {
  int counter[k] = {};
  for (int i = 0; i < k; i++)
    counter[i] = 0;
  for (int i = 0; i < n; i++)
    counter[ (arr[i]/exp)%k ]++;
  for (int i = 1; i < k; i++)
    counter[i] += counter[i-1];
  
  int temp[n] = {};
  for (int i = 0; i < n; i++)
    temp[i] = arr[i];
  for (int i = n - 1; i >= 0; i--) {
    int index = --counter[ (temp[i]/exp)%k ];
    arr[index] = temp[i];
  }
}

void RadixSort(int* arr, int n) {
  // find max value
  int max = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > max)
      max = arr[i];
  }
  
  const int base = 10;
  for (int e = 1; max/e > 0; e *= base)
    CountingSort(arr, n, base, e);
  
}

int main() {
  int n = 5;
  int* arr = new int[n];
  arr[0] = 310;
  arr[1] = 5074;
  arr[2] = 10;
  arr[3] = 90020;
  arr[4] = 258;
  
  PrintArray(arr, n);
  RadixSort(arr, n);
  PrintArray(arr, n);
}

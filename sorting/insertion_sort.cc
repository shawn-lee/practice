#include <iostream>

void PrintArray(const int* arr, int n) {
  std::cout << "{";
  for (int i = 0; i < n; i++)
    std::cout << arr[i] << ",";
  std::cout << "}" << std::endl;
}

void InsertionSort(int* arr, int n) {
  for (int i = 1; i < n; i++) {
    int temp = arr[i];
    int j = i - 1;
    while (j >=0 && arr[j] > temp) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
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
  
  PrintArray(arr, n);
  InsertionSort(arr, n);
  PrintArray(arr, n);
}

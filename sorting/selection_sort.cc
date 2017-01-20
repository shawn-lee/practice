#include <iostream>

void PrintArray(const int* arr, int n) {
  std::cout << "{";
  for (int i = 0; i < n; i++)
    std::cout << arr[i] << ",";
  std::cout << "}" << std::endl;
}

void SelectionSort(int* arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_index = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_index])
        min_index = j;
    }
    int temp = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = temp;
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
  SelectionSort(arr, n);
  PrintArray(arr, n);
}

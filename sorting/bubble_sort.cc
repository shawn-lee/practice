#include <iostream>

void PrintArray(const int* arr, int n) {
  std::cout << "{";
  for (int i = 0; i < n; i++)
    std::cout << arr[i] << ",";
  std::cout << "}" << std::endl;
}

void BubbleSort(int* arr, int n) {
  bool has_swapped = false;
  do {
    has_swapped = false;
    for (int i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        has_swapped = true;
      }
    }
  } while (has_swapped);
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
  BubbleSort(arr, n);
  PrintArray(arr, n);
}

#include <iostream>

void PrintArray(const int* arr, int n) {
  std::cout << "{";
  for (int i = 0; i < n; i++)
    std::cout << arr[i] << ",";
  std::cout << "}" << std::endl;
}

int Partition(int* arr, int start, int end) {
  int pivot = arr[end];
  int p_index = start;
  for(int i = start; i < end; i++) {
    if (arr[i] <= pivot) {
      int temp = arr[i];
      arr[i] = arr[p_index];
      arr[p_index] = temp;
      p_index++;
    }
  }
  arr[end] = arr[p_index];
  arr[p_index] = pivot;
  return p_index;
}

void QuickSort(int* arr, int start, int end) {
  if (start >= end) return;
  int p_index = Partition(arr, start, end);
  QuickSort(arr, start, p_index - 1);
  QuickSort(arr, p_index + 1, end);
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
  QuickSort(arr, 0, 4);
  PrintArray(arr, n);
}

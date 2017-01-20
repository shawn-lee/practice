#include <iostream>

void PrintArray(const int* arr, int n) {
  std::cout << "{";
  for (int i = 0; i < n; i++)
    std::cout << arr[i] << ",";
  std::cout << "}" << std::endl;
}

void Merge(int* arr, int* temp, int start, int middle, int end) {
  for (int i = start; i <= end; i++)
    temp[i] = arr[i];
  
  int i = start;
  int j = middle + 1;
  int k = start;
  
  while (i <= middle && j <= end) {
    if (temp[i] > temp[j])
      arr[k++] = temp[j++];
    else
      arr[k++] = temp[i++];
  }
  
  while (i <= middle)
    arr[k++] = temp[i++];
}

void MergeSortUtil(int* arr, int* temp, int start, int end) {
  if (start >= end) return;
  int middle = (end + start) / 2;
  MergeSortUtil(arr, temp, start, middle);
  MergeSortUtil(arr, temp, middle + 1, end);
  Merge(arr, temp, start, middle, end);
}

void MergeSort(int* arr, int n) {
  int* temp = new int[n];
  MergeSortUtil(arr, temp, 0, n - 1);
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
  MergeSort(arr, n);
  PrintArray(arr, n);
}

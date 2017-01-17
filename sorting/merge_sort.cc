#include <iostream>

void PrintArray(int input[], int n) {
  std::cout << "{";
  for (int i = 0; i < n; i++)
    std::cout << input[i] << ",";
  std::cout << "}" << std::endl;
}

void Merge(int input[], int temp[], int start, int middle, int end) {
  for (int i = start; i <= end; i++)
    temp[i] = input[i];
  
  int i = start;
  int j = middle + 1;
  int k = start;
  
  while (i <= middle && j <= end) {
    if (temp[i] > temp[j])
      input[k++] = temp[j++];
    else
      input[k++] = temp[i++];
  }
  
  while (i <= middle)
    input[k++] = temp[i++];
}

void MergeSortUtil(int input[], int temp[], int start, int end) {
  if (start >= end) return;
  int middle = (end + start) / 2;
  MergeSortUtil(input, temp, start, middle);
  MergeSortUtil(input, temp, middle + 1, end);
  Merge(input, temp, start, middle, end);
}

void MergeSort(int input[], int n) {
  int temp[n] = {};
  MergeSortUtil(input, temp, 0, n - 1);
}


int main() {
  int input[] = {3, 5, 1, 9, 2};
  
  PrintArray(input, 5);
  MergeSort(input, 5);
  PrintArray(input, 5);
}

#include <iostream>

void PrintArray(int input[], int n) {
  std::cout << "{";
  for (int i = 0; i < n; i++)
    std::cout << input[i] << ",";
  std::cout << "}" << std::endl;
}

int Partition(int input[], int start, int end) {
  int pivot = input[end];
  int p_index = start;
  for(int i = start; i < end; i++) {
    if (input[i] <= pivot) {
      int temp = input[i];
      input[i] = input[p_index];
      input[p_index] = temp;
      p_index++;
    }
  }
  input[end] = input[p_index];
  input[p_index] = pivot;
  return p_index;
}

void QuickSort(int input[], int start, int end) {
  if (start >= end) return;
  int p_index = Partition(input, start, end);
  QuickSort(input, start, p_index - 1);
  QuickSort(input, p_index + 1, end);
}

int main() {
  int input[] = {3, 5, 1, 9, 2};
  
  PrintArray(input, 5);
  QuickSort(input, 0, 4);
  PrintArray(input, 5);
}

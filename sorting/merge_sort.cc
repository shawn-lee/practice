#include <iostream>

void PrintArray(int input[], int n) {
  std::cout << "{";
  for (int i = 0; i < n; i++)
    std::cout << input[i] << ",";
  std::cout << "}" << std::endl;
}

void Merge(int input[], int start, int middle, int end) {
  int temp[end - start + 1] = {};
  int index_temp = 0;
  for (int i = start; i <= end; i++)
    temp[index_temp++] = input[i];
  
  int i = start;
  int j = middle + 1;
  int k = start;
  int offset = start;
  
  while (i <= middle && j <= end) {
    if (temp[i - offset] > temp[j - offset]) {
      input[k] = temp[j - offset];
      j++;
    }
    else {
      input[k] = temp[i - offset];
      i++;
    }
    k++;
  }
  
  while (i <= middle) {
    input[k] = temp[i - offset];
    i++; k++;
  }
  while (j <= end) {
    input[k] = temp[j - offset];
    j++; k++;
  } 
}

void MergeSort(int input[], int start, int end) {
  if (start >= end) return;
  int middle = (end + start) / 2;
  MergeSort(input, start, middle);
  MergeSort(input, middle + 1, end);
  Merge(input, start, middle, end);
}


int main() {
  int input[] = {3, 5, 1, 9, 2};
  
  PrintArray(input, 5);
  MergeSort(input, 0, 4);
  PrintArray(input, 5);
}

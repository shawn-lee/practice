#include <iostream>

void PrintArray(int input[], int n) {
  std::cout << "{";
  for (int i = 0; i < n; i++)
    std::cout << input[i] << ",";
  std::cout << "}" << std::endl;
}

void InsertionSort(int input[], int n) {
  for (int i = 1; i < n; i++) {
    int temp = input[i];
    int j = i - 1;
    while (j >=0 && input[j] > temp) {
      input[j + 1] = input[j];
      j--;
    }
    input[j + 1] = temp;
  }
}

int main() {
  int input[] = {3, 5, 1, 9, 2};
  
  PrintArray(input, 5);
  InsertionSort(input, 5);
  PrintArray(input, 5);
}

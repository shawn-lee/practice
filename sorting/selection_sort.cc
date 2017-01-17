#include <iostream>

void PrintArray(int input[], int n) {
  std::cout << "{";
  for (int i = 0; i < n; i++)
    std::cout << input[i] << ",";
  std::cout << "}" << std::endl;
}

void SelectionSort(int input[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_index = i;
    for (int j = i + 1; j < n; j++) {
      if (input[j] < input[min_index])
        min_index = j;
    }
    int temp = input[i];
    input[i] = input[min_index];
    input[min_index] = temp;
  }
}

int main() {
  int input[] = {3, 5, 1, 9, 2};
  
  PrintArray(input, 5);
  SelectionSort(input, 5);
  PrintArray(input, 5);
}

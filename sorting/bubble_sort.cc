#include <iostream>

void PrintArray(int input[], int n) {
  std::cout << "{";
  for (int i = 0; i < n; i++)
    std::cout << input[i] << ",";
  std::cout << "}" << std::endl;
}

void BubbleSort(int input[], int n) {
  bool has_swapped = false;
  do {
    has_swapped = false;
    for (int i = 0; i < n - 1; i++) {
      if (input[i] > input[i + 1]) {
        int temp = input[i];
        input[i] = input[i + 1];
        input[i + 1] = temp;
        has_swapped = true;
      }
    }
  } while (has_swapped);
}

int main() {
  int input[] = {3, 5, 1, 9, 2};
  
  PrintArray(input, 5);
  BubbleSort(input, 5);
  PrintArray(input, 5);
}

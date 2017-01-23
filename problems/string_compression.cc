#include <iostream>
#include <string>

std::string Compress(std::string input) {
  int n =  input.length();
  if (n < 3) return input;
  
  std::string output;
  int i = 0;
  int count = 0;
  
  char current = input[i++];
  output += current;
  count = 1;
  
  for (int i = 1; i < n; i++) {
    if (output.length() >= n) return input;
    
    if (input[i] != current) {
      output += std::to_string(count);
      current = input[i];
      output += current;
      count = 1;
    }
    else {
      count++;
    }
  }
  output += std::to_string(count);
  return output;
}

int main() {
  std::string input = "aabccccaaa";
  std::string output = Compress(input);
  std::cout << input << std::endl << output << std::endl;
}

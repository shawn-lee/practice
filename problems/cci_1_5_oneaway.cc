/*
  Determine if two strings are only 1 edit away (insert, delete, replace)
*/

#include <iostream>
#include <cmath>

bool IsOneAway(const char s1[], int n1, const char s2[], int n2) {
  if (abs(n1 - n2) > 1) return false;
  
  bool diff_flag = false;
  int idx1 = 0, idx2 = 0;
  
  while (idx1 < n1 && idx2 < n2) {
    if (s1[idx1] != s2[idx2]) {
      if (diff_flag) {
        return false;
      }
      else {
        diff_flag = true;
        if (n1 == n2) {
          idx1++; idx2++;
        }
        else {
          n1 > n2 ? idx1++ : idx2++;
        }
      }
    }
    idx1++; idx2++;
  }
  return true;
}

int main() {
  char s1[] = {'p', 'a', 'l', 'e'};
  char s2[] = {'b', 'a', 'k', 'e'};
  int n1 = sizeof(s1) / sizeof(char);
  int n2 = sizeof(s2) / sizeof(char);
  
  if (IsOneAway(s1, n1, s2, n2))
    std::cout << "yes";
  else
    std::cout << "no";
  std::cout << std::endl;
}
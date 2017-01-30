#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

bool IsCombination(string str, unordered_set<string> words) {
  // {a, am, i, mam, man}
  // "iamaman"
  // "iamahuman"
  // "iiiii"
  
  for (int len = 1; len <= str.size(); len++) {
    string substr = str.substr(0, len);
    // This part of string is one of the words
    if (words.find(substr) != words.end()) {
      if (len == str.size()) return true;
      if(IsCombination(str.substr(len, str.size() - len), words))
        return true;
    }
  }
  return false;
}

int main() {
  string s = "iamahuman";
  unordered_set<string> words;
  words.insert("a");
  words.insert("am");
  words.insert("i");
  words.insert("mam");
  words.insert("man");
  
  
  if (IsCombination(s, words))
    cout << "Yes\n";
  else
    cout << "No\n";
}


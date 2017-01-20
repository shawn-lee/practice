#include <iostream>
#include <unordered_set>
#include <unordered_map>


int main() {
  
  std::unordered_set<int> hashset;
  hashset.insert(5);
  hashset.insert(1);
  hashset.insert(9);
  
  if (hashset.find(9) != hashset.end())
    std::cout << "Key found" << std::endl;
  else
    std::cout << "Key not found" << std::endl;
  
  std::unordered_map<int, int> hashmap;
  hashmap[5] = 50;
  hashmap[1] = 50;
  hashmap[9] = 90;
  
}

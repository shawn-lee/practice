#include <iostream>
#include <set>
#include <map>


int main() {
  
  std::set<int> bst_set;
  bst_set.insert(5);
  bst_set.insert(1);
  bst_set.insert(9);
  
  if (bst_set.find(9) != bst_set.end())
    std::cout << "Key found" << std::endl;
  else
    std::cout << "Key not found" << std::endl;
  
  std::map<int, int> bst_map;
  bst_map[5] = 50;
  bst_map[1] = 50;
  bst_map[9] = 90;
  
}

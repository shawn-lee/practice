#ifndef HASHMAP_H
#define HASHMAP_H

#include <string>
#include <vector>
#include <list>

struct pair {
  std::string key;
  std::string value;
  pair(std::string key, std::string value) : key(key), value(value) {}
};

class HashMap {
  
  
  public:
  HashMap(int capacity);
  void Insert(std::string key, std::string vaue);
  void Delete(std::string key);
  bool Contains(std::string key);
  std::string Find(std::string key);
  
  private:
  int capacity;
  int size;
  std::vector<std::list<pair>> table;
  std::list<pair>::iterator GetIter(std::list<pair>* lst, std::string key);
};
#endif
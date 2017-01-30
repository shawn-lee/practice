#include <iostream>
#include "hashmap.h"

int GetHash(std::string str, int limit) {
  std::hash<std::string> hasher;
  return hasher(str) % limit;
}

HashMap::HashMap(int capacity) {
  this->capacity = capacity;
  table.reserve(capacity);
  size = 0;
  for (int i = 0; i < capacity; i++) {
    std::list<pair> new_list;
    table.push_back(new_list);
  }
}

void HashMap::Insert(std::string key, std::string value) {
  int hashed = GetHash(key, capacity);
  std::list<pair>* bucket = &table[hashed];
  for (std::list<pair>::iterator it = bucket->begin(); it != bucket->end(); it++) {
    if (it->key == key) {
      std::cout << "Key already exists! Update instead of insert.\n";
      return;
    }
  }
  pair kv = pair(key, value);
  bucket->push_back(kv);
  size++;
}

void HashMap::Delete(std::string key) {
  int hashed = GetHash(key, capacity);
  std::list<pair>* bucket = &table[hashed];
  for (std::list<pair>::iterator it = bucket->begin(); it != bucket->end(); it++) {
    if (it->key == key) {
      bucket->erase(it);
      return;
    }
  }
  std::cout << "Key doesn't exist.\n";
}

bool HashMap::Contains(std::string key) {
  int hashed = GetHash(key, capacity);
  std::list<pair>* bucket = &table[hashed];
  for (std::list<pair>::iterator it = bucket->begin(); it != bucket->end(); it++) {
    if (it->key == key) return true;
  }
  return false;
}

std::string HashMap::Find(std::string key) {
  int hashed = GetHash(key, capacity);
  std::list<pair>* bucket = &table[hashed];
  for (std::list<pair>::iterator it = bucket->begin(); it != bucket->end(); it++) {
    if (it->key == key) return it->value;
  }
  return "";
}

std::list<pair>::iterator HashMap::GetIter(std::list<pair>* lst, std::string key) {
  for (std::list<pair>::iterator it = lst->begin(); it != lst->end(); it++) {
    if (it->key == key) return it;
  }
  return lst->end();
}

int main() {
  HashMap hmap = HashMap(100);
  hmap.Insert("hello", "world");
  hmap.Insert("cat", "mouse");
  
  hmap.Insert("hello", "whatup");
  hmap.Delete("cat");
  hmap.Contains("cat") ? std::cout << "O\n" : std::cout << "X\n";
  hmap.Delete("cat");
}
#include <vector>
#include <list>
#include <queue>
#include <cstddef>
#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

vector<list<Node*>*> CreateLevelList2(Node* root) {
  vector<list<Node*>*> level_list;
  list<Node*>* current = new list<Node*>;
  list<Node*>* prev;
  
  current->push_back(root);
  while (current->size() > 0) {
    level_list.push_back(current);
    prev = current;
    current = new list<Node*>;
    for (auto node : *prev) {
      if (node->left != nullptr)
        current->push_back(node->left);
      if (node->right != nullptr)
        current->push_back(node->right);
    }
  }
  return level_list;
}

vector<list<Node*>*> CreateLevelList(Node* root) {
  vector<list<Node*>*> level_list;
  queue<Node*> q;
  
  q.push(root);
  q.push(nullptr);
  list<Node*>* new_level = new list<Node*>;
  //new_level->push_back(root);
  //level_list.push_back(new_level);
  
  while (!q.empty()) {
    Node* temp = q.front();
    q.pop();
    
    if (temp == nullptr) {
      if (q.empty()) {
        level_list.push_back(new_level);
        break;
      }
      else {
        q.push(nullptr);
        level_list.push_back(new_level);
        new_level = new list<Node*>;
        continue;
      }
    }
    new_level->push_back(temp);
    if (temp->left != nullptr) q.push(temp->left);
    if (temp->right != nullptr) q.push(temp->right);
  }
  return level_list;
}

int main() {
  Node* root = new Node(5);
  root->left = new Node(3);
  root->right = new Node(10);
  root->left->left = new Node(2);
  root->right->right = new Node(15);
  
  vector<list<Node*>*> levels = CreateLevelList(root);
  cout << "# of Levels = " << levels.size() << endl;
  
}
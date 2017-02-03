#include <limits.h>
#include <cstddef>
#include <cmath>
#include <iostream>

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

int GetHeight(Node* root) {
  if (root == nullptr) return -1;
  int h_left = GetHeight(root->left);
  int h_right = GetHeight(root->right);
  if (h_left == INT_MIN || h_right == INT_MIN)
    return INT_MIN;
  
  if (abs(h_left - h_right) > 1)
    return INT_MIN;
  else
    return h_left > h_right ? h_left + 1 : h_right + 1;
}

bool IsBalanced (Node* root) {
  return GetHeight(root) != INT_MIN;
}

int main() {
  Node* root = new Node(5);
  root->left = new Node(3);
  root->right = new Node(10);
  root->left->left = new Node(2);
  root->right->left = new Node(8);
  root->right->right = new Node(15);
  root->right->right->right = new Node(25);
  
  if (IsBalanced(root))
    std::cout << "Balanced\n";
  else
    std::cout << "Unbalanced\n";
  
}
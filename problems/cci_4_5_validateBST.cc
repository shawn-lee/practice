#include <iostream>
#include <cstddef>
#include <limits.h>

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

int CheckOrder(Node* root) {
  if (root == nullptr) return -1;
  
  int left = CheckOrder(root->left);
  if (left == INT_MIN || (left > root->data && left != -1))
    return INT_MIN;
  
  int right = CheckOrder(root->right);
  if (right == INT_MIN || (right < root->data && right != -1))
    return INT_MIN;
  
  return root->data;
}

bool IsBST(Node* root) {
  return CheckOrder(root) != INT_MIN;
}

int main() {
  Node* root = new Node(5);
  root->left = new Node(3);
  root->right = new Node(10);
  root->left->left = new Node(2);
  root->right->left = new Node(20);
  root->right->right = new Node(15);
  root->right->right->right = new Node(25);
  
  if (IsBST(root))
    std::cout << "BST\n";
  else
    std::cout << "Not BST\n";
  
}

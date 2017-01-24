#ifndef HEAP_H
#define HEAP_H
class Heap {
public:
  Heap(int n);
  Heap(int arr[], int n);
  ~Heap();
  void Insert(int key);
  void Delete(int key);
  int GetMin();
  int ExtractMin();
  void Print();
  
private:
  int* heap_array;          // array to hold elements
  int size;                 // current size of heap
  const int capacity;       // max capacity
  
  void Heapify(int index);  // Heapify at given index to preserve heap property
  int Parent(int i);        // Utility function to get index of parent node
  int Left(int i);          // Utility function to get index of left child
  int Right(int i);         // Utility function to get index of right child
  
};
#endif
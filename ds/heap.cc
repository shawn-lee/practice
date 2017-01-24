#include <iostream>
#include <limits.h>

#include "heap.h"

void Swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

Heap::Heap(int n) : capacity(n * 2), size(0) {
  heap_array = new int[capacity];
}

Heap::Heap(int arr[], int n) : capacity(n * 2), size(n) {
  heap_array = new int[capacity];
  for (int i = 0; i < n; i++)
    heap_array[i] = arr[i];
  
  for (int i = (n - 1) /2; i >=0; i--)
    Heapify(i);
}

Heap::~Heap() {
  delete heap_array;
  heap_array = NULL;
}

void Heap::Insert(int key) {
  if (size == capacity) {
    std::cout << "Cannot insert any more\n";
    return;
  }
  
  // Insert at the end first
  heap_array[size++] = key;
  
  // Compare with parent and swap if needed
  int i = size - 1;
  while (i > 0 && heap_array[Parent(i)] > heap_array[i]) {
    Swap(heap_array[Parent(i)], heap_array[i]);
    i = Parent(i);
  }
}

void Heap::Delete(int key) {
  
}

int Heap::GetMin() { return heap_array[0]; }

int Heap::ExtractMin() {
  if (size <= 0) return INT_MAX;
  
  // Replace root with last element
  int min = heap_array[0];
  heap_array[0] = heap_array[--size];
  
  // "Bubble down" to restore/maintain heap property
  Heapify(0);
  return min;
}

void Heap::Print() {
  for (int i = 0; i < size; i++)
    std::cout << heap_array[i] << " ";
  std::cout << std::endl;
}

void Heap::Heapify(int index) {
  int left = Left(index);
  int right = Right(index);
  int smallest = index;
  // Compare with children and find smaller one
  // Repeat down the heap as necessary
  if (heap_array[smallest] > heap_array[left] && left < size) {
    smallest = left;
  }
  if (heap_array[smallest] > heap_array[right] && right < size) {
    smallest = right;
  }
  if (smallest != index) {
    Swap(heap_array[index], heap_array[smallest]);
    Heapify(smallest);
  }
}

int Heap::Parent(int i) { return (i - 1) / 2; }
int Heap::Left(int i) { return (i * 2) + 1; }
int Heap::Right(int i) { return (i * 2) + 2; }

int main() {
  Heap h(8);
  h.Insert(4);
  h.Insert(50);
  h.Insert(23);
  h.Insert(88);
  h.Insert(90);
  h.Insert(32);
  h.Insert(74);
  h.Insert(96);
  
  h.Print();
  std::cout << "Old Min = " << h.ExtractMin() << std::endl;
  
  h.Print();
  std::cout << "New Min = " << h.GetMin() << std::endl;
  
  int arr[] = {50, 23, 88, 90, 32, 74, 96, 4};
  Heap h2(arr, 8);
  h2.Print();
}

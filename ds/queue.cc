#include <iostream>
#include <queue>
#include <deque>
#include <priority_queue>


int main() {
  
  std::queue<int> my_queue;
  my_queue.push(5);
  
  std::deque<int> my_deque;
  my_deque.push_front(10);
  
  std::priority_queue<int> my_pqueue;
  my_pqueue.push(100);
}

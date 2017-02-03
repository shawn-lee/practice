int Retrieve(Node* head, int k) {
  if (head == null) {
    return INT_MAX;
  }
  
  Node* p1 = head;
  Node* p2 = head;
  for (int i=0; i<k; i++) {
    if (p2->next->next == null)
      return INT_MAX;
    p2 = p2->next;
  }
  
  while (p2->next != null) {
    p1 = p1->next;
    p2 = p2->next;
  }
  return p1->data;
}
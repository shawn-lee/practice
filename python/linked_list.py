def main():
    ll = LinkedList()
    ll.insert(5)
    ll.insert(10)
    ll.insert(15)
    ll.printout()
    
    ll.remove()
    ll.printout()
    
    if ll.contains(10): print("10 is in the list")
    else: print("10 is not in the list")
    

class Node:
    def __init__ (self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__ (self):
        self.head = None
        
    def insert(self, data):
        temp = Node(data)
        temp.next = self.head
        self.head = temp
    
    def remove(self, data = None):
        if data == None:
            self.head = self.head.next
            return
        curr = self.head
        prev = None
        while curr != None:
            if curr.data == data:
                prev.next = curr.next
                return
            prev = curr
            curr = curr.next
        print("Key to be removed not found.")
        
    def contains(self, data):
        curr = self.head
        while curr != None:
            if curr.data == data:
                return True
            curr = curr.next
        return False
    
    def element_at(self, index):
        pass
        
    def printout(self):
        curr = self.head
        while curr != None:
            print(curr.data)
            curr = curr.next
            
if __name__ == "__main__": main()
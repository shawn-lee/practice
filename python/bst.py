def main():
    tree = BST()
    tree.insert(20)
    tree.insert(15)
    tree.insert(25)
    tree.insert(10)
    tree.insert(5)
    tree.insert(0)
    tree.insert(55)
    tree.insert(35)
    tree.insert(100)
    tree.printout()
    
    print("8 exists" if tree.contains(8) else "8 doesn't exist")
    print("55 exists" if tree.contains(55) else "55 doesn't exist")

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None
        
    def insert(self, key):
        if self.root == None:
            temp = Node(key)
            self.root = temp
            return
        self.insert_util(self.root, key)
        
    def insert_util(self, root, key):
        if root == None:
            return Node(key)
        
        if key < root.data:
            root.left = self.insert_util(root.left, key)
        elif key > root.data:
            root.right = self.insert_util(root.right, key)
        else:
            print("Duplicate keys are not allowed")
        return root
        
    def delete(self, root, key):
        pass
        
    def contains(self, key):
        if self.root == None:
            return False
        curr = self.root
        while curr != None:
            if curr.data == key:
                return True
            elif curr.data > key:
                curr = curr.left
            elif curr.data < key:
                curr = curr.right
        return False
        
    def printout(self):
        self.print_dfs(self.root)
    
    def print_dfs(self, root):
        if root == None:
            return
        # in-order traversal
        self.print_dfs(root.left)
        print(root.data)
        self.print_dfs(root.right)
        
    def print_bfs(self, root):
        q = []
        

if __name__ == "__main__": main()
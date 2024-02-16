# import headers
import pdb; 
pdb.set_trace()

""" 
    This is Node class that has Data, Left_child and right_child_child as its
    members.
"""
class Node(object):
    def __init__(self, data):
        self.data = data
        self.left_child = None
        self.right_child = None

"""
    Class:      BinaryTree
    Desc:       This class has various functions for the implementaion
                of BinaryTree.
    Input:      root can be None as default.  
"""
class BinaryTree(object):
    def __init__(self, root=None):
        self.root = root
    """
    Funct:      inorder
    Desc:       This function print the BinaryTree in Inorder
    Input:      root or any Node
    Output:     Prints Inorder tree
    """
    def inorder(self, root):
        if root:
            self.inorder(root.left_child)
            print(root.data, end = " ")
            self.inorder(root.right_child)
    """
    Func:   insert
    Desc:   Insert the data node into the Binary Tree
    Input:  data
    Output: None
    """
    def insert(self, data):
        new_node = Node(data)
        current = self.root
        if(self.root is None):
            self.root = new_node
        else:
            while(current is not None):
                parent = current
                if(new_node.data < current.data):
                    current = current.left_child
                else:
                    current = current.right_child
            if(new_node.data < parent.data):
                parent.left_child = new_node
            else:
                parent.right_child = new_node
   

    # Given a non-empty binary search tree, return the node 
    # with minum key value found in that tree. Note that the 
    # entire tree does not need to be searched  
    def minValueNode(self, node): 
        current = node 
        # loop down to find the leftmost leaf 
        while(current.left_child is not None): 
            current = current.left_child
        return current
    """
    Func:   delete
    Desc:   delete the data from the BinaryTree.
    Input:  data
    Output: None
    """
    def deleteNode(self, root, key): 
        if self.root is None: 
            return root  
  
        # If the key to be deleted is smaller than the root's 
        # key then it lies in  left subtree 
        if(key < root.data):
            root.left_child = self.deleteNode(root.left_child, key)
        # If the kye to be delete is greater than the root's key 
        # then it lies in right subtree 
        elif(key > root.data): 
            root.right_child = self.deleteNode(root.right_child, key) 
        # If key is same as root's key, then this is the node 
        # to be deleted 
        else: 
            # Node with only one child or no child 
            if root.left_child is None : 
                temp = root.right_child  
                root = None 
                return temp  
            elif root.right_child is None : 
                temp = root.left_child  
                root = None
                return temp 
  
            # Node with two children: Get the inorder successor 
            # (smallest in the right subtree) 
            temp = self.minValueNode(root.right_child) 
            # Copy the inorder successor's content to this node 
            root.data = temp.data
            # Delete the inorder successor 
            root.right_child = self.deleteNode(root.right_child , temp.data) 
        return root
"""
Funct:  main
Desc:   This is the driver function.
Input:  None
Output: None
""" 
if __name__ == "__main__":
    btree = BinaryTree()
    btree.insert(52)
    btree.insert(22)
    btree.insert(92)
    btree.insert(74)
    btree.insert(65)
    btree.insert(95)
    btree.insert(78)
    btree.insert(12)
    btree.insert(38)
    btree.insert(45)
    btree.inorder(btree.root)
    print()
    btree.deleteNode(btree.root, 52)
    btree.inorder(btree.root)
    print()

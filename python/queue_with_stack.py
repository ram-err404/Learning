class Node:
    def __init__(self, val):
        self.data = val
        self.next = None

class Stack:
    def __init__(self, Node = None):
        if Node is None:
            self.top = None
        else:
            self.top = Node

    def st_print(self):
        cur = self.top
        while cur:
            print(cur.data, end ='->')
            cur = cur.next

    def push(self, new_node):
        new_node.next = self.top
        self.top = new_node

    def pop(self):
        if self.top is None:
            print("Stack Underflow!!")
        #elif self.top.next is None:
        #    pop_node = self.top
        #    self.top = None
        else:
            pop_node = self.top
            self.top = self.top.next
        print("value pop:", pop_node.data)
        del pop_node

def enque(Stack_obj, new_node):
    Stack_obj.push(new_node)

# Need to correct this logic:
def deque(Stack_obj):
    if Stack_obj.top is None:
        print("Deque Underflow!!")
    elif Stack_obj.top.next is None:
        Stack_obj.pop()
        print(Stack_obj.top.data)
    else: 
        deque(Stack(Stack_obj.top.next))

#Code execution starts here
if __name__ == '__main__':
    st_obj = Stack()
    st_obj.push(Node(10))
    st_obj.push(Node(20))
    st_obj.push(Node(30))
    st_obj.push(Node(40))
    st_obj.push(Node(50))
    st_obj.push(Node(60))
    st_obj.push(Node(70))
    st_obj.push(Node(80))
    st_obj.push(Node(90))
    
    st_obj.st_print()
    # Implementing queue from here:
    print("\n-----------------------")
    enque(st_obj, Node(100))
    enque(st_obj, Node(120))
    st_obj.st_print()
    print("\n-----------------------")
    deque(st_obj)
    print("adacdc")
    deque(st_obj)
    print("adacdc")
#    print("Deque: ", deque(st_obj))
#    print("Deque: ", deque(st_obj))
    enque(st_obj, Node(130))
    print("-----------------------")
    st_obj.st_print()

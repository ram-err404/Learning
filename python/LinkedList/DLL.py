class Node(object):
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DLL(object):
    def __init__(self, Head=None):
        self.Head = None

    def print_dll(self):
        current = self.Head
        while(current is not None):
            print(current.data, "-->", end = " ")
            current = current.next
        print()
    
    def insert(self, data):
        new_node = Node(data)
        current = self.Head
        if (self.Head == None):
            self.Head = new_node
        else:
            while(current.next is not None):
                current = current.next
            current.next = new_node
            new_node.prev = current

    def delete(self, data):
        current = self.Head
        found = None
        while(current is not None):
            if(current.data == data):
                found = current
                current.prev.next = current.next
                if(current.next is not None):
                    current.next.prev = current.prev
                break
            current = current.next
        if(found is None):
            print("Data not found to be deleted")
        else:
            print("Deleting data node")
            del found

if __name__ == "__main__":
    dll = DLL()
#    dll.Head = Node(5)
    dll.insert(12)
    dll.insert(15)
    dll.insert(18)
    dll.insert(11)
    dll.insert(16)
    dll.print_dll()
    dll.delete(15)
    dll.print_dll()
    dll.insert(95)
    dll.print_dll()
    dll.delete(36)
    dll.delete(11)
    dll.insert(65)
    dll.print_dll()
    dll.delete(65)
    dll.print_dll()


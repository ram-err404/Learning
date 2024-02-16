class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None

    def get_data(self):
        return self.data

    def get_next(self):
        return self.next

    def set_next(self, new_node):
        self.next = new_node

class LinkedList(object):
    def __init__(self, Head=None):
        self.Head = Head

    def size(self):
        current = self.Head
        count = 0
        while current:
            count += 1
            current = current.get_next()
        return count

    def print_ll(self):
        current = self.Head
        while current is not None:
            print(current.get_data(), "-->", end = "")
            current = current.get_next()

    # insertion at begening
    def insert(self, data):
        new_node = Node(data)
        new_node.set_next(self.Head)
        self.Head = new_node

    def search(self, data):
        current = self.Head
        found = False
        while current and found is False:
            if current.get_data() == data:
                found = True
            else:
                current = current.get_next()
        if current is None:
            raise ValueError("Data not in list")
        return current

    def delete(self, data):
        current = self.Head
        prev = None
        if (current.get_data() == data and current.get_next() is None):
            # This is the first Node.
            found = current
            self.Head = None
        else:
            while current is not None:
                prev = current
                if (current.get_data() == data):
                    found = current
                    prev.set_next(current.get_next())
                    break
                current = current.get_next()
        if(found is not None):
            print("Data founded to be deleted. ", found.get_data())
            del found
        else:
            print("Data not found!!")


def MidValOfLL(head):
    slow_ptr = fast_ptr = head

    while fast_ptr is not None:
        slow_ptr = slow_ptr.next
        if fast_ptr.next is not None:
            fast_ptr = fast_ptr.next.next
        else:
            fast_ptr = None

    print("Mid value of Linked List: ", slow_ptr.data)

# Code Execution starts here.
if __name__ == "__main__":
    llist = LinkedList()

    llist.Head = Node(1)
    second = Node(2)
    third = Node(3)

    llist.Head.set_next(second)
    # Link first node with second
    second.set_next(third)
    # Link second node with the third node

    print(llist.size())
    llist.print_ll()
    llist.insert(27)
    llist.insert(26)
    llist.insert(25)
    llist.insert(24)
    print()
    llist.print_ll()
    print()
    print(llist.Head.data)
    print(llist.size())

    MidValOfLL(llist.Head)


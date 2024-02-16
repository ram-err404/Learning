# import packages.


class Node(object):
    def __init__(self, val=None, next_node=None):
        self.data = val
        self.next_node = next_node

    def get_data(self):
        return self.data

    def get_next(self):
        return self.next_node

    def set_next(self, new_node):
        self.next_node = new_node


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


# Code execution starts here
if __name__ == '__main__':

    # Start with the empty list
    llist = LinkedList()

    llist.Head = Node(1)
    second = Node(2)
    third = Node(3)

    '''
    Three nodes have been created.
    We have references to these three blocks as first,
    second and third

    llist.Head        second              third
         |                |                  |
         |                |                  |
    +----+------+     +----+------+     +----+------+
    | 1  | None |     | 2  | None |     |  3 | None |
    +----+------+     +----+------+     +----+------+
    '''

    llist.Head.set_next(second)
    # Link first node with second

    '''
    Now next of first Node refers to second.  So they
    both are linked.

    llist.Head        second              third
         |                |                  |
         |                |                  |
    +----+------+     +----+------+     +----+------+
    | 1  |  o-------->| 2  | null |     |  3 | null |
    +----+------+     +----+------+     +----+------+
    '''

    second.set_next(third)
    # Link second node with the third node

    '''
    Now next of second Node refers to third.  So all three
    nodes are linked.

    llist.Head        second              third
         |                |                  |
         |                |                  |
    +----+------+     +----+------+     +----+------+
    | 1  |  o-------->| 2  |  o-------->|  3 | null |
    +----+------+     +----+------+     +----+------+
    '''
    print(llist.size())
    llist.print_ll()
    llist.insert(25)
    llist.insert(27)
    llist.insert(25)
    print()
    llist.print_ll()
    print()

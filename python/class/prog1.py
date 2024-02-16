'''
class and objects.
'''
class item():
    def __init__(self, name, price):
        self.name = name
        self.price = price

class storage:
    def __init__(self):
        self.itemList = []

    def add_item(self, item):
        self.itemList.append(item)

    def get_item(self, item_name):
        for x in self.itemList:
            if x.name == item_name:
                return x

    def remove_item(self, item_name):
        for x in self.itemList:
            if x.name == item_name:
                self.itemList.remove(x)
                break

if __name__ == "__main__":
    storage_object = storage()
    '''
    store items in storage object.
    '''
    for i in range(10):
        storage_object.add_item(item("item"+str(i), 500+i))
    for x in storage_object.itemList:
        print(x.name, " ", x.price)

    temp_item = storage_object.get_item("item3")
    print("\n", temp_item.name, " ", temp_item.price)
    storage_object.remove_item("item6")
    for x in storage_object.itemList:
        print(x.name, " ", x.price)

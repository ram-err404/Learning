class Parent(object):
    def __init__(self, name):
        self.parent_name = name
        print("Parent constructor")


class Child(Parent):
    def __init__(self, name, p_obj):
        self.child_name = name
        self.parent_name = p_obj.parent_name
        super().__init__("M. K. Misra")
        print("Child constructor")


if __name__ == "__main__":
    p_ob = Parent("Manoj")
    c_ob = Child("Ramji", p_ob)

    '''
    Python do not solve ambiguity. It it taken care by programmer himself.
    To resolve ambiguity, better give another names.
    '''
    print("\n Name: ", c_ob.child_name, " Parent name: ", c_ob.parent_name)

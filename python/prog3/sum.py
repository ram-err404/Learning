def my_sum(a, b):
    c = a + b
    return (c)


def my_substract(a, b):
    c = a - b
    return (c)


def my_multiply(a, b):
    c = a * b
    return (c)


def my_divide(a, b):
    c = a / b
    return (c)


def menu():
    print("***** Menu ********")
    print("1. Sum")
    print("2. Substract")
    print("3. Multiply")
    print("4. Divide")


# a = int(input("Enter 1st number"))
# b = int(input("Enter 2nd number"))
a, b = [int(x) for x in input("Enter 2 number").split()]
menu()
ch = input("Enter your choice")
if(ch == 1):
    print(my_sum(a, b))
elif(ch == 2):
    print(my_substract(a, b))
elif(ch == 3):
    print(my_multiply(a, b))
elif(ch == 4):
    print(my_divide(a, b))

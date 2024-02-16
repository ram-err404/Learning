def my_max(num1, num2):
    if (num1 > num2):
        return num1
    else:
        return num2


if __name__ == "__main__":
    num = list(map(int, input("Enter 2 numbers").split()))
    num.append(30)
    max_num = my_max(num[0], num[1])
    print(max_num)
    print(num[2])

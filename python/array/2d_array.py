if __name__ == "__main__":
    arr2d = [[0]*5]*5
    print(len(arr2d))
    print(arr2d[0])
    for i in range(len(arr2d)):
        for j in range(len(arr2d[i])):
            print(arr2d[i][j], end = " ")
        print()


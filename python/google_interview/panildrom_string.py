def panlindrom_string(str):
    start = end = -1
    q = N = len(str)-1
    p = 0
    for x in range(int(N/2)):
        if(str[p] == str[q]):
            if(start == -1 or end == -1):
                start = p
                end = q
            p += 1
            q -= 1
        else:
            start = end = -1
    if(start != -1):
        print(str[start:end+1])
    else:
        print("Palindrom doesn't exists")


str = input("Enter string to find palindrom in it: ")
panlindrom_string(str)

# print sum of command line values:
from sys import argv


def sum(argv):
    args = argv[1:]
    sum = 0
    for x in args:
        sum += int(x)
    return sum


print(argv)	# python3 comand_line_args.py 10 20 15 11 05 12 65 90
print(type(argv))
print(argv[0])
print(argv[1:])
print("The number of command line args :", len(argv))
print(argv[1] + argv[2])    # ==> 1020 (str concat)
for x in argv:
    print(x)
print("slice operator result:", argv[1:3])  # [start:end-1:step]

print("sum = ", sum(argv))

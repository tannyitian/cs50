while True:
    n = int(input("Positive Integer: "))
    if n>0 and n<8:
        break
for i in range(n):
    for j in range(n):
        if j < (n-i-1):
            print(" ", end="")
        else:
            print("#", end="")
    print()

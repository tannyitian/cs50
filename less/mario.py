while True:
    try:
        n = int(input("Height: "))
        if n>0 and n<=8:
            break
    except:
        continue
for i in range(n):
    for j in range(n):
        if j < (n-i-1):
            print(" ", end="")
        else:
            print("#", end="")
    print()
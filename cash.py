while True:
    try:
        no = float(input("Changed owed: "))
        if no >= 0:
            break
    except:
        continue
no = round(no * 100)
count = 0
for i in [25, 10, 5, 1]:
    while no >= i:
        count = count + no//i
        no = no %i
    if no == 0:
        break
print(count)
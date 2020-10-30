while True:
    try:
        cc = int(input("Number: "))
        if cc >= 0:
            break
    except:
        continue

#cclist = list(map(int, str(cc))) #map returns an iterable object. List only works with iterables.
cc_reverse = str(cc)[::-1]
no_digits = len(cc_reverse)
check = ''.join(str(elem) for elem in [int(cc_reverse[i])*2 if i%2!=0 else int(cc_reverse[i]) for i in range(no_digits)]) #turning it into a string for mapping
check =  sum(map(int, check))
cc_two = int(str(cc)[:2]) #first 2 numbers of credit card

mcard = [51, 52, 53, 54, 55]
amex = [34, 37]
if check%10 == 0:
    if cc_two in amex and no_digits==15:
        print("AMEX\n")
    elif cc_two in mcard and no_digits == 16:
        print("MASTERCARD\n")
    elif (39 < cc_two < 50) and (no_digits == 13 or no_digits == 16):
        print("VISA\n")
    else:
        print("INVALID\n")
else:
    print("INVALID\n")
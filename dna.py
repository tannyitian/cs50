import csv
import re
from sys import argv

with open(argv[2], 'r') as g: #argv2
      reader = csv.reader(g)
      for row in reader:
          dna = row
          break

with open(argv[1], 'r') as f: #argv1
    database = csv.DictReader(f)
    matchcount = 0
    for row in database:
        read = row
        count=0


        key = list(map(str, read.keys()))
        val = list(map(str, read.values()))


        for i in range(1, len(key)):
            test = "(?:" + key[i] + ")" + "+"
            if not re.findall(test, dna[0]): #checking if list is empty
                continue
            elif len(max(re.findall(test, dna[0]))) // (len(key[i])) == int(val[i]):
                count += 1

        if count == len(val) - 1:
            matchcount += 1
            print(val[0])
            break

    if matchcount == 0:
        print("No match")






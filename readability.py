while True:
    try:
        word = input("Text: ")
        break
    except:
        continue

letters, words, sentences = 0, 0, 0

for i in range(len(word)):
    if word[i].isalpha() == True:
        letters += 1
    if word[i].isspace() == True:
        words += 1
    if word[i] in ("!", ".", "?"):
        sentences += 1
words += 1
print(letters)
print(words)
print(sentences)

L = (letters/words * 100)
S = (sentences/words * 100)
index = round(0.0588*L - 0.296*S - 15.8)
# print(index)

if index < 1:
    print("Before Grade 1\n")
elif index >= 16:
    print("Before Grade 16+\n")
else:
    print("Grade", str(index))
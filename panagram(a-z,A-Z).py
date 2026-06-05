s = input("Enter a string: ")

letters = set()

for ch in s:
    if ch.isalpha():
        letters.add(ch.lower())

if len(letters) == 26:
    print("Pangram")
else:
    print("Not Pangram")

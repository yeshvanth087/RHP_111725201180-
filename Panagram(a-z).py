s = input("Enter a string: ")

letters = set()

for ch in s:
    if 'a' <= ch <= 'z':
        letters.add(ch)

if len(letters) == 26:
    print("Pangram")
else:
    print("Not Pangram")
    

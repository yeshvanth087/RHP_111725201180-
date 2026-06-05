s = input("Enter a string: ")
for i in range(len(s)):
    for j in range(i + 1, len(s)):
        print(s[i] + s[j])

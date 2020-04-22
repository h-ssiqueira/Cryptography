msg = input("Insert your message: ")
key = int(input("insert the key: "))
l = len(msg)
i = 0
while i < l:
    if msg[i] == 32:
        continue
    else:
        x = key^ord(msg[i])
        print(chr(x), end = '')
    i+=1
print("\n")

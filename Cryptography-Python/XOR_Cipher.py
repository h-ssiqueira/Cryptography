msg = input("Insert your message: ")
key = int(input("insert the key: ")) # key = 32 change case of letters
l = len(msg)
i = 0
while i < l:
    if msg[i] > '@' and msg[i] < '[' or msg[i] > '`' and msg[i] < '{':
        x = key ^ ord(msg[i])
        print(chr(x), end = '')
    else:
        print(msg[i], end = '')
    i += 1
print("\n")

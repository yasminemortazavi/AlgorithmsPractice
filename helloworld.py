string1 = input()
currentstring = ""
hellocount = 0
count = 0
for char in string1:
    currentstring = currentstring + char
    if char is 'h':
        currentstring = 'h'
    elif char is 'w':
        currentstring = 'w'
    elif currentstring == 'hello':
        hellocount = hellocount + 1
        currentstring = ""
    elif currentstring == 'world':
        currentstring = ""
        count = count + hellocount
print(count)


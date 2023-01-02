x = int(input())
for i in range(1,x+1):
    if i == 1:
        print(0)
    elif i == 2:
        print(6)
    else:
        print(int(((i**4) - 9*(i**2) + (24*i) - 16)* 0.5))

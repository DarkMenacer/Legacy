bob=[]
tim=[]
x=int(input('enter numebr of numbers'))
for i in range(0,x):
    y=int(input('enter the number'))
    bob.append(y)
for i in bob:
    tim.append(i*i)
print(tim)
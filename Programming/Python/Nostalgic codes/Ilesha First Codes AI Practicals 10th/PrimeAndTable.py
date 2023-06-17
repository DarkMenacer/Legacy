y=int(input("Enter any number"))
p=0
for x in range(2,y):
    if y%x==0:
        print(y,"Is a composite number")
        p=1
        break
if p==0:
    print(y,"is a prime number")
for i in range(1, 11):
    print(y,"*",i,"=",i*y)

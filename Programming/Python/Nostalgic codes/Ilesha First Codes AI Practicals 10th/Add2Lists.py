x=int(input("enter no. of numbers"))
NumA=[]
for i in range(0,x):
    y=int(input("enter number"))
    NumA.append(y)
NumB=[]
for i in range(0,x):
    y=int(input("enter no."))
    NumB.append(y)
for i in range(0,x):
    print(NumA[i]+NumB[i])
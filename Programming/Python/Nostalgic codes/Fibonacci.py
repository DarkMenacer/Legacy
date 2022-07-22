def Fibonacci(x):
    i = 0
    j = 1
    print(i)
    print(j)
    for _ in range(x-2):
        k = i + j
        i = j
        j = k
        print(k)

Fibonacci(int(input("Enter number of terms needed: ")))
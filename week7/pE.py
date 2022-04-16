n, k = input().split()
n = int(n)
k = int(k)

fib = [0, 1, 1]

for i in range(3, n+1):
    fib.append(fib[i-1] + fib[i-2])

while n > 2:
    if k > fib[n-2]:
        k -= fib[n-2]
        n -= 1
    else:
        n -= 2
    
if n == 1:
    print("N")
else:
    print("A")
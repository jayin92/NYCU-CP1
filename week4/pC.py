def f(x, y):
    global a, b, c, d, dp
    res = c
    if x >= 0 and y >= 0 and dp[x][y] != -1:
        return dp[x][y]
    if x > 0 and y > 0:
        for i in range(len(a)):
           res += f(x - a[i], y - b[i])
        dp[x][y] = res
        return res
    else:
        return d 

n = int(input())

while n != 0:
    n -= 1
    tmp = list(map(int, input().split(" ")))

    a = []
    b = []
    dp = []
    for _ in range(105):
        dp.append([-1 for _ in range(105)])
    
    for i in range(0, len(tmp)-2, 2):
        a.append(tmp[i])
        b.append(tmp[i+1])
    c, d = tmp[-2], tmp[-1]
    tmp = list(map(int, input().split(" ")))

    for i in range(0, len(tmp), 2):
        x = tmp[i]
        y = tmp[i+1]
        print(f(x, y))
    print()
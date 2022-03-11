m = dict()

op = ['+', '-', '*', '//']

for i in op:
    for j in op:
        for k in op:
            eq = f"4 {i} 4 {j} 4 {k} 4"
            res = eval(eq)
            eq = eq.replace("//", "/")
            m[res] = eq


t = int(input())

while t != 0:
    t -= 1
    n = int(input())
    if n in m:
        print(f"{m[n]} = {n}")
    else:
        print("no solution")
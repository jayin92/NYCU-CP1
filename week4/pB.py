n, k = map(int, input().split(" "))

if k >= 336 or n <= 2 ** k:
    print("Your wish is granted!")
else:
    print("You will become a flying monkey!")
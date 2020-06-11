from cs50 import get_int
while True:
    n = get_int("Height: \n")
    if n > 0 and n < 9:
        break
for p in range(n):
    for q in range(n - p - 1):
        print(" ", end="")
    for r in range (n - p - 1 , n, 1):
        print("#", end="")
    for s in range (n, n + 2, 1):
        print(" ", end="")
    for t in range (n + 2, n + 2 + p + 1, 1):
        print("#", end="")
    print()

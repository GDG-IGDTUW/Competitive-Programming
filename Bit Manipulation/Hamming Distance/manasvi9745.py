def hamming_distance(x, y):
    n = x ^ y
    c = 0
    while n:
        n &= (n - 1)
        c += 1
    return c


x = int(input())
y = int(input())
print(hamming_distance(x, y))

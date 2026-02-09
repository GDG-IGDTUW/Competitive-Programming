import math

def min_coins(k):
    if k == 1:
        return 1
    
    for i in range(2, int(math.sqrt(k)) + 1):
        if k % i == 0:
            return i
    
    return k


t = int(input())
for _ in range(t):
    k = int(input())
    print(min_coins(k))

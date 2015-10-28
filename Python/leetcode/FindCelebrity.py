def findCelebrity(self, n):
    x = 0
    for i in range(1, n):  #1...n-1
        if knows(x, i):
            x = i

    for i in range(n):   # 0..n-1
        if x!=i:
            if knows(x, i) or not knows(i, x):
                return -1

    return x
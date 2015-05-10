def countPrimes(n):
    count=0
    is_prime = [True for i in range(0,n)]
    for i in range(2,n):
        if (is_prime[i]):
            count += 1
            print (i)
            j = i*2
            while(j < n):
                is_prime[j]=False
                j += i
    return count


print (countPrimes(6))
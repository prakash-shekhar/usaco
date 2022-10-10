nums = []
for i in range(5):
    nums.append(int(input("Enter a number:  ")))
for i in range(5):
    primes = 0
    counter = 1
    isPrime = True
    latestPrime = 0
    while(primes<nums[i]):
        isPrime = True
        for j in range(2, counter):
            if(counter % j == 0 and j != counter):
                isPrime = False
                break
            latestPrime = j
        if (isPrime):
            primes+=1
    print(str(latestPrime))
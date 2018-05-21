# Find primes using Euler's proof of infinite primes

def factorial(n):
    if n == 1:
        return 1

    else:
        return n * factorial(n-1)

def addTo(db, n):
    if n in db:
        db[n] += 1

    else:
        db[n] = 1

def primeDivisors(n):
    print("Finding prime factors of " + str(n))
    primes = {}
    highestPrime = n ** (1/2) 
    min = 2

    i = min
    max = n ** (1/2)
    while(i < max and n > 1):
        if n%i == 0:
            n = n/i
            addTo(primes, i)
            i = min
            max = n ** (1/2)

        else:
            i += 1
            min += 1

    if n != 1:
        addTo(primes, int(n))

    return primes

def main():
    highestPrime = input("Give me a large number, and I'll find a prime that's bigger: ")

    f = factorial(int(highestPrime))
    ps = primeDivisors(f + 1)

    print(str(f + 1) + " :" + str(ps))
    print("This is higher: " + str(max(ps.keys())) )

while True:
    main()

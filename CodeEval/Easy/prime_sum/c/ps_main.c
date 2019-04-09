#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int primeGen( int* numPrimesRequested ) {
    // static state...
    // (Note: I really really wouldn't do this for anything larger...)
    static int arraySize = 0;
    static int idx = 0;
    static int* primes;
    static int maxPrimeVal = 100000;

    /* successive runs don't need to calculate again, just
     * pull the next value of the array */
    if ( (numPrimesRequested == NULL) &&
         (idx < arraySize) &&
         (primes != NULL)  )
    {
        idx++;
        return primes[idx-1];
    }
    /* initial run using sieve of Eratosthenes */
    else if ( (numPrimesRequested != NULL) &&
              (numPrimesRequested > 0) )
    {
        int limit = ceil(sqrt((double)maxPrimeVal));
        int* tmpArray = calloc(maxPrimeVal, sizeof(int));

        // fill the numbers
        for ( int i=0; i<(maxPrimeVal-1); i++)
        {
            tmpArray[i]=i+2;
        }

        // the sieve -> 0 = non-prime ; 1 = prime
        int i=2 , j=0, idx=0;
        while ( i < limit )
        {
            if ( tmpArray[idx] != 1 )
            {
                j=i*i;
                while ( j <= maxPrimeVal)
                {
                    tmpArray[j-2] = 1;
                    j+=i;
                }
            }
            i++; idx++;
        }

        // figure out how many primes we need to allocate
        int numPrimes = 0;
        for ( i=0; (i<maxPrimeVal); i++)
        {
            if (tmpArray[i] != 1) { numPrimes++; }
        }
        if ( numPrimes > *numPrimesRequested)
        {
            numPrimes = *numPrimesRequested;
        }

        // sort the primes into their own array
        primes = calloc(numPrimes, sizeof(primes));
        for ( i=0, j=0; (i<maxPrimeVal) && (j<=numPrimes); i++)
        {
            if ( tmpArray[i] != 1 )
            {
                *(primes + j) = tmpArray[i];
                j++;
            }
        }
        // free our tmpArray[]...
        free(tmpArray);
        // and return the actual number of primes generated
        return arraySize = numPrimes;
    }
    else { return 0; }
}

/*
 * This program will sum N prime numbers.
 * Eg: 2+3+5+7 = 17 if 4 is the input.
 * This can be to a given number of primes (if given as an argument)
 * or will sum a default number of primes.
 */
int main(int argc, const char * argv[]) {

    int primeSum = 0;
    int numPrimesRequested = 1000;
    if (argc > 1) {
        // I'll just assume/hope an integer was given
        sscanf(argv[1], "%d", &numPrimesRequested);
    }

    // Note: The first run gives the number of primes generated
    int limit = primeGen(&numPrimesRequested);
    for ( int idx=0; (idx < limit); idx++)
    {
        primeSum += primeGen(NULL);
    }
    printf("%d\n", primeSum);
    return 0;
}

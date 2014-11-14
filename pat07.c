#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int isPrime(int num)
{
    int i = 2;

    for( i = 1; i * i <= num ; i++)
    {
        if( num % i == 0 && i != 1 )
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int num, i = 0;
    int lastPrime = 3;
    int primeArr = 0;
    
    scanf("%d", &num);
    
    for(i = 3; i <= num; i += 1)
    {
        if( isPrime(i) == 0 )
        {
            if(i - lastPrime == 2)
            {
                //printf("%d %d\n", i, lastPrime);
                primeArr++;
            }
            
            lastPrime = i;
        }
    }
    printf("%d\n", primeArr);
    
    return 0;
}


#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int isPrime(int num)
{
    int i = 0;
    if(i == 1)
    {
        return 1;
    }

    for( i = 2; i * i <= num ; i++)
    {
        if( num % i == 0 )
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int startp, endp, i = 2;
    int flag = 0, count = 0;
	
    scanf("%d%d", &startp, &endp);
    
    while(1)
    {
        if( isPrime(i) == 0 )
        {
	     flag++;
        
            if( flag >= startp && flag <= endp )
            {
                count++;
                //printf("%d", i);
                if(count % 10 != 1)
                {
                    printf(" ");
                }
                printf("%d", i);

                if(count % 10 == 0)
                {
                    printf("\n");
                }
                
                if( flag == endp)
                {
                    break;
                }
            }
	  }
	  i++;
    }
    printf("\n");
    return 0;
}


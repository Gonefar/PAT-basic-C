#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1001

int main()
{
    char num[MAX];
    int charNum[10] = {0}, temp, i = 0;

    scanf("%s", num);

    while( '\0' != num[i] )
    {
        temp = num[i] - '0';
        charNum[temp]++;
        i++;
    }

    for( i = 0; i < 10; i++ )
    {
        if( charNum[i] > 0 )
        {
            printf("%c:%d\n", i+'0', charNum[i]);
        }
    }
    
    return 0;
}



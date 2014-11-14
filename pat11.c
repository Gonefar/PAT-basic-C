#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNUM 10

int main()
{
    long int a[MAXNUM][3];
    int num, i, j;
    char ch;

    scanf("%d", &num);

    for( i = 0; i < num; i++ )
    {
        for( j = 0; j < 3; j++ )
        {
            scanf("%ld", &(a[i][j]));
            //scanf("%c", &ch);
        }
    }

    for( i = 0; i < num; i++ )
    {
        if( a[i][0] + a[i][1] > a[i][2] )
        {
            printf("Case #%d: true\n", i+1);
        }
        else
        {
            printf("Case #%d: false\n", i+1);
        }
    }
    
    return 0;
    
}


#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    int a[4010] = {0}, num = 0, i = 0, flag = 0;

    scanf("%d", &(a[i]));
    scanf("%c", &ch);
    num++;
    i++;
    
    while( ch != '\n' )
    {
        scanf("%d", &(a[i]));
        scanf("%c", &ch);
        num++;
        i++;
    }

    for( i = 0; i < num; i++ )
    {
        if( (i+1) % 2 == 0)
        {
            a[i] -= 1;
        }
        else
        {
            a[i] = a[i] * a[i+1];
        }
        //printf("%d ", a[i]);
    }

    for( i = 0; i < num; i++ )
    {
        if( (i+1) % 2 == 0 && a[i] == -1 )
        {
            flag = i;
            //printf("\ni:%d a[i]:%d\n", i, a[i]);
        }
    }



    if( flag )
    {
        num -= 2;
        for( i = flag - 1; i < num; i++ )
        {
            a[i] = a[i+2];
        }
    }
    
    for( i = 0; i < num; i++)
    {
        printf("%d", a[i]);

        if( i == num - 1 )
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
    }

    return 0;
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[50][80];
    int i=0, num = 0;
    char ch='a';

    while( ch != '\n' )
    {
        scanf("%s", str[i]);
        scanf("%c", &ch);
        i++;
        if(ch == '\n')
        {
            break;
        }
        
    }
    
    i--;
    while( i >= 0)
    {
        
        printf("%s", str[i]);
        if(i != 0)
        {
            printf(" ");
        }
        i--;
    }
    printf("\n");
    return 0;
}


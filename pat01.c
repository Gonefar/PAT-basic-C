#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int len = 0;

    scanf("%d", &num);

    while( num != 1)
    {
        if( num % 2 == 0)
        {
            num /= 2;
        }
        else
        {
            num = (3 * num + 1) / 2;
        }
        len++;
    }

    printf("%d\n", len);
    return 0;
}



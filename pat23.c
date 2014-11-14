#include <stdio.h>

int main()
{
    int digitNum[10] = {0};
    int i = 0, flag = 0, j = 0, note = 0;

    for( i = 0; i < 10; i++ )
    {
        scanf("%d", digitNum + i);
        if( i >= 1 && digitNum[i] > 0 && note == 0 )
        {
            note = 1;
            flag = i;
        }
    }

    printf("%d", flag);
    digitNum[flag]--;
    for( i = 0; i < 10; i++ )
    {
        if( digitNum[i] > 0 )
        {
            for( j = 0; j < digitNum[i]; j++ )
            {
                printf("%d", i);
            }
        }
    }

    printf("\n");
    return 0;
    
}

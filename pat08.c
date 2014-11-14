#include <stdio.h>

#define LEN 100

int main()
{
    int len, shift, i, start = 0;
    int arr[LEN];

    scanf("%d%d", &len, &shift);

    for(i = 0; i < len; i++)
    {
        scanf("%d", &(arr[i]));
    }

    start = shift % len;

    for(i = len -start; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    for(i = 0; i < len -start; i++)
    {
        printf("%d", arr[i]);
        if(i != len - start-1)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}


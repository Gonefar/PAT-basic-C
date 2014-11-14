#include <stdio.h>
#include <string.h>

int main()
{
    int num;
    int i = 0, times = 0;

    scanf("%d", &num);

    times = num / 100;
    for(i = 0; i < times; i++)
    {
        printf("%c", 'B');
    }

    times = num / 10 % 10;
    for(i = 0; i < times; i++)
    {
        printf("%c", 'S');
    }

    times = num % 10;
    for(i = 0; i < times; i++)
    {
        printf("%d", i+1);
    }
    printf("\n");

    return 0;
}

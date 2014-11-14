#include <stdio.h>
#define MAXNUM 1000

int output1(int num)
{
    if( num == 0 )
    {
        printf("N");
    }
    else
    {
        printf("%d", num);
    }

    return 0;
}

int output2(int sum, int num)
{
    if( num == 0 )
    {
        printf("N");
    }
    else
    {
        printf("%.1f", (float)sum/num);
    }

    return 0;
}

int output3(int a, int num)
{
    if(num == 0)
    {
        printf("N");
    }
    else
    {
        printf("%d", a);
    }

    return 0;
}

int output(int a1, int a2, int a2Num, int a3, int a4, int a4Num, int a5)
{
    //printf("%d %d %d %d %d %d %d\n", a1, a2, a2Num, a3, a4, a4Num, a5);
    output1(a1);
    printf(" ");
    output3(a2, a2Num);
    printf(" ");
    output1(a3);
    printf(" ");
    output2(a4, a4Num);
    printf(" ");
    output1(a5);
    printf("\n");
}

int main()
{
    int a[1000], num;
    int i = 0, a1 = 0, a2 = 0, a2Num = 0, a3 = 0, a4 = 0, a5 = 0, flag = 1, a4Num = 0;

    scanf("%d", &num);
    for( i = 0; i < num; i++ )
    {
        scanf("%d", &(a[i]));
    }

    for( i = 0; i < num; i++ )
    {
        if(a[i] % 5 == 0 )
        {
            if(a[i] % 2 == 0)
            {
                a1 += a[i];
            }
        }
        else if(a[i] % 5 == 1)
        {
            a2 += flag * a[i];
            flag *= -1;
            a2Num++;
        }
        else if(a[i] % 5 == 2)
        {
            a3++;
        }
        else if(a[i] % 5 == 3)
        {
            a4Num++;
            a4 += a[i];
        }
        else
        {
            if( a[i] > a5 )
            {
                a5 = a[i];
            }
        }

    }

    output(a1, a2, a2Num, a3, a4, a4Num, a5);
    return 0;
}


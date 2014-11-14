#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void showList(int *arr, int len)
{
    int i = 0;

    for(i = 0; i < len ; i++)
    {
        printf("%d", arr[i]);
        if( i == len - 1)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
    }

    return;
}

int isCover(int a, int b) // is a cover b
{
    while( a != 1)
    {
        if( a == b )
        {
            return 0;
        }
        
        if( a % 2 == 0)
        {
            a /= 2;
        }
        else
        {
            a = (3 * a + 1) / 2;
        }       
    }

    return 1;
}

int swap(int *a, int *b)
{
    int temp = *a;

    *a = * b;
    *b = temp;

    return 0;
}

int bubbleSortAsLarge(int *arr, int len)
{
    int i = 0, j = 0;

    for(i = 0; i < len; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(arr[i] > arr[j])
            {
                swap(&(arr[i]), &(arr[j]));
            }
        }
    }

    return 0;
}

int main()
{
    int num, i, j, bLen = 1;
    int a[MAX], b[MAX];
    int coverFlag = 0;

    scanf("%d", &num);
    for(i = 0; i < num; i++)
    {
        scanf("%d", &(a[i]));
    }

    b[0] = a[0];

    for(i = 1; i < num; i++)
    {
        for(j = 0; j < bLen; j++)
        {
            if(isCover(b[j], a[i]) == 0)
            {
                break;
            }

            if(isCover(b[j], a[i]) == 1 && j == bLen - 1) //not cover untill end
            {
                coverFlag++;
            }

            if(isCover(a[i], b[j]) == 0)
            {
                b[j] = a[i];
                break;
            }

            if(isCover(b[j], a[i]) == 1 && j == bLen - 1)
            {
                coverFlag++;
            }
        }

        if(coverFlag == 2)
        {
            b[bLen] = a[i];
            bLen++;
            
        }

        coverFlag = 0;
        
    }

    bubbleSortAsLarge(b, bLen);
    showList(b, bLen);
    
    return 0;
}



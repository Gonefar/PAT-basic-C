#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int swap(int *a, int *b)
{
    int temp = *a;

    *a = * b;
    *b = temp;

    return 0;
}

int bubbleSortAsSmall(int *arr, int len)
{
    int i = 0, j = 0;

    for(i = 0; i < len; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(arr[i] < arr[j])
            {
                swap(&(arr[i]), &(arr[j]));
            }
        }
    }

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

int getValue(int *arr, int len)
{
    int i = 0, sum = 0;

    for( i = 0; i < len; i++ )
    {
        sum = sum * 10 + arr[i];
    }

    return sum;
}

void printNum(int *arr, int len)
{
    int i = 0;

    for( i = 0; i < len; i++ )
    {
        printf("%d", arr[i]);
    }

    return;
}

int convertToArr(int value, int *arr, int len)
{
    int i = 0;

    for( i = len-1; i >= 0; i-- )
    {
        arr[i] = value % 10;
        value /= 10;
    }

    return 0;
}

int isAllEqual(int *arr, int len)
{
    int i = 0;

    for(i = 0; i < len - 1; i++)
    {
        if( arr[i] != arr[i+1] )
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int num=1, value = 0, i = 1;
    int bigArr[4], smallArr[4], temp[4];

    scanf("%d", &num);

    convertToArr(num, temp, 4);

    if(isAllEqual(temp, 4) == 0)
    {
        printNum(temp, 4);
        printf(" - ");
        printNum(temp, 4);
        printf(" = 0000\n");


        return 0;
    }

    if( num == 6174 )
    {
        printf("7641 - 1467 = 6174\n");
        return 0;
    }
#if 0
    bubbleSortAsLarge(temp, 4);
    printNum(temp, 4);
    printf("\nlarge value:%d\n", getValue(temp, 4));
    bubbleSortAsSmall(temp, 4);
    printNum(temp, 4);
    printf("\nlarge value:%d\n", getValue(temp, 4));
#endif

#if 1  
    while( num != 6174 )
    {
        if(num == 0)
        {
            break;
        }
        
        convertToArr(num, bigArr, 4);
        convertToArr(num, smallArr, 4);
        bubbleSortAsLarge(bigArr, 4);
        bubbleSortAsSmall(smallArr, 4);

        num = getValue(bigArr, 4) - getValue(smallArr, 4);
        convertToArr(num, temp, 4);
        printNum(bigArr, 4);
        printf(" - ");
        printNum(smallArr, 4);
        printf(" = ");
        printNum(temp, 4);
        printf("\n");
    }
#endif
    return 0;
}



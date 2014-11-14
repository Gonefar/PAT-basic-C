#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct _mk
{
    float amount;
    float value;
};

void showList(struct _mk *arr, int len)
{
    int i = 0;

    for(i = 0; i < len ; i++)
    {
        printf("%.2f %.2f\n", arr[i].amount, arr[i].value);
    }

    return;
}

int swapInt(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = *a;
}

void swapStruct(struct _mk *a, struct _mk *b)
{
    struct _mk temp = *a;
    *a = *b;
    *b = temp;
}

int bubbleSortAsLarge(struct _mk *arr, int len)
{
    int i = 0, j = 0;

    for(i = 0; i < len; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(arr[i].value / arr[i].amount > arr[j].value / arr[j].amount)
            {
                swapStruct(&(arr[i]), &(arr[j]));
            }
        }
    }

    return 0;
}

int main()
{
    int num;
    float total;
    struct _mk *mk = (struct _mk*)malloc(sizeof(struct _mk) * MAX);
    int i = 0;
    float totalValue = 0;

    scanf("%d%f", &num, &total);
    for(i = 0; i < num; i++)
    {
        scanf("%f", &(mk[i].amount));
    }
    
    for(i = 0; i < num; i++)
    {
        scanf("%f", &(mk[i].value));
    }

    bubbleSortAsLarge(mk, num);
    //showList(mk, num);
    i = 0;
    while(total > 0.0)
    {
        if(total >= mk[i].amount)
        {
            total -= mk[i].amount;
            totalValue += mk[i].value;
        }
        else
        {
            totalValue += total * mk[i].value / mk[i].amount;
            break;
        }
        i++;
	if(i == num)
	{
	    break;
	}
    }

    printf("%.2f\n", totalValue);
    return 0;
}


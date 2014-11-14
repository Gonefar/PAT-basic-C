#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNUM 1010

int divBigNum(char *num, int div, char *res)
{
    int i = 0, temp = 0;

    while(num[i] != '\0')
    {
        res[i] = (temp * 10 + (num[i] - '0')) / div + '0';
	temp = (temp * 10 + num[i] - '0') % div;
	//printf("temp:%d res:%c\n", temp, res[i]);
	i++;

    }

    return temp;
}

int main()
{
    char num[MAXNUM];
    char res[MAXNUM];
    int div, rem, i, j;
    int flag = 0;

    memset(num, 0, MAXNUM * sizeof(char));
    memset(res, 0, MAXNUM * sizeof(char));

    scanf("%s", num);
    scanf("%d", &div);

//for(j = 1; j < 10; j++)
//{
    rem = divBigNum(num, div, res);
    for(i = 0; res[i] != '\0'; i++)
    {
	//printf("for:%c\n", res[i]);
        if( !flag && res[i] == '0' )
	{
	    continue;
	}
	
	printf("%c", res[i]);
	flag = 1;	
    }

    if( !flag )
    {
        printf("0");
    }
    printf(" %d\n", rem);
//    flag = 0;
//}
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

int partInt(long int a, int da)
{
    int sum = 0;
    int daNum = 0, i = 0;

    while( a > 0 )
    {
        if( da == a % 10 )
	{
	    daNum++;
	}
	a /= 10;
    }

    for( i = 0; i < daNum; i++ )
    {
        sum = sum * 10 + da;
    }

    return sum;
}

int main()
{
    int da, db;
    long int a, b;

    scanf("%d%d%ld%ld", &a, &da, &b, &db);
    printf("%d\n", partInt(a, da)+partInt(b, db));
    return 0;

}

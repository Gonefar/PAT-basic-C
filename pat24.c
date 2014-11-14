#include <stdio.h>

int procs(char *num, int exp, int len, int notePos)
{
    int digitNum = len - 2;
    int fractNum = len - 3;
    int i = 3, flag = 0, tempExp = 0;

    if( exp > 0 )
    {
        if( '-' == num[0] )
        {
            printf("-");
        }

        printf("%c", num[1]);

        while( exp > 0 || fractNum > 0 )
        {
            if( exp > 0 && fractNum > 0 )
            {
                printf("%c", num[i]);
                i++;
            }
            else if( exp > 0 && fractNum <= 0 )
            {
                printf("0");
            }
            else if( exp <= 0 && fractNum > 0 )
            {
                if( 0 == flag )
                {
                    printf(".");
                    flag = 1;
                    fractNum++;
                }
                else
                {
                    printf("%c", num[i]);
                    i++;
                }
            }

            exp--;
            fractNum--;
        }
    }
    else if( exp < 0 )
    {
        if( '-' == num[0] )
        {
            printf("-");
        }   

        printf("0.");
        tempExp = - exp;
        for( i = 0; i < tempExp-1; i++ )
        {
            printf("0");
        }

        printf("%c", num[1]);
        for( i = 0; i < fractNum; i++ )
        {
            printf("%c", num[i+3]);
        }
    }
    else
    {
        for( i = 0; i < len; i++ )
        {
            printf("%c", num[i]);
        }
    }

    printf("\n");
    return 0;
}

int main()
{
    char num[10000];
    char temp;
    int exp, i = 0, notePos = 0;

    scanf("%c", &temp);
    while( 'E' != temp )
    {
        num[i] = temp;
        if( '.' == temp )
        {
            notePos = i;
        }
        
        i++;
        scanf("%c", &temp);
    }

    scanf("%d", &exp);
    procs(num, exp, i, notePos);
    
    return 0;
}


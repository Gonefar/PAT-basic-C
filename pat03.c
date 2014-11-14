#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXROW 10
#define MAXCOL 100

int checkString(char *str)
{
    int i = 0, len = 0, flag = -1; //flag 0:P*A*T 1:xP(n)AT(n)x
    int info = 0; // 1:find the first P 2:find the first A 3:find the first T

    len = strlen(str);
    
    for( i = 0; i < len; i++ )
    {
        if( info == 0 && str[i] != 'P' && str[i] != 'A' ) //illegal char before the first A or P
        {
            //printf("%d:return\n", __LINE__);
            return 1; //
        }

        if( info == 0 && str[i] == 'P' )
        {
            info = 1;
            continue;
        }
        else if( info == 0 && str[i] == 'A' )
        {
            continue;
        }

        if( info == 1 && str[i] == 'A' )
        {
            info = 2;
            continue;
        }
        
        if( str[i] != 'T' && str[i] != 'A' )
        {
            //printf("%d:return\n", __LINE__);
            return 1;
        }

        if( info == 2 && str[i] == 'T' )
        {
            return 0;
        }
    }

    //printf("%d:return\n", __LINE__);
    return 1;
}

int checkTypeZero(char *str)
{
    int i = 0, len = 0, info = 0;

    len = strlen(str);

    for( i = 1; i < len; i++ )
    {
        if( info == 0 && str[i] != 'P' && str[i] != 'A' ) //illegal char before the first A or P
        {
            //printf("%d:return\n", __LINE__);
            return 1; //
        }

        if( info == 0 && str[i] == 'A' )
        {
            info = 1;
            continue;
        }

        if( info == 1 && str[i] == 'A' )
        {
            continue;
        }
        else if( info == 1 && str[i] == 'T' )
        {
            if( i == len - 1)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
        
    }
}

int checkTypeOne(char *str)
{
    int len = 0, i = 0, flag = 0; //flag 0-left 1-mid 2-right
    int leftAnum = 0, midAnum = 0, rightAnum = 0;

    len = strlen(str);

    for(i = 0; i < len; i++)
    {
        if( str[i] == 'P' )
        {
            flag = 1;
            continue;
        }
        else if(str[i] == 'T')
        {
            flag = 2;
            continue;
        }
        else if( str[i] == 'A' )
        {
            ;
        }
        else
        {
            return 1;
        }
        
        if( flag == 0 )
        {
            leftAnum++;            
        }
        else if( flag == 1 )
        {
            midAnum++;
        }
        else
        {
            rightAnum++;
        }
    }

    if( midAnum == 1 && leftAnum == rightAnum)
    {
        return 0;
    }

    if( midAnum == 2 && rightAnum == 2 * leftAnum )
    {
        return 0;
    }

    return 1;
    
}

int checkStringNew(char *str)
{
    if( str[0] == 'A' )
    {
        return checkTypeOne(str);
    }
    else if( str[0] == 'P' )
    {
        return checkTypeZero(str);
    }
    else
    {
        return 1;
    }

}

int main()
{
    int testLineNum = 0, i = 0 , j = 0;
    char inputStr[MAXROW][MAXCOL];

    memset( inputStr, 0, sizeof(char)*MAXROW*MAXCOL);
    scanf("%d", &testLineNum);

    for( i = 0; i < testLineNum; i++ )
    {
        scanf("%s", inputStr[i]);
    }

    for( i = 0; i < testLineNum; i++ )
    {
        if( checkStringNew(inputStr[i]) > 0 )
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }

    return 0;
}

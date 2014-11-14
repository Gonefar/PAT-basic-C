#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 70

void printDay(char ch)
{
    switch(ch)
    {
        case 'A':
            printf("MON ");
            break;
        case 'B':
            printf("TUE ");
            break;
        case 'C':
            printf("WED ");
            break;
        case 'D':
            printf("THU ");
            break;
        case 'E':
            printf("FRI ");
            break;
        case 'F':
            printf("SAT ");
            break;
        case 'G':
            printf("SUN ");
            break;
        default:
            //printf("error char\n");
            break;

    }
}

int main()
{
    char str[4][MAXLINE];
    int i = 0;
    int flag = 0;

    for(i = 0; i < 4; i++)
    {
        scanf("%s", str[i]);
    }

    for( i = 0; str[0][i] != '\0' && str[1][i] != '\0'; i++ )
    {
        if( !flag && str[0][i] == str[1][i] && str[0][i] >= 'A' && str[0][i] <= 'G' )
        {
            printDay(str[0][i]);
            flag = 1;
            continue;
        }

        if( flag && str[0][i] == str[1][i] )
        {
            if( str[0][i] >= '0' && str[0][i] <= '9' )
            {
                printf("0%c:", str[0][i]);
                break;
            }
            else if( str[0][i] >= 'A' && str[0][i] <= 'N' )
            {
                printf("%d:", str[0][i]-'A'+10);
                break;
            }
            
        }
    }

    for( i = 0; str[2][i] != '\0' && str[3][i] != '\0'; i++ )
    {
        if( str[2][i] == str[3][i] && 
            ( (str[2][i] >= 'a' && str[2][i] <= 'z') 
            || (str[2][i] >= 'A' && str[2][i] <= 'Z' )) )
        {
            if( i < 10 )
            {
                printf("0%d\n", i);
                break; //find it and break
            }
            else
            {
                printf("%d\n", i);
                break; //find it and break
            }
        }
    }

    return 0;
    
}


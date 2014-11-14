#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXCHAR 12

struct _st
{
    char name[MAXCHAR];
    char subject[MAXCHAR];
    int score;
};

int main()
{
    struct _st max, min, temp;
    int num, i;
    char ch;

    max.score = min.score = 0;

    scanf("%d", &num);

    for(i = 0; i < num; i++)
    {
        memset(&temp, 0 ,sizeof(struct _st));
        scanf("%s", temp.name);
        scanf("%c", &ch);
        scanf("%s", temp.subject);
        scanf("%c", &ch);
        scanf("%d", &(temp.score));
        scanf("%c", &ch);

        if( i == 0 )
        {
            memcpy(&max, &temp, sizeof(struct _st));
            memcpy(&min, &temp, sizeof(struct _st));
            continue;
        }
        
        if( temp.score > max.score )
        {
            memcpy(&max, &temp, sizeof(struct _st));
        }

        if( temp.score < min.score )
        {
            memcpy(&min, &temp, sizeof(struct _st));
        }
    }

    printf("%s %s\n", max.name, max.subject);
    printf("%s %s\n", min.name, min.subject);

    return 0;
}



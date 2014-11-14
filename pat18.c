#include <stdio.h>
#include <string.h>

struct _st
{
    int win;
    int equal;
    int lose;
    int cwin;
    int jwin;
    int bwin;
    char pose;
};

int comparePose(struct _st *mena, struct _st *menb)
{
    if( mena->pose == menb->pose )
    {
        mena->equal++;
        menb->equal++;
    }
    else if(mena->pose == 'C' && menb->pose == 'J')
    {
        mena->win++;
        menb->lose++;
        mena->cwin++;
    }
    else if(mena->pose == 'J' && menb->pose == 'B')
    {
        mena->win++;
        menb->lose++;
        mena->jwin++;
    }
    else if(mena->pose == 'B' && menb->pose == 'C')
    {
        mena->win++;
        menb->lose++;
        mena->bwin++;
    }
    else if(mena->pose == 'J' && menb->pose == 'C')
    {
        menb->win++;
        mena->lose++;
        menb->cwin++;
    }    
    else if(mena->pose == 'C' && menb->pose == 'B')
    {
        menb->win++;
        mena->lose++;
        menb->bwin++;
    } 
    else if(mena->pose == 'B' && menb->pose == 'J')
    {
        menb->win++;
        mena->lose++;
        menb->jwin++;
    } 
    
}

int bestPose(struct _st *men)
{
    if(men->cwin == men->jwin && men->cwin == men->bwin)
    {
        printf("B");
    }
    else if(men->cwin == men->bwin && men->cwin > men->jwin)
    {
        printf("B");
    }
    else if(men->cwin == men->jwin && men->cwin > men->bwin)
    {
        printf("C");
    }
    else if(men->jwin == men->bwin && men->jwin > men->cwin)
    {
        printf("B");
    }
    else if(men->jwin > men->cwin && men->jwin > men->bwin)
    {
        printf("J");
    }
    else if(men->cwin > men->jwin && men->cwin > men->bwin)
    {
        printf("C");
    }
    else if(men->bwin > men->jwin && men->bwin > men->cwin)
    {
        printf("B");
    }
    
}

int output(struct _st *mena, struct _st *menb)
{
    printf("%d %d %d\n", mena->win, mena->equal, mena->lose);
    printf("%d %d %d\n", menb->win, menb->equal, menb->lose);
    bestPose(mena);
    printf(" ");
    bestPose(menb);
    printf("\n");
}

int main()
{
    struct _st mena, menb;
    int num;
    int i = 0;
    char ch;

    memset(&mena, 0 ,sizeof(struct _st));
    memset(&menb, 0 ,sizeof(struct _st));

    scanf("%d", &num);
    scanf("%c", &ch);
    
    for(i = 0; i < num; i++)
    {
        scanf("%c %c", &(mena.pose), &(menb.pose));
        scanf("%c", &ch);
        comparePose(&mena, &menb);
    }

    output(&mena, &menb);
    
    return 0;
}


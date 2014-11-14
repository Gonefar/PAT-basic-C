#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNUM 100000

struct _st
{
    int id;
    int dscore;
    int cscore;
};

struct _num
{
    int DCnum;
    int Dnum;
    int DPrinum;
    int Remnum;
};

void showList(struct _st *arr, int len)
{
    int i = 0;

    for(i = 0; i < len ; i++)
    {
        printf("%d %d %d\n", arr[i].id, arr[i].dscore, arr[i].cscore);
    }

    return;
}

void swap(struct _st *a, struct _st *b)
{
    struct _st temp = *a;

    *a = *b;
    *b = temp;

    return;
}

int getNum(struct _st *arr, int len, struct _num *para, int score2, int score1) //type 1:DC, 2:D 3:Dpri
{
    int i = 0;

    for(i = 0; i < len; i++)
    {
        if(arr[i].dscore >= score2 && arr[i].cscore >= score2 )
        {
            para->DCnum++;
        }
         else if(arr[i].dscore >= score2 && arr[i].cscore < score2 && arr[i].cscore >= score1)
        {
            para->Dnum++;
        }
         else if(arr[i].dscore < score2 //&& arr[i].cscore < score2 
            && arr[i].dscore >= score1 && arr[i].cscore >= score1
            && arr[i].dscore >= arr[i].cscore)
        {
            para->DPrinum++;
        }
         else if(arr[i].dscore < score2 //&& arr[i].cscore < score2
            && arr[i].dscore >= score1 && arr[i].cscore >= score1
            && arr[i].dscore < arr[i].cscore)
        {
            para->Remnum++;
        }
    }
    
    return 0;
}

int classifyByDC(struct _st *arr, int len, int score2)
{
    int i = 0, index = 0;

    for(i = 1; i < len; i++)
    {
        if(arr[index].dscore >= score2 && arr[index].cscore >= score2)
        {
            index++;
            continue;
        }

        if(arr[i].dscore >= score2 && arr[i].cscore >= score2
            &&(arr[index].dscore < score2 || arr[index].cscore < score2))
        {
            swap(arr+i, arr+index);
            index++;
        }
    }

    return 0;
}

int classifyByD(struct _st *arr, int len, int score2, int score1)
{
    int i = 0, index = 0;

    for(i = 1; i < len; i++)
    {
        if(arr[index].dscore >= score2 && arr[index].cscore >= score1)
        {
            index++;
            continue;
        }
        
        if(arr[i].dscore >= score2 && arr[i].cscore >= score1
            && !(arr[index].dscore >= score2 && arr[index].cscore >= score1))
        {
            swap(arr+i, arr+index);
            index++;
        }
    }

    return 0;
}

int classifyByDPri(struct _st *arr, int len, int score1)
{
    int i = 0, index = 0;

    for(i = 1; i < len; i++)
    {
        if(arr[index].dscore >= arr[index].cscore
            && arr[index].cscore >= score1)
        {
            index++;
            continue;
        }
        
        if(arr[i].dscore >= arr[i].cscore && arr[i].cscore >= score1
            && !(arr[index].dscore >= arr[index].cscore && arr[index].cscore >= score1))
        {
            swap(arr+i, arr+index);
            index++;
        }
    }

    return 0;
}

int classifyBySum(struct _st *arr, int len, int score1)
{
    int i = 0, index = 0;

    for(i = 1; i < len; i++)
    {
        if(arr[index].dscore >= score1 && arr[index].cscore >= score1)
        {
            index++;
            continue;
        }
        
        if(arr[i].dscore >= score1 && arr[i].cscore >= score1
            && (arr[index].dscore < score1 || arr[index].cscore < score1) )
        {
            swap(arr+i, arr+index);
            index++;
        }
    }

    return 0;
}

int checkAndSwap(struct _st *a, struct _st *b, struct _st *c)
{
    if(a->dscore+a->cscore > b->dscore+b->cscore)
    {
        swap(a, c);
    }
    else if(a->dscore + a->cscore == b->dscore + b->cscore
        && a->dscore > b->dscore)
    {
        swap(a, c);
    }                
    else if(a->dscore+a->cscore == b->dscore+b->cscore
        && a->dscore == b->dscore && a->id < b->id)
    {
        swap(a, c);
    }
    else
    {
        return 1;
    }

    return 0;
}

void qsortByDC(struct _st *arr, int len, int score2)
{
    int i, last = 0, flag = 0;
    
    if(len <= 1 )  
    {
        return;
    }

    swap(arr, arr+rand() % len); 

    for( i = 1; i < len; i++ ) 
    {
        if(arr[i].dscore >= score2 && arr[i].cscore >= score2
            &&(arr[0].dscore < score2 || arr[0].cscore < score2))
        {
            swap(arr+i, arr+(++last));
        }
        else if(arr[i].dscore >= score2 && arr[i].cscore >= score2
                &&(arr[0].dscore >= score2 || arr[0].cscore >= score2))
        {
            flag = checkAndSwap(arr+i, arr, arr+(++last));
            last -= flag;                
        }        
        
    }
    swap(arr, arr+last); 
    qsortByDC(arr, last, score2);
    qsortByDC(arr + last + 1, len - last - 1, score2);
}

void qsortByD(struct _st *arr, int len, int score2)
{
    int i, last = 0, flag = 0;
    
    if(len <= 1 )  
    {
        return;
    }

    swap(arr, arr+rand() % len); 

    for( i = 1; i < len; i++ ) 
    {
        if(arr[i].dscore >= score2 && arr[0].dscore < score2)
        {
            swap(arr+i, arr+(++last));
        }
        else if(arr[i].dscore >= score2 && arr[0].dscore >= score2)
        {
            flag = checkAndSwap(arr+i, arr, arr+(++last));
            last -= flag;                
        }        
        
    }
    swap(arr, arr+last); 
    qsortByD(arr, last, score2); 
    qsortByD(arr + last + 1, len - last - 1, score2);
}

void qsortByDPri(struct _st *arr, int len)
{
    int i, last = 0, flag = 0;
    
    if(len <= 1 )  
    {
        return;
    }

    swap(arr, arr+rand() % len); 

    for( i = 1; i < len; i++ ) 
    {
        if(arr[i].dscore >= arr[i].cscore && arr[0].dscore < arr[0].cscore)
        {
            swap(arr+i, arr+(++last));
        }
        else if(arr[i].dscore >= arr[i].cscore && arr[0].dscore >= arr[0].cscore)
        {
            flag = checkAndSwap(arr+i, arr, arr+(++last));
            last -= flag;                
        }        
        
    }
    swap(arr, arr+last);  
    qsortByDPri(arr, last);
    qsortByDPri(arr + last + 1, len - last - 1);
}

void qsortBySum(struct _st *arr, int len)
{
    int i, last = 0, flag = 0;
    
    if(len <= 1 )  
    {
        return;
    }

    swap(arr, arr+rand() % len); 

    for( i = 1; i < len; i++ ) 
    {
        flag = checkAndSwap(arr+i, arr, arr+(++last));
        last -= flag;         
    }
    swap(arr, arr+last);
    qsortBySum(arr, last);
    qsortBySum(arr + last + 1, len - last - 1);
}

int main()
{
    int stNum, score1, score2;
    int i = 0, DCnum = 0, Dnum = 0, DpriNum = 0;
    struct _st *stud = (struct _st *)malloc(sizeof(struct _st) * MAXNUM);
    struct _num para;

    memset(&para, 0, sizeof(para));
    scanf("%d%d%d", &stNum, &score1, &score2);
    for( i = 0; i < stNum; i++ )
    {
        scanf("%d%d%d", &(stud[i].id), &(stud[i].dscore), &(stud[i].cscore));        
    }

    getNum(stud, stNum, &para, score2, score1);
    classifyByDC(stud, stNum, score2);
    classifyByD(stud+para.DCnum, stNum-para.DCnum, score2, score1);
    classifyByDPri(stud+para.DCnum+para.Dnum, stNum-para.DCnum-para.Dnum, score1);
    classifyBySum(stud+para.DCnum+para.Dnum+para.DPrinum, stNum-para.DCnum-para.Dnum-para.DPrinum, score1);

    qsortByDC(stud, para.DCnum, score2);
    qsortByD(stud+para.DCnum, para.Dnum, score2);
    qsortByDPri(stud+para.DCnum+para.Dnum, para.DPrinum);    
    qsortBySum(stud+para.DCnum+para.Dnum+para.DPrinum, para.Remnum);

    printf("%d\n", para.DCnum+para.Dnum+para.DPrinum+para.Remnum);
    showList(stud, para.DCnum+para.Dnum+para.DPrinum+para.Remnum);

    return 0;
}



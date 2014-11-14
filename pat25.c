#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX 100000

int reverseSublinklist(int *nodeArray, int *value, int *startIndex, int rvsNum, int *newStartAdd, int *lastEndIndex)
{
    int i = 0, add = 0;
    int curAdd = *startIndex, startAdd;
    int tempNextAdd = nodeArray[*startIndex];
    int nextAdd = nodeArray[*startIndex];
    static int flag = 0;

    //printf("start node:%05d\n", *startIndex);
    for( i = 0; i < rvsNum - 1; i++ )
    {
        //printf("Before:%05d %d %05d\n", curAdd, value[curAdd], nodeArray[curAdd]);
        //printf("Before:%05d %d %05d\n", nextAdd, value[nextAdd], nodeArray[nextAdd]);
        tempNextAdd = nodeArray[nextAdd];
        nodeArray[nextAdd] = curAdd;
        curAdd = nextAdd;
        nextAdd = tempNextAdd;     
    }
    
    if( -1 == nodeArray[curAdd] )
    {
        nodeArray[*startIndex] = -1;
    }    

    nodeArray[*startIndex] = tempNextAdd;
    
    if( 0 == flag )
    {
        *newStartAdd = curAdd;
        //printf("copy new start add:%d\n", *newStartAdd);
        flag = 1;
    }

    //printf("last node:%d\n", *lastEndIndex);
    if( -1 != *lastEndIndex )
    {
        nodeArray[*lastEndIndex] = curAdd;
                
    }

    *lastEndIndex = *startIndex;
    *startIndex = tempNextAdd;
    
    //printf("start index:%05d, last:%05d\n\n", *startIndex, *lastEndIndex);    
    //printf("start:%d %d %d\n\n", (nodeArray+add)->add, (nodeArray+add)->value, (nodeArray+add)->next);
    
    return 0;
}

int output(int *nodeArray, int *value, int nodeNum, int startAdd)
{
    int add = startAdd, i = 0;
    //printf("new start add:%d\n", add);
    
    while( -1 != nodeArray[add] )
    {

        i++;
        printf("%05d %d %05d\n", add, value[add], nodeArray[add]);

        if( i == nodeNum )
        {
            return 0;
        }
        
        add = nodeArray[add];
    }

    printf("%05d %d %d\n", add, value[add], nodeArray[add]);
    return 0;
}

int reverseLinklist(int *nodeArray, int *value, int *startAdd, int rvsNum, int nodeNum)
{
    int startIndex = *startAdd;
    int remainNum = nodeNum;
    int keyNode = -1;

    while( remainNum / rvsNum > 0 )
    {
        reverseSublinklist(nodeArray, value, &startIndex, rvsNum, startAdd, &keyNode);
        remainNum -= rvsNum;
    }

    return 0;
}

int main()
{
    int N, K;
    int i = 0, tempValue = 0, tempAdd = 0, tempNext = 0;
    int startAdd;
    int add[MAX], value[MAX];
    int nodeNum = 1, temp;

    scanf("%d %d %d", &startAdd, &N, &K);

    for( i = 0; i < MAX; i++ )
    {
        add[i] = -1;
        value[i] = -1;
    }

    for( i = 0; i < N; i++  )
    {
        scanf("%d %d %d", &tempAdd, &tempValue, &tempNext);
        add[tempAdd] = tempNext;
        value[tempAdd] = tempValue;
    }

    temp = startAdd;
    while( -1 != add[temp] )
    {
        nodeNum++;
        temp = add[temp];
    }
    
    reverseLinklist(add, value, &startAdd, K, nodeNum);
    output(add, value, nodeNum, startAdd);

    return 0;
}



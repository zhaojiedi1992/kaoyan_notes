#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

#define ElemType int 

typedef struct 
{
   ElemType data ; 
   int  next ; 
}SLinkList[MaxSize];

bool InitSlinkList(SLinkList L){
    for (int i=0;i<MaxSize;i++){
        L[i].next = -2;
    }
    L->next =-1 ;
    return true ;
}


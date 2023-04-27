#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

#define ElemType int 

typedef struct CDNode
{
   ElemType data ; 
   CDNode *next ; 
   CDNode *prior ; 
} CDNode,*CDLinkList;

bool InitCLinkList(CDLinkList &L);//初始化
bool Empty(CDLinkList L);//判空

bool InitCLinkList(CDLinkList &L){
    L = (CDLinkList)malloc(sizeof(CDNode));
    if (L==NULL){
        return false; 
    }
    L->next = L; 
    L->prior = L ;
    return L;
}
bool Empty(CDLinkList L){
    if (L->next ==L){
        return true ;
    }
    return false; 
}

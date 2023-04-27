#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

#define ElemType int 

typedef struct CNode
{
   ElemType data ; 
   CNode *next ; 
   CNode *prior ; 
} CNode,*CLinkList;

bool InitCLinkList(CLinkList &L);//初始化
bool Empty(CLinkList L);//判空

bool InitCLinkList(CLinkList &L){
    L = (CLinkList)malloc(sizeof(CNode));
    if (L==NULL){
        return false; 
    }
    L->next = L; 
    return L;
}
bool Empty(CLinkList L){
    if (L->next ==L){
        return true ;
    }
    return false; 
}


bool IsTail(CLinkList L,CNode *p){
    if (p==NULL){
        return false;
    }
    if (p->next==L){
        return true;
    }
    return false;
}
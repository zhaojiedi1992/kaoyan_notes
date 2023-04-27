#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

#define ElemType int 

typedef struct DNode
{
   ElemType data ; 
   DNode *next ; 
   DNode *prior ; 
} DNode,*DLinkList;

bool InitDLinkList(DLinkList &L);//初始化
bool Empty(DLinkList L);//判空
bool InsertNextDNode(DNode *p, DNode *s);//指定节点的后插操作
bool DeleteNextNode(DNode *p);//删除P节点的后继节点
bool DestroyList(DLinkList &L);//销毁整个表
bool PrintNextElems(DNode *p);//从P点向后遍历
bool PrintPriorElems(DNode *p);//从P点向前遍历
bool PrintPriorElemsOverHead(DNode *p);//从P点向前遍历（跳过头节点）


bool InitDLinkList(DLinkList &L){
    L = (DLinkList)malloc(sizeof(DNode));
    if (L==NULL){
        return false; 
    }
    L->next = NULL; 
    L->prior = NULL;
    return L;
}
bool Empty(DLinkList L){
    if (L->next ==NULL){
        return true ;
    }
    return false; 
}

bool InsertNextDNode(DNode *p, DNode *s){
    // p s n
    if (p==NULL || s==NULL){
        return false;
    }
    s->next = p->next;
    if (p->next!=NULL){
        p->next->prior = s ;
    }

    s->prior = p ;
    p->next = s ;
    return true;
}
bool DeleteNextNode(DNode *p){
    if (p==NULL){
        return false;
    }
    //p s n 
    DNode *q;
    q= p->next ;
    if (q==NULL){
        return false;
    }
    p->next = q->next ;
    if (q->next != NULL){
        q->next->prior = p ;
    }
    free(q);
    return true ;
}
bool DestroyList(DLinkList &L){
    while (L->next!=NULL){
        DeleteNextNode(L);
    }
    free(L);
    return true;
}


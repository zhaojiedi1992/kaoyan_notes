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
bool InsertNextElem(DNode *p, DNode *s);//指定节点的后插操作
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
    if (L==NULL){
        return true;
    }
    if (L->next ==NULL){
        return true ;
    }
    return false; 
}

bool InsertNextElem(DNode *p, DNode *s){
    // p s n 
    s->next = p->next;
    p->next->prior = s ; 
    s->prior = p ;
    p->next = s ;
    return true;
}
bool DeleteNextNode(DNode *p){
    if (p==NULL){
        return false;
    }
    //p s n 
    DNode *s; 
    s= p->next ;
    if (s==NULL){
        return false;
    }
    p->next = s->next ;
    if (s->next != NULL){
        s->next->prior = p ; 
    }
    free(s);
    return true ;
}
bool DestroyList(DLinkList &L){
    DLinkList l;
    l = L ; 
    while (L->next!=NULL){
        DeleteNextNode(L);
    }
    free(L);
    return L;
    return true;
}


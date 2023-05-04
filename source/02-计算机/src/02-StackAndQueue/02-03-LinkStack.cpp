#include <stdio.h>
#include <stdlib.h>
#define ElemType int
typedef struct LinkNode{
    ElemType data;
    LinkNode* next ;
}*LinkStack;

bool InitStack(LinkStack &S);
bool DestroyStack(LinkStack &S);
bool StackEmpty(LinkStack S);
int StackLen(LinkStack S);
bool Push(LinkStack &S, ElemType x);
bool Pop(LinkStack &S, ElemType &x);
bool GetTop(LinkStack S, int &x);

bool InitStack(LinkStack &S){
    S = (LinkStack)malloc(sizeof(LinkNode));
    if (S==NULL){
        return false;
    }
    S->next = NULL;
    return true;
}
bool DestroyStack(LinkStack &S){

    int x;
    while(S->next!=NULL){
        Pop(S,x);
    }
    free(S);
    return true ;
}
bool StackEmpty(LinkStack S){
    if (S->next == NULL){
        return true ;
    }
    return false;
}
int StackLen(LinkStack S){
    int i=0 ;
    LinkStack p = S;
    while (p!=NULL && p->next !=NULL ){
        i+=1;
        p= p->next;
    }
    return i ;
}
bool Push(LinkStack &S, ElemType x){
    LinkNode *x_node = (LinkNode*) malloc(sizeof(LinkNode));
    if (x_node ==NULL){
        return false;
    }
    x_node->data =x;
    x_node->next = S->next;
    S->next = x_node ;
    return true ;
}
bool Pop(LinkStack &S, ElemType &x){
    if (StackEmpty(S)){
        return false;
    }
    LinkNode *p = S->next;
    x = p->data;
    S->next = p->next;
    free(p);
    return true;
}
bool GetTop(LinkStack S, int &x){
    if (StackEmpty(S)){
        return false;
    }
    x = S->next->data;
    return true ;
}

void PrintStack(LinkStack S) {
    printf("从栈顶元素开始，栈如下：\n");


    LinkStack p = S;
    while (p->next !=NULL ){
        printf("%d\t",p->next->data);
        p= p->next;
    }

    printf("\n栈打印完毕\n");
}



int Test(){
    LinkStack S;
    int x;
    InitStack(S);
    printf("是否是空的: %d",StackEmpty(S));
    Push(S,1);
    PrintStack(S);
    Push(S,2);
    Pop(S,x);
    Push(S,3);
    PrintStack(S);
    PrintStack(S);
    if(GetTop(S,x)) {
        printf("顶部元素是%d\n", x);
    }else{
        printf("顶部元素获取失败\n");
    }
    Pop(S,x);
    printf("len=%d\n", StackLen(S));
    Pop(S,x);
    if(GetTop(S,x)) {
        printf("顶部元素是%d\n", x);
    }else{
        printf("顶部元素获取失败\n");
    }
    printf("len=%d\n", StackLen(S));
    DestroyStack(S);
//    Push(S,3);
//    printf("len=%d\n", StackLen(S));
    return 0;
}


int main03(){
    Test();
}
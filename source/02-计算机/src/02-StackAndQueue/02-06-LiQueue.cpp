#include <stdio.h>
#include <stdlib.h>
#define ElemType int

typedef struct LinkNode{
    ElemType data;
    LinkNode *next ;
}LinkNode;

typedef struct {
    LinkNode *front;
    LinkNode *real;
}LiQueue;

bool InitQueue(LiQueue &Q);
bool QueueEmpty(LiQueue S);
bool EnQueue(LiQueue &Q,ElemType x);
bool DeQueue(LiQueue &Q,ElemType &x);
bool GetHead(LiQueue Q, int &x);


bool InitQueue(LiQueue &Q){
    LinkNode *head = (LinkNode*)malloc(sizeof(LinkNode));
    if (head ==NULL){
        return false;
    }
    head->next = NULL;
    Q.front = head ;
    Q.real = head ;
    return true ;
}
bool QueueEmpty(LiQueue Q){
    if (Q.front == Q.real){
        return true ;
    }
    return false;

}
bool QueueFull(LiQueue Q){
    return false;
}
bool EnQueue(LiQueue &Q,ElemType x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    if (s==NULL){
        return false;
    }
    s->data =x ;
    s->next = NULL;
    Q.real->next = s ;
    Q.real = s ;
    return true ;
}
bool DeQueue(LiQueue &Q,ElemType &x){
    if (QueueEmpty(Q)){
        return false;
    }
    LinkNode *s = Q.front->next;
    x = s->data ;
    Q.front->next =s->next;
    if (Q.real ==s ){
        Q.real = Q.front;
    }
    free(s);
    return true ;
}
bool GetHead(LiQueue Q, int &x){
    if (QueueEmpty(Q)){
        return false;
    }
    x = Q.front->next->data;
    return true ;
}
void PrintQueue(LiQueue Q){
    LinkNode *p = Q.front->next;
    while(p!=NULL and p!=Q.real->next){
        printf("%d\t",p->data);
        p=p->next;
    }

}

//测试
void TestQueue() {
    printf("开始测试！\n");
    LiQueue Q;
    InitQueue(Q);
    if (EnQueue(Q, 1)) {
        printf("入队成功啦！\n");
    } else {
        printf("入队失败了\n");
    }
    if (EnQueue(Q, 2)) {
        printf("入队又成功啦！\n");
    } else {
        printf("入队又失败了\n");
    }
    PrintQueue(Q);
    int x;
    if (DeQueue(Q, x)) {
        printf("出队成功，弹出的元素为:%d\n", x);
    } else {
        printf("出队失败了，再检出一下吧！\n");
    }
    if (GetHead(Q, x)) {
        printf("获取队头成功！,队头元素为：%d\n", x);
    } else {
        printf("获取队头元素失败！");
    }
    if (QueueEmpty(Q)) {
        printf("队空啦\n");
    } else {
        printf("队非空\n");
    }
    PrintQueue(Q);
    printf("结束测试！\n");
}
/**测试模块**/

int main() {
    TestQueue();
    return 0;
}

#include <stdio.h>
#define ElemType int
#define MaxSize 10

struct SqQueue{
    ElemType data[MaxSize];
    int front;
    int real;
    int size;
};

bool InitQueue(SqQueue &Q);
bool QueueEmpty(SqQueue S);
bool EnQueue(SqQueue &Q,ElemType x);
bool DeQueue(SqQueue &Q,ElemType &x);
bool GetHead(SqQueue Q, int &x);


bool InitQueue(SqQueue &Q){
    Q.front =0;
    Q.real =0 ;
    Q.size =0 ;
    return true ;
}
bool QueueEmpty(SqQueue Q){
    if (Q.size==0){
        return true;
    }
    return false;
}
bool QueueFull(SqQueue Q){
    if (Q.size==MaxSize){
        return true;
    }
    return false;
}
bool EnQueue(SqQueue &Q,ElemType x){
    if (QueueFull(Q)){
        return false;
    }
    Q.data[Q.real] = x;
    Q.real = (Q.real+1)%MaxSize;
    Q.size+=1;
    return true ;
}
bool DeQueue(SqQueue &Q,ElemType &x){
    if (QueueEmpty(Q)){
        return false;
    }
    x = Q.data[Q.front] ;
    Q.front = (Q.front+1)%MaxSize;
    Q.size-=1;
    return true ;
}
bool GetHead(SqQueue Q, int &x){
    if (QueueEmpty(Q)){
        return false;
    }
    x = Q.data[Q.front] ;
    return true ; 
}
void PrintQueue(SqQueue Q){
    int front = Q.front;
    int real = Q.real;

    while (front!=real){
        printf("%d\t",Q.data[front]);
        front = (front+1)%MaxSize;
    }
}

//测试
void TestQueue() {
    printf("开始测试！\n");
    SqQueue Q;
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

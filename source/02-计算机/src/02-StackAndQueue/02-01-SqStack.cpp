
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10 
#define ElemType int 

typedef struct{
    ElemType data[MaxSize];
    int top ;
}SqStack;

bool InitStack(SqStack &S);
bool DestoryStack(SqStack &S);
bool StackEmpty(SqStack S);
bool StackLen(SqStack S);
bool Push(SqStack &S, ElemType x);
bool Pop(SqStack &S, ElemType &x); 
bool GetTop(SqStack S, int &x);

bool InitStack(SqStack &S){
   S.top = -1 ;
}
bool DestoryStack(SqStack &S){
    S.top =-1 ;
}
bool StackEmpty(SqStack S){
    if (S.top == -1){
        return true ;
    }
    return false;
}
bool StackFull(SqStack S){
    if (S.top +1 == MaxSize){
        return true ;
    }
    return false;
}
bool StackLen(SqStack S){
    return S.top +1; 
}
bool Push(SqStack &S, ElemType x){
    if (S.top+1 >= MaxSize){
        return false;
    }
    S.data[S.top+1] = x ;
    S.top +=1;
}
bool Pop(SqStack &S, ElemType &x){
    if (S.top ==-1){
        return false; 
    }
    x = S.data[S.top];
    S.top -=1;
    return true ;
}
bool GetTop(SqStack S, int &x){
    if (S.top ==-1){
        return false; 
    }
    x = S.data[S.top];
    return true  ;
}
void PrintStack(SqStack S) {
    printf("从栈顶元素开始，栈如下：\n");
    int x ;
    int top = S.top ;
    while (top !=-1){
        printf("%d\t",S.data[top]);
        top-=1;
    }
   
    printf("\n栈打印完毕\n");
}

int Test(){
    SqStack  S;
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
    Pop(S,x);
    if(GetTop(S,x)) {
        printf("顶部元素是%d\n", x);
    }else{
        printf("顶部元素获取失败\n");
    }
}


int main(){
    Test();
}
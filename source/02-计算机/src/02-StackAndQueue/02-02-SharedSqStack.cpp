
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10 
#define ElemType int 

typedef struct{
    ElemType data[MaxSize];
    int top_left ;
    int top_right;
}SharedSqStack;

bool InitStack(SharedSqStack &S);
bool DestoryStack(SharedSqStack &S);
bool StackEmpty(SharedSqStack S);
int StackLen(SharedSqStack S);
bool Push(SharedSqStack &S, ElemType x);
bool Pop(SharedSqStack &S, ElemType &x); 
bool GetTop(SharedSqStack S, int &x);

bool InitStack(SharedSqStack &S){
   S.top_left = -1 ;
   S.top_right = MaxSize;
}
bool DestoryStack(SharedSqStack &S){
    S.top_left = -1 ;
    S.top_right = MaxSize;
}
bool StackEmpty_Left(SharedSqStack S){
    if (S.top_left == -1 ){
        return true ;
    }
    return false;
}
bool StackEmpty_Right(SharedSqStack S){
    if (S.top_right == MaxSize ){
        return true ;
    }
    return false;
}
bool StackEmpty(SharedSqStack S){
    if (StackEmpty_Left(S) && StackEmpty_Right(S)){
        return true ;
    }
    return false;
}
bool StackFull(SharedSqStack S){
    if (S.top_right - S.top_left ==1){
        return true ;
    }
    return false;
}
int StackLen(SharedSqStack S){
    return MaxSize - (S.top_right-S.top_left)+1;
}
bool Push_Left(SharedSqStack &S, ElemType x){
    if (StackLen(S)>=MaxSize){
        return false;
    }
    S.data[S.top_left+1] = x ;
    S.top_left +=1;
    return true;
}
bool Push_Right(SharedSqStack &S, ElemType x){
    if (StackLen(S)>=MaxSize){
        return false;
    }
    S.data[S.top_right-1] = x ;
    S.top_right -=1;
    return true;
}
bool Pop_Left(SharedSqStack &S, ElemType &x){
    if (StackEmpty_Left(S)){
        return false; 
    }
    x = S.data[S.top_left];
    S.top_left -=1;
    return true ;
}
bool Pop_Right(SharedSqStack &S, ElemType &x){
    if (StackEmpty_Right(S)){
        return false;
    }
    x = S.data[S.top_right];
    S.top_right +=1;
    return true ;
}
bool GetTop_Left(SharedSqStack S, int &x){
    if (StackEmpty_Left(S)){
        return false; 
    }
    x = S.data[S.top_left];
    return true  ;
}
bool GetTop_Right(SharedSqStack S, int &x){
    if (StackEmpty_Right(S)){
        return false;
    }
    x = S.data[S.top_right];
    return true  ;
}
void PrintStack(SharedSqStack S) {
    printf("左侧栈如下：");

    int top_left = S.top_left ;
    while (top_left !=-1){
        printf("%d\t",S.data[top_left]);
        top_left-=1;
    }
   
    printf("\t左栈打印完毕\n");

    printf("右侧栈如下：");

    int top_right = S.top_right ;
    while (top_right !=MaxSize){
        printf("%d\t",S.data[top_right]);
        top_right+=1;
    }

    printf("\t右栈打印完毕\n");
}

int Test(){
    SharedSqStack  S;
    int x;
    InitStack(S);
    printf("是否是空的: %d\n",StackEmpty(S));
    for (int i=0;i<5;i++){
        Push_Left(S,i+1);
    }
    for (int i=5;i<10;i++){
        Push_Right(S,i+1);
    }
    printf("len=%d\n",StackLen(S));
    printf("是否是满的: %d\n",StackFull(S));
    PrintStack(S);
    Pop_Left(S,x);
    printf("是否是满的: %d\n",StackFull(S));
    PrintStack(S);
    Pop_Right(S,x);
    PrintStack(S);
//    PrintStack(S);
//    Push(S,2);
//    Pop(S,x);
//    Push(S,3);
//    PrintStack(S);
//    PrintStack(S);
    if(GetTop_Left(S,x)) {
        printf("顶部元素是%d\n", x);
    }else{
        printf("顶部元素获取失败\n");
    }
//    Pop(S,x);
//    Pop(S,x);
    Pop_Right(S,x);
    Pop_Right(S,x);
    Pop_Right(S,x);
    Pop_Right(S,x);
    if(GetTop_Right(S,x)) {
        printf("顶部元素是%d\n", x);
    }else{
        printf("顶部元素获取失败\n");
    }
}


int main02(){
    Test();
}
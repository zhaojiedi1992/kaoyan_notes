#include <stdio.h>
#define MaxSize 100

typedef struct 
{
   int data[MaxSize];
   int length;
} SqList;

// 初始化
void InitList(SqList &L) ; 
// 判断是否为空
bool Empty(SqList L);                              
// 获取长度
// 获取特定index 的值
int GetElem(SqList L, int idx) ;
// 查找特定值的index
int LocateElem(SqList L, int val) ;
// 插入
bool ListInsert(SqList &l, int idx , int val);
// 删除
//删除
bool ListDelete(SqList &L, int idx, int &e) ;

void InitList(SqList &L) {
    for (int i=0; i<MaxSize; i++){
        L.data[i] =0;
    }
    L.length = 0 ;
}

bool Empty(SqList L){
    if (L.length ==0){
        return true;
    }
    return false;
}

int GetElem(SqList L, int idx) {
    if (idx <0 || idx >L.length){
        return -1;
    }
    return L.data[idx-1] ;
}

int LocateElem(SqList L, int val){
    for (int i =0 ;i<L.length;i++){
        if (val == L.data[i]){
            return i+1;
        }
    }
    return 0 ;
}

bool ListInsert(SqList &L, int idx , int val){
    if (idx <1 || idx >L.length+1){
        return false;
    }
    if ( L.length >=MaxSize ){
        return false ;
    }
    for (int i=L.length;i>=idx ;i--){
        L.data[i] = L.data[i-1] ;
    }
    L.data[idx-1] = val ; 
    L.length +=1 ;
    return true ;
}
bool ListDelete(SqList &L, int idx, int &e) {
    if (idx <1 || idx >L.length){
        return false ;
    }
    e = L.data[idx-1] ;
    for (int i=idx; i<L.length;i++){
        L.data[i-1]= L.data[i] ;
    }
    L.length -=1 ;
    return true ;

}

void PrintSqList(SqList L) {
    //循环打印
    printf("开始打印顺序表\n");
    for (int i = 0; i < L.length; i++) {
        printf("Data[%d]==%d\n", i, L.data[i]);
    }
    printf("打印结束！\n");
}


void TestSqList() {
    SqList L;
    InitList(L);

//    初试化一些值
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;

    //插入操作
    if (ListInsert(L, 2, 3)) {
        printf("插入成功了\n");
    } else {
        printf("插入失败了，i的位置不合法，请检查\n");
    }

    PrintSqList(L);
    //删除操作
    int e = -1;
    if (ListDelete(L, 2, e)) {
        printf("删除成功！删除的值是：%d\n", e);
    } else {
        printf("删除失败，请检查位序是否正确\n");
    }

    //数组当前长度
    printf("数组当前长度是多少？%d\n", L.length);

    //查找第一个元素是什么？
    printf("第一个元素是什么？\n %d\n", GetElem(L, 1));

    //查找值为3的元素在什么位置
    printf("第一个值为3的元素在什么位置？\n %d \n", LocateElem(L, 3));

    //打印输出

    PrintSqList(L);

}

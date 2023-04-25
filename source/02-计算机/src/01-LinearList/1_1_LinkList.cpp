#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

#define ElemType int 

typedef struct LNode
{
   ElemType data ; 
   LNode *next ; 
} LNode,*LinkList;

// 初始化
bool InitList(LinkList &L) ; 
// 判断是否为空
bool Empty(LinkList L);                              
// 获取长度
// 获取特定index 的值
ElemType GetElem(LinkList L, int idx) ;
// 查找特定值的index
int LocateElem(LinkList L, ElemType val) ;
// 插入
bool ListInsert(LinkList &l, int idx , int val);
// 删除
//删除
bool ListDelete(LinkList &L, int idx, int &e) ;

bool InsertPriorNode(LNode *p, int e) ;
bool InsertNextNode(LNode *p, int e) ;



bool InitList(LinkList &L) {
    L =  (LNode *) malloc(sizeof(LNode));
    if (L == NULL){
        return false;
    }
    L->next = NULL;
    return true;
}
// 判断是否为空
bool Empty(LinkList L){
    if (L==NULL){
        return true ;
    }
    if (L->next ==NULL){
        return true ; 
    }
    return false ;
}                              
// 获取长度
// 获取特定index 的值
ElemType GetElem(LinkList L, int idx){
    LinkList cur = L ;
    int cnt =0 ;
    while (cur && cnt <idx)
    {
       cur=cur->next;
       cnt+=1;
    }
    if (cur ==NULL){
        return -1 ; 
    }
    return cur->data;
    
}
// 查找特定值的index
int LocateElem(LinkList L, ElemType val){
    LinkList cur = L ; 
    int idx =0 ; 
    while (cur && cur->data != val){
            cur=cur->next; 
            idx +=1;
    }
    if (cur == NULL){
        return 0;
    }
    return idx ;

}
// 插入
bool ListInsert(LinkList &L, int idx , int val){
    LinkList  cur = L ;
    int cnt = 1 ;
    while (cnt<idx){
        cnt+=1;
        cur = cur->next;
    }
    LNode *node = (LNode*) malloc(sizeof(LNode));
    if (node == NULL){
        return false;
    }
    node->next = NULL;
    node->data = val ;

    node->next = cur->next ;
    cur->next = node ;
    return true ;
}
// 删除
//删除
bool ListDelete(LinkList &L, int idx, int &e) {
    LinkList  cur = L ;
    int cnt = 1 ;
    while (cur &&  cnt<idx){
        cnt+=1;
        cur = cur->next;
    }
    if (cur->next     == NULL){
        return false ;
    }
    e = cur->next->data ;
    LNode *node  = cur->next ;
    cur->next = cur->next->next;
    free(node) ;
    return true ;
}
int ListLen(LinkList L){
    int cnt =0;
    LinkList  cur = L->next;
    while (cur){
        cnt +=1 ;
        cur = cur->next;
    }
    return cnt ;
}
void PrintList(LinkList L) {
    //循环打印
    printf("开始打印顺序表\n");
    LinkList cur  = L->next ;
    while (cur !=NULL){
        printf("%d\t",cur->data);
        cur = cur->next;
    }
    printf("打印结束！\n");
}
bool InsertPriorNode(LNode *p, int e){
    if (p == NULL){
        return false;
    }
    LNode *node = (LNode *) malloc(sizeof(LNode)) ;
    if (node == NULL){
        return false;
    }
    node->data = e ;
    node->next = p->next;
    p->next = node ;
    return true ;
}
bool InsertNextNode(LNode *p, int e) {
    if (p == NULL){
        return false;
    }
    LNode *node = (LNode *) malloc(sizeof(LNode)) ;
    if (node == NULL){
        return false;
    }
    node->next = p->next ;
    p->next = node ;
    node->data = p->data;
    p->data = e ;
    return true ;
    
}

void Test_LinkList() {
    LinkList L;
    InitList(L);

//    初试化一些值
    ListInsert(L,1,1);
    ListInsert(L,1,2);
    ListInsert(L,1,3);
    ListInsert(L,1,4);
    PrintList(L);
    printf("%d",ListLen(L));
    //插入操作
    if (ListInsert(L, 2, 10)) {
        printf("插入成功了\n");
        PrintList(L);
    } else {
        printf("插入失败了，i的位置不合法，请检查\n");
    }

    //删除操作
    int e = -1;
    if (ListDelete(L, 2, e)) {
        printf("删除成功！删除的值是：%d\n", e);
    } else {
        printf("删除失败，请检查位序是否正确\n");
    }
    //删除操作
    PrintList(L);
    if (ListDelete(L, ListLen(L)+1, e)) {
        printf("删除成功！删除的值是：%d\n", e);
    } else {
        printf("删除失败，请检查位序是否正确\n");
    }
    //数组当前长度
    PrintList(L);
    printf("数组当前长度是多少？%d\n", ListLen(L));

    //查找第一个元素是什么？
    printf("第一个元素是什么？\n %d\n", GetElem(L, 1));

    //查找值为3的元素在什么位置
    printf("第一个值为3的元素在什么位置？\n %d \n", LocateElem(L, 3));

    //打印输出

    PrintList(L);


}

int main(){
    Test_LinkList();
}
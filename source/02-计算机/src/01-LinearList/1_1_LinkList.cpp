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
LNode* GetElem(LinkList L, int i) ;
// 查找特定值的index
LNode* LocateElem(LinkList L, ElemType val) ;
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
    if (L->next ==NULL){
        return true ; 
    }
    return false ;
}                              
// 获取长度
// 获取特定index 的值
LNode* GetElem(LinkList L, int i){
    if (i<=0){
        return NULL;
    }
    LinkList p = L ;
    int j =0 ;
    while (p && j <i)
    {
        p=p->next;
       j+=1;
    }
    return p ;
    
}
// 查找特定值的index
LNode* LocateElem(LinkList L, ElemType val){
    LinkList p = L->next ;
    while (p!=NULL && p->data != val){
            p=p->next;
    }
    return p ;

}
// 插入
bool ListInsert(LinkList &L, int idx , int val){
    LNode *p = GetElem(L,idx-1);
    if (p==NULL){
      return false;
    }

    return InsertNextNode(p,val) ;
}
// 删除
//删除
bool ListDelete(LinkList &L, int i, int &e) {
    LNode *p = GetElem(L,i-1);
    if (p==NULL){
        return false;
    }
    if (p->next ==NULL){
        return false;
    }
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q) ;
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
    LNode *s = (LNode *) malloc(sizeof(LNode)) ;
    if (s == NULL){
        return false;
    }
    s->next = p->next ; 
    p->next =s ; 

    s->data =p->data ; 
    p->data =e ; 
    return true ;
}
bool InsertNextNode(LNode *p, int e) {
    if (p == NULL){
        return false;
    }
    LNode *s = (LNode *) malloc(sizeof(LNode)) ;
    if (s == NULL){
        return false;
    }
    s->data = e ; 
    s->next = p->next ;
    p->next = s ;
    return true ;
}

LinkList List_HeadInsert(LinkList &L){
    int x ; 
    LNode *s ; 
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d",x);
    while (x !=9999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data =x ; 
        s->next = L->next ; 
        L->next = s ; 
       scanf("%d",x);
    }
    return L ; 
}
LinkList List_TailInsert(LinkList &L){
    int x ; 
    LNode *r , *s; 
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    r = L ; 
    scanf("%d",&x) ;
    while(x!=9999){
        s = (LNode*)malloc(sizeof(LNode));
        if (s==NULL){
            //destroy
            return NULL;
        }
        s ->data = x ; 
        r->next = s ; 
        r =s ;
        scanf("%d",&x) ;
    }
    r->next = NULL;
    return L ; 
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

    List_TailInsert(L);
    PrintList(L);

}

int main(){
    Test_LinkList();
}
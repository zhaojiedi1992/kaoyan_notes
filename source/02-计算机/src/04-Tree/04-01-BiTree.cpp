#include <stdio.h>
#include <stdlib.h>

/***定义模块*/
struct ElemType {
    int value;
};

typedef struct BiTNode {
    ElemType data;//数据域
    struct BiTNode *lchild, *rchild;//左右孩子指针
} BiTNode, *BiTree;

void InitTree(BiTree root){
//    root = (BiTree)malloc(sizeof(BiTNode));
//    ElemType e = {1};
//    root->data = e;
//    root->lchild=NULL;
//    root->rchild =NULL;

}
////插入新结点
//bool InsertNode(BiTree T, int val) {
//    BiTNode  *p = (BiTNode*) malloc(sizeof(BiTNode));
//    if (p==NULL){
//        return false;
//    }
//    ElemType e = {val};
//    p->data=e;
//    p->lchild =NULL;
//    p->rchild =NULL;
//    T->lchild=p ;
//    return true ;
//}
void visit(BiTree T){
    printf("%d\t",T->data.value);
}
void PreOder(BiTree T) {
    if (T ==NULL){
        return ;
    }
    visit(T);
    PreOder(T->lchild);
    PreOder(T->rchild);
}
void InOder(BiTree T) {
    if (T ==NULL){
        return ;
    }

    InOder(T->lchild);
    visit(T);
    InOder(T->rchild);
}
void PostOder(BiTree T) {
    if (T ==NULL){
        return ;
    }

    PostOder(T->lchild);
    PostOder(T->rchild);
    visit(T);
}
void Test01(){
    BiTNode  *n1 = (BiTNode*) malloc(sizeof(BiTNode));

    n1->data.value=1;
    n1->lchild=NULL;
    n1->rchild =NULL;

    BiTNode  *n2 = (BiTNode*) malloc(sizeof(BiTNode));

    n2->data.value=2;
    n1->lchild=NULL;
    n1->rchild =NULL;

    BiTNode  *n3 = (BiTNode*) malloc(sizeof(BiTNode));
    n3->data.value=3;
    n1->lchild=NULL;
    n1->rchild =NULL;

    BiTNode  *n4 = (BiTNode*) malloc(sizeof(BiTNode));
    n4->data.value=4;
    n1->lchild=NULL;
    n1->rchild =NULL;

    BiTNode  *n5 = (BiTNode*) malloc(sizeof(BiTNode));

    n5->data.value=5;
    n1->lchild=NULL;
    n1->rchild =NULL;

    n1->lchild =n2 ;
    n1->rchild=n3;
    n2->lchild =n4 ;
    n4->rchild=n5;

    PreOder(n1);
}


int main(){
    Test01();
}
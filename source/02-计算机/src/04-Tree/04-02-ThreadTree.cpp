#include <stdio.h>
#include <stdlib.h>

/***定义模块*/
struct ElemType {
    int value;
};


void PostThread(ThreadTree pNode, ThreadTree pNode1);

typedef struct ThreadNode{
    ElemType data;
    ThreadNode *lchild,*rchild;
    int ltag ,rtag;
}ThreadNode ,*ThreadTree;

void InThread(ThreadTree p, ThreadTree &pre){
    if (p==NULL){
        return ;
    }
    InThread(p->lchild,pre);
    if (p->lchild ==NULL){
        p->lchild = pre;
        p->ltag =1;
    }
    if (pre!=NULL && pre->rchild ==NULL){
        pre->rchild = p ;
        pre->rtag =1 ;
    }
    pre =p ;
    InThread(p->rchild,pre);
}
void PreThread(ThreadTree p , ThreadTree &pre){
   if (p==NULL){
       return ;
   }
    if (p->lchild ==NULL){
        p->lchild = pre ;
        p->ltag =1 ;
    }
    if (pre!=NULL && pre->rchild ==NULL){
        pre->rchild = p ;
        pre->rtag =1 ;
    }
    pre = p;
    if (p->ltag==0){
        PreThread(p->lchild,pre);
    }
    if (p->rtag==0){
        PreThread(p->rchild,pre);
    }


}
//void PreThread(ThreadTree p, ThreadTree &pre) {
//    if (p != NULL) {
//        if (p->lchild == NULL) {
//            p->lchild = pre;
//            p->ltag = 1;
//        }
//        if (pre != NULL && pre->rchild == NULL) {
//            pre->rchild == p;//建立前驱结点的后及线索
//            pre->rtag = 1;
//        }
//        pre = p;
//        if (0 == p->ltag) {
//            PreThread(p->lchild, pre);
//        }
//        PreThread(p->rchild, pre);
//    }
//}


void CreateInThread(ThreadTree T){

    if (T==NULL){
        return ;
    }
    ThreadTree  pre = NULL;
    InThread(T,pre);
    if (pre->rchild == NULL) {
        pre->rchild=NULL;
        pre->rtag =1;
    }

}
void CreatePreThread(ThreadTree T){
    if (T==NULL){
        return ;
    }
    ThreadTree  pre = NULL;
    PreThread(T,pre);
    if (pre->rchild == NULL) {
        pre->rtag =1;
    }
}

void PostThread(ThreadTree p, ThreadTree &pre) {
    if (p==NULL){
        return ;
    }
    PostThread(p->lchild,pre);
    PostThread(p->rchild,pre);
    if (p->rchild ==NULL){
        p->rchild = pre;
        p->rtag =1;
    }
    if (pre!=NULL && pre->rchild==NULL){
        pre->rchild = p ;
        pre->rtag = 1;
    }
    pre = p ;
}
void CreatePostThread(ThreadTree T){
    if (T==NULL){
        return ;
    }
    ThreadTree  pre = NULL;
    PostThread(T,pre);
    if (pre->rchild == NULL) {
        pre->rtag =1;
    }

}


ThreadNode* InFirstNode(ThreadTree p){
    while(p->ltag==0){
        p=p->lchild;
    }
    return p ;
}
ThreadNode* InNextNode(ThreadTree p){
    if (p->rtag ==0){
        return InFirstNode(p->rchild);
    }
    return p->rchild;
}
void InOrder(ThreadTree T){
    printf("中序遍历\t");
    for (ThreadNode *p= InFirstNode(T);p!=NULL;p= InNextNode(p)){
        printf("%d\t",p->data.value);
    }
    printf("\n");
}

ThreadNode* PreFirstNode(ThreadTree p){
    return p ;
}
ThreadNode* PreNextNode(ThreadTree p){
    if (p->ltag ==0){
        return p->lchild;
    }
    if (p->rtag==0){
        return p->rchild;
    }
    return p->rchild;
}
void PreOrder(ThreadTree T){
    printf("先序遍历\t");
    for (ThreadNode *p= PreFirstNode(T);p!=NULL;p= PreNextNode(p)){
        printf("%d\t",p->data.value);
    }
    printf("\n");
}



//ThreadNode* PostFirstNode(ThreadTree p){
//    while (p!=NULL&& p->ltag ==0){
//        p=p->lchild;
//    }
//    return p ;
//}
//ThreadNode* PostNextNode(ThreadTree p){
//    if (p->rtag==0){
//        return PostNextNode(p->)
//    }
//    return p->rchild;
//}

//void PostOrder(ThreadTree T){
//    printf("后序遍历\t");
//    for (ThreadNode *p= PostFirstNode(T);p!=NULL;p= PostNextNode(p)){
//        printf("%d\t",p->data.value);
//    }
//    printf("\n");
//}

ThreadTree InitDemoTree(){
    //                    1
//
//                2     3
//            4
//               5
    ThreadNode  *n1 = (ThreadNode*) malloc(sizeof(ThreadNode));

    n1->data.value=1;
    n1->lchild=NULL;
    n1->rchild =NULL;
    n1->ltag =0;
    n1->rtag=0;


    ThreadNode  *n2 = (ThreadNode*) malloc(sizeof(ThreadNode));

    n2->data.value=2;
    n2->lchild=NULL;
    n2->rchild =NULL;
    n2->ltag =0;
    n2->rtag=0;

    ThreadNode  *n3 = (ThreadNode*) malloc(sizeof(ThreadNode));
    n3->data.value=3;
    n3->lchild=NULL;
    n3->rchild =NULL;
    n3->ltag =0;
    n3->rtag=0;

    ThreadNode  *n4 = (ThreadNode*) malloc(sizeof(ThreadNode));
    n4->data.value=4;
    n4->lchild=NULL;
    n4->rchild =NULL;
    n4->ltag =0;
    n4->rtag=0;

    ThreadNode  *n5 = (ThreadNode*) malloc(sizeof(ThreadNode));
    n5->data.value=5;
    n5->lchild=NULL;
    n5->rchild =NULL;
    n5->ltag =0;
    n5->rtag=0;


    n1->lchild =n2 ;
    n1->rchild=n3;
    n2->lchild =n4 ;
    n4->rchild=n5;
    return n1;
}
void Test02(){

    printf("start\n");
    ThreadTree n1 ;

//    n1 = InitDemoTree();
//    CreateInThread(n1);
//    InOrder(n1);

//    n1 = InitDemoTree();
//    CreatePreThread(n1);
//    PreOrder(n1);

    n1 = InitDemoTree();
    CreatePostThread(n1);
    PostOrder(n1);

}

int main(){
    Test02();
}
// 并查集
//#define ElemType int
#define Max_Size 100

//typedef struct PTNode{
//    ElemType data ;
//    int parent ;
//}PTNode;
//
//typedef struct  PTree{
//    PTNode nodes[Max_Size];
//    int n  ;
//}PTree;

int UFSets[Max_Size] ;

void InitUFSet(int S[]);
int Find(int  S[],int x );
void Union(int  S[],int root1,int root2);

void InitUFSet(int S[]){
    for (int i=0;i<Max_Size;i++){
        S[i]=-1;
    }
}
int Find(int  S[],int x ){
    while (S[x]>=0){
        x = S[x];
    }
    return x ;
}

void Union(int  S[],int root1,int root2){
   if (root1 == root2){
       return ;
   }
   S[root1] = root2;
}
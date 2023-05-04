#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef  struct {
    char ch[MaxSize] ;
    int length ;
}SString;

bool InitStr(SString &S);
int StrLength(SString S);

bool InitStr(SString &S){
    S.ch[1] = '\0';
    S.length = 0 ;
    return true ;
}

//获取字符串长度
int StrLength(SString S) {
    return S.length;
}
bool StrAssign(SString &S , char *str, int strLength){
    for (int i=0; i<strLength;i++){
        S.ch[i+1] = str[i];
    }
    S.length = strLength;
    return true ;
}
// 普通的index匹配方法
bool Index(SString S, SString T,int next[]){
    int i =1 ;
    int j =1 ;
    while(i<=StrLength(S)&& j<= StrLength(T)){
        if (S.ch[i]==T.ch[j]){
            i+=1;
            j+=1;
        }else{
            j=1;
            i=i-j+2;
        }

    }
    if (j> StrLength(T)){
        return i- StrLength(T);
    }
    return 0 ;
}
// 普通的index匹配方法
bool Index_KMP(SString S, SString T,int next[]){
    int i =1 ;
    int j =1 ;
    while(i<=StrLength(S)&& j<= StrLength(T)){
        if (j==0){
            i+=1;
            j+=1;
        }
        if (S.ch[i]==T.ch[j]){
            i+=1;
            j+=1;
        }else{
            j=next[j];
            //i=i-j+2;
        }

    }
    if (j> StrLength(T)){
        return i- StrLength(T);
    }
    return 0 ;
}
//求模式串T的next数组
void getNext(SString T, int *next) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            ++i;
            ++j;
            //如果pi=pj，则next[j+1]=next[j]+1
            next[i] = j;
        } else {
            //否则令j=next[j],循环继续
            j = next[j];
        }
    }
}
void getNextVal(SString T, int *betternext){
    int i = 1, j = 0;
    int next[T.length + 1];
    getNext(T,next);
    betternext[1]=0;
    for (j=2;j<= StrLength(T);j++){
        if (T.ch[next[j]] == T.ch[j]){
            betternext[j] = betternext[next[j]];
        }else{
            betternext[j] = next[j];
        }
    }
}
void print_array(int* next,int cnt){
    for (int i=1;i<=cnt;i++){
        printf("%d\t",next[i]);
    }
}

int Test02(){
    SString  S;
    InitStr(S);
    char *p = (char *)"ababaaababaa";
    StrAssign(S,p,12);
    int *next =(int*) malloc(sizeof(int)* (StrLength(S)+1));
    getNext(S,next);
    print_array(next,StrLength(S));
    return 0;
}

int main(){
    Test02();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef  struct {
    char ch[MaxSize] ;
    int length ;
}SString;

bool InitStr(SString &S);
bool StrAssign(SString &S , char *str, int strLength);
void StrCopy(SString &T ,SString S) ;
bool StrEmpty(SString S);
bool StrLength(SString S);
bool StrCompare(SString S ,SString T) ;
bool StrConcat(SString &T, SString S1, SString S2);
int Index(SString S, SString T);
void ClearStr(SString &S);
bool SubString(SString &Sub, SString S, int pos, int len);



bool InitStr(SString &S){
    S.ch[1] = '\0';
    S.length = 0 ;
    return true ;
}
bool StrAssign(SString &S , char *str, int strLength){
    for (int i=0; i<strLength;i++){
        S.ch[i+1] = str[i];
    }
    S.length = strLength;
}
void StrCopy(SString &T ,SString S) {
    for (int i=1;i<=S.length;i++){
        T.ch[i]= S.ch[i];
    }
    T.length = S.length;
}
bool StrEmpty(SString S){
    if (S.length==0){
        return true ;
    }
    return false;
}
bool StrLength(SString S){
    return S.length;
}
bool StrCompare(SString S ,SString T) {
    for (int i=1;i<=S.length&&i<=T.length;i++){
        if (S.ch[i]!=T.ch[i]){
            return S.ch[i]-T.ch[i];
        }
    }
    return S.length - T.length;
}
bool StrConcat(SString &T, SString S1, SString S2){

    for (int i=1;i<=S1.length;i++){
        T.ch[i] = S1.ch[i];
    }
    for (int i=1;i<=S2.length;i++){
        T.ch[i+S1.length] = S2.ch[i];
    }
    T.length = S1.length + S2.length ;
    return true ;
}
int Index(SString S, SString T){
    SString sub;
    int i=1 ;
    while (i <= S.length - T.length + 1) {
        SubString(sub, S, i, T.length);
        if (StrCompare(sub,T)==0){
            return i ;
        }
        i+=1;
    }
    return 0;
}
void ClearStr(SString &S){
    S.length =0 ;
}
void StrPrint(SString S){
    for (int i=1; i<=S.length;i++){
        printf("%c",S.ch[i]);
    }
    printf("\n");
}
bool SubString(SString &Sub, SString S, int pos, int len){
    if (pos+len-S.length >0){
        return false;
    }
    for (int i=pos;i<pos+len;i++){
        Sub.ch[i-pos+1] = S.ch[i];
    }
    Sub.length = len;
    return true ;
}

int Test01(){
    printf("开始测试！\n");

    SString S, T,R;
    InitStr(S);
    InitStr(T);

    StrAssign(S,"abcdef",6);
    StrAssign(T,"de",2);
    StrPrint(S);
    StrPrint(T);
    printf("大小比较%d\n", StrCompare(S,T));
    SubString(R,S,2,3);
    StrPrint(R);
    int index = Index(S,T);
    printf("index=%d\n",index);
    StrConcat(S,T,T);
    StrPrint(S);
    printf("测试结束!\n");
    return 1;
}

int main01(){
    Test01();
}
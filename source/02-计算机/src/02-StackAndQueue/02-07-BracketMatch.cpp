
#include "02-03-LinkStack.cpp"

bool bracketCheck(char *str, int length) {
    LinkStack  s ;
    InitStack(s);
    for (int i=0;i<length;i++){
        if (str[i]=='(' || str[i]=='[' || str[i]=='{'){
            Push(s,str[i]);
            continue;
        }
        if (StackEmpty(s)){
            return false;
        }
        int x ;
        Pop(s,x);
        if (str[i]==')' && x!='('){
            return false;
        }
        if (str[i]==']' && x!='['){
            return false;
        }
        if (str[i]=='}' && x!='{'){
            return false;
        }
    }
    return StackEmpty(s);
}

int main(){
    printf("%d\n",bracketCheck("()",2));
    printf("%d\n",bracketCheck("(",1));
    printf("%d\n",bracketCheck("(()())",6));
    printf("%d\n",bracketCheck("(()()))",7));
    printf("%d\n",bracketCheck("[()]",4));
}
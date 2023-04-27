#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

#define ElemType int 

typedef struct 
{
   ElemType data ; 
   int  next ; 
}CDLinkList[MaxSize];
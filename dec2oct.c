#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef int ElemType;
typedef struct
{

	ElemType *base;
	ElemType *top;
	int stackSize;

}sqStack;


void InitStack(sqStack *S)
{
	S->base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!S->base)
	{exit(0);
	}
	S->top=S->base;
	S->stackSize= STACK_INIT_SIZE;

}

void Push(sqStack *S,ElemType e)
{if(S->top-S->base>S->stackSize)
	{S->base=(ElemType*)realloc(S->base,(S->stackSize+STACKINCREMENT)*sizeof(ElemType));
		if(!S->base) exit(0);
		S->top=S->base+S->stackSize;
		S->stackSize+=STACKINCREMENT;
	}
	*S->top=e;
S->top++;
}

void Pop(sqStack *S,ElemType *e)
{
	if(S->top==S->base)
	{return;}
	*e=*--(S->top);
}



int main()
{int e;
ElemType N;
sqStack S;
InitStack(&S);
printf("请输入10进制数：");
scanf("%d",&N);

while(N)
	{Push(&S,N%8);
	N=N/8;}
	
	while(S.base!=S.top)
	{Pop(&S,&e);
	printf("%d",e);
	}

	return 0;

}
	
	
	
	
	

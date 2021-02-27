#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
struct Stack{
    int size;
    int num;
    int *stk;
};

void Initialize(Stack *s,int size)
{
    s->stk = (int*)malloc(sizeof(int)*size);
    s->num = 0;
    s->size = size;
}

int Push(Stack *s,const int *x)
{
    if(s->size <= s->num) return -1;
    s->stk[s->num++] = *x;
    return 0;
}

int Pop(Stack *s)
{
    if(s->num <= 0) return -1;
    return s->stk[--s->num];
}

int Size(const Stack *s)
{
    return s->num;
}

int Empty(const Stack *s)
{
    return s->num <= 0 ? 1 : 0;
}

int Top(const Stack *s)
{
    if(Empty(s)) return -1;
    return s->stk[s->num-1];
}

int main()
{   
    int N,x,s; char str[15]; Stack A;
    scanf("%d",&N); Initialize(&A,N);

    while(N--)
    {
        scanf("%s",str);

        if(!strcmp(str,"push"))
        {
            scanf("%d",&x);
            Push(&A,&x);
        }
        else if(!strcmp(str,"pop")) printf("%d\n",Pop(&A));
        else if(!strcmp(str,"size")) printf("%d\n",Size(&A));
        else if(!strcmp(str,"empty")) printf("%d\n",Empty(&A));
        else printf("%d\n",Top(&A));
    }
    return 0;
}


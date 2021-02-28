#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
struct Queue{
    int size;
    int num;
    int front;
    int rear;
    int *que;
};

void Initialize(Queue *q,int size)
{
    q->que = (int*)malloc(sizeof(int)*size);
    q->num = q->front = q->rear = 0; q->size = size;
}

int Push(Queue *q,const int *x)
{
    if(q->num >= q->size) return -1;
    q->num++;
    q->que[q->rear++] = *x;
    if(q->rear == q->size) q->rear = 0;
    return 0;
}

int Pop(Queue *q)
{
    if(q->num <= 0) return -1;
    q->num--; int t;
    t = q->que[q->front++];
    if(q->front == q->size) q->front = 0;
    return t;
}

int Size(const Queue *q)
{
    return q->num;
}

int Empty(const Queue *q)
{
    return q->num <= 0 ? 1 : 0;
}

int Front(const Queue *q)
{
    if(Empty(q)) return -1;
    return q->que[q->front];
}

int Back(const Queue *q)
{
    if(Empty(q)) return -1;
    
    if(q->rear == 0) return q->que[q->size-1];
    return q->que[q->rear-1];
}

int main()
{
    int N,x; char str[15]; Queue A;
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
        else if(!strcmp(str,"front")) printf("%d\n",Front(&A));
        else printf("%d\n",Back(&A));
    }
    return 0;
}

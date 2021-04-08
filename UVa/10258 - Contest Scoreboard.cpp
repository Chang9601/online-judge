#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int T;
int c,p,t;
char L;
char s[100];
struct Contestant{
    int num,cnt,t;
};

void deleteNewline(char s[])
{
    int i = 0;
    while(s[i] != '\n') i++;
    s[i] = '\0';
}

int cmp(const Contestant *a,const Contestant *b)
{
    if((*a).cnt != (*b).cnt)
        return -1*((*a).cnt-(*b).cnt);
    if((*a).t != (*b).t)
        return (*a).t-(*b).t;
    return (*a).num-(*b).num;
}

int main()
{
    scanf("%d",&T);
    getchar(); getchar();
    while(T--)
    {
        int i,j,idx = 0; 
        int problem[101][10] = {}; Contestant A[101];
        bool solved[101][10] = {}; bool in[101] = {};
        memset(A,0,sizeof(A)); 
        while(fgets(s,sizeof(s),stdin))
        {
            deleteNewline(s);
            if(!strcmp(s,"")) break;
            sscanf(s,"%d %d %d %c",&c,&p,&t,&L);
            in[c] = true;

            if(solved[c][p]) continue;

            if(L == 'C')
            {
                solved[c][p] = true;
                problem[c][p] += t;
            }
            else if(L == 'I')
                problem[c][p] += 20;
        }

        for(i = 1; i <= 100; i++)
        {
            if(!in[i]) continue;
            A[idx].num = i;
            for(j = 1; j <= 9; j++)
                if(solved[i][j])
                {
                    A[idx].t += problem[i][j];
                    A[idx].cnt++;
                }
            idx++;
        }

        qsort(A,idx,sizeof(Contestant),(int(*)(const void*,const void*))cmp);
        for(i = 0; i < idx; i++)
            printf("%d %d %d\n",A[i].num,A[i].cnt,A[i].t);
        if(T) putchar('\n');
    }
    return 0;   
}

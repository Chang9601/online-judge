#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int N;
char s[51][105];
int cmp(const char *a,const char *b)
{
    char buf1[205] = {},buf2[205] = {};
    
    strcat(buf1,a); strcat(buf1,b);
    strcat(buf2,b); strcat(buf2,a);

    return -1*strcmp(buf1,buf2);
}

int main()
{
    while(scanf("%d",&N) == 1)
    {
        if(!N) break; int i;
        for(i = 0; i < N; i++) scanf("%s",s[i]);
        qsort(s,N,sizeof(s[0]),(int(*)(const void*,const void*))cmp);
        for(i = 0; i < N; i++)
            printf("%s",s[i]);
        putchar('\n');
    }
  
    return 0;   
}

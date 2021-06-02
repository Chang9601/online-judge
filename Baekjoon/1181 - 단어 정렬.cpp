#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
using namespace std;

int cmp(const char *a,const char *b)
{
    int la = strlen(a); int lb = strlen(b);
    
    if(la != lb)
        return la-lb;
    return strcmp(a,b);
}

int main() {
    int i,N;
    char A[20005][55];
    map<string,int> m;
    
    scanf("%d",&N);
    for(i = 0; i < N; i++)
        scanf("%s",A[i]);
        
    qsort(A,N,sizeof(A[0]),((int(*)(const void*,const void*))cmp));
    
    for(i = 0; i < N; i++)
    {
        if(m.count(A[i]))
            continue;
        m[A[i]] = 1;
        printf("%s\n",A[i]);
    }
    return 0;
}

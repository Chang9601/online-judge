#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int A[105],B[105];
char str[105];

bool is_subset(const int a[],int n1,const int b[],int n2)
{
    int i,j;
    for(i = 0; i < n1; i++)
    {
        for(j = 0; j < n2; j++)
            if(a[i] == b[j]) break;
        if(j == n2) return false;
    }
    return true;
}

bool is_inter(const int a[],int n1,const int b[],int n2)
{
    int i,j,cnt = 0;
    for(i = 0; i < n1; i++)
        for(j = 0; j < n2; j++)
            if(a[i] == b[j]) cnt++;
    
    return cnt >= 1 ? true : false;
}

int main()
{   
    while(gets(str))
    {
        char *d = strtok(str," "); int t;
        int cnt1 = 0,cnt2 = 0; int i,j;
        cnt1 = cnt2 = 0; bool subA,subB,inter;
        subA = subB = inter = false;

        while(d)
        {
            t = atoi(d);
            A[cnt1++] = t;
            d = strtok(NULL," ");
        }

        gets(str);
        d = strtok(str," ");
        while(d)
        {
            t = atoi(d);
            B[cnt2++] = t;
            d = strtok(NULL," ");
        }

        subA = is_subset(A,cnt1,B,cnt2);
        subB = is_subset(B,cnt2,A,cnt1);
        inter = is_inter(A,cnt1,B,cnt2);

        if(cnt1 == cnt2 && subA && subB) puts("A equals B");
        else if(cnt1 < cnt2 && subA) puts("A is a proper subset of B");
        else if(cnt1 > cnt2 && subB) puts("B is a proper subset of A");
        else if(!inter) puts("A and B are disjoint");
        else puts("I'm confused!");
    }

    return 0;
}

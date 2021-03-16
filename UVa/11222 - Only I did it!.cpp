#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctype.h>
#include <algorithm>
using namespace std;
int T,S,n;
int A[4][1005];
int cnt[4];
int solved[10005];
int *buf;
struct Person{
    int num,size;
    int A[1005];
};

void _merge(int arr[],int l,int h)
{
    if(l >= h) return;
    int m = l+(h-l)/2;

    _merge(arr,l,m); _merge(arr,m+1,h);

    int i,j,k = 0,p = l;
    for(i = l,j = 0; i <= m; i++) buf[j++] = arr[i];
    while(i <= h && k < j) arr[p++] = (buf[k] <= arr[i]) ? buf[k++] : arr[i++];
    while(k < j) arr[p++] = buf[k++]; 
}

void _mergeSort(int arr[],int size)
{
    buf = (int*)malloc(sizeof(int)*size);
    _merge(arr,0,size-1);
    free(buf);
}

int main()
{  
    scanf("%d",&T); int idx = 1;
    while(T--)
    {
        int i,j,k,mx,num; Person B[4];
        memset(solved,0,sizeof(solved));
        memset(A,0,sizeof(A)); memset(B,0,sizeof(B));
        mx = -1;

        for(i = 1; i <= 3; i++)
        {
            scanf("%d",&S);
            cnt[i] = S;
            for(j = 0; j < S; j++)
            {
                scanf("%d",&n);
                A[i][j] = n;
                solved[n]++;
            }
        }

        for(i = 1; i <= 3; i++)
        {
            num = 0;
            for(j = 0; j < cnt[i]; j++)
            {
                if(solved[A[i][j]] == 1)
                {
                    B[i].A[num] = A[i][j];
                    num++;
                } 
            }
            mx = max(mx,num);
            B[i].num = num;
        }

        printf("Case #%d:\n",idx++);
        for(i = 1; i <= 3; i++)
        {
            if(mx == B[i].num)
            {
                _mergeSort(B[i].A,B[i].num);
                printf("%d %d",i,B[i].num);
                for(j = 0; j < B[i].num; j++)
                    printf(" %d",B[i].A[j]);
                puts("");
            }
        }
    }
    return 0;
}

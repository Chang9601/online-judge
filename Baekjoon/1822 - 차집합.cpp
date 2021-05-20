#include <iostream>
#define SWAP(a,b) do{int t = a; a = b; b = t;}while(0)
#define MAX 500005
using namespace std;

static void _heapify(int A[],int low,int high)
{
    int tmp = A[low];
    int parent;
    int child,leftChild,rightChild;
    
    for(parent = low; parent < (high+1)/2; parent = child) 
    {
        leftChild = parent*2+1;
        rightChild = parent*2+2;
        child = (rightChild <= high && A[rightChild] > A[leftChild]) ? rightChild : leftChild; 
        if(A[child] <= tmp) 
            break;
        SWAP(A[parent],A[child]);
    }
    A[parent] = tmp;
}

void heap_sort(int A[],int n)
{
    int i;
    for(i = (n-1)/2; i >= 0; i--)
        _heapify(A,i,n-1);
    for(i = n-1; i > 0; i--) 
    {
        SWAP(A[0],A[i]);
        _heapify(A,0,i-1);
    }
}

int binary_search(int A[],int n,int x)
{
    int low = 0,high = n-1;
    int mid; 
    
    while(low <= high)
    {
        mid = low+(high-low)/2;
        if(A[mid] == x)
            return mid;
        else if(A[mid] > x)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1; 
}

int main() {
    int N,M,i,cnt;
    int A[MAX],B[MAX],ans[MAX];
    
    cnt = 0; 
    scanf("%d %d",&N,&M);
    
    for(i = 0; i < N; i++)
        scanf("%d",&A[i]);
    for(i = 0; i < M; i++)
        scanf("%d",&B[i]);
        
    heap_sort(B,M);
    for(i = 0; i < N; i++) 
    {
        if(binary_search(B,M,A[i]) == -1)
            ans[cnt++] = A[i];
    }
    
    printf("%d\n",cnt);
    if(cnt)
    {
        heap_sort(ans,cnt);
        for(i = 0; i < cnt; i++) 
            printf("%d ",ans[i]);
    }
    return 0;
}

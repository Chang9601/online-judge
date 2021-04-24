#include <cstdio>
#include <algorithm>
using namespace std;
int T;
void insertionSort(int A[],int n)
{
    int i,j;
    for(i = 1; i < n; i++)
    {
        j = i;
        while(j > 0 && A[j-1] > A[j])
        {
            swap(A[j],A[j-1]);
            j--;
        }
    }
}

int main()
{   
    scanf("%d",&T); int idx = 1;
    while(T--)
    {
        char c;
        int x,A[3]; int i,sum = 0;
        for(i = 0; i < 4; i++)
        {
            scanf("%d",&x);
            sum += x;
        }
        for(i = 0; i < 3; i++)
            scanf("%d",&A[i]);
        insertionSort(A,3);
        sum += (A[1]+A[2])/2;
        switch(sum/10)
        {
            case 10:
            case 9:
                c = 'A';
                break;
            case 8:
                c = 'B';
                break;
            case 7:
                c = 'C';
                break;
            case 6:
                c = 'D';
                break;
            default:
                c = 'F';
                break;
        }
        printf("Case %d: %c\n",idx++,c);  
    }    
    return 0;    
}

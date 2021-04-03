#include <cstdio>
using namespace std;
int N,x;
int A[10005];
void quickSort(int X[], int l, int h)
{
    int pl = l,ph = h;
    int m = X[(h-l)/2+l];

    do
    {
        while(m > X[pl]) pl++;
        while(m < X[ph]) ph--;

        if(pl <= ph)
        {
            int t = X[pl];
            X[pl] = X[ph];
            X[ph] = t;

            pl++; ph--;
        }
    }while(pl <= ph);

    if(l < ph) quickSort(X,l,ph); 
    if(pl < h) quickSort(X,pl,h);
}

int main()
{
    int i = 0,m;
    while(scanf("%d",&x) == 1)
    {
        A[i++] = x;

        quickSort(A,0,i-1);
        if(i&1) m = A[i/2];
        else m = (A[i/2]+A[i/2-1])/2;
        printf("%d\n",m);
    }    
    return 0;   
}

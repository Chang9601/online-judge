#include <cstdio> 
#include <cmath>
using namespace std;

int main()
{
    int i,j,N,B;
    int A[95];

    while(scanf("%d %d",&N,&B) == 2 && N && B)
    {
        bool flag = true;
        bool has[95] = {};
        for(i = 0; i < B; i++)
            scanf("%d",&A[i]);

        for(i = 0; i < B; i++)
            for(j = 0; j < B; j++)
                    has[abs(A[i]-A[j])] = true;
        
        for(i = 0; i <= N; i++)
            if(!has[i])
                flag = false;
                
        printf("%s\n",flag ? "Y" : "N");
    } 
    return 0;    
}

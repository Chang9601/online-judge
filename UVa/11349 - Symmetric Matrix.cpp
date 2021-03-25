#include <cstdio>
using namespace std;
int T,n;
long long grid[105][105];
void clearInputBuffer()
{
    while(getchar() != '\n');
}

int main()
{
    scanf("%d",&T); int idx = 1;
    while(T--)
    {
        clearInputBuffer();
        int i,j; bool isNegative = true,isSymmetric = true;
        scanf("N = %d",&n);
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                scanf("%lld",&grid[i][j]);

        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
            {
                if(grid[i][j] < 0) isNegative = false;
                if(grid[i][j] != grid[n-1-i][n-1-j]) isSymmetric = false;
            }

        if(!isSymmetric || !isNegative) printf("Test #%d: Non-symmetric.\n",idx++);
        else printf("Test #%d: Symmetric.\n",idx++);
    }

    return 0;   
}


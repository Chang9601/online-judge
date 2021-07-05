#include <cstdio>
using namespace std;

int main()
{ 
    int idx;
    int n,m;
    int i,j,k,l;
    int r,c;
    int cnt;
    char grid[105][105];

    idx = 1;
    while(scanf("%d %d",&n,&m) == 2 && n && m)
    {
        if(idx != 1)
            putchar('\n');
        for(i = 0; i < n; i++)
            scanf("%s",grid[i]);

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(grid[i][j] == '.')
                {
                    cnt = 0;
                    for(k = -1; k <= 1; k++)
                    {
                        for(l = -1; l <= 1; l++)
                        {
                            r = i+k; c = j+l;

                            if(r < 0 || r >= n || c < 0 || c >= m)
                                continue;
                            if(grid[r][c] != '*')
                                continue;
                            cnt++;
                        }
                    }
                    grid[i][j] = '0'+cnt;
                }
            }
        }

        printf("Field #%d:\n",idx++);
        for(i = 0; i < n; i++,puts(""))
            for(j = 0; j < m; j++)
                printf("%c",grid[i][j]);
    }
    return 0;    
}

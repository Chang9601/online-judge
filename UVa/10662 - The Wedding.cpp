#include <cstdio>
using namespace std;

int main()
{
    int T,R,H;

    while(scanf("%d %d %d",&T,&R,&H) == 3)
    {
        int i,j,k;
        int sum,mn,ti,ri,hi;
        int buf[25][25];
        int t[25],r[25],h[25]; 
        bool tr[25][25] = {},rh[25][25] = {},ht[25][25] = {};

        mn = 1e9;
        for(i = 0; i < T; i++)
            for(j = 0; j < R+1; j++)
                scanf("%d",&buf[i][j]);

        for(i = 0; i < T; i++)
            t[i] = buf[i][0];

        for(i = 0; i < T; i++)
            for(j = 1; j < R+1; j++)
                tr[i][j-1] = (buf[i][j]) ? true : false;
        ////////////////////////////////////////////

        for(i = 0; i < R; i++)
            for(j = 0; j < H+1; j++)
                scanf("%d",&buf[i][j]);

        for(i = 0; i < R; i++)
            r[i] = buf[i][0];
        
        for(i = 0; i < R; i++)
            for(j = 1; j < H+1; j++)
                rh[i][j-1] = (buf[i][j]) ? true : false;
        ////////////////////////////////////////////

        for(i = 0; i < H; i++)
            for(j = 0; j < T+1; j++)
                scanf("%d",&buf[i][j]);

        for(i = 0; i < H; i++)
            h[i] = buf[i][0];
        
         for(i = 0; i < H; i++)
            for(j = 1; j < T+1; j++)
                ht[i][j-1] = (buf[i][j]) ? true : false;

        for(i = 0; i < T; i++)
        {
            for(j = 0; j < R; j++)
            {
                for(k = 0; k < H; k++)
                {
                    if(!tr[i][j] && !rh[j][k] && !ht[k][i])
                    {
                        sum = t[i]+r[j]+h[k];
                        if(sum < mn)
                        {
                            mn = sum;
                            ti = i;
                            ri = j;
                            hi = k;  
                        }
                    }
                }
            }
        }

        if(mn == 1e9)
            printf("Don't get married!");
        else
            printf("%d %d %d:%d",ti,ri,hi,mn);
        putchar('\n');
    }
  
    return 0;    
}

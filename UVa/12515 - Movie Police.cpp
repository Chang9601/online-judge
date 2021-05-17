#include <cstdio>
#include <cstring>
using namespace std;
#define INF 1000000000
int M,Q;
char movie[1005][150],clip[505][150];

int main()
{
    int i,j,k,l;
    int cnt,mn,ans;
    int lenM,lenC;
   // mn = INF;
    scanf("%d %d",&M,&Q);
    for(i = 0; i < M; i++)
        scanf("%s",movie[i]);
    for(i = 0; i < Q; i++)
        scanf("%s",clip[i]);

    for(i = 0; i < Q; i++)
    {
        mn = INF;
        for(j = 0; j < M; j++)
        {
            lenM = strlen(movie[j]);
            lenC = strlen(clip[i]); 
            if(lenM < lenC)
                continue;
    
            for(l = 0; l <= lenM-lenC; l++)
            {   
                cnt = 0;
                for(k = 0; k < lenC; k++)
                    if(movie[j][l+k] != clip[i][k])
                        cnt++;
                 
                if(mn > cnt)
                {
                    mn = cnt;
                    ans = j+1;
                }        
            }
        }
        printf("%d\n",ans);
    }
    return 0;    
}

#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int N;    
    int num,cc,cw,ans,ncc,ncw;
    int i,j,k,size,start,finish;
    char buf[15],tmp[15];
    int flag[10];

    scanf("%d",&N);
    while(N--)
    {
        scanf("%d %d %d",&num,&cc,&cw);
        sprintf(buf,"%d",num);
        size = strlen(buf);
        ans = 0;
        //printf("%d %d\n",cc,cw);

        switch(size)
        {
            case 2:
                start = 10;
                finish = 100;
                break;
            case 3:
                start = 100;
                finish = 1000;
                break;
            case 4:
                start = 1000;
                finish = 10000;
                break;
            case 5:
                start = 10000;
                finish = 100000;
                break;
        }

        for(i = start; i < finish; i++)
        {
            sprintf(tmp,"%d",i);
            memset(flag,0,sizeof(flag));
            ncw = ncc = 0;

            for(j = 0; j < size; j++)
                flag[tmp[j]-'0']++;

            if(flag[0] > 0)
                continue;
            else
                memset(flag,0,sizeof(flag));
            
            // cw
            for(j = 0; j < size; j++)
                flag[buf[j]-'0']++;

            for(j = 0; j < size; j++)
                if(flag[tmp[j]-'0'] > 0)
                {
                    ncw++;
                    flag[tmp[j]-'0']--;
                }
            
            // cc
            for(j = 0; j < size; j++)
                if(tmp[j] == buf[j])
                {
                    ncc++;
                    ncw--;
                }
            
            if(ncw == cw && ncc == cc)
                ans++;
        }

        printf("%d\n",ans);
    }
    return 0;    
}

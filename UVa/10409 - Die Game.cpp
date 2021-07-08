#include <cstdio>
#include <cstring>
using namespace std;
int tmp[6];

void north(int D[],int size)
{
    memcpy(tmp,D,size);
    D[1] = tmp[2];
    D[2] = tmp[0];
    D[0] = tmp[3];
    D[3] = tmp[1];
}

void south(int D[],int size)
{
    memcpy(tmp,D,size);
    D[1] = tmp[3];
    D[3] = tmp[0];
    D[0] = tmp[2];
    D[2] = tmp[1];
}

void east(int D[],int size)
{
    memcpy(tmp,D,size);
    D[1] = tmp[4];
    D[4] = tmp[0];
    D[0] = tmp[5];
    D[5] = tmp[1];
}

void west(int D[],int size)
{
    memcpy(tmp,D,size);
    D[1] = tmp[5];
    D[5] = tmp[0];
    D[0] = tmp[4];
    D[4] = tmp[1];
}

int main()
{ 
    int i,N,size;
    char cmd[10];

    while(scanf("%d",&N) == 1 && N)
    {
        int D[6] = {1,6,2,5,4,3};
        size = sizeof(D);
        for(i = 0; i < N; i++)
        {
            scanf("%s",cmd);

            if(!strcmp(cmd,"north"))
                north(D,size);
            else if(!strcmp(cmd,"south"))
                south(D,size);
            else if(!strcmp(cmd,"east"))
                east(D,size);
            else
                west(D,size);
        }
        printf("%d\n",D[0]);
    }
    return 0;    
}

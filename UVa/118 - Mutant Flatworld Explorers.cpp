#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int x,y;
char s[105];
bool off[55][55];

char convert(int n)
{
    switch(n)
    {
        case 0: return 'N';
        case 1: return 'E';
        case 2: return 'S';
        case 3: return 'W';
    }
    return '\n';
}

int main()
{
    scanf("%d %d",&x,&y);
    int cx,cy; char c; int d;
    int px,py,pd; int flag = 1; memset(off,false,sizeof(off));
    char ans,pans;
    while(scanf("%d %d %c",&cx,&cy,&c) == 3)
    {  
        flag = 1;
        switch(c)
        {
            case 'N': d = 0; break;
            case 'E': d = 1; break;
            case 'S': d = 2; break;
            case 'W': d = 3; break;
        }

        scanf("%s",s);
        for(int i = 0; s[i]; i++)
        {

            if(s[i] == 'R') d = (d+1)%4;
            else if(s[i] == 'L') d = (d+4-1)%4;
            else
            {
                switch(d)
                {
                    case 0: cy++; break;
                    case 1: cx++; break;
                    case 2: cy--; break;
                    case 3: cx--; break;
                }
            }

            if(cx > x || cy > y || cx < 0 || cy < 0)
            {
                switch(d)
                {
                    case 0: cy--; break;
                    case 1: cx--; break;
                    case 2: cy++; break;
                    case 3: cx++; break;
                }

                if(off[cx][cy]) continue;
                flag = 0;
                off[cx][cy] = true;
                break;
            }

        }
        ans = convert(d); //pans = convert(pd);

        if(flag) printf("%d %d %c\n",cx,cy,ans);
        else printf("%d %d %c LOST\n",cx,cy,ans);
    }
    return 0;
}

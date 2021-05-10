#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int vt,v0;

    while(scanf("%d %d",&vt,&v0) == 2)
    {
        if(!vt && !v0)
            break;

        int i,j,num,dup;
        j = dup = 0;
        double A[60005] = {};
        double v,d,mx = -1.0;

        for(i = 1; i <= vt; i++)
        {
            v = (double)vt/i;
            if(v >= v0)
                d = 0.3*sqrt(v-v0)*i;
            else
                d = 0;

            A[j++] = d;
            if(d > mx)
            {
                mx = d;
                num = i;
            }
        }

        for(i = 0; i < j; i++)
            if(abs(mx-A[i]) < 1e-12)
                dup++;
        if(!mx || dup > 1)
            puts("0");
        else 
            printf("%d\n",num);
    }
    return 0;    
}

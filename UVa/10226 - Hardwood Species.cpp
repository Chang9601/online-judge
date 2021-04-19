#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <iomanip>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <assert.h>
using namespace std;
#define INF 1000000000
const double PI = acos(-1.0); 
int T;

void clearInputBuffer(void)
{
    while(getchar() != '\n')
        ;
}

void deleteNewline(char s[])
{
    int i = 0;
    while(s[i] != '\n')
        i++;
    s[i] = '\0';
}

int main()
{
    scanf("%d",&T);
    clearInputBuffer();
    clearInputBuffer();
    while(T--)
    {
        map<string,int> m;
        char s[35]; int base = 0;
        while(fgets(s,sizeof(s),stdin))
        {
            deleteNewline(s);
            if(s[0] == '\0') break;
            m[s]++;
            base++;
        }

        for(map<string,int>::iterator it = m.begin(); it != m.end(); it++)
            printf("%s %.4lf\n",it->first.c_str(),100.0*it->second/(double)base);
        if(T)
            putchar('\n');
    }

    return 0;    
}

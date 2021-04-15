#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int T;
char s[100005];
void clearInputBuffer(void)
{
    while(getchar() != '\n');
}
void deleteNewline(char str[])
{
    int i = 0;
    while(str[i] != '\n')
        i++;
    str[i] = '\0';
}

int main()
{
    scanf("%d",&T);
    clearInputBuffer();
    while(T--)
    {
        clearInputBuffer();
        fgets(s,sizeof(s),stdin);
        deleteNewline(s);   
        int i = 0, j = 0;
        long long idx[100005]; char num[100005][1005];
        char *d = strtok(s," ");
        while(d)
        {
            idx[i++] = atoll(d);
            d = strtok(NULL," ");
        }

        fgets(s,sizeof(s),stdin);
        deleteNewline(s);  
        d = strtok(s," ");
        while(d)
        {
            strcpy(num[idx[j++]-1],d);
            d = strtok(NULL," ");
        }

        for(j = 0; j < i; j++)
            printf("%s\n",num[j]);
        if(T)
            putchar('\n');
    }
    return 0;    
}

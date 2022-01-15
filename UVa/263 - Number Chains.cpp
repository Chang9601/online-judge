#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

int cmp_asc(const char *x, const char *y)
{
	if(*x < *y)
		return -1;
	else if(*x > *y)
		return 1;
	else
		return 0; 
}

int cmp_desc(const char *x, const char *y)
{
	if(*x < *y)
		return 1;
	else if(*x > *y)
		return -1;
	else
		return 0; 
}

int main(int argc, char *argv[])
{
	char num[15];
	char asc_num[15];
	char desc_num[15];
	char copy[15];
	int new_num;
	int asc;
	int desc;
	int chain_length;
	
	while(scanf("%s", num) == 1)
	{
		if(!strcmp(num, "0"))
			break;
		
		map<int, int> m;
		chain_length = 0;
		printf("Original number was %s\n", num);
		m[atoi(num)]++;
		while(1)
		{
			strcpy(desc_num, num);
			qsort(desc_num, strlen(desc_num), sizeof(desc_num[0]), (int(*)(const void*, const void*))cmp_desc);
			desc = atoi(desc_num);

			strcpy(asc_num, num);
			qsort(asc_num, strlen(asc_num), sizeof(asc_num[0]), (int(*)(const void*, const void*))cmp_asc);
			asc = atoi(asc_num);
	
			new_num = desc - asc;	
			printf("%d - %d = %d\n", desc, asc, new_num);
			
			m[new_num]++;
			chain_length++;			
			if(m[new_num] > 1)
				break;		
			
			sprintf(num, "%d", new_num);	
		}			

		printf("Chain length %d\n\n", chain_length);
	}
	return 0;
}

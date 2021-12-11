#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char line[205];

	while(scanf("%s", line) == 1)
	{
		if(line[0] == '*')
			break;
		int cnt = 0;
		char *token = strtok(line, "/");
		while(token)	
		{
			int i, sum;
			sum = 0;
			for(i = 0; token[i]; i++)
			{
				switch(token[i])
				{
					case 'W':
						sum += 64;
						break;
					case 'H':
						sum += 32;
						break;
					case 'Q':
						sum += 16;
						break;
					case 'E':
						sum += 8;
						break;
					case 'S':
						sum += 4;
						break;
					case 'T':
						sum += 2;
						break;
					case 'X':
						sum += 1;
						break;
				}
			}
			cnt += (sum == 64) ? 1 : 0;	
			token = strtok(NULL, "/");
		}
		printf("%d\n", cnt);
	}
	return 0;
}

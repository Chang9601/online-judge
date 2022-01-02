#include <stdio.h>
#include <string.h>

void delete_newline(char line[])
{
	int i;
	i = 0;
	
	while(line[i] != '\n')
		i++;
	line[i] = '\0';
}

int main(int argc, char *argv[])
{
	char line[105][105], buffer[105][105];
	int ct, i, j, max_len, len;
	
	memset(buffer, ' ', sizeof(buffer));
	max_len = -1;
	ct = 0;
	while(fgets(line[ct], sizeof(line[0]), stdin))
	{
		delete_newline(line[ct]);
		len = strlen(line[ct]);
		max_len = max_len < len ? len : max_len; 
		ct++;
	}		

	for(i = 0; i < ct; i++)
		for(j = 0; line[i][j]; j++)
				buffer[j][ct - i - 1] = line[i][j];
	
	for(i = 0; i < max_len; i++)
	{
		buffer[i][ct] = '\0';
		for(j = 0; j < ct; j++)
			putchar(buffer[i][j]); 	
		putchar('\n');
	}
	return 0;
}

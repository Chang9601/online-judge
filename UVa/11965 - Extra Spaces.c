#include <stdio.h>

void clear_input_buffer()
{
	while(getchar() != '\n')
		;
}

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
	int T, N, i, test_case;
	char line[505];
	char last;
	
	test_case = 1;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		clear_input_buffer();

		printf("Case %d:\n", test_case++);	
		while(N--)
		{
			fgets(line, sizeof(line), stdin);
			delete_newline(line);
	
			last = '\0';
			for(i = 0; line[i]; i++)
			{
				if(!(line[i] == ' ' && line[i] == last))
					putchar(line[i]);
				last = line[i];		
			}
			putchar('\n');
		}

		if(T)
			putchar('\n');
	}

	return 0;
}

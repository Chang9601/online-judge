#include <stdio.h>
#include <ctype.h>

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
	char line[250];
	char ch;
	int i, j, num;

	num = 0;
	while(fgets(line, sizeof(line), stdin))
	{
		delete_newline(line);

		for(i = 0; line[i]; i++)
		{
			ch = line[i];
			if(isdigit(ch))
				num += (ch - '0');
			else
			{
				if(ch == '!')
					putchar('\n');
				else
				{
					for(j = 0; j < num; j++)
					{
						if(ch == 'b')
							putchar(' ');
						else
							putchar(ch);
					}
					num = 0;
				}
			}
		}
		putchar('\n');
	}

	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_soundex(char c, char not_soundex[], int array_len)
{
	int i;
	for(i = 0; i < array_len; i++)
		if(c == not_soundex[i])
			return false;
	return true;
}

int main(int argc, char *argv[])
{
	char word[25];
	char ASCII[128] = {0,};
	char not_soundex[] = {'A', 'E', 'I', 'O', 'U', 'H', 'W', 'Y'};
	
	ASCII['B'] = ASCII['F'] = ASCII['P'] = ASCII['V'] = '1';
	ASCII['C'] = ASCII['G'] = ASCII['J'] = ASCII['K'] = ASCII['Q'] = ASCII['S'] = ASCII['X'] = ASCII['Z'] = '2';
	ASCII['D'] = ASCII['T'] = '3';
	ASCII['L'] = '4';
	ASCII['M'] = ASCII['N'] = '5';
	ASCII['R'] = '6';
 
	while(scanf("%s", word) == 1)
	{
		int i;
		int word_len = strlen(word);
		char last_ch = 'A';

		for(i = 0; word[i]; i++)
		{
			if(is_soundex(word[i], not_soundex, sizeof(not_soundex)))
			{
				if(ASCII[word[i]] != last_ch)
				{
					last_ch = ASCII[word[i]];
					putchar(ASCII[word[i]]);
				}
			}
			else
				last_ch = 'A';
		}
		putchar('\n');
	}

	return 0;
}

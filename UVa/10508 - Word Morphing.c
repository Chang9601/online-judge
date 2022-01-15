#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int num_words, num_letters;
	char start[1050], finish[1050], word[1050];
	char words[1050][1050];
	int i, j, k, change;

	while(scanf("%d %d", &num_words, &num_letters) == 2)
	{	
		scanf("%s", start);
		scanf("%s", finish);
		num_words -= 2;

		for(i = 0; i < num_words; i++)
			scanf("%s", words[i]);

		strcpy(word, start);
		puts(start);

		for(i = 0; i < num_words; i++)
		{	
			for(j = 0; j < num_words; j++)
			{
				change = 0;
				for(k = 0; k < num_letters; k++)
					change += word[k] != words[j][k];
				if(change == 1)
				{
					strcpy(word, words[j]); 
					puts(words[j]);
					memset(words[j], '\0', sizeof(words[j]));	
					break;	
				}	
			}
		}	
		puts(finish);
	}	

	return 0;
}

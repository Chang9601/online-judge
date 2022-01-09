#include <stdio.h>

void print_waveforms(int amplitude)
{
	int i, j;
	for(i = 1; i <= amplitude; i++)
	{
		for(j = 1; j <= i; j++)
			printf("%d", i);
		putchar('\n');
	}

	for(i = amplitude - 1; i >= 1; i--)
	{
		for(j = 1; j <= i; j++)
			printf("%d", i);
		putchar('\n');
	}
}

int main(int argc, char *argv[])
{
	int test_case;
	int i, newline;
	
	newline = 0;
	scanf("%d", &test_case);
	while(test_case--)
	{
		int amplitude, frequency;
		scanf("%d %d", &amplitude, &frequency);
		
		if(++newline > 1)
			putchar('\n');				

		for(i = 0; i < frequency; i++)
		{
			print_waveforms(amplitude);
			if(i != frequency - 1)
				putchar('\n');				
		}
		
	}

	return 0;
}

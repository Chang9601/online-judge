#include <stdio.h>


int main(int argc, char *argv[])
{
	char *QWERTY1 = "1234567890-=";
	char *QWERTY2 = "WERTYUIOP[]\\";
	char *QWERTY3 = "SDFGHJKL;\'";
	char *QWERTY4 = "XCVBNM,./";

	char *WERTYU1 = "`1234567890-";
	char *WERTYU2 = "QWERTYUIOP[]";
	char *WERTYU3 = "ASDFGHJKL;";
	char *WERTYU4 = "ZXCVBNM,.";

	char c;
	int i;

	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\n')
			putchar(c);
	
		for(i = 0; QWERTY1[i]; i++)
			if(c == QWERTY1[i])
				putchar(WERTYU1[i]);
			
		for(i = 0; QWERTY2[i]; i++)
			if(c == QWERTY2[i])
				putchar(WERTYU2[i]);
		
		for(i = 0; QWERTY3[i]; i++)
			if(c == QWERTY3[i])
				putchar(WERTYU3[i]);

		for(i = 0; QWERTY4[i]; i++)
			if(c == QWERTY4[i])
				putchar(WERTYU4[i]);
	}
	
	return 0;
}

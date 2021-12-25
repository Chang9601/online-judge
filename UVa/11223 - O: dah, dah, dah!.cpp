#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

void clear_input_buffer()
{
	while(getchar() != '\n')
		;
}

void delete_newline(char msg[])
{
	int i = 0;
	while(msg[i] != '\n')
		i++;
	msg[i] = '\0';
}

int main(int argc, char *argv[])
{
	map<string, char> morse;

	morse[".-"] = 'A', morse[".---"] = 'J', morse["..."] = 'S', morse[".----"] = '1', morse[".-.-.-"] = '.', morse["---..."] = ':';
	morse["-..."] = 'B', morse["-.-"] = 'K', morse["-"] = 'T', morse["..---"] = '2', morse["--..--"] = ',', morse["-.-.-."] = ';';
	morse["-.-."] = 'C', morse[".-.."] = 'L', morse["..-"] = 'U', morse["...--"] = '3', morse["..--.."] = '?', morse["-...-"] = '=';
	morse["-.."] = 'D', morse["--"] = 'M', morse["...-"] = 'V', morse["....-"] = '4', morse[".----."] = '\'', morse[".-.-."] = '+';
	morse["."] = 'E', morse["-."] = 'N', morse[".--"] = 'W', morse["....."] = '5', morse["-.-.--"] = '!', morse["-....-"] = '-';
	morse["..-."] = 'F', morse["---"] = 'O', morse["-..-"] = 'X', morse["-...."] = '6', morse["-..-."] = '/', morse["..--.-"] = '_';
	morse["--."] = 'G', morse[".--."] = 'P', morse["-.--"] = 'Y', morse["--..."] = '7', morse["-.--."] = '(', morse[".-..-."] = '\"';
	morse["...."] = 'H', morse["--.-"] = 'Q', morse["--.."] = 'Z', morse["---.."] = '8', morse["-.--.-"] = ')', morse[".--.-."] = '@';
	morse[".."] = 'I', morse[".-."] = 'R', morse["-----"] = '0', morse["----."] = '9', morse[".-..."] = '&';
	
	int T, test_case;
	scanf("%d", &T);

	test_case = 0;	
	cin.ignore();
	//clear_input_buffer();
	while(T--)
	{
		printf("Message #%d\n", ++test_case);

		int i, buffer_len;
		int cnt;
		char c;
		char msg[2005], buffer[20] = {0,};
		fgets(msg, sizeof(msg), stdin);
		//delete_newline(msg);	
		
		i = 0;
		while((c = msg[i++]))
		{
			if(isspace(c))
			{
				buffer_len = strlen(buffer);
				buffer[buffer_len] = '\0';
				putchar(morse[buffer]);

				memset(buffer, '\0', sizeof(buffer));
				
				if(msg[i] && isspace(msg[i]))
				{
					i++;
					putchar(' ');
				}
			}
			else
				strcat(buffer, &c);
		}

		putchar('\n');
		if(T)
			putchar('\n');
	}	
	return 0;
}

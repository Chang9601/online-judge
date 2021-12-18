#include <stdio.h>

void clear_input_buffer()
{
	while(getchar() != '\n')
		;
}

int calc_digit(int num)
{
	int sum = 0;
	do
	{
		sum += num % 10;
		num /= 10;
	}
	while(num > 0);

	return sum;
}

int main(int argc, char *argv[])
{
	int N;
	scanf("%d", &N);
	clear_input_buffer();

	while(N--)
	{
		char credit_card[50];
		char num1[10], num2[10], num3[10], num4[10];
		int sum = 0;
	
		fgets(credit_card, sizeof(credit_card), stdin);
		sscanf(credit_card, "%s %s %s %s", num1, num2, num3, num4);	

		sum += calc_digit(2 * (num1[0] - '0'));
		sum += calc_digit(2 * (num1[2] - '0'));
		sum += calc_digit(2 * (num2[0] - '0'));
		sum += calc_digit(2 * (num2[2] - '0'));
		sum += calc_digit(2 * (num3[0] - '0'));
		sum += calc_digit(2 * (num3[2] - '0'));
		sum += calc_digit(2 * (num4[0] - '0'));
		sum += calc_digit(2 * (num4[2] - '0'));

		sum += (num1[1] - '0') + (num1[3] - '0');
		sum += (num2[1] - '0') + (num2[3] - '0');
		sum += (num3[1] - '0') + (num3[3] - '0');
		sum += (num4[1] - '0') + (num4[3] - '0');

		printf("%s\n", sum % 10 == 0 ? "Valid" : "Invalid");
	}

	return 0;
}

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int T, test_case;
	scanf("%d", &T);
	
	test_case = 1;	
	while(T--)
	{
		int k;
		double tax;
		scanf("%d", &k);
		
		tax = 0;
		if(k > 180000)
		{
			k -= 180000;
			if(k > 300000)
			{
				tax += 30000; 
				k -= 300000;
				if(k > 400000)
				{
					tax += 60000;
					k -= 400000;

					if(k > 300000)
					{
						tax += 60000;
						k -= 300000;
						if(k > 0)
							tax += k * 0.25;
					}
					else
						tax += k * 0.2;
				}
				else
					tax += k * 0.15; 
			}
			else
				tax += k * 0.1;

			if(tax < 2000)
				tax = 2000;
		}

		printf("Case %d: %d\n", test_case++, (int)ceil(tax));
	}

	return 0;
}

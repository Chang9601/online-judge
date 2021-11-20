#include <stdio.h>

int main(int argc, char *argv[])
{
	int file_size;
	int total_time;
	double transfer_rate;
	int remaining_bytes;
	int remaining_time;
	int bytes;
	int bytes_five_secs; 
	int case_num;

	case_num = 1;
	while(scanf("%d", &file_size) == 1 && file_size)
	{
		printf("Output for data set %d, %d bytes:\n", case_num++, file_size);
		total_time = total_bytes = bytes_five_secs = 0;
		while(scanf("%d", &bytes) == 1)
		{
			file_size -= bytes;
			bytes_five_secs += bytes;
			total_time++;
			
			if(total_time % 5 == 0)
			{
				remaining_bytes = 5 * file_size;
				
				if(bytes_five_secs == 0)
					puts("   Time remaining: stalled");
				else
				{
					remaining_time = remaining_bytes / bytes_five_secs + (remaining_bytes % bytes_five_secs != 0);
					printf("   Time remaining: %d seconds\n", remaining_time);
				}
				bytes_five_secs = 0;
			}

			if(file_size == 0)
				break;
		}
		printf("Total time: %d seconds\n\n", total_time);
	}

	return 0;
}

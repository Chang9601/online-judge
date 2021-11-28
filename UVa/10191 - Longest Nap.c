#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Appt{
	int begin_time;
	int end_time;
}Appt;

int cmp(const Appt *a, const Appt *b)
{
	if(a -> begin_time < b -> begin_time)
		return -1;
	else if(a -> begin_time > b -> begin_time)
		return 1;
	else
		return 0;
}

void clear_input_buffer()
{
	while(getchar() != '\n')
		;
}

void calc_nap(int *longest_nap, int diff, int *start_time, int last)
{
	*longest_nap = diff;
	*start_time = last;
}

int main(int argc, char *argv[])
{
	int s;
	int test_case = 1;
	
	while(scanf("%d", &s) == 1)
	{
		Appt appt[100];
		int idx = 0;
		int i;
		int longest_nap = -1;
		int diff;
		char start[15];
		int hh, mm;
		int start_time;
		int last = 600;

		clear_input_buffer();
		while(s--)
		{
			char line[300];
			char time1[10], time2[10];

			fgets(line, sizeof(line), stdin);
			sscanf(line, "%s %s", time1, time2);	
			
			appt[idx].begin_time = (10 * (time1[0] - '0') + (time1[1] - '0')) * 60 + (10 * (time1[3] - '0') + (time1[4] - '0'));
			appt[idx].end_time = (10 * (time2[0] - '0') + (time2[1] - '0')) * 60 + (10 * (time2[3] - '0') + (time2[4] - '0'));

			idx++;
		}

		qsort(appt, idx, sizeof(appt[0]), (int(*)(const void*, const void*))cmp);
		for(i = 0; i < idx; i++)
		{
			diff = abs(last - appt[i].begin_time);
			if(longest_nap < diff)
				calc_nap(&longest_nap, diff, &start_time, last);
			last = appt[i].end_time;
		}
		
		if(longest_nap < abs(1080 - last))
			calc_nap(&longest_nap, 1080 - last, &start_time, last);
			
		if(longest_nap < 60)
			printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d minutes.\n", test_case, start_time / 60, start_time % 60, longest_nap);
		else
			printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d hours and %d minutes.\n", test_case, start_time / 60, start_time % 60, longest_nap / 60, longest_nap % 60);
		test_case++;
	}
	return 0;
}

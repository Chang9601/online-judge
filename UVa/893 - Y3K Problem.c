#include <stdio.h>
#include <stdbool.h>

static int month_day[][12] = { 
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

typedef struct _Date {
	int day;
	int month;
	int year;
} Date;

bool is_leap_year(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

void calc_date_ahead(Date *date, int days)
{	
	date -> day += days;
	
	while(date -> day > month_day[is_leap_year(date -> year)][(date -> month) - 1])
	{
		date -> day -= month_day[is_leap_year(date -> year)][(date -> month) - 1];
		if(++(date -> month) > 12)
		{
			date -> month = 1;	
			(date -> year)++;
		}
	}
}

int main(int argc, char *argv[])
{
	int N;
	Date date;
	
	while((scanf("%d %d %d %d", &N, &date.day, &date.month, &date.year) == 4) && N && date.day && date.month && date.year)
	{
		calc_date_ahead(&date, N);
		printf("%d %d %d\n", date.day, date.month, date.year);
	}

	return 0;
}

#include "date.h"
#include <stdlib.h>

s_date_t* parseDate(char* date_string)
{
	s_date_t* date = (s_date_t*)malloc(sizeof(s_date_t));
	char* next = NULL;
	char* temp = strtok_s(date_string, "/", &next);

	if (temp != NULL) {
		date->day = 0;
	}

	temp = strtok_s(NULL, "/", &next);

	if (temp != NULL) {
		date->month = atoi(temp);
	}

	temp = strtok_s(NULL, "/", &next);

	if (temp != NULL) {
		date->year = atoi(temp);
	}

	return date;
}

int getOlder(s_date_t* d1, s_date_t* d2)
{
	if (d1->year > d2->year) return 2;
	else if (d1->year < d2->year) return 1;
	if (d1->month > d2->month) return 2;
	else if (d1->month < d2->month) return 1;
	return 0;
}

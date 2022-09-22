#ifndef DATE_H
#define DATE_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct date {
	int day;
	int month;
	int year;
}s_date_t;

s_date_t* parseDate(char* date_string);

int getOlder(s_date_t* d1, s_date_t* d2);

#endif


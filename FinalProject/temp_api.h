#ifndef _TEMPAPI_
#define _TEMPAPI_

#define CSV_DELIMITER ';'
#define ITEM_NUM 6

#include <stdio.h>
#include <unistd.h>
#include "stdlib.h"

typedef struct tempStorage_t{
    unsigned int     year[4];
    unsigned int     month[2];
    unsigned int     day[2];
    unsigned int     hour[2];
    unsigned int     minute[2];
    int              temp;
} tempStorage_t;



int getMonthVal(int month[]);
int getYearVal(int year[]);
int getMonthName(char* name, int idx);
void SortByDate(tempStorage_t* info,int n);
void cgangeIJ(tempStorage_t* info,int i,int j);
unsigned int DateToInt(tempStorage_t * info);
float getMonthMeanTemp(tempStorage_t storage[], int storLen, int mon, int year);
int getMonthMinTemp(tempStorage_t storage[], int storLen, int mon, int year);
int getMonthMaxTemp(tempStorage_t storage[], int storLen, int mon, int year);
float getYearMeanTemp(tempStorage_t storage[], int storLen, int year);
int getYearMinTemp(tempStorage_t storage[], int storLen, int year);
int getYearMaxTemp(tempStorage_t storage[], int storLen, int year);
int processLine(char line[], tempStorage_t * storage, int month);
void addStructItem(tempStorage_t * storage, tempStorage_t * item);
void printStat(tempStorage_t storage[], int storageLen, int selectedMonth);


#endif
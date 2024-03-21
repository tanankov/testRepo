#include "temp_api.h"
#include "string.h"

int NumberCheck(char c){
	int result=0;
	if(c >= '0' && c <= '9') 
		result = 1;
	return result;
}

int getMonthVal(int month[])
{
    return month[0]*10 + month[1];
}

int getYearVal(int year[])
{
    return year[0]*1000 + year[1]*100 + year[2]*10 + year[3];
}

unsigned int DateToInt(tempStorage_t * info)
{
    return ((getYearVal(info->year) << 16) | (getMonthVal(info->month) << 8) | (getMonthVal(info->day)));
}

void cgangeIJ(tempStorage_t * info,int i,int j)
{
    tempStorage_t temp;
    temp=info[i];
    info[i]=info[j];
    info[j]=temp;
}

void SortByDate(tempStorage_t* info,int n)
{
    
    for(int i=0; i<n; ++i)
        for(int j=i; j<n; ++j)
            if(DateToInt(info+i)>= DateToInt(info+j))
                cgangeIJ(info,i,j);
}

int getMonthName(char name[], int idx)
{
    int len = 0;
    switch(idx){
        case 1:
        {
            len = 8;
            memcpy(name, "January", len);
            break;
        }
        case 2:{
            len = 9;
            memcpy(name, "February", len);
            break;
        }
        case 3:{
            len = 6;
            memcpy(name, "March", len);
            break;
        }
        case 4:{
            len = 6;
            memcpy(name, "April", len);
            break;
        }
        case 5:{
            len = 4;
            memcpy(name, "May", len);
            break;
        }
        case 6:{
            len = 5;
            memcpy(name, "June", len);
            break;
        }
        case 7:{
            len = 5;
            memcpy(name, "July", len);
            break;
        }
        case 8:{
            len = 7;
            memcpy(name, "August", len);
            break;
        }
        case 9:{
            len = 10;
            memcpy(name, "September", len);
            break;
        }
        case 10:{
            len = 8;
            memcpy(name, "October", len);
            break;
        }
        case 11:{
            len = 9;
            memcpy(name, "November", len);
            break;
        }
        case 12:{
            len = 9;
            memcpy(name, "December", len);
            break;
        }
    }
    return len;
}

float getMonthMeanTemp(tempStorage_t storage[], int storLen, int mon, int year)
{
    int meanTemp = 0, cnt = 0;
    for(int i = 0; i < storLen; i++){
        if(year == getYearVal(storage[i].year)){
            if(mon == getMonthVal(storage[i].month)){
                meanTemp += storage[i].temp;
                cnt++;
            }
        }
    }
    if (cnt == 0)
        return 255; // err value
    else 
        return (float)meanTemp/(float)cnt;
}

int getMonthMinTemp(tempStorage_t storage[], int storLen, int mon, int year)
{
    int minTemp = 255; // err value
    for(int i = 0; i < storLen; i++){
        if(year == getYearVal(storage[i].year)){
            if(mon == getMonthVal(storage[i].month)){
                if (minTemp > storage[i].temp){
                    minTemp = storage[i].temp;
                }
            }
        }
    }
    return minTemp;
}

int getMonthMaxTemp(tempStorage_t storage[], int storLen, int mon, int year)
{
    int maxTemp = -255; // err value
    for(int i = 0; i < storLen; i++){
        if(year == getYearVal(storage[i].year)){
            if(mon == getMonthVal(storage[i].month)){
                if (maxTemp < storage[i].temp){
                    maxTemp = storage[i].temp;
                }
            }
        }
    }
    return maxTemp;
}


float getYearMeanTemp(tempStorage_t storage[], int storLen, int year)
{
    int meanTemp = 0, cnt = 0;
    for(int i = 0; i < storLen; i++){
        if(year == getYearVal(storage[i].year)){
            meanTemp += storage[i].temp;
            cnt++;
        }
    }
    if (cnt == 0)
        return 255; // err value
    else 
        return (float)meanTemp/(float)cnt;
}

int getYearMinTemp(tempStorage_t storage[], int storLen, int year)
{
    int minTemp = 255; // err value
    for(int i = 0; i < storLen; i++){
        if(year == getYearVal(storage[i].year)){
            if (minTemp > storage[i].temp){
                minTemp = storage[i].temp;
            }
        }
    }
    return minTemp;
}

int getYearMaxTemp(tempStorage_t storage[], int storLen, int year)
{
    int maxTemp = -255; // err value
    for(int i = 0; i < storLen; i++){
        if(year == getYearVal(storage[i].year)){
            if (maxTemp < storage[i].temp){
                maxTemp = storage[i].temp;
            }
        }
    }
    return maxTemp;
}

int processLine(char line[], tempStorage_t * storage, int month)
{
    int temp = 0, sign = 0;
    int cnt = 0, itemCnt = 0, i = 0, itemSize;
    char c;
    while (((c = line[cnt]) != '\n') && ((c = line[cnt]) != '\0')){ // until end of line

        if (c == CSV_DELIMITER){
            if (i < itemSize){ // item too short
                return 1;
            }
            if (itemCnt == 1){ //check for month validity
                if ((month > 0) && (month != getMonthVal(storage->month))){
                    return 2; // line will not be used for statistics
                } 
            }
            itemCnt++;
            i = 0;
        }
        else{
            if (c == ' '){
                c = '0';
            }
            switch(itemCnt)
            {
                case 0: //year
                {
                    itemSize = 4;
                    if (NumberCheck(c)){
                        if (i < itemSize){
                            storage->year[i++] = c - '0';
                        }  
                        else{
                            // printf("Oversize\n");
                            return 1; // item too long
                        }
                    }
                    else {
                        // printf("Invalid symbol\n");
                        return 1; // item has invalid symbol                    
                    }
                    break;
                }
                case 1: //month
                {
                    itemSize = 2;
                    if (NumberCheck(c)){
                        if (i < itemSize){
                            storage->month[i++] = c - '0';
                        }  
                        else{
                            // printf("Oversize\n");
                            return 1; // item too long
                        }
                    }
                    else {
                        // printf("Invalid symbol\n");
                        return 1; // item has invalid symbol                    
                    }
                    break;
                }
                case 2: //day
                {
                    itemSize = 2;
                    if (NumberCheck(c)){
                        if (i < itemSize){
                            storage->day[i++] = c - '0';
                        }  
                        else{
                            // printf("Oversize\n");
                            return 1; // item too long
                        }
                    }
                    else {
                        // printf("Invalid symbol\n");
                        return 1; // item has invalid symbol                    
                    }
                    break;
                }
                case 3: //hour
                {
                    itemSize = 2;
                    if (NumberCheck(c)){
                        if (i < itemSize){
                            storage->hour[i++] = c - '0';
                        }  
                        else{
                            // printf("Oversize\n");
                            return 1; // item too long
                        }
                    }
                    else {
                        // printf("Invalid symbol\n");
                        return 1; // item has invalid symbol                    
                    }
                    break;
                }
                case 4: //minute
                {
                    itemSize = 2;
                    if (NumberCheck(c)){
                        if (i < itemSize){
                            storage->minute[i++] = c - '0';
                        }  
                        else{
                            // printf("Oversize\n");
                            return 1; // item too long
                        }
                    }
                    else {
                        // printf("Invalid symbol\n");
                        return 1; // item has invalid symbol                    
                    }
                    break;
                }
                case 5: //temp
                {
                    itemSize = 1; // min temp length to check later
                    int maxTempSize  = 2;
                    if (sign == 0){ //  first symbol
                        if(NumberCheck(c)){
                            storage->temp = c - '0';
                            i++;
                            sign = 1;
                        }
                        else if (c == '-'){
                            sign = -1;
                            storage->temp = 0;
                        }
                        else {
                            // printf("Invalid symbol\n");
                            return 1; // item has invalid symbol                    
                        }
                        
                    }
                    else if(NumberCheck(c)){
                        if (i < maxTempSize){
                            storage->temp *= 10;
                            storage->temp += c - '0';
                            i++;
                        }
                        else{
                            // printf("Oversize\n");
                            return 1; // item too long
                        }
                    }
                    else {
                        // printf("Invalid symbol\n");
                        return 1; // item has invalid symbol

                    }
                    break;
                }
                default:
                {
                    // printf("Too much items");
                    return 1; // more items than needed
                }
            }
        }
        
    cnt++;
	}
    storage->temp *= sign;
    if(itemCnt < ITEM_NUM - 1){ // last item doesnt have delimiter, so -1{
        // printf("Not enough items");
        return 1; // not all items are filled
    }
    else{
        return 0; // success
    }
}

void addStructItem(tempStorage_t * storage, tempStorage_t * item)
{
    memcpy(storage->year, item->year, sizeof(item->year)); 
    memcpy(storage->month, item->month, sizeof(item->month));
    memcpy(storage->day, item->day, sizeof(item->day));
    memcpy(storage->hour, item->hour, sizeof(item->hour));
    memcpy(storage->minute, item->minute, sizeof(item->minute));
    storage->temp = item->temp;
}

void printStat(tempStorage_t storage[], int storageLen, int selectedMonth)
{
    int curYear = 0;
    int curMon = 0;
    if (selectedMonth > 0){ // print for specific month
        for (int i = 0; i<storageLen; i++){
            int mn = getMonthVal(storage[i].month);
            int yr = getYearVal(storage[i].year);
            if ((curMon != mn) && (curYear != yr)){
                char monName[9];
                getMonthName(monName, mn);
                printf("%s %d:\n", monName, yr);
                printf("    median temperature: %.1f\n", getMonthMeanTemp(storage, storageLen, mn, yr));
                printf("    minimum temperature: %d\n", getMonthMinTemp(storage, storageLen, mn, yr));
                printf("    maximum temperature: %d\n\n", getMonthMaxTemp(storage, storageLen, mn, yr));
                curMon = mn;
                curYear = yr;
            }
        }
    }
    else { // print by default
        for (int i = 0; i<storageLen; i++){
            int mn = getMonthVal(storage[i].month);
            int yr = getYearVal(storage[i].year);
            if (curYear != yr){
                printf("%d:\n", yr);
                printf("    yearly median temperature: %.1f\n", getYearMeanTemp(storage, storageLen, yr));
                printf("    yearly minimum temperature: %d\n", getYearMinTemp(storage, storageLen, yr));
                printf("    yearly maximum temperature: %d\n\n", getYearMaxTemp(storage, storageLen, yr));
                curYear = yr;
                curMon = 0;
            }
            if ((curMon != mn)){
                char monName[9];
                getMonthName(monName, mn);
                printf("%s %d:\n", monName, yr);
                printf("    median temperature: %.1f\n", getMonthMeanTemp(storage, storageLen, mn, yr));
                printf("    minimum temperature: %d\n", getMonthMinTemp(storage, storageLen, mn, yr));
                printf("    maximum temperature: %d\n\n", getMonthMaxTemp(storage, storageLen, mn, yr));
                curMon = mn;
            }
        }
    }
}

void printStatToFile(FILE *file, tempStorage_t storage[], int storageLen, int selectedMonth)
{
    int curYear = 0;
    int curMon = 0;
    if (selectedMonth > 0){ // print for specific month
        for (int i = 0; i<storageLen; i++){
            int mn = getMonthVal(storage[i].month);
            int yr = getYearVal(storage[i].year);
            if ((curMon != mn) && (curYear != yr)){
                char monName[9];
                getMonthName(monName, mn);
                fprintf(file, "%s %d:\n", monName, yr);
                fprintf(file,"    median temperature: %.1f\n", getMonthMeanTemp(storage, storageLen, mn, yr));
                fprintf(file,"    minimum temperature: %d\n", getMonthMinTemp(storage, storageLen, mn, yr));
                fprintf(file,"    maximum temperature: %d\n\n", getMonthMaxTemp(storage, storageLen, mn, yr));
                curMon = mn;
                curYear = yr;
            }
        }
    }
    else { // print by default
        for (int i = 0; i<storageLen; i++){
            int mn = getMonthVal(storage[i].month);
            int yr = getYearVal(storage[i].year);
            if (curYear != yr){
                fprintf(file,"%d:\n", yr);
                fprintf(file,"    yearly median temperature: %.1f\n", getYearMeanTemp(storage, storageLen, yr));
                fprintf(file,"    yearly minimum temperature: %d\n", getYearMinTemp(storage, storageLen, yr));
                fprintf(file,"    yearly maximum temperature: %d\n\n", getYearMaxTemp(storage, storageLen, yr));
                curYear = yr;
                curMon = 0;
            }
            if ((curMon != mn)){
                char monName[9];
                getMonthName(monName, mn);
                fprintf(file,"%s %d:\n", monName, yr);
                fprintf(file,"    median temperature: %.1f\n", getMonthMeanTemp(storage, storageLen, mn, yr));
                fprintf(file,"    minimum temperature: %d\n", getMonthMinTemp(storage, storageLen, mn, yr));
                fprintf(file,"    maximum temperature: %d\n\n", getMonthMaxTemp(storage, storageLen, mn, yr));
                curMon = mn;
            }
        }
    }
}
/*
 * task1.c
 * 
 * Copyright 2024 tanan <tanan@KREMLEBOT>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#define LINE_LENGTH 10

int find_max_array(int size, int a[])
{
	int maxValue = a[0];
	for(int i = 1; i<size; i++){
		if (a[i] > maxValue)
			maxValue = a[i];
	}
	return maxValue;
}

int CharToDec(char c){
	int result=-1;
	if(c>='0' && c<='9')
		result=c-'0';
	return result;
}


int getSumMax(char string[], int numbArr[], int strLength)
{
	int charCnt = 0, intIdx = 0, data, sumMax = 0;
	while(charCnt < strLength){
		int result = INT_MAX; // default
		data = CharToDec(string[charCnt++]);
		while(data >= 0){
			if (result == INT_MAX){
				result = 0;
			}
			result *= 10;
			result += data;
			if(charCnt < strLength){
				data = CharToDec(string[charCnt++]);
			}
			else 
				break;
		}
		if (result < INT_MAX) {
			numbArr[intIdx++] = result; 
		}
		// get max value from string
		if (intIdx >= LINE_LENGTH){
			sumMax += find_max_array(intIdx, numbArr);
			intIdx = 0;
		}
	}
	return sumMax;
}

int main(int argc, char **argv)
{
	char input[LINE_LENGTH*LINE_LENGTH*5], symb;
	int num[LINE_LENGTH], len = 0, sum; 
	printf("Input array of numbers:\n"); 
	while( (symb = getchar()) != '\n'){ // get line till RC symbol
		input[len++] = symb;
	}
	if (len == 0){ // check for empty line
		printf("Input is empty, try again\n");
		return 1;
	}
	sum = getSumMax(input, num, len);
	printf("%d", sum);
	return 0;
}


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
#define NUM_LENGTH 100

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


int str2num(char string[], int numbArr[], int strLength)
{
	int charCnt = 0, intIdx = 0, data;
	while(charCnt < strLength){
		int result = INT_MAX; // default
		data = CharToDec(string[charCnt++]);
		while(data >= 0){
			if (result == INT_MAX)
				result = 0;
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
	}
	return intIdx;
}

int main(int argc, char **argv)
{
	char input[NUM_LENGTH*3], symb;
	int num[NUM_LENGTH], len = 0, numCnt, maxVal; 
	printf("Input array of numbers:\n"); 
	while( (symb = getchar()) != '\n') // get line till RC symbol
		input[len++] = symb;
	if (len == 0){ // check for empty line
		printf("Input is empty, try again\n");
		return 1;
	}
	numCnt = str2num(input, num, len);
	if (numCnt == 0){ // check for any numbers
		printf("None numeric symbols were entered, try again\n");
		return 1;
	}
	maxVal = find_max_array(numCnt, num);
	//output
	printf("%d", maxVal);
}


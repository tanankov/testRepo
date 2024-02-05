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
#define LINE_LENGTH 5

int numArrGreaterThanVal(int arr[LINE_LENGTH][LINE_LENGTH], int val)
{
	int counter = 0;
	for(int i = 0; i<LINE_LENGTH; i++)
		for(int j = 0; j<LINE_LENGTH; j++)
			if((arr[i][j] > val) && (arr[i][j] > 0))
				counter++;
	return counter;
}

int meanValMainDiag(int arr[LINE_LENGTH][LINE_LENGTH])
{
	int sum = 0;
	for(int i = 0; i<LINE_LENGTH; i++)
		sum += arr[i][i];
	return sum/LINE_LENGTH;
}

int CharToDec(char c){
	int result=-1;
	if(c>='0' && c<='9')
		result=c-'0';
	return result;
}


void str2matrix(char string[], int numbArr[LINE_LENGTH][LINE_LENGTH], int strLength)
{
	int charCnt = 0, colIdx = 0, data, lineIdx = 0;
	while((charCnt < strLength) && (lineIdx < LINE_LENGTH)){
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
			if (colIdx >= LINE_LENGTH){
				colIdx = 0;
				lineIdx++;
			}
			numbArr[lineIdx][colIdx++] = result; 
		}
		
	}
}

int main(int argc, char **argv)
{
	char input[LINE_LENGTH*LINE_LENGTH*5], symb;
	int num[LINE_LENGTH][LINE_LENGTH], len = 0, meanDiag; 
	printf("Input array of numbers:\n"); 
	while( (symb = getchar()) != '\n'){ // get line till RC symbol
		input[len++] = symb;
	}
	if (len == 0){ // check for empty line
		printf("Input is empty, try again\n");
		return 1;
	}
	str2matrix(input, num, len);
	meanDiag = meanValMainDiag(num);
	printf("%d", numArrGreaterThanVal(num, meanDiag));
	return 0;
}


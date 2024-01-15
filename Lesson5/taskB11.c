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
#define NUM_LENGTH 6

int main(int argc, char **argv)
{
	char num[NUM_LENGTH] = {0}; 
	int length;
	printf("Input number:\n"); 
	scanf_s("%s", num);
	length = strlen(num);
	//char numNew[length];
	for (int i = length-1; i >= 0; i--){
		if ((num[i] < 48) || (num[i] > 57)){ // check if symbol is numeric and non empty
			printf("Non numeric symbol was entered, try again\n"); 
			return 0;
		}
		printf("%c",num[i]);
		//numNew[length-1-i] = num[i];
	}
	printf("\n");
	return 0;
}


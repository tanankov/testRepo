/*
 * taskD4.c
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
#define MAX_NUMBERS 100

void findOdds (int* array);

int main(int argc, char **argv)
{
	int argArr[MAX_NUMBERS], i=0;
	printf("Input numbers:\n"); 
	while(i<MAX_NUMBERS){		
		int stat = scanf_s("%d", &argArr[i]);
		if (stat < 1){
			printf("Non valid number, try again\n"); 
			return 1;
		}
		if (argArr[i] == 0) break;
		i++;
	}
	findOdds(argArr);
	return 0;
}

void findOdds (int* array){
	if (*array != 0){
		if (*array%2 > 0) printf("%d ", *array);
		findOdds(++array);
	}
}

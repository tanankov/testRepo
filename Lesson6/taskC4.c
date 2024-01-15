/*
 * tsakC5.c
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
#include <limits.h>
#define MAX_NUMBERS 100

int func (int arg);

int main(int argc, char **argv)
{
	int argArr[MAX_NUMBERS], i=0, maxVal;
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
	maxVal = func(argArr[0]);
	for (int j = 1; j<=i; j++)
		if (maxVal < func(argArr[j])) maxVal = func(argArr[j]);
	printf("%d", maxVal);
	return 0;
}

int func (int arg){
	if (arg < -2) return -4;
	else if (arg < 2) return arg*arg;
	else return arg*arg + 4*arg + 5;
}


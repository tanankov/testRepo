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
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define NUM_LENGTH 6

int checkNumber(int number);

int main(int argc, char **argv)
{
	int num; 
	int luckyNum = 10;
	printf("Input number:\n"); 
	int stat = scanf_s("%d", &num);
	if ((stat == 0) || (num < 10))  { // check if symbol is numeric and non empty
		printf("Non numeric symbol was entered or number less than 10, try again\n"); 
		return 0;
	}
	while (num > luckyNum)
	{
		if (checkNumber(luckyNum)) printf("%d \n",luckyNum);
		luckyNum++;
	}
	return 0;
}

int checkNumber(int number){ //if lucky return 1 else 0
	int mult = 1, sum = 0;
	do{
		sum += number%10;
		mult *= number%10;
		number /= 10; 
	} while(number > 0);
	if (sum == mult) return 1;
	else return 0;
}


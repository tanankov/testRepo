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

int countOnes(int number);

int main(int argc, char **argv)
{
	int a; 
	printf("Input number:\n"); 
	int stat = scanf_s("%d", &a);
	if ((stat < 1))  { // check if symbol is numeric and non empty
		printf("Non numeric symbol was entered, try again\n"); 
		return 0;
	}
	printf("%d", countOnes(a));
	return 0;
}

int countOnes(int number){
	if (number > 1)	return countOnes(number/2) + number%2;
	else return number;
}

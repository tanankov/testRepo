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

int commonDivider (int num1, int num2);

int main(int argc, char **argv)
{
	int a,b;
	printf("Input 2 numbers:\n"); 
	int stat = scanf_s("%d%d", &a, &b);
	if (stat < 2){
		printf("Non valid numbers, try again\n"); 
		return 1;
	}
	
	printf("%d", commonDivider(a, b));
	return 0;
}

int commonDivider (int num1, int num2){
	int i;
	if (num1>num2){
		int buf = num1;
		num1 = num2;
		num2 = buf;
	}
	for (i = num1; i>1; i--){
		if ((num1%i == 0) && (num2%i == 0)) break;}
	return i;
}


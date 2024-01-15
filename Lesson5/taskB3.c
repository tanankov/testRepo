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
	int a, b, sum = 0;
	printf("Input 2 numbers (-100..100):\n"); 
	int stat = scanf_s("%d%d", &a, &b);
	if ((stat <  2) || (abs(a) > 100) || (abs(b) >100)){
		printf("Non numeric symbols were entered or numbers are not valid, try again\n"); 
		return 1;
	}
	if (a > b){
		int buf = a;
		a = b;
		b = buf;
	}
	for (int i = a; i <= b; i++){
		sum += i*i;
	}
	printf("%d", sum);
	return 0;
}


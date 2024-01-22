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

int recurs_power(int n, int p);

int main(int argc, char **argv)
{
	int num, exp;
	printf("Input number and exponent values (number -100..100, exponent 0.100):\n"); 
	int stat = scanf("%d%d", &num, &exp);
	if ((stat < 2)||(num < -100)||(num>100)||(exp<0)||(exp>100)){
		printf("Values are not valid. Try again");
		return -1;
	}
	printf("%d", recurs_power(num, exp));
}

int recurs_power(int n, int p)
{
	if (p > 0)
		return n * recurs_power(n, p-1);
	else 
		return 1;
}

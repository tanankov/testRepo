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

double riceNumber (int siteNum);

int main(int argc, char **argv)
{
	int number;
	printf("Input site number (1..64):\n"); 
	int stat = scanf_s("%d", &number);
	if ((stat < 1) || (number > 64) || (number < 0)){
		printf("Non valid number, try again\n"); 
		return 1;
	}
	printf("%.0lf", riceNumber(number));
	return 0;
}

double riceNumber (int siteNum){
	double res = 1;
	while (siteNum > 1) {
		res *= (double)2;
		siteNum--;
	}
	return res;
}


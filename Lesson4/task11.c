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

int main(int argc, char **argv)
{
	int a, b, c; 
	printf("Input numbers:\n"); 
	int state = scanf_s("%d%d%d", &a, &b, &c);
	if ((state != 3) || (a < 0) || (b < 0) || (c < 0)){//not all fields filled or number is not valid
		printf("These arent valid numbers, try again\n"); 
		return 0;
	} 
	if ((a + b > c) && (a + c > b) && (b + c > a)) printf("YES");
	else printf("NO");
	return 0;
}


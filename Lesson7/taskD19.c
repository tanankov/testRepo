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
#define MAX_LENGTH_STRING 100

int acounter(void);

int main(int argc, char **argv)
{
	int res;
	printf("Input characters ending on '.':\n"); 
	res = acounter();
	if (res == -1)
		printf("Character is not valid. Try again");
	else
		printf("%d", res);
	return 0;
}

int acounter(void) 
{
	char symb;
	int stat = scanf("%c", &symb);
	if (stat == 0){
		return -1;
	}
	if (symb != '.') 
	{
		if (symb == 'a') 
			return 1 + acounter();
		else
			return acounter();
	}
	else 
		return 0; // end of line
}

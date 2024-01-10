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
	int num;
	printf("Input number:\n"); 
	int state = scanf_s("%d", &num);
	if ((state != 1) || (num < 1) || (num > 12)){//not all fields filled or number is not valid
		printf("This isnt valid number, try again\n"); 
		return 0;
	} 
	switch (num){
		case 1:
		case 2:
		case 12:
		{
			printf("Winter");
			break;
		}
		case 3:
		case 4:
		case 5:
		{
			printf("Spring");
			break;
		}
		case 6:
		case 7:
		case 8:
		{
			printf("Summer");
			break;
		}
		case 9:
		case 10:
		case 11:
		{
			printf("Autumn");
			break;
		}
	}
	return 0;
}


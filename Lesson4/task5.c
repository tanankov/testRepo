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

#include <math.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int x1, y1, x2, y2;
	float k, b; 
	printf("Input 2 dots coord.(ex. x1 y1 x2 y2):\n"); 
	int state = scanf_s("%d%d%d%d", &x1, &y1, &x2, &y2);
	if (state < 4){ // scan unsuccessful
		printf("Invalid numbers were entered, please try again");
		return 1;
	}
	if (x1 > x2) { //swap dots if reverse order
		int buf = x1;
		x1 = x2;
		x2 = buf;
		buf = y1;
		y1 = y2;
		y2 = buf;
	}
	k = (float)(y2 - y1) / (float)(x2 - x1);
	b = (float)y1 - k * (float)x1;
	printf("%.2f %.2f", k, b);
	return 0;
}


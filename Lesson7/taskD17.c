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

long int akkerman(int m, int n);

int main(int argc, char **argv)
{
	int m, n;
	printf("Input numbers:\n"); 
	int stat = scanf_s("%d%d", &m, &n);
	if (stat <2){
		printf("Values are not valid. Try again");
		return 1;
	}
	printf("%ld", akkerman(m, n));
	return 0;
}

long int akkerman(int m, int n){ // from wikipedia
	while (n != 0) {
		if (m == 0) m = 1;
		else m = akkerman(n,m-1);
		n--;
	}
	return (long int)m + 1;
}

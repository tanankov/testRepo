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
	// Сделал цикл до 3 элементов, пока вводятся числа
	int num[10];
	int max, min;
	int cnt = 0; 
	printf("Input numbers (max 3 or enter any symbol after last):\n"); 
	while (cnt<3){
		int state = scanf_s("%d", &num[cnt]);
		if (state == 1){ // scan successful
			 if (cnt == 0){
				 max = num[cnt];
				 min = num[cnt];
			 }
			 else { 
				 if (num[cnt] > max) max = num[cnt];
				 if (num[cnt] < min) min = num[cnt];
			 }
			 cnt++;
		} 
		else break;
	}
	if (cnt > 0) printf("%d", min+max); 
	else printf("No numbers were entered");
	return 0;
}


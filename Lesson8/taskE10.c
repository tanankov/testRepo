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
#define NUM_LENGTH 12
#define NUM_SHIFTS 4

int main(int argc, char **argv)
{
	int num[NUM_LENGTH] = {0}; 
	int buf[NUM_SHIFTS] = {0}; //try to save memory
	printf("Input array of 12 numbers:\n"); 
	for (int i = 0; i < NUM_LENGTH; i++){
		int stat = scanf_s("%d", &num[i]);
		if (stat == 0) { // check if symbol is numeric and non empty
			printf("Non numeric symbol was entered, try again\n"); 
			return 0;
		}
	}
	//shift 4 elements
	for(int i = NUM_LENGTH-1; i >= 0; i--){
		if (i >= NUM_LENGTH - NUM_SHIFTS){ // save last 4 elements to buffer
			buf[NUM_SHIFTS - (NUM_LENGTH - i)] = num[i]; 
		}
		else {
			num[i+NUM_SHIFTS] = num[i];
			if (i < NUM_SHIFTS){
				num[i] = buf[i]; // send buffer to first elements
			}
		}
	}
	// output
	for (int i = 0; i < NUM_LENGTH; i++){
		printf("%d ", num[i]);
	}
	return 0;
}


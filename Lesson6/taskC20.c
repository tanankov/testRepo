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
#include <string.h>

#define MAX_CHARS 1000

int checkString (char *string);

int main(int argc, char **argv)
{
	char string[MAX_CHARS];
	printf("Input string:\n"); 
	int stat = scanf_s("%s", string);
	if (stat < 1){
		printf("Non valid string, try again\n"); 
		return 1;
	}
	if (checkString(string)) printf("YES");
	else printf("NO");
	return 0;
}

int checkString (char *string){
	int count = 0;
	for(int i = 0; i<strlen(string); i++){
		if (string[i] == '(') count++;
		else if (string[i] == ')') count--;
		if (count < 0) return 0; 
	}
	if (count == 0) return 1;
	else return 0;
}


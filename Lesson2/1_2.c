/*
 * homework2.c
 * 
 * Copyright 2023 tanan <tanan@KREMLEBOT>
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
#include <stdlib.h>
#include <string.h>

//const char* dec2hex(int input);

int main(void)
{
	int num1 = 12345678;
	int num2  = 1000000;
	int num3dec;
	int num4dec;
	char num3[] = "12345678";
	char num4[] = "1000000";
	num3dec = (int)strtol(num3, NULL, 16);
	num4dec = (int)strtol(num4, NULL, 16);
	printf("%d in dec -> %x in hex\n", num1, num1);
	printf("%d in dec -> %x in hex\n", num2, num2);
	printf("%x in hex -> %d in dec\n", num3dec, num3dec);
	printf("%x in hex -> %d in dec\n", num4dec, num4dec);

	return 0;
}




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
 * MA 02110-1301, USA.s
 * 
 * 
 */


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#define LINE_LENGTH 1000


int CharToDec(char c){
	int result=-1;
	if(c>='0' && c<='9')
		result=c-'0';
	return result;
}

int PackNumArr(int out[], int in, int arrLen, int flag)
{
	if (flag == 1){
		out[arrLen-1] *= 10; 
		out[arrLen-1] += in;
	}
	else{
		out[arrLen++] = in;
	}
	return arrLen;
}

void sort_arr(int n, int a[])
{
	for(int i = 0; i<n; i++){
		for(int j = n-1; j > i;j--){
			if (a[j-1] > a[j]){
				int buf = a[j-1];
				a[j-1] = a[j];
				a[j] = buf;
			}
		}
	}
}

int main(int argc, char **argv)
{
	FILE *f_in, *f_out;
	char name_in[] = "input.txt";
	char name_out[] = "outG8.txt";
	char c;
	int numCount = 0, output[LINE_LENGTH/2], flag;
	if((f_in = fopen(name_in, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return 1;
    }
    if((f_out = fopen(name_out, "w")) == NULL)
    {
        perror("Error occured while creating output file!");
        return 1;
    }
    while((c = getc(f_in)) != EOF){
		int digit = CharToDec(c);
		if(digit >= 0){
			numCount = PackNumArr(output, digit, numCount, flag);
			flag = 1; // number has started, next func call is the same number
		}
		else
			flag = 0; // number has ended, next func call is other number
	}
	fclose(f_in);
	if(numCount == 0)
    {
        printf("Error! No numbers in file.");
        return 1;
    }
    sort_arr(numCount, output);
    //printf("%s\n", line);
	//printf("%s\n", output);
	for(int i = 0; i < numCount; i++){ 
		fprintf(f_out, "%d ", output[i]);
	}
	fclose(f_out);
	return 0;
}


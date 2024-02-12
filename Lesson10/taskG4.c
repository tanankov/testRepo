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
#define LINE_LENGTH 100

void getRepeatingSymb(char out[], char line1[], char line2[], int len1, int len2)
{
	int counter = 0;
	for(int i = 0; i < len1; i++)
		for(int j = 0; j < len2; j++)
			if(line1[i] == line2[j]){
				out[counter++] = line1[i];
				out[counter++] = ' ';
				break;
			}
}


int main(int argc, char **argv)
{
	FILE *f_in, *f_out;
	char name_in[] = "input.txt";
	char name_out[] = "outG4.txt";
	char c, word1[LINE_LENGTH], word2[LINE_LENGTH], output[2*LINE_LENGTH];
	int count1 = 0, count2 = 0, flag = 0;
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
		if (c == ' ') {
			flag = 1;
		}
		else {
			if (flag == 0)
				word1[count1++] = c;
			else
				word2[count2++] = c;
		}
	}
	if(flag == 0)
    {
        printf("Error! Not enough symbols in input file to operate");
        return 1;
    }
    fclose(f_in);
	getRepeatingSymb(output, word1, word2, count1, count2);
	fprintf(f_out, "%s", output);
	fclose(f_out);
	return 0;
}


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

void replaceAtoB(char out[], char in[], int len)
{
	for(int i = 0; i < len; i++){
		if(in[i] == 'a')
			out[i] = 'b';
		else if(in[i] == 'A')
			out[i] = 'B';
		else if(in[i] == 'b')
			out[i] = 'a';
		else if(in[i] == 'B')
			out[i] = 'A';
		else
			out[i] = in[i];
	}
}


int main(int argc, char **argv)
{
	FILE *f_in, *f_out;
	char name_in[] = "input.txt";
	char name_out[] = "outG5.txt";
	char c, line[LINE_LENGTH];
	int count = 0;
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
    while((c = getc(f_in)) != EOF)
		line[count++] = c;
    fclose(f_in);
    char output[count];
    //printf("%s\n", line);
	replaceAtoB(output, line, count);
	//printf("%s\n", output);
	fprintf(f_out, "%s", output);
	fclose(f_out);
	return 0;
}


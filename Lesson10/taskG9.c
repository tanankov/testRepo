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


int LetterCheck(char c){
	int result=0;
	if((c >= 'a' && c<='z') ||( c >= 'A' && c<='Z'))
		result=1;
	return result;
}

int DuplicateCheck(char out[], char chcr, int outLen)
{
	int flag = 0;
	for (int i = 0; i < outLen; i++){
		if (out[i] == chcr) {
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		out[outLen++] = chcr;
	return outLen;
}


int main(int argc, char **argv)
{
	FILE *f_in, *f_out;
	char name_in[] = "input.txt";
	char name_out[] = "outG9.txt";
	char c, output[LINE_LENGTH];
	int letterCount = 0;
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
		int flag = LetterCheck(c);
		if(flag > 0)
			letterCount = DuplicateCheck(output, c, letterCount);
	}
	fclose(f_in);
	if(letterCount == 0)
    {
        printf("Error! No letters in file.");
        return 1;
    } 
	fprintf(f_out, "%s", output);
	fclose(f_out);
	return 0;
}


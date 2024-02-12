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

int SetURLtoHTML(char out[], char in[], int inLen)
{
	int slashPoint = -1, dotPoint = inLen;
	char postfix[5] = ".html";
	//slashPoint = strrchr(in, '/');
	//dotPoint = strrchr(in, '.');
	for (int i = inLen-1; i >= 0; i--){
		if (in[i] == '/') {
			slashPoint = i;
			break;
		}
		else if ((in[i] == '.') && (dotPoint == inLen)) // only last dot needed
			dotPoint = i;
	}
	if (slashPoint == -1) // URL not valid
		return 1;
	//if ((dotPoint == -1) || (dotPoint < slashPoint)) 
		//dotPoint = inLen;
	for (int i = 0; i < dotPoint + 5; i ++){
		if (i < dotPoint)
			out[i] = in[i];
		else 
			out[i] = postfix[i - dotPoint];
	}
	return 0;
}


int main(int argc, char **argv)
{
	FILE *f_in, *f_out;
	char name_in[] = "input.txt";
	char name_out[] = "outG13.txt";
	char c, url_in[LINE_LENGTH], url_out[LINE_LENGTH];
	int  cnt = 0;
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
		url_in[cnt++] = c;
	}
	fclose(f_in);
	if(cnt == 0)
    {
        printf("Error! No symbols in file.");
        return 1;
    } 
    if (SetURLtoHTML(url_out, url_in, cnt) > 0)
	{
        printf("Error! Invalid URL in file.");
        return 1;
    } 
    
	fprintf(f_out, "%s", url_out);
	fclose(f_out);
	return 0;
}


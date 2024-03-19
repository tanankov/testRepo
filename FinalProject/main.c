
#include "temp_api.h"

#define MAX_RECORDS_NUM 100
#define MAX_PATH_SIZE 100
#define FILE_LINE_LENGTH 25


int main(int argc, char **argv){
    int rez=0;
    opterr=0;
    char filePath [MAX_PATH_SIZE] = "";
    int selMonthNum = 0;
    printf("Welcome to temperature statistic analyzer v0.1!\n\n"); 

    // Parse options
    while ( (rez = getopt(argc,argv,"hf:m:")) != -1){
        switch (rez){
            case 'h': {
                printf("Script function:\n"); 
                printf("Prints mean, max and min temperature values on each year from file given\n"); 
                printf("Avaliable options:\n"); 
                printf("-f <FILEPATH> - input file for analisys (mandatory option);\n"); 
                printf("-m <MONTHNUM> - print statistics only for one month each year (1 - Jan, 2 -Feb ... 12 - Dec)\n");
                printf("-s <FILENAME> - save results\n");  // TODO
                return 0;
            }
            case 'f': {
                memcpy(filePath, optarg, sizeof(optarg));
                break;
            }
            case 'm': {
                char monName[9];
                int len = getMonthName(monName, atoi(optarg));
                if (len > 0){
                    printf("Statistics only for %s is selected\n\n", monName);
                    selMonthNum = atoi(optarg);
                }
                else{
                    printf("Invalid month selected!\nStatistics will be shown for every month\n\n");
                    //return 1;
                }
                break;
            }
            case '?': {
                printf("Unknown option! Try '-h' for help."); 
                return 1;
            }
        }
    }

    // Parse the file
    FILE *inputFile;
    if((inputFile = fopen(filePath, "r")) == NULL)
    {
        printf("Error occured while opening input file!");
        return 1;
    }
    
    tempStorage_t tempStorage[MAX_RECORDS_NUM];
    int lineCnt = 0, itemCnt = 0;
    int fileEnd = 0;
    char line[FILE_LINE_LENGTH] = "";
    while ((fgets(line, FILE_LINE_LENGTH, inputFile)) && (itemCnt < MAX_RECORDS_NUM)) { 
        tempStorage_t lineBuf;
        switch (processLine(line, &lineBuf, selMonthNum)){
            case 0: // line is valid and useful
            {
                if (itemCnt < MAX_RECORDS_NUM){
                    addStructItem(tempStorage + (itemCnt++), &lineBuf);
                }
                else{
                    printf("Max value of temperature records (%d) was exceeded.\nUnprocessed data may not be used.\n");
                }
                break;
            }
            case 1: // line is invalid 
            {
                printf("Line %d has invalid format. Skipping...\n", lineCnt);
                break;
            }
            case 2: // line is valid but not used
                //ignore
        }
        lineCnt++;
    }
    fclose(inputFile);
    if (itemCnt == 0){
        printf("Input file does not have any usable data or data in specified range.\nTry to use different range or different file.");
        return 1;
    }

    // ------Info processing-------
    // Sort array by date
    SortByDate((tempStorage_t *)tempStorage, itemCnt);
    
    // Printing stat
    printStat((tempStorage_t *)tempStorage, itemCnt, selMonthNum);
    

}
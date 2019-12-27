#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CDD.h"

int main(){

    FILE  *fd1; 
    FILE  *fd2; 
    //char line[1000];
    char comma[255];
    int numCommas=0;
    int numLines=0;
    int earthquakeCheck=0;
    unsigned short int records=0; 


    // Open the file for reading only
    fd1 = fopen("/Users/hudaali/Desktop/Assignment6/CDD2.cvs", "r");
    if (!fd1) {
        printf("ERROR: Could not open file\n");
        exit(1);
    } 

    // Open a new file for writing only
    fd2 = fopen("/Users/hudaali/Desktop/Assignment6/CDD2.bin", "w");
    if (!fd2) {
        printf("ERROR: Could not open file\n");
        exit(1);
    }

    while(!feof(fd1)){
        char line[1000];
        fscanf(fd1, "%[^,]s", comma);
        while(fscanf(fd1, "%[^\n]", line)>0){
            numLines++;
            //printf("%s", comma);
            //printf("%s\n", line);
            char compare[9];
            compare[0]=comma[1];
            compare[1]=comma[2];
            compare[2]=comma[3];
            compare[3]=comma[4];
            compare[4]=comma[5];
            compare[5]=comma[6];
            compare[6]=comma[7];
            compare[7]=comma[8];
            compare[8]='\0';
            char *d= "Disaster";

            if(numLines>0 && strcmp(compare,d)==0){
               records++;
                char *pt;
                pt=strtok(line, ",");
                numCommas=0;
                printf("%s\n", pt); 
            }

            break;
        }
    }

    fclose(fd1);
    fclose(fd2);
}
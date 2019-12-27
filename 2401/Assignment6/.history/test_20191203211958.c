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
        while(fscanf(fd1, "%[^\n]", line)>0){
            numLines++;
            fscanf(fd1, "%[^,]s", comma);
            printf("%s\n", line);
            break;
        }
    }

    fclose(fd1);
    fclose(fd2);
}
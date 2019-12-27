#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CDD.h"

int main(){

    FILE  *fd1; 
    FILE  *fd2;
    char M='M';
    char B='B';
    char G='G';
    char type[255];
    char header[255];
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
    fd2 = fopen("/Users/hudaali/Desktop/Assignment6/CDD2.bin", "wb");
    if (!fd2) {
        printf("ERROR: Could not open file\n");
        exit(1);
    }
    
    fwrite(&records, sizeof(short int), 1, fd2);

    while(!feof(fd1)){
        numLines++;
        char line[1000];
        if(numLines==0){
            fscanf(fd1, "%[^\n]s", header);
        }
        fscanf(fd1, "%[^,]s", type);
        printf("%s\n", type);
        fgetc(fd1);
        //printf("%s\n", type);
        char compare[9];
        compare[0]=type[1];
        compare[1]=type[2];
        compare[2]=type[3];
        compare[3]=type[4];
        compare[4]=type[5];
        compare[5]=type[6];
        compare[6]=type[7];
        compare[7]=type[8];
        compare[8]='\0';
        char *d= "Disaster";

        // if(numLines>0 && strcmp(compare,d)==0){
        //     records++;
        //     char *pt;
        //     pt=strtok(line, ",");
        //     numCommas=0;
        //     for(int i=0; i>21; i++){

        //         char comma[255];
        //         printf("%s\n", comma);
        //         fscanf(fd1, "%[^,]s", comma);
        //         fgetc(fd1);
        //         printf("%s\n", comma);

                //printf("Comma %d  ", numCommas);
                //printf("%s\n",pt);
                // if(numCommas==1){
                //     printf("EVENT SUBGROUP %d: %s\n", numLines, pt);
                //     if(strcmp("Meteorological - Hydrological", pt)==0){
                //         fwrite(&M, sizeof(char), 1, fd2);
                //     }
                //     if(strcmp("Geological", pt)==0){
                //         fwrite(&G, sizeof(char), 1, fd2);
                //     }
                //     if(strcmp("Biological", pt)==0){
                //         fwrite(&B, sizeof(char), 1, fd2);
                //     }
                //     numCommas++;
                //     pt = strtok (NULL, ",");
                //     continue;
                // }

                // if(numCommas==2){
                //     printf("EVENT TYPE %d: %s\n", numLines, pt);
                //     for(int i=0; i<20; i++){
                //         if(comma==EventTypes[i]){
                //             if(i==15){
                //                 earthquakeCheck==1;
                //             }
                //             fwrite(&i, sizeof(char), 1, fd2);
                //             break;
                //         }
                //     }
                //     numCommas++;
                //     pt = strtok (NULL, ",");
                //     continue;
                // }

                // if(numCommas==6){
                //     printf("FATALITIES %d: %s\n", numLines, pt);
                //     int fatalities;
                //     fatalities=atoi(pt);
                //     fwrite(&fatalities, sizeof(int), 1, fd2);
                //     numCommas++;
                //     pt = strtok (NULL, ",");
                //     continue;
                // }

                // if(numCommas==7){
                //     printf("INJURIES %d: %s\n", numLines, pt);
                //     int injuries;
                //     injuries= atoi(pt);
                //     fwrite(&injuries, sizeof(int), 1, fd2);
                //     numCommas++;
                //     pt = strtok (NULL, ",");
                //     continue;
                // }

                // if(numCommas==10){
                //     printf("UTILITY %d: %s\n", numLines, pt);
                //     int utility;
                //     utility= atoi(pt);
                //     fwrite(&utility, sizeof(int), 1, fd2);
                //     numCommas++;
                //     pt = strtok (NULL, ",");
                //     continue;
                // }

                // if(numCommas==11 && earthquakeCheck==1){
                //     printf("MAGNITUDE %d: %s\n", numLines, pt);
                //     earthquakeCheck=0;
                //     float magnitude;
                //     magnitude=atoi(pt);
                //     fwrite(&magnitude, sizeof(float), 1, fd2);
                //     numCommas++;
                //     pt = strtok (NULL, ",");
                //     continue;
                // }
                // pt = strtok (NULL, ",");
                // numCommas++;

            //}

        //}
    }

    rewind(fd1);
    fwrite(&records, sizeof(short int), 1, fd2);
    printf("%d\n", records);


    fclose(fd1);
    fclose(fd2);
}
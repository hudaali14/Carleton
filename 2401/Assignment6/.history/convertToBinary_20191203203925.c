#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CDD.h"

int main(){

    FILE  *fd1; 
    FILE  *fd2; 
    char line[255];
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

    printf("Opened files successfully moving to converting...\n");

    while(!feof(fd1) && fscanf(fd1, "%[^\n]s", line)>0){

        numLines++;
        printf("Line %d: %s\n", numLines, line);
        fscanf(fd1, "%[^,]s", comma);
        printf("%s\n", comma);
        printf("\n");
        printf("Line %d: %s\n", numLines, line);

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
            //printf("%s", comma);
            //printf("%s\n", line);
            records++;
            char *pt;
            pt=strtok(line, ",");
            numCommas=0;

            while(pt!=NULL){
                if(numCommas==1){
                    //printf("EVENT SUBGROUP %d: %s\n", numLines, pt);
                    if(strcmp("Meteorological - Hydrological", comma)==0){
                        fwrite(METEOROLOGICAL_HYDROLOGICAL, sizeof(char), 1, fd2);
                    }
                    if(strcmp("Geological", comma)==0){
                        fwrite(GEOLOGICAL, sizeof(char), 1, fd2);
                    }
                    if(strcmp("Biological", comma)==0){
                        fwrite(BIOLOGICAL, sizeof(char), 1, fd2);
                    }
                    numCommas++;
                    pt = strtok (NULL, ",");
                    continue;
                }

                if(numCommas==2){
                    //printf("EVENT TYPE %d: %s\n", numLines, pt);
                    for(int i=0; i<20; i++){
                        if(comma==EventTypes[i]){
                            if(i==15){
                                earthquakeCheck==1;
                            }
                            fwrite(&i, sizeof(char), 1, fd2);
                            break;
                        }
                    }
                    numCommas++;
                    pt = strtok (NULL, ",");
                    continue;
                }

                if(numCommas==5){
                    //printf("FATALITIES %d: %s\n", numLines, pt);
                    int fatalities=*comma;
                    fwrite(&fatalities, sizeof(int), 1, fd2);
                    numCommas++;
                    pt = strtok (NULL, ",");
                    continue;
                }

                if(numCommas==6){
                    //printf("INJURIES %d: %s\n", numLines, pt);
                    int injuries=*comma;
                    fwrite(&injuries, sizeof(int), 1, fd2);
                    numCommas++;
                    pt = strtok (NULL, ",");
                    continue;
                }

                if(numCommas==9){
                    //printf("UTILITY %d: %s\n", numLines, pt);
                    int utility=*comma;
                    fwrite(&utility, sizeof(int), 1, fd2);
                    numCommas++;
                    pt = strtok (NULL, ",");
                    continue;
                }

                if(numCommas==10 && earthquakeCheck==1){
                    //printf("MAGNITUDE %d: %s\n", numLines, pt);
                    earthquakeCheck=0;
                    float magnitude=*comma;
                    fwrite(&magnitude, sizeof(float), 1, fd2);
                    numCommas++;
                    pt = strtok (NULL, ",");
                    continue;
                }
                pt = strtok (NULL, ",");
                numCommas++;
            }
        }
        
    }

    printf("EXITS FINE");

    // if (fclose(fd1) == EOF) {
    //     printf("ERROR: Could not close file\n");
    //     exit(1);
    // }
    // if (fclose(fd2) == EOF) {
    //     printf("ERROR: Could not close file\n");
    //     exit(1);
    // }
    fclose(fd1);
    fclose(fd2);
}

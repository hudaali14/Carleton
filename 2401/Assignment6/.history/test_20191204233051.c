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
    char type[400];
    char header[400];
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
    
    fscanf(fd1, "%[^\n]s", header);
    fscanf(fd1, "\n");

    while(!feof(fd1)){

        //type[0]='\0';
        fscanf(fd1, "%[^,]s", type);
        fgetc(fd1);

        //printf("%s", type);

        if(strcmp(type,"Disaster")==0){
            //printf("equals\n");
            records++;

            for(int i=0; i<21; i++){
                //printf("Entered second for loop\n");
                char comma[40];
                fscanf(fd1, "%[^,]s", comma);
                fgetc(fd1);
                printf("Comma %d: %s\n", i, comma);

                if(i==1){
                    //printf("EVENT SUBGROUP %d: %s\n", numLines, pt);
                    if(strcmp("Meteorological - Hydrological", comma)==0){
                        fwrite(&M, sizeof(char), 1, fd2);
                    }
                    if(strcmp("Geological", comma)==0){
                        fwrite(&G, sizeof(char), 1, fd2);
                    }
                    if(strcmp("Biological", comma)==0){
                        fwrite(&B, sizeof(char), 1, fd2);
                    }
                    continue;
                }

                if(i==2){
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
                    continue;
                }

                if(i==6){
                    //printf("FATALITIES %d: %s\n", numLines, pt);
                    int fatalities;
                    fatalities=atoi(comma);
                    fwrite(&fatalities, sizeof(int), 1, fd2);
                    fgetc(fd1);
                    continue;
                }

                if(i==7){
                    //printf("INJURIES %d: %s\n", numLines, pt);
                    int injuries;
                    injuries= atoi(comma);
                    fwrite(&injuries, sizeof(int), 1, fd2);
                    continue;
                }

                if(i==19){
                    //printf("UTILITY %d: %s\n", numLines, pt);
                    int utility;
                    utility= atoi(comma);
                    fwrite(&utility, sizeof(int), 1, fd2);
                    continue;
                }

                if(i==20){
                    //printf("MAGNITUDE %d: %s\n", numLines, pt);
                    if(earthquakeCheck==1){
                        earthquakeCheck=0;
                        float magnitude;
                        magnitude=atoi(comma);
                        fwrite(&magnitude, sizeof(float), 1, fd2);
                    }
                    fscanf(fd1, "\n");
                    continue;
                }

            }

        }else{
            fscanf(fd1, "%[^\n]s", header);
            fscanf(fd1, "\n");
        }
    }

    rewind(fd1);
    fwrite(&records, sizeof(short int), 1, fd2);
    //printf("%d\n", records);


    fclose(fd1);
    fclose(fd2);
}
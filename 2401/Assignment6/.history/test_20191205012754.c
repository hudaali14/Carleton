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
    fd2 = fopen("/Users/hudaali/Desktop/Assignment6/CDD2.bin", "w");
    if (!fd2) {
        printf("ERROR: Could not open file\n");
        exit(1);
    }
    
    fwrite(&records, sizeof(short int), 1, fd2);
    
    fscanf(fd1, "%[^\n]s", header);
    fscanf(fd1, "\n");

    while(!feof(fd1)){

        fscanf(fd1, "%[^,]s", type);
        fgetc(fd1);

        //printf("%s", type);

        if(strcmp(type,"Disaster")==0){
            records++;

            for(int i=0; i<20; i++){
                char comma[255];

                //printf("BEFORE adding null terminator %d: %s\n", i, comma);
                
                comma[0]='\0';

                //printf("AFTER adding null terminator %d: %s\n", i, comma);

                //printf("\n");

                if(i==19){
                   fscanf(fd1, "%[^\n]s",comma); 
                   fscanf(fd1, "\n");
                   fgetc(fd1);
                }else{
                    fscanf(fd1, "%[^,]s", comma);
                    fgetc(fd1);
                }
                //printf("CURRENT %d: %s\n", i, comma);
                //printf("\n");

                if(i==1){
                    printf("EVENT SUBGROUP: %s\n", comma);
                    if(strcmp("Meteorological - Hydrological", comma)==0){
                        fwrite(&M, sizeof(char), 1, fd2);
                    }
                    if(strcmp("Geological", comma)==0){
                        fwrite(&G, sizeof(char), 1, fd2);
                    }
                    if(strcmp("Biological", comma)==0){
                        fwrite(&B, sizeof(char), 1, fd2);
                    }
                }

                if(i==2){
                    printf("EVENT TYPE: %s\n",  comma);
                    for(int i=0; i<20; i++){
                        if(comma==EventTypes[i]){
                            if(i==15){
                                earthquakeCheck==1;
                            }
                            fwrite(&i, sizeof(char), 1, fd2);
                            break;
                        }
                    }
                }

                if(i==5){
                    printf("FATALITIES: %s\n", comma);
                    int fatalities;
                    fatalities=atoi(comma);
                    fwrite(&fatalities, sizeof(int), 1, fd2);
                    fgetc(fd1);
                }

                if(i==6){
                    printf("INJURIES: %s\n", comma);
                    int injuries;
                    injuries= atoi(comma);
                    fwrite(&injuries, sizeof(int), 1, fd2);
                }

                if(i==7){
                    printf("EVACUTED: %s\n", comma);
                    int evacuted;
                    evacuted= atoi(comma);
                    fwrite(&evacuted, sizeof(int), 1, fd2);
                }

                if(i==18){
                    printf("UTILITY: %s\n", comma);
                    int utility;
                    utility= atoi(comma);
                    fwrite(&utility, sizeof(int), 1, fd2);
                }

                if(i==19){
                    printf("MAGNITUDE: %s\n", comma);
                    if(earthquakeCheck==1){
                        earthquakeCheck=0;
                        float magnitude;
                        magnitude=atoi(comma);
                        fwrite(&magnitude, sizeof(float), 1, fd2);
                    }
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
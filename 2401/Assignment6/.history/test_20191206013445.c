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
    char type[400];                  // Hold event type
    char check[400];                 // Hold check if "Disaster" or "Incident"
    char header[400];                // Hold header
    int earthquakeCheck=0;           // Earthquake check
    unsigned short int records=0;    // Hold number of disasters



    // Open the file for reading only
    fd1 = fopen("CDD2.csv", "r");
    if (!fd1) {
        printf("ERROR: Could not open file\n");
        exit(1);
    }

    // Open a new file for writing only
    fd2 = fopen("CDD2.bin", "w");
    if (!fd2) {
        printf("ERROR: Could not open file\n");
        exit(1);
    }

    // Read in header and newline character
    fscanf(fd1, "%[^\n]s", header);
    fscanf(fd1, "\n");

    // Read in the number of disasters first
    while(!feof(fd1)){

        // Get up to first comma
        fscanf(fd1, "%[^,]s", check);
        fgetc(fd1);

        // Check if disaster if it is then increase records
        if(strcmp(check, "Disaster")==0){
            records++;
        }

        // Skip over rest of the line
        fscanf(fd1, "%[^\n]s", header);
        fscanf(fd1, "\n");
    }

    // Rewinds back to beginning 
    rewind(fd1);

    // Write records to file
    fwrite(&records, sizeof(short int), 1, fd2);

    // Read in header and newline character
    fscanf(fd1, "%[^\n]s", header);
    fscanf(fd1, "\n");

    // While file hasn't closed
    while(!feof(fd1)){

        // Read up to comma
        fscanf(fd1, "%[^,]s", type);
        fgetc(fd1);

        // If its a disaster read through this line
        if(strcmp(type, "Disaster")==0){

            //For all items in line
            for(int i=0; i<20; i++){
                char comma[255];   // Hold up to comma
                comma[0]='\0';     // Empty comma buffer

                // If we reached the end then read up to new line
                if(i==19){
                   fscanf(fd1, "%[^\n]s",comma);
                   fscanf(fd1, "\n");
                
                // Otherwise up to comma
                }else{
                    fscanf(fd1, "%[^,]s", comma);
                    fgetc(fd1);
                }

                // If 1 then its a subgroup and write based on subgroup
                if(i==1){
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

                // If 2 then its a event type and write based on event type      
                if(i==2){
                    for(int i=0; i<20; i++){
                        if(strcmp(comma,EventTypes[i])==0){

                            //If its an earthequake then set off earthquake check
                            if(i==14){
                                earthquakeCheck=1;
                            }
                            fwrite(&i, sizeof(char), 1, fd2);
                            break;
                        }
                    }
                }

                // If 5 then its a fatalities, convert to int and write to file
                if(i==5){
                    int fatalities;
                    fatalities=atoi(comma);
                    fwrite(&fatalities, sizeof(int), 1, fd2);
                }

                // If 6 then its a injured, convert to int and write to file
                if(i==6){
                    int injuries;
                    injuries= atoi(comma);
                    fwrite(&injuries, sizeof(int), 1, fd2);
                }

                // If 7 then its a evacuated, convert to int and write to file
                if(i==7){
                    int evacuted;
                    evacuted= atoi(comma);
                    fwrite(&evacuted, sizeof(int), 1, fd2);
                }

                // If 18 then its a utility, convert to int and write to file
                if(i==18){
                    int utility;
                    utility= atoi(comma);
                    fwrite(&utility, sizeof(int), 1, fd2);
                }

                // If 19 check if earthquake, convert to float and write to file
                if(i==19){
                    if(earthquakeCheck==1){
                        earthquakeCheck=0;
                        float magnitude;
                        magnitude=atof(comma);
                        fwrite(&magnitude, sizeof(float), 1, fd2);
                    }
                }

            }
        }else{

            // If "Incident" then skip over
            fscanf(fd1, "%[^\n]s", header);
            fscanf(fd1, "\n");
        }
    }

    // Close files
    fclose(fd1);
    fclose(fd2);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CDD.h"



typedef struct{
    char subgroup;
    char type;
    int fatalities;
    int injured;
    int evacuated;
    int utilities;
    float magnitude;
} Disaster;


typedef struct{
    char *type;
    int numOfTypes;
} Events;

// Swaps two Event structs
void swap(Events *xp, Events *yp){ 
    Events temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

// Swap the adjacent elements if they are in wrong order
void bubbleSort(Events arr[], int n){ 
    int i, j; 
    for (i = 0; i < n-1; i++){
        // Last i elements are already in place    
        for (j = 0; j < n-i-1; j++){  
            if (arr[j].numOfTypes > arr[j+1].numOfTypes){ 
                swap(&arr[j], &arr[j+1]); 
            }
        }
    }
}

int main(){

    FILE  *fd1;

    short int numOfDisasters;    // Total number of disasters
    int numOfFatalities=0;       // Total number of fatalities
    int numOfInjured=0;          // Total number of injured/infected
    int numOfEvacuated=0;        // Total number of evacuated
    int numOfUtilities=0;        // Total number of utilities
    Disaster mostFatalitiesD;    // Disaster that holds highest number of fatalities
    int mostFatalitiesI=0;       // Highest number of fatalities
    Disaster mostEvacuatedD;     // Disaster that holds highest number of evacuated
    int mostEvacuatedI;          // Highest number of evacuated
    Disaster highestMagnitudeD;  // Disaster that holds highest magnitude
    float highestMagnitudeF;     // Highest magnitude
    
    Events list[20];             // Hold 20 types of disasters
    for(int i=0; i<20; i++){
        list[i].type=EventTypes[i];
        list[i].numOfTypes=0;
    }

    // Open the file for reading only
    fd1 = fopen("/Users/hudaali/Desktop/Assignment6/CDD2.bin", "r");
    if (!fd1) {
        printf("ERROR: Could not open file\n");
        exit(1);
    }

    // Read number of diasaters
    fread(&numOfDisasters,sizeof(short int), 1, fd1);

    // Create disaster array
    Disaster *disasters[numOfDisasters];

    // Hold index for disasters array
    int count=0;

    // Counter for amount of disasters
    int counter=0;

    // Loops through each disaster
    while(counter<numOfDisasters){
        counter++;

        // Allocates memory for the disaster
        Disaster *disas = malloc(sizeof(Disaster));

        // Read subgroup
        fread(&(disas->subgroup), sizeof(char), 1, fd1);

        // Read type, save to Events array, and increase by one
        fread(&(disas->type), sizeof(char), 1, fd1);
        char index=disas->type;
        list[index].numOfTypes+=1;

        // Read fatalites and add to total number of fatalities
        fread(&(disas->fatalities), sizeof(int), 1, fd1);
        numOfFatalities+=disas->fatalities;

        // If fatalities is greater than highest fatalities replace and save data
        if(disas->fatalities >= mostFatalitiesI){
            mostFatalitiesD=*disas;
            mostFatalitiesI=disas->fatalities;
        }

        // Read injured/infected and add to total number of injured
        fread(&(disas->injured), sizeof(int), 1, fd1);
        numOfInjured+=disas->injured;

        // Read evacuated and add to total number of evacuated
        fread(&(disas->evacuated), sizeof(int), 1, fd1);
        numOfEvacuated+=disas->evacuated;

        // If evacuated is greater than highest evacuated replace and save data
        if(disas->evacuated >= mostEvacuatedI){
            mostEvacuatedD=*disas;
            mostEvacuatedI=disas->evacuated;
        }

        // Read utilities and add to total number of utilities
        fread(&(disas->utilities), sizeof(int), 1, fd1);
        numOfUtilities+=disas->utilities;

        // If index(type) is equal to 14 aka "Earthquake" then reads in magnitude
        if(index==14){
            fread(&(disas->magnitude), sizeof(float), 1, fd1);

            // If magnitude is greater than highest magnitude replace and save data
            if(disas->magnitude >= highestMagnitudeF){
                highestMagnitudeD=*disas;
                highestMagnitudeF=disas->magnitude;
            }
        }

        // Add to disasters array and increase count
        disasters[count]=disas;
        count++;

        //continue to next disaster
        continue;

    }

    //prints out all values

    printf("TOTAL NUMBER OF FATALITIES         -> %d\n", numOfFatalities);
    printf("TOTAL NUMBER OF INJURED/INFECTED   -> %d\n", numOfInjured);
    printf("TOTAL NUMBER OF EVACUATED          -> %d\n", numOfEvacuated);
    printf("TOTAL NUMBER OF UTILITIES-AFFECTED -> %d\n", numOfUtilities);
    printf("\n");

    int index1=mostFatalitiesD.type;  // Index in array
    printf("TYPE %s HAD THE MOST FATALITIES WITH  -> %d\n", EventTypes[index1] ,mostFatalitiesI);
    int index2=mostEvacuatedD.type;   // Index in array
    printf("TYPE %s HAD THE MOST EVACUATIONS WITH -> %d\n", EventTypes[index2] ,mostEvacuatedI);
    printf("\n");

    printf("EARTHQUAKE WITH THE HIGHEST MAGNITUDE WAS -> %f\n", highestMagnitudeF);
    printf("\n");

    // Sort list
    bubbleSort(list, 20);

    // Print out in descending order
    for(int i=19; i>=0; i--){
        printf("%s OCCURED %d TIMES\n", list[i].type, list[i].numOfTypes);
    }

    // Free all disasters
    for(int i=0; i>numOfDisasters; i++){
        free(disasters[i]);
    }

    // Close file
    fclose(fd1);

    
}
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


int main(){

    FILE  *fd1;

    short int numOfDisasters;
    int numOfFatalities=0;
    int numOfInjured=0;
    int numOfEvacuated=0;
    int numOfUtilities=0;
    Disaster mostFatalitiesD;
    int mostFatalitiesI=0;
    Disaster mostEvacuatedD;
    int mostEvacuatedI;
    Disaster highestMagnitudeD;
    float highestMagnitudeF;
    int list[20];


    fd1 = fopen("/Users/hudaali/Desktop/Assignment6/CDD2.bin", "r");
    if (!fd1) {
        printf("ERROR: Could not open file\n");
        exit(1);
    }

    fread(&numOfDisasters,sizeof(short int), 1, fd1);
    printf("%d\n", numOfDisasters);
    Disaster *disasters[numOfDisasters];
    int count=0;

    while(!feof(fd1)){
        Disaster *disas = malloc(sizeof(Disaster));

        fread(&(disas->subgroup), sizeof(char), 1, fd1);
        //printf("SUBGROUP: %c\n", disas->subgroup);

        fread(&(disas->type), sizeof(char), 1, fd1);
        //printf("TYPE: %d\n", disas->type);
        int index=disas->type;
        list[index]+=1;

        fread(&(disas->fatalities), sizeof(int), 1, fd1);
        //printf("FATALITIES: %d\n", disas->fatalities);
        numOfFatalities+=disas->fatalities;
        if(disas->fatalities >= mostFatalitiesI){
            mostFatalitiesD=*disas;
            mostFatalitiesI=disas->fatalities;
        }

        fread(&(disas->injured), sizeof(int), 1, fd1);
        //printf("INJURED: %d\n", disas->injured);
        numOfInjured+=disas->injured;


        fread(&(disas->evacuated), sizeof(int), 1, fd1);
        //printf("EVACUATED: %d\n", disas->evacuated);
        numOfEvacuated+=disas->evacuated;
        if(disas->evacuated >= mostEvacuatedI){
            mostEvacuatedD=*disas;
            mostEvacuatedI=disas->evacuated;
        }

        fread(&(disas->utilities), sizeof(int), 1, fd1);
        //printf("UTILITIES: %d\n", disas->utilities);
        numOfUtilities+=disas->utilities;

        if(disas->type==14){
            fread(&(disas->magnitude), sizeof(float), 1, fd1);
            //printf("MAGNITUDE: %0.1f\n", disas->magnitude);
            if(disas->magnitude >= highestMagnitudeF){
                highestMagnitudeD=*disas;
                highestMagnitudeF=disas->magnitude;
            }
        }

        disasters[count]=disas;
        count++;
        continue;

    }

    printf("TOTAL NUMBER OF FATALITIES         -> %d\n", numOfFatalities);
    printf("TOTAL NUMBER OF INJURED/INFECTED   -> %d\n", numOfInjured);
    printf("TOTAL NUMBER OF EVACUATED          -> %d\n", numOfEvacuated);
    printf("TOTAL NUMBER OF UTILITIES-AFFECTED -> %d\n", numOfFatalities);
    printf("\n");

    int index1=mostFatalitiesD.type;
    printf("TYPE %s HAD THE MOST FATALITIES WITH  -> %d\n", EventTypes[index1] ,mostFatalitiesI);
    int index2=mostEvacuatedD.type;
    printf("TYPE %s HAD THE MOST EVACUATIONS WITH -> %d\n", EventTypes[index2] ,mostEvacuatedI);
    printf("\n");

    printf("EARTHQUAKE WITH THE HIGHEST MAGNITUDE WAS -> %f\n", highestMagnitudeF);
    printf("\n");

    for(int i=0; i<20; i++){
        printf("%s OCCURED %d TIMES\n", EventTypes[i], list[i]);
    }


    for(int i=0; i>numOfDisasters; i++){
        free(disasters[i]);
    }


    
}
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
            mostFatalitiesD=disas;
            mostFatalitiesI=disas->fatalities;
        }

        fread(&(disas->injured), sizeof(int), 1, fd1);
        //printf("INJURED: %d\n", disas->injured);
        numOfInjured+=disas->injured;


        fread(&(disas->evacuated), sizeof(int), 1, fd1);
        //printf("EVACUATED: %d\n", disas->evacuated);
        numOfEvacuated+=disas->evacuated;
        if(disas->evacuated >= mostEvacuatedI){
            mostEvacuatedD=disas;
            mostEvacuatedI=disas->evacuated;
        }

        fread(&(disas->utilities), sizeof(int), 1, fd1);
        //printf("UTILITIES: %d\n", disas->utilities);
        numOfUtilities+=disas->utilities;

        if(disas->type==14){
            fread(&(disas->magnitude), sizeof(float), 1, fd1);
            printf("MAGNITUDE: %0.1f\n", disas->magnitude);
            if(disas->magnitude >= highestMagnitudeF){
                highestMagnitudeD=disas;
                highestMagnitudeF=disas->magnitude;
            }
        }

        disasters[count]=disas;
        count++;
        continue;

    }



    for(int i=0; i>numOfDisasters; i++){
        free(disasters[i]);
    }


    
}
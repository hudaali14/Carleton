#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CDD.h"

typedef struct{

    char Subgroup;
    char Type;
    int fatalities;
    int injured;
    int evacuated;
    int utilities;
    int magnitude;

} Disaster;


int main(){

    FILE  *fd1;

    short int numOfDisasters;
    int numOfFatalities=0;
    int numOfInjured=0;
    int numOfevacuated=0;
    int numOfutilities=0;
    Disaster mostFatalities;
    Disaster mostEvacuated;
    Disaster highestMagnitude;
    int list[20];


    fd1 = fopen("/Users/hudaali/Desktop/Assignment6/CDD2.bin", "r");
    if (!fd1) {
        printf("ERROR: Could not open file\n");
        exit(1);
    }

    fscanf(fd1, "%[^\n]d", numOfDisasters);
    printf("%d\n", numOfDisasters);
    Disaster *disasters[numOfDisasters];

    // for(int i=0; i<numOfDisasters; i++){
    //     Disaster *disas=malloc(sizeof(Disaster));



    // }


}
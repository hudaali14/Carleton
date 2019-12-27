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

    fread(&numOfDisasters,sizeof(short int), 1, fd1);
    printf("%d\n", numOfDisasters);
    Disaster *disasters[numOfDisasters];
    int count=0;

    while(!feof(fd1)){
        Disaster *disas = malloc(sizeof(Disaster));

        fread(&(disas->subgroup), sizeof(char), 1, fd1);
        //printf("%c\n", disas->subgroup);
        fread(disas->type, sizeof(char), 1, fd1);
        fread(&(disas->fatalities), sizeof(int), 1, fd1);
        fread(&(disas->injured), sizeof(int), 1, fd1);
        fread(&(disas->evacuated), sizeof(int), 1, fd1);
        fread(&(disas->utilities), sizeof(int), 1, fd1);
        if(strcmp(disas->type, "Earthquake")==0){
            fread(&(disas->magnitude), sizeof(int), 1, fd1);
        }
        

    }

    for(int i=0; i>numOfDisasters; i++){
        free(disasters[i]);
    }


    
}
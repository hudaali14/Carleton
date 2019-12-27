#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// max fish fisher can store in bucket
#define MAX_FISH 10
// max fish pond can store
#define MAX_POND 15

typedef struct{
    unsigned char size;
    char *species;
} Fish;

typedef struct{
    char *name;
    unsigned char keepSize;
    Fish *bucket[MAX_FISH];
    unsigned char numFish;
} Fisher;

typedef struct{
    Fish *fish[MAX_POND];
    unsigned char numFish;
} Pond;

int addFish(Pond *p, unsigned char size, char *species){
    // allocates memory for fish and copy values
    Fish *add = malloc(sizeof(Fish));
    add->size = size;
    add->species=species;

    // If the fish in the pond has passed maximum capacity return 0
    if(p -> numFish >= MAX_POND){
        return 0;
    }else{
        // index of end of fish array
        int index= p -> numFish;

        // stores fish pointer to pond
        p -> fish[index]= add;

        // decreses number of fish in pond and returns 1
        p -> numFish++;
        return 1;
    }
}

void listFish(Fish **arrayOfFish, int n){
    // checks if there are no fish
    if(n!=0){
        // if there are increment through and print size and species of fish
        for(int i=0; i<n; i++){
            printf("%2d cm %s\n", (int) arrayOfFish[i]->size, arrayOfFish[i]->species);
        }
    }

}

char likes(Fisher *fisher, Fish *f){
  /* if fish size id greater than or equal to keepsize and the species is not
  a Sunfish then return 1 else return 0 */
    if((f ->size >= fisher -> keepSize) && (strcmp(f -> species, "Sunfish")!=0)){
        return 1;
    }else{
        return 0;
    }
}

int keep(Fisher *fisher, Fish *f){
  // if fish in bucket has reaches maximum capacity return 0
    if(fisher ->numFish >= MAX_FISH){
        return 0;
    }else{
        // index of end of array in fisher's bucket
        int index=fisher-> numFish;

        // store fish pointer in bucket
        fisher-> bucket[index]= f;

        // decreses number of fish in bucket and returns 1
        fisher -> numFish++;
        return 1;
    }
}

int castLine(Fisher *fisher, Pond *p){
    // index of end of array in fishers's bucket
    int index=p->numFish;

    // get random index from range to end of fish array in bucket
    int rand_num= rand() % index;

    // if fish in bucket has reaches maximum capacity return 0
    if(p -> numFish == 0){
        return 0;
    }else{
       // saves fish pointer to be fish pointer from pond at random index
       Fish *rand_fish= p -> fish[rand_num];

       /* if fisher likes the fish and it adds to the fisher's bucket then
       removes fish from pond and decrese number of fish in pond then return 1*/
       if(((likes(fisher, rand_fish)) > 0) && (keep(fisher, rand_fish)>0)){
           p-> fish[rand_num] = p-> fish[index-1];
           p -> numFish--;
       }
       return 1;
    }
}

void giveAwayFish(Fisher *fisher1, Fisher *fisher2, Pond *p){
    // index of end of fish array in bucket
    int n= fisher1 ->numFish;

    // traverses through fisher1's bucket
    for(int i=0; i<n; i++){

        /* if fisher2 likes the fish and it adds to fisher2's bucket then decrease
        number of fish in fisher1's bucket */
        if((likes(fisher2, fisher1->bucket[i])>0) && (keep(fisher2, fisher1->bucket[i])>0)){
            fisher1->numFish--;

        /* otherwise add fish to pond and decrease number of fish in
        fisher1's bucket*/
        }else{
            int index = p -> numFish;
            p -> fish[index]= fisher1->bucket[i];
            p -> numFish++;
            fisher1->numFish--;
        }
    }
}


int main() {
    srand(time(NULL));

    Pond pondp;
    Pond *pond;
    pond = &pondp;
    pond -> numFish = 0;

    Fisher fredp;
    Fisher *fred;
    fred = &fredp;
    fred -> name = "Fred";
    fred -> numFish = 0;
    fred -> keepSize = 15;

    Fisher suzyp;
    Fisher *suzy;
    suzy = &suzyp;
    suzy -> name = "Suzy";
    suzy -> numFish = 0;
    suzy -> keepSize = 10;

    printf("Here are the fish in the pond:\n");
    addFish(pond, 4, "Sunfish");
    addFish(pond, 25, "Pike");
    addFish(pond, 20, "Bass");
    addFish(pond, 30, "Perch");
    addFish(pond, 14, "Sunfish");
    addFish(pond, 15, "Pike");
    addFish(pond, 9, "Pike");
    addFish(pond, 12, "Bass");
    addFish(pond, 5, "Sunfish");
    addFish(pond, 12, "Sunfish");
    addFish(pond, 10, "Bass");
    addFish(pond, 2, "Bass");
    addFish(pond, 16, "Perch");
    addFish(pond, 30, "Sunfish");
    addFish(pond, 7, "Perch");
    listFish(pond -> fish, pond-> numFish);
    printf("\n");

    printf("First Fred attempts to catch 10 fish in the big pond ...\n");
    castLine(fred, pond);
    castLine(fred, pond);
    castLine(fred, pond);
    castLine(fred, pond);
    castLine(fred, pond);
    castLine(fred, pond);
    castLine(fred, pond);
    castLine(fred, pond);
    castLine(fred, pond);
    castLine(fred, pond);
    printf("Fred's Fish: \n");
    listFish(fred->bucket, fred->numFish);
    printf("\n");

    printf("Suzy now attempts to catch 10 fish in the big pond ...\n");
    castLine(suzy, pond);
    castLine(suzy, pond);
    castLine(suzy, pond);
    castLine(suzy, pond);
    castLine(suzy, pond);
    castLine(suzy, pond);
    castLine(suzy, pond);
    castLine(suzy, pond);
    castLine(suzy, pond);
    castLine(suzy, pond);
    printf("Suzy's Fish: \n");
    listFish(suzy->bucket, suzy->numFish);
    printf("\n");

    printf("Here is what is left of the pond ... \n");
    listFish(pond ->fish, pond-> numFish);
    printf("\n");

    giveAwayFish(suzy, fred, pond);
    printf("Fred's Fish: \n");
    listFish(fred->bucket, fred->numFish);
    printf("\n");
    printf("Suzy's Fish: \n");
    listFish(suzy->bucket, suzy->numFish);
    printf("\n");

    printf("Here are the fish now in the pond: \n");
    listFish(pond ->fish, pond-> numFish);

    //frees all memory that was allocated
    for(int i=0; i<(pond->numFish); i++){
      free(pond->fish[i]);
    }
    for(int j=0; j<(fred->numFish); j++){
      free(fred->bucket[j]);
    }
    for(int k=0; k<(suzy->numFish); k++){
      free(suzy->bucket[k]);
    }

    return 0;

}

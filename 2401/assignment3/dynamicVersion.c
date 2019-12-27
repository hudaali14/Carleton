#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FISH 10
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
    Fish *add = malloc(sizeof(Fish));
    add->size = size;
    add->species=species;
    //printf("%d %s \n%d %s \n", (int) add->size, add->species, (int) size, species);
    if(p -> numFish >= MAX_POND){
        return 0;
    }else{
        //printf("%c \n", p -> numFish);
        int index= p -> numFish;
        //printf("%d \n", index);
        p -> fish[index]= add;
        p -> numFish++;
        //printf("%d \n", p -> numFish);
        return 1;
    }
    //free(add);
}

void listFish(Fish **arrayOfFish, int n){
    if(n!=0){
        for(int i=0; i<n; i++){
            printf("%2d cm %s\n", (int) arrayOfFish[i]->size, arrayOfFish[i]->species);
        }
    }
    
}

char likes(Fisher *fisher, Fish *f){
    //printf("Likes was called \n");
    if((f ->size >= fisher -> keepSize) && (strcmp(f -> species, "Sunfish")!=0)){
        return 1;
    }else{
        return 0;
    }
}

int keep(Fisher *fisher, Fish *f){
    //printf("Keep was called \n");
    if(fisher ->numFish >= MAX_FISH){
        return 0;
    }else{
        //printf("Keep was called \n");
        int index=fisher-> numFish;
        //printf("%d \n", index);
        //printf("%s \n" , fisher-> bucket[index] -> species);
        fisher-> bucket[index]= f;
        //printf("Adding fish to bucket is okay \n");
        fisher -> numFish++;
        //printf("Adding fish to bucket \n");
        return 1;
    }
}

int castLine(Fisher *fisher, Pond *p){
    int index=p->numFish;
    int rand_num= rand() % index;
    //printf("rand num: %d \n", rand_num);
    //printf("fish: %2d cm %s \n",(int) p->fish[rand_num]->size, p->fish[rand_num]->species);
    //printf("%d \n", p->numFish);
    if(p -> numFish == 0){
        return 0;
    }else{
       //printf("There is fish in the pond \n");
       Fish *rand_fish= p -> fish[rand_num];
       //printf("fish: %2d cm %s \n",(int) rand_fish->size, rand_fish->species);
       //printf("%d \n", likes(fisher, rand_fish));
      // printf("%d \n", keep(fisher, rand_fish));
       if(((likes(fisher, rand_fish)) > 0) && (keep(fisher, rand_fish)>0)){
           //printf("rand fish: %2d cm %s \n",(int) p->fish[rand_num]->size, p->fish[rand_num]->species);
           //printf("last fish: %2d cm %s \n",(int) p->fish[index-1]->size, p->fish[index-1]->species);
           p-> fish[rand_num] = p-> fish[index-1];
           //printf("fish: %2d cm %s \n",(int) p->fish[rand_num]->size, p->fish[rand_num]->species);
           //free(p->fish[index-1]);
           p -> numFish--;
       }
       //free(p->fish[index-1]);
       return 1;
    }
}

void giveAwayFish(Fisher *fisher1, Fisher *fisher2, Pond *p){
    int addpond=0;
    //printf("Number of fish in suzys bucket: %d \n", (int) fisher1->numFish);
    int index= fisher1 ->numFish;
    for(int i=0; i< index; i++){
        if(fisher2 -> numFish == MAX_FISH){
            break;
        }else{
            if((likes(fisher2, fisher1->bucket[i])>0) && (keep(fisher2, fisher1->bucket[i])>0)){
                //printf("Fish has been added to fred's bucket \n");
                fisher1->numFish--;
            }else{
                //printf("Fish has been added to pond: %d \n", addpond);
                addpond= addFish(p, fisher1->bucket[i]->size, fisher1->bucket[i]->species);
                fisher1->numFish--;
            }
        }
        //free(&(fisher1->bucket[i]));
    }
}


int main() {
    srand(time(NULL));

    Pond pondp;
    Pond *pond;
    pond = &pondp;
    //pond ->fish=malloc(MAX_POND * sizeof(Fish));
    //Fish *fishes[15];
    pond -> numFish = 0;
    //pond -> fish = fishes;

    Fisher fredp;
    Fisher *fred;
    fred = &fredp;
    //Fish *fishes_fred[10];
    fred -> name = "Fred";
    fred -> numFish = 0;
    fred -> keepSize = 13;
    //fred -> bucket = fishes_fred;

    Fisher suzyp;
    Fisher *suzy;
    suzy = &suzyp;
    //Fish *fishes_suzy[10];
    suzy -> name = "Suzy";
    suzy -> numFish = 0;
    suzy -> keepSize = 10;
    //suzy -> bucket = fishes_suzy;

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
    listFish(*(pond ->fish), pond-> numFish);

    printf("Fred catching fish:\n");
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
    printf("Fish now in Fred's bucket: \n");
    listFish(*(fred->bucket), fred->numFish);

    printf("Suzy catching fish:\n");
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
    printf("Fish now in Suzy's bucket: \n");
    listFish(*(suzy->bucket), suzy->numFish);

    printf("Fish left in pond: \n");
    listFish(*(pond ->fish), pond-> numFish);

    //giveAwayFish(suzy, fred, pond);
    printf("Fish now in Fred's bucket: \n");
    listFish(*(fred->bucket), fred->numFish);
    printf("Fish now in Suzy's bucket: \n");
    listFish(*(suzy->bucket), suzy->numFish);

    printf("Fish left in pond: \n");
    listFish(*(pond ->fish), pond-> numFish);

    //free(pond-> fish);
    return 0;
    
}
#include <stdio.h>

int main(){

    //intialize values
    float length;
    float width;
    float maxlen1 = 0;     //maximum length for curb pieces
    float maxlen2 = 0;     //maximum length for paver stones
    float maxwid1 = 0;     //maximum width for curb pieces
    float maxwid2 = 0;     //maximum width for paver stones
    float curbs = 0;       //number of curb pieces 
    float stonelen = 0;    //number of paver stones along the length
    float stonewid  = 0;   //number of paver dtones along the width
    float stones = 0;      //number of paver stones
    float lengthstone = 0; //length of paver stone minus the curb pieces
    float hst = 0;
    float total = 0;

    //asks user for length and width then converts to inches
    printf("Enter the length you wish your patio to be\n");
    scanf("%f", &length);
    while(getchar()!='\n');
    printf("Enter the width you wish your patio to be\n");
    scanf("%f", &width);
    while(getchar()!='\n');

    //convert feet to inches
    width= width*12;
    length=length*12;

    //if length or width is less than 24 inches exit from program
    if (width<24 || length<24){
        printf("Sorry, either the length or width you entered is shorter than 24 inches\n");
        return 0;  
    }
    
    //calculates amount of curb paver needed for both sides of the length
    while (maxlen1<=length){
        curbs+=2;
        maxlen1+=11.8;
    }

    //since adding curb pavers length it has reduced the amount needed to cover the width
    width= width-8.6;
    
    //calculates amount of curb pavers needed for both sides on the width
    while (maxwid1<=width){
        curbs+=2;
        maxwid1+=11.8;
    }

    //the length of the stones had also been reduced by the curb pavers so we reduced the length needed to cover the patio
    length=length-8.6;
    
    //calculates amount of stones needed to fill the length of the patio
    while (maxlen2<=length){
        stonelen+=1;
        maxlen2+=7.75;
    }

    //calculates amount of stones needed to fill the width of the patio
    while (maxwid2<=width){
        stonewid+=1;
        maxwid2+=7.75;
    }
 
    //if we multiply the amount of stones needed to cover the length and width we'll calculate the amount needed to cover the full patio
    stones=(stonelen*stonewid)*3.90;
    curbs=curbs*2.48;
    printf("The paver stones total will be %f \n", stones);
    printf("The concrete curb pieces total will be %f \n", curbs);
    hst= (stones+curbs)*0.13;
    printf("The tax total will be %f \n", hst);
    total=(stones+curbs)*1.13;
    printf("The total will be %f \n", total);
    return 0;

}

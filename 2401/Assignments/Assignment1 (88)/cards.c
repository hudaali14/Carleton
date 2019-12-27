#include <stdio.h>

// isVaildRank function check if char c is a vaild rank then return 1 else return 0
char isVaildRank(char c){
    if(c=='2'){
        return 1;
    }else if(c=='3'){
        return 1;
    }else if (c=='4'){
        return 1;
    }else if(c=='5'){
        return 1;
    }else if(c=='6'){
        return 1;
    }else if(c=='7'){
        return 1;
    }else if(c=='8'){
        return 1;
    }else if(c=='9'){
        return 1;
    }else if(c=='J'){
        return 1;
    }else if(c=='Q'){
        return 1;
    }else if(c=='K'){
        return 1;
    }else if(c=='A'){
        return 1;
    }else{
        return 0;
    }
}

// isVaildSuit function check if char c is a vaild suit then return 1 else return 0
char isVaildSuit(char c){
    if(c=='H'){
        return 1;
    }else if(c=='D'){
        return 1;
    }else if(c=='S'){
        return 1;
    }else if(c=='C'){
        return 1;
    }else{
        return 0;
    }
}

// getTrump() function returns a vaild suit
char getTrump(){
    char suit;    // store trump suit

    // continously ask user for suit till vaild suit is entered
    do{
        printf("Please enter a vaild suit from the following: H, D, S, C \n");
        scanf("%c", &suit);
        while(getchar()!='\n');
        if(isVaildSuit(suit)==1){
            return suit;
        }
        printf("Error vaild suit was not entered. \n");
    }while (isVaildSuit(suit)==0);
    return 0;
}

// compareRanks function compares the rank of two cards' rank and returns either 1 or 0
int compareRanks(char black, char white){
    
    // converts card to number for easy comparison
    if(black =='J'){
        black = 10;
    }else if(black =='Q'){
        black=11;
    }else if(black=='K'){
        black=12;
    }else if(black=='A'){
        black=13;
    }else{
        black= black - '0';
    }
    
    if(white=='J'){
        white=10;
    }else if(white=='Q'){
        white=11;
    }else if(white=='K'){
        white=12;
    }else if(white=='A'){
        white=13;
    }else{
        white= white - '0';
    }

    // cast to integer
    int blackRank= (int) black;
    int whiteRank= (int) white;

    // compares rank. If black rank is higher returns 1 else returns 0
    if(blackRank > whiteRank){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char trump= getTrump();      // get trump suit from user and store in variable
    char card[3];                // store card
    char players[8];             // store all four players' cards
    int index=0;                 // count index for players' array        
    int player=1;                // count which players have vaild cards
    
    // ask user for each players' cards and doesn't stop till all four players have vaild cards
    do{
        printf("Player %d: Enter card rank and suit (e.g., 2S, TC, KD) \n", player);
        scanf("%c%c", &card[0], &card[1]);
        while(getchar()!='\n');

        //if any player enter '.' then exits program 
        if(card[0]=='.'){
            return 0;
        }
        if(((isVaildRank(card[0]))==1) && ((isVaildSuit(card[1]))==1)){
            player++;
            players[index]=card[0];       // add all players' ranks to list
            index++;
            players[index]=card[1];       // add all players' suits to list
            index++;
            continue;
        }
        printf("Invaild card, please re-enter card \n");
    }while(player<5);

    // print all four players ranks and suits
    printf("%c%c, %c%c, %c%c, %c%c \n", players[0], players[1], players[2], players[3], players[4], players[5], players[6], players[7]);
    char suitLed=players[1];                             // store suitled
    char winningCard[2]={players[0], players[1]};        // store winningcard initially with player1's rank and suit
    
    /* first check if any players have a trump suit. If one player does they win, but if two players have trump suits, 
    call upon compareRanks funtion to determine which player has higher rank */
    for(int i=1; i<8; i+=2){
        if(winningCard[1]==trump && winningCard[1]==players[i]){
            if(compareRanks(players[i-1], winningCard[0])==1){
                winningCard[0]=players[i-1];
                winningCard[1]=players[i];
            }
        }else if(players[i]==trump){
            winningCard[0]=players[i-1];
            winningCard[1]=players[i];
        }else{
            continue;
        }
    }

    //If one of the player does have a trump card this means we don't need to check the suitLed and that player wins
    if(winningCard[1]==trump){
        int count=1;               //check which player has the winning card

        //check which player has the winning card and display that player as the winner then exit program
        for(int j=0; j<8; j+=2){
            if(winningCard[0]==players[j] && winningCard[1]==players[j+1]){
                printf("Player %d has the winning card \n", count);
                return 0;
            }
            count++;
        }

    // this means there are no players with a trump suit which means we need to check which player has the highest suitLed suit
    }else{

        /* check if any players have a higher rank suitLed suit then the first player. If another player had a 
        suitLed suit, call upon compareRanks funtion to determine which player has higher rank */
        for(int i=1; i<8; i+=2){
            if(winningCard[1]==suitLed && winningCard[1]==players[i]){
                if(compareRanks(players[i-1], winningCard[0])==1){
                    winningCard[0]=players[i-1];
                    winningCard[1]=players[i];
                }
            }else if(players[i]==suitLed){
                winningCard[0]=players[i-1];
                winningCard[1]=players[i];
            }else{
                continue;
            }
        }   
    }
    if(winningCard[1]==suitLed){
        int count=1;               //check which player has the winning card

        //check which player has the winning card and display that player as the winner then exit program
        for(int j=0; j<8; j+=2){
            if(winningCard[0]==players[j] && winningCard[1]==players[j+1]){
                printf("Player %d has the winning card \n", count);
                return 0;
            }
            count++;
        } 
    }

    return 0;
}

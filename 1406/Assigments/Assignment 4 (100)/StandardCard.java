package comp1406a4;

import comp1406a4.Card;
import java.util.*;

public class StandardCard extends Card{

    public StandardCard(String rank, String suit){
        super(suit, rank);
        if(rank==Card.RANKS[1]){
            this.suit=Card.SUITS[4];
        }
    }

    public StandardCard(int rank, String suit){
        super(suit, Card.RANKS[rank]);
        if(rank==1){
            this.suit=Card.SUITS[4];
        }
    }

    @Override
    public int getRankValue(){
        if(this.rank==Card.RANKS[0]){
            return 0;
        }else if(this.rank==Card.RANKS[1]){
            return 1;
        }else if(this.rank==Card.RANKS[2]){
            return 2;
        }else if(this.rank==Card.RANKS[3]){
            return 3;
        }else if(this.rank==Card.RANKS[4]){
            return 4;
        }else if(this.rank==Card.RANKS[5]){
            return 5;
        }else if(this.rank==Card.RANKS[6]){
            return 6;
        }else if(this.rank==Card.RANKS[7]){
            return 7;
        }else if(this.rank==Card.RANKS[8]){
            return 8;
        }else if(this.rank==Card.RANKS[9]){
            return 9;
        }else if(this.rank==Card.RANKS[10]){
            return 10;
        }else if(this.rank==Card.RANKS[11]){
            return 11;
        }else if(this.rank==Card.RANKS[12]){
            return 12;
        }else if(this.rank==Card.RANKS[13]){
            return 13;
        }else{
            return 14;
        }
    }

    @Override
    public int compareTo(Card other){
        int rank1=this.getRankValue();
        int rank2=other.getRankValue();
        if(this.getRank() == Card.RANKS[1]) {
            rank1=15;
        }
        if(other.getRank() == Card.RANKS[1]){
            rank2=15;
        }

        if(this.getSuit() == Card.SUITS[3]){
            if(other.getSuit() == Card.SUITS[0] || other.getSuit() == Card.SUITS[1] || other.getSuit() == Card.SUITS[2]) {
                return 1;
            }else{
                if(rank1>rank2){
                    return 1;
                }else if(rank1<rank2){
                    return -1;
                }else{
                    return 0;
                }
            }
        }else if(this.getSuit()==Card.SUITS[2]){
            if(other.getSuit() == Card.SUITS[3]) {
                return -1;
            }else if(other.getSuit() == Card.SUITS[0] || other.getSuit() == Card.SUITS[1]) {
                return 1;
            }else{
                if(rank1>rank2){
                    return 1;
                }else if(rank1<rank2){
                    return -1;
                }else{
                    return 0;
                }
            }
        }else if(this.getSuit() == Card.SUITS[1]){
            if(other.getSuit() == Card.SUITS[2] || other.getSuit() == Card.SUITS[3]) {
                return -1;
            }else if(other.getSuit() == Card.SUITS[0]) {
                return 1;
            }else{
                if(rank1>rank2){
                    return 1;
                }else if(rank1<rank2){
                    return -1;
                }else{
                    return 0;
                }
            }
        }else if(this.getSuit() == Card.SUITS[0]){
            if(other.getSuit() == Card.SUITS[1] || other.getSuit() == Card.SUITS[2] || other.getSuit() == Card.SUITS[3]) {
                return -1;
            }else{
                if(rank1>rank2){
                    return 1;
                }else if(rank1<rank2){
                    return -1;
                }else{
                    return 0;
                }
            }
        }else{
            if(this.getRank() == Card.RANKS[1] && other.getRank() != Card.RANKS[1]) {
                return 1;
            }else if(other.getRank() == Card.RANKS[1] && this.getRank() != Card.RANKS[1]){
                return -1;
            }else{
                return 0;
            }
        }
    }

    public static void main(String[] args){
        StandardCard[] array= new StandardCard[30];
        Random random= new Random();
        for(int i=0; i<array.length; i++){
            int suits=random.nextInt(Card.SUITS.length);
            int ranks=random.nextInt(Card.RANKS.length);
            while(suits==4 && ranks!=1 || ranks==0){
                suits=random.nextInt(Card.SUITS.length);
                ranks=random.nextInt(Card.RANKS.length);
            }
            if(i%2==0){
                array[i]= new StandardCard(Card.RANKS[ranks], Card.SUITS[suits]);
            }else{
                array[i]= new StandardCard(ranks, Card.SUITS[suits]);
            }
            System.out.println(array[i].getRankValue());
        }
        System.out.println(Arrays.toString(array));
        Arrays.sort(array);
        System.out.println(Arrays.toString(array));
    }

}
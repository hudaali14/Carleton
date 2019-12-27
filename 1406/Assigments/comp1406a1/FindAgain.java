package comp1406a1;

public class FindAgain{

    public static int[] locateAllSequenceLocations(int[] target, int[] Sequence){
        int total=0;
        int count=0;
        int seq=0;
        int wrong=0;
        int indexs=1;
        for (int i=0; i<Sequence.length; i++){
            if (target.length==1){
                if (target[0]==Sequence[i]){
                    seq+=1;
                    indexs+=1;
                }
            }else{
                if (i!=Sequence.length-1 && count!=target.length-1){
                    if (Sequence[i]==target[count] && Sequence[i+1]==target[count+1]){
                        seq+=1;
                        count+=1;
                        if (count==1){
                            indexs+=1;
                        }
                    }
                    else{
                        wrong+=1;
                    }
                }
            }
            if (target.length==1){
                if (seq==target.length){
                    total+=1;
                    seq=0;
                    count=0;
                }
            }else{
                if (seq==target.length-1){
                    total+=1;
                    seq=0;
                    count=0;
                }
            }
            if (wrong==1 && seq>=1){
                indexs-=1;
                seq=0;
                count=0;
            }
            wrong=0;
        }
        if (seq>=1){
            indexs-=1;
            seq=0;
            count=0;
        }
        int[] arr= new int[indexs];
        arr[0]=total;
        int counter=1;
        int index=1;
        for (int j=0; j<Sequence.length; j++){
            if (target.length==1){
                if (target[0]==Sequence[j]){
                    seq+=1;
                    arr[counter]=j;
                    counter+=1;
                }
            }else{
                if (j!=Sequence.length-1 && count!=target.length-1){
                    if (Sequence[j]==target[count] && Sequence[j+1]==target[count+1]){
                        seq+=1;
                        count+=1;
                        if (count==1){
                            index=j;
                        }
                    }else{
                        wrong+=1;
                    }
                }
            }
            if (target.length==1){
                if (seq==target.length){
                    seq=0;
                    count=0;
                }
            }else{
                if (seq==target.length-1){
                    arr[counter]=index;
                    counter+=1;
                    seq=0;
                    count=0;
                }
            }
            if (wrong==1 && seq>=1){
                seq=0;
                count=0;
            }
            wrong=0;
        }
        return arr;
    }
}
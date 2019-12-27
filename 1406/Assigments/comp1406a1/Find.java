package comp1406a1;

/** Assignment 1 - Winter 2019
  * <p>
  * Problem 1
  * <p>
  * In the provided Find.java file, complete the locateSequence method. 
  * For a given target sequence (non-empty array of integers), the method 
  * searches the input array (of integers) to find an occurrence of the 
  * target sequence if it is present. If the sequence is present, the 
  * method returns the array index position of where it starts in the array. 
  * If the sequence is not present, the method returns -1.
  */
public class Find{
  
  /** Finds the last occurrence of the sequence in the array or indicates that 
    * the sequence is not present.
    * 
    * @param sequence is an array of one or more integers. 
    *        It is the target sequence we are looking for.
    * 
    * @param array is an array integers. 
    * 
    * @return the starting position of the last occurrence of the target sequence in the 
    *         array if it exists. Returns -1 otherwise.
    */
  public static int locateSequence(int[] sequence, int[] array){
    int index=0;
    int index2=0;
    int total=0;
    int count=0;
    int seq=0;
    int wrong=0;
    for(int i=0; i<array.length; i++){
      if (sequence.length==1){
         if (sequence[0]==array[i]){
            seq+=1;
            index=i;
         }
      }else{
        if (i!=array.length-1 && count!=sequence.length-1){
          if (array[i]==sequence[count] && array[i+1]==sequence[count+1]){
            seq+=1;
            count+=1;
            if(count==1){
              index=i;
              }
          }
          else{
            wrong+=1;
          }
        }
      }
      if (sequence.length==1){
        if (seq==sequence.length){
           total+=1;
           seq=0;
           count=0;
           index2=index;
        }
      }else{
        if (seq==sequence.length-1){
          total+=1;
          seq=0;
          count=0;
          index2=index;
        }
      }
      if (wrong==1 && seq>=1){
        index=index2;
        seq=0;
        count=0;
      }
      wrong=0;  
    }
    index=index2;
    if (total>=1){
      return index;
    }
    else{
      return -1;
    }
  }
}
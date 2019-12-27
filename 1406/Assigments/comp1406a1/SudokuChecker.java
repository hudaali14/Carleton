package comp1406a1;

/** Assignment 1 - Winter 2019
  * <p>
  * Problem 4
  * <p> 
  * In this problem, you will complete three methods to check if a SUDOKU game is valid or not.
  */

  public class SudokuChecker{



  	/** checks if row 'row' is OK in the grid */	
    public static boolean checkRow(int row, byte[][] grid){
      int[] nums= new int[]{0,0,0,0,0,0,0,0,0};
      int count=0;
      int zeros=0;
      for (int row2 = 0; row2 < grid[row].length; row2++) {
        for (int i=0; i<nums.length; i++){  
          if (grid[row][row2]!=nums[i]){
            nums[count]=grid[row][row2];
            count+=1;
            break;
          }else{
            nums[count]=0;
            count+=1;
            break;
          }
        }
      }
      for (int j=0; j<nums.length; j+=1){
        if (nums[j]==0){
          zeros+=1;
        }
      }
      if (zeros==0){
        return true;
      }else{
        return false;
      }
    }

  	/** checks if column 'col' is OK in the grid */
    public static boolean checkColumn(int col, byte[][] grid){
      int[] nums= new int[]{0,0,0,0,0,0,0,0,0};
      int count=0;
      int zeros=0;
      for (int col2 = 0; col2 < grid.length; col2++) {
        for (int i=0; i<nums.length; i++){  
          if (grid[col2][col]!=nums[i]){
            nums[count]=grid[col2][col];
            count+=1;
            break;
          }else{
            nums[count]=0;
            count+=1;
            break;
          }
        }
      }
      for (int j=0; j<nums.length; j+=1){
        if (nums[j]==0){
          zeros+=1;
        }
      }
      if (zeros==0){
        return true;
      }else{
        return false;
      }
    }

  	/** checks if the subregion 'region' is OK in the grid */
    public static boolean checkSubregion(int region, byte[][] grid){
      int[] nums= new int[]{0,0,0,0,0,0,0,0,0};
      int count=0;
      int counter=0;
      int zeros=0;
      int start1=0;
      int start2=0;
      if (region==0){
        start1=0;
        start2=0;
      }else if(region==1){
        start1=0;
        start2=3;
      }else if(region==2){
        start1=0;
        start2=6;
      }else if(region==3){
        start1=3;
        start2=0;
      }else if(region==4){
        start1=3;
        start2=3;
      }else if(region==5){
        start1=3;
        start2=6;
      }else if(region==6){
        start1=6;
        start2=0;
      }else if(region==7){
        start1=6;
        start2=3;
      }else{
        start1=6;
        start2=6;
      }
      for (int sub=start1; sub<(start1+3); sub++) {
        for (int sub2= start2; sub2<(start2+3); sub2++){    
          for (int i=0; i<nums.length; i++){  
            if (grid[sub][sub2]==nums[i]){
              counter+=1;
            }
          }
          if (counter==0){
            nums[count]=grid[sub][sub2];
            count+=1;
          }else{
            count+=1;
          }
        }
      }
      for (int j=0; j<nums.length; j+=1){
          if (nums[j]==0){
              zeros+=1;
          }
      }
      if (zeros==0){
        return true;
      }else{
        return false;
      }
    }


    public static boolean check(byte[][] grid){
      // check the subregions
      for(int subregion=0; subregion<9; subregion+=1){  
        if( !checkSubregion(subregion, grid) ){
          return false;
        }
      }

      // check the rows
      for(int row=0; row<9; row+=1){                    
        if( !checkRow(row, grid) ){
          return false;
        }
      }

     // check the rows
     for(int col=0; col<9; col+=1){                    
        if( !checkColumn(col, grid) ){
          return false;
        }
      }
    
  		
  		// if we get this far then we conclude that the grid
  		// must be valid (because if it was not, we would have
  		// returned false somewhere above)
      return true;
    }
      


    public static void main(String[] args){

      System.out.print("exmample1 | expected output is true  | actual output is ");
      System.out.println(check(example1));

      System.out.print("exmample2 | expected output is false | actual output is ");
      System.out.println(check(grid));

    }


      /** sample valid game */
    public static byte[][] grid = new byte[][]{
      {5,3,4,6,7,8,9,1,2},
      {6,7,2,1,9,5,3,4,8},
      {1,9,8,3,4,2,5,6,7},
      {8,5,9,7,6,1,4,2,3},
      {4,2,6,8,5,3,7,9,1},
      {7,1,3,9,2,4,8,5,6},
      {9,6,1,5,3,7,2,8,4},
      {2,8,7,4,1,9,6,3,5},
      {3,4,5,2,8,6,1,7,9}};

    public static byte[][] example1 = new byte[][]{  
      {2,9,5,7,4,3,8,6,1},
      {4,3,1,8,6,5,9,2,7},
      {8,7,6,1,9,2,5,4,3},
      {3,8,6,4,5,9,2,1,6},
      {6,1,2,3,8,7,4,9,5},
      {5,4,9,2,1,6,7,3,8},
      {7,6,3,5,3,4,1,8,9},
      {9,2,8,6,7,1,3,5,4},
      {1,5,4,9,3,8,6,7,2}};

    /** sample invalid game */
    public static byte[][] example2 = new byte[][]{
      {5,3,4,6,7,8,9,1,2},
      {6,7,2,1,9,5,3,4,8},
      {1,9,8,3,4,2,5,6,7},
      {8,5,9,7,6,1,4,2,3},
      {4,2,6,8,5,3,7,9,1},
      {7,1,3,9,2,4,8,5,6},
      {9,6,1,5,3,7,2,8,3},
      {2,8,7,4,1,9,6,2,6},
      {3,4,5,2,8,6,1,8,8}};

}
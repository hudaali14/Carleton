package comp1406a1; 

public class Grades{
  
  /** Computes the minimum final exam grade needed to achieve a desired 
    * target letter grade based on provided assignment, tutorial and midterm 
    * grades.
    * <p>
    * The Grade determination is based on that given in the course outline.
    * (See Piazza and be sure to read the course outline!)
    * 
    * @param target is the desired letter grade.
    * @param assignments contains all nine assignment grades (each out of 100). The first six are the main assignments and the last three are the study assignments.
    * @param tutorials contains all 10 tutorial grades (each out of 100). 
    * @param midterms contains all 3 midterm grades (each out of 100).
    * 
    * @return the minimum grade needed to achieve the target letter grade based on 
    *         the provided assignment/tutorial/midterm grades and the description 
    *         provided in the course outline. If the needed final exam grade is more 
    *         than 100.0, return -1.0. If the target grade will be achieved (or surpassed) 
    *         regardless of the final exam mark, returns 0.0.
    */
    public static double finalExamGradeNeeded(String   target,
                                            double[] assignments,
                                            double[] tutorials,
                                            double[] midterms){
        int index=0;
        double min_assignment=100;
        for (int j=6; j<assignments.length; j+=1){
            if (assignments[j]<=min_assignment){
                min_assignment=assignments[j];
                index=j;
            }
        }
        assignments[index]=0;
        for (int n=0; n<2; n+=1){
            double lowest=100;
            int index2=0;
            for (int x=0; x<tutorials.length; x+=1){
                if (tutorials[x]!=0 && tutorials[x]<=lowest){
                    lowest=tutorials[x];
                    index2=x;
                }
            }
            tutorials[index2]=0;
        }
        int index3=0;
        double min_midterm=100;
        for (int i=0; i<midterms.length; i+=1){
            if (midterms[i]<=min_midterm){
                min_midterm=midterms[i];
                index3=i;

            }
        }
        midterms[index3]=0;
        double assignment_grade1=0;
        double assignment_grade2=0;
        double tutorials_grade=0;
        double midterms_grade=0;
        for (int y=0; y<6; y+=1){
            assignment_grade1+=assignments[y];
        }
        for (int w=6; w<assignments.length; w+=1){
            assignment_grade2+=assignments[w];
        }
        assignment_grade1=((assignment_grade1/6)*0.30);
        assignment_grade2=((assignment_grade2/2)*0.02);
        for (double t : tutorials){
            tutorials_grade+=t;
        }
        tutorials_grade=(tutorials_grade/8)*0.08;
        for (double m : midterms){
            midterms_grade+=m;
        }
        midterms_grade=((midterms_grade/2)*0.30);
        double current=0;
        current = ((assignment_grade1+assignment_grade2+tutorials_grade+midterms_grade)/70)*100;
        double required=0;
        if (target.equals("A+")){
            required=(90-current*(1.0-0.3))/0.3;
        }else if (target.equals("A")){
            required=(85-current*(1.0-0.3))/0.3;
        }else if(target.equals("A-")){
            required=(80-current*(1.0-0.3))/0.3;
        }else if(target.equals("B+")){
            required=(77-current*(1.0-0.3))/0.3;
        }else if(target.equals("B")){
            required=(73-current*(1.0-0.3))/0.3;
        }else if(target.equals("B-")){
            required=(70-current*(1.0-0.3))/0.3;
        }else if(target.equals("C+")){
            required=(67-current*(1.0-0.3))/0.3;
        }else if(target.equals("C")){
            required=(63-current*(1.0-0.3))/0.3;
        }else if(target.equals("C-")){
            required=(60-current*(1.0-0.3))/0.3;
        }else if(target.equals("D+")){
            required=(57-current*(1.0-0.3))/0.3;    
        }else if(target.equals("D")){
            required=(53-current*(1.0-0.3))/0.3;
        }else if(target.equals("D-")){
            required=(50-current*(1.0-0.3))/0.3;
        }else{
            required=50;
        }
        if ((midterms_grade+(required*0.3))<=30){
            return ((30-midterms_grade)/30)*100;
        }

        if (required>100){
            return -1.0;
        }
        if (required<0){
            return 0.0;
        }
        return required;
    }
}   
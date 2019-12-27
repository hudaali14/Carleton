package comp1406t2;

import java.lang.Math;

public class Point2D{
	// instance attributes (state of objects)
	double x;
	double y;
	// instance methods (behanviour of objects)
	
	//
	// add your methods here
	//
	public double magnitude(){
		double mag=0;
        mag=Math.sqrt((Math.pow((x-0),2))+(Math.pow((y-0),2)));
        return mag;
	}
	public double distance(Point2D other){
		double dis=0;
        dis=Math.sqrt((Math.pow((this.x-other.x),2))+(Math.pow((this.y-other.y),2)));
        return dis;
	}
	public String toString(){
		return "(" + x + ","+ y+ ")";
	}
	
}

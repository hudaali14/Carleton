package comp1406a5;

public class Blob extends Image{

  	// leave this constructor as is. This is the constructor that we will  use
	// when testing your code.
	public Blob(int rows, int cols){
		super(rows, cols);
	}

  	public void computePixelPerimeters(int row, int column){
		Pixel pixel=getPixel(row, column);
		Pixel top=null;
		Pixel left=null;
		Pixel right=null;
		Pixel bottom=null;
		if((row-1)>=0){
			top=getPixel(row-1, column);
		}
		if((column+1)<cols){
			right=getPixel(row, column+1);
		}
		if((row+1)<rows){
			bottom=getPixel(row+1, column);
		}
		if((column-1)>=0){
			left=getPixel(row, column-1);
		}
		if(pixel.hasInk()==false){
			pixel.setSides(0);
		}else{
			if(pixel.visited()==false){
				pixel.setVisited(true);
				if((top!=null && top.visited()==false)){
					if(top.hasInk()==false){
						pixel.setSides(pixel.getSides()+1);
					}else{
						computePixelPerimeters(row-1,column);
					}
				}
				if(right!=null && right.visited()==false){
					if(right.hasInk()==false){
						pixel.setSides(pixel.getSides()+1);
					}else{
						computePixelPerimeters(row,column+1);
					}
				}
				if(bottom!=null && bottom.visited()==false){
					if(bottom.hasInk()==false){
						pixel.setSides(pixel.getSides()+1);
					}else{
						computePixelPerimeters(row+1,column);
					}
				}
				if(left!=null && left.visited()==false){
					if(left.hasInk()==false){
						pixel.setSides(pixel.getSides()+1);
					}else{
						computePixelPerimeters(row,column-1);
					}
				}
			}
		}
		// System.out.println("("+row+","+column+")= "+ pixel.getSides());
	}

	public int helperPerimeter(int row, int column){
		Pixel pixel=getPixel(row, column);
		boolean top=false;
		boolean left=false;
		boolean right=false;
		boolean bottom=false;
		if(pixel.hasInk()==true && pixel.visited()==true){
			pixel.setExtra(true);
			getPixel(row, column).setExtra(true);
			if((row-1)>=0 && getPixel(row-1, column).hasInk()==true && getPixel(row-1, column).visited()==true && getPixel(row-1, column).getExtra()==null){
				top=true;
				getPixel(row-1, column).setExtra(true);
			}
			if((column+1)<cols && getPixel(row, column+1).hasInk()==true && getPixel(row, column+1).visited()==true && getPixel(row, column+1).getExtra()==null){
				right=true;
				getPixel(row, column+1).setExtra(true);
			}
			if((row+1)<rows && getPixel(row+1, column).hasInk()==true && getPixel(row+1, column).visited()==true && getPixel(row+1, column).getExtra()==null){
				bottom=true;
				getPixel(row+1, column).setExtra(true);
			}
			if((column-1)>=0 && getPixel(row, column-1).hasInk()==true && getPixel(row, column-1).visited()==true && getPixel(row, column-1).getExtra()==null){
				left=true;
				getPixel(row, column-1).setExtra(true);
			}
		}
		if(top==true && right==false && bottom==false && left==false){
			return pixel.getSides() + helperPerimeter(row-1,column);
		}else if(top==false && right==true && bottom== false && left==false){
			return pixel.getSides() + helperPerimeter(row,column+1);
		}else if(top==false && right==false && bottom==true && left==false){
			return pixel.getSides() + helperPerimeter(row+1,column);
		}else if(top==false && right==false && bottom==false && left==true){
			return pixel.getSides() + helperPerimeter(row,column-1);
		}else if(top==true && right==true && bottom==false && left==false){
			return pixel.getSides() + helperPerimeter(row-1,column) + helperPerimeter(row,column+1);
		}else if(top==true && right==false && bottom==true && left==false){
			return pixel.getSides() + helperPerimeter(row-1,column) + helperPerimeter(row+1,column);
		}else if(top==true && right==false && bottom==false && left==true){
			return pixel.getSides() + helperPerimeter(row-1,column) + helperPerimeter(row,column-1);
		}else if(top==false && right==true && bottom==true && left==false){
			return pixel.getSides() + helperPerimeter(row,column+1) + helperPerimeter(row+1,column);
		}else if(top==false && right==true && bottom==false && left==true){
			return pixel.getSides() + helperPerimeter(row,column+1) + helperPerimeter(row,column-1);
		}else if(top==false && right==false && bottom==true && left==true){
			return pixel.getSides() + helperPerimeter(row+1,column) + helperPerimeter(row,column-1);
		}else if(top==true && right==true && bottom==true && left==false){
			return pixel.getSides() + helperPerimeter(row-1,column) + helperPerimeter(row,column+1) + helperPerimeter(row+1,column);
		}else if(top==true && right==false && bottom==true && left==true){
			return pixel.getSides() + helperPerimeter(row-1,column) + helperPerimeter(row+1,column) + helperPerimeter(row,column-1);
		}else if(top==true && right==true && bottom==false && left==true){
			return pixel.getSides() + helperPerimeter(row-1,column) + helperPerimeter(row,column+1) + helperPerimeter(row,column-1);
		}else if(top==false && right==true && bottom==true && left==true){
			return pixel.getSides() + helperPerimeter(row,column+1) + helperPerimeter(row+1,column) + helperPerimeter(row,column-1);
		}else if(top==true && right==true && bottom==true && left==true){
			return pixel.getSides() + helperPerimeter(row-1,column) + helperPerimeter(row,column+1) + helperPerimeter(row+1,column) + helperPerimeter(row,column-1);
		}else{
			return pixel.getSides();
		}
	}


	public int perimeter(int row, int column){
		clearImage();
		computePixelPerimeters(row, column);
		return helperPerimeter(row, column);
	}

	public static void main(String[] args){
		// for testing...
		// Image img = Helper.makeRandomImage(20,80,0.45);
		Image img = new Blob(3,3);
		Pixel pixel1=new Pixel(0,0, false);
		Pixel pixel2=new Pixel(0,1, false);
		Pixel pixel3=new Pixel(0,2, true);
		Pixel pixel4=new Pixel(1,0, false);
		Pixel pixel5=new Pixel(1,1, true);
		Pixel pixel6=new Pixel(1,2, true);
		Pixel pixel7=new Pixel(2,0, false);
		Pixel pixel8=new Pixel(2,1, true);
		Pixel pixel9=new Pixel(2,2, false);
		img.pixels[0][0]=pixel1;
		img.pixels[0][1]=pixel2;
		img.pixels[0][2]=pixel3;
		img.pixels[1][0]=pixel4;
		img.pixels[1][1]=pixel5;
		img.pixels[1][2]=pixel6;
		img.pixels[2][0]=pixel7;
		img.pixels[2][1]=pixel8;
		img.pixels[2][2]=pixel9;
		System.out.println(img);
		// ((Blob)img).computePixelPerimeters(19,19);
		// img.clearImage();
		System.out.println(((Blob)img).perimeter(0,0));
		System.out.println(((Blob)img).perimeter(0,1));
		System.out.println(((Blob)img).perimeter(0,2));
		System.out.println(((Blob)img).perimeter(1,0));
		System.out.println(((Blob)img).perimeter(1,1));
		System.out.println(((Blob)img).perimeter(1,2));
		System.out.println(((Blob)img).perimeter(2,0));
		System.out.println(((Blob)img).perimeter(2,1));
		System.out.println(((Blob)img).perimeter(2,2));
		// System.out.println(((Blob)img).perimeter(0,0));
		// ((Blob)img).computePixelPerimeters(19,0);
		// img.clearImage();
		// System.out.println(((Blob)img).perimeter(0,0));
		// ((Blob)img).computePixelPerimeters(0,19);
		// System.out.println(((Blob)img).perimeter(0,1));
		// ((Blob)img).computePixelPerimeters(0,0);
		// img.clearImage();
		// System.out.println(((Blob)img).perimeter(0,2));
		// img.clearImage();
		// System.out.println(((Blob)img).perimeter(0,2));

		// System.out.println(((Blob)img).perimeter(0,2));
	}


}

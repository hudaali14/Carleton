package comp1406a5;
import java.util.*;

public class BinaryTree {
	protected Node root;
  	protected int  size;

	public BinaryTree(){
		size = 0;
	}

  public BinaryTree(String s){
		root = new Node(s);
		size = 1;
	}

	public int getSize(){ return this.size; }
	public Node getRoot(){ return this.root; }


	public boolean contains(String target){
		if( root == null ){ return false; }
		if( root.getData().equals(target) ){
			return true;
		}
		return false;
	}



	public void add(String s){
		addLeft(s);
	}

	/* add a node in the left most free spot in the existing tree */
	private void addLeft(String s){
		if(root == null && size == 0){
			root = new Node(s);
			return;
		}else{
		  Node tmp = root;
		  while(tmp.getLeft() != null){
		  	tmp = tmp.getLeft();
		  }
		  // assert: temp.left == null
			// yea! we have a place to add s
		  tmp.setLeft(new Node(s));
		}
		size += 1;
	}
	




	/** Computes the height of the binary tree
	  *
		* The height is the length of the longest path from
		* the root of the tree to any other node.
		*
		* @return the height of the tree
		*/
	public int height(){
	  if( root == null ){ return -1; }
		return heightRecursive(root);
	}
	protected static int heightRecursive(Node root){
			if( root == null ){
			  return -1;
			}
			int leftHeight = heightRecursive(root.getLeft());
			int rightHeight = heightRecursive(root.getRight());
			if( leftHeight < rightHeight){
				return 1 + rightHeight;
			}else{
			  return 1 + leftHeight;
			}
		}


	public static void main(String[] args){
		BST t = new BST();
		BST test=new BST();
		test.add("hey");
		System.out.println(test.isValidBST());
		System.out.println(test.getRoot());
		t.root = new Node("cat");
		t.add("dog");
		t.add("babyyyyy");
		t.add("eel");
		t.add("animals");
		t.add("caxxxxxx");
		t.add("zat");
		t.add("bx");
		t.add("implementation");
		t.add("Maven");
		t.add("BinaryTree");
		t.add("Library");
		t.add("either");
		t.add("with");
		t.add("project");
		t.add("found");
		t.add("run");
		t.add("should");
		t.add("all");
		t.add("these");
		t.add("and");
		t.add("using");
		t.add("plain");
		t.add("size");
		System.out.println(t.getRoot());
		System.out.println(t.isValidBST());
		System.out.println(t.makeBalanced());
	}
}

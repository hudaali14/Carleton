package comp1406a5;
import java.util.*;

public class BST extends BinaryTree{

	// You MUST have a zero argument constructor that
	// creates an empty binary search tree
	// You can can add code to this if you want (or leave it alone).
    // We will create all BSTs for testing using this constructor
    public BST(){}



    @Override
    public boolean contains(String s){
        Node temp= getRoot();
        while(true){
            if(temp.getData().compareTo(s)==0){
                return true;
            }else if(temp.getLeft()==null && temp.getRight()==null){
                return false;
            }else if(temp.getData().compareTo(s)<0){
                if(temp.getRight()==null){
                    return false;
                }else{
                    temp=temp.getRight();
                }
            }else if(temp.getData().compareTo(s)>0){
                if(temp.getLeft()==null){
                    return false;  
                }else{
                    temp=temp.getLeft();
                }
            }else{
                continue;
            }
        }
    }



    @Override
    public void add(String s){
        Node add= new Node(s);
        Node temp= getRoot();
        while(true){
            if(getRoot()==null){
                this.root=add;
                break;
            }
            if(temp.getData().compareTo(s)<0){
                if(temp.getRight()==null){
                    temp.setRight(add);
                    break;
                }else{
                    temp=temp.getRight();
                }
            }else if(temp.getData().compareTo(s)>0){
                if(temp.getLeft()==null){
                    temp.setLeft(add);
                    break;        
                }else{
                    temp=temp.getLeft();
                }
            }else{
                continue;
            }
        }
        this.size++; 
    }


    public void isBST(Node node, List<String> list){
        if(node==null){
            return;
        }   
        isBST(node.getLeft(), list);
        list.add(node.getData());
        isBST(node.getRight(), list);
    }

    public boolean isValidBST(){
        if(getRoot()==null){
            return true;
        }
        ArrayList<String> list = new ArrayList<>();
        isBST(getRoot(), list);
        int count=0;
        for(int i=0; i<list.size(); i++){
            if(i+1!=list.size() && list.get(i).compareTo(list.get(i+1))<0){
                count+=1;
            }
        }
        if(count==list.size()-1){
            return true;
        }else{
            return false;
        }
    }

    public Node addBST(List<String> list, int start, int end){
        if(start>end){
            return null;
        }
        int mid=(start+end)/2;
        Node node=new Node(list.get(mid));
        node.setLeft(addBST(list, start, mid-1));
        node.setRight(addBST(list, mid+1, end));
        return node;
    }

    public BST makeBalanced(){
        ArrayList<String> list= new ArrayList<>();
        isBST(getRoot(), list);
        Collections.sort(list);
        BST tree= new BST();
        tree.size=list.size();
        tree.root= addBST(list, 0, list.size()-1);
        return tree;
    }

}

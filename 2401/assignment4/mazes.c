#include <stdio.h>
#include <stdlib.h>

#include "graphSet.h"
#include "mazeDisplay.h"


Node* recursive(Node* prev, int y, int x, char maze[HEIGHT][WIDTH]){
    maze[y][x]=50;

    Node *n=malloc(sizeof(Node));
    n->x=x;
    n->y=y;

    printf("current node: (%d, %d) \n", n->x, n->y);
    //printf("\n");

    //printf("maze at (%d, %d) is %d\n", x, y-1, maze[y-1][x]-'0');
    if(y!=0){
        if(maze[y-1][x]!=49 && maze[y-1][x]==50){
            if(prev!=NULL){
                prev->down=n;
            }
            n->up=NULL;
            //printf("(%d, %d) prev node above has been set \n", n->x, n->y);
        }else if(maze[y-1][x]==48){
            //printf("(%d, %d) has an up node \n", n->x, n->y);
            recursive(n, y-1, x, maze);
        }else{
            //printf("(%d, %d) has a wall above it \n", n->x, n->y);
            n->up=NULL;
        }
    }
    //printf("\n");

    //printf("maze at (%d, %d) is %d\n", x-1, y, maze[y][x-1]-'0');
    if(x!=0){
        if(maze[y][x-1]!=49 && maze[y][x-1]==50){
            if(prev!=NULL){
                prev->right=n;
            }
            n->left=NULL;
            //printf("(%d, %d) prev to the left has been set \n", n->x, n->y);
        }else if(maze[y][x-1]==48){
            //printf("(%d, %d) has an left node \n", n->x, n->y);
            recursive(n, y, x-1, maze);
        }else{
            //printf("(%d, %d) has a wall to the left it \n", n->x, n->y);
            n->left=NULL;
        }
    }

    //printf("maze at (%d, %d) is %d\n", x+1, y, maze[y][x+1]-'0');
    if(x!=WIDTH){
        if(maze[y][x+1]!=49 && maze[y][x+1]==50){
            if(prev!=NULL){
                prev->left=n;
            }
            n->right=NULL;
            //printf("(%d, %d) prev to the right has been set \n", n->x, n->y);
        }else if(maze[y][x+1]==48){
            //printf("(%d, %d) has an right node \n", n->x, n->y);
            recursive(n, y, x+1, maze);
        }else{
            //printf("(%d, %d) has a wall to the right it \n", n->x, n->y);
            n->right=NULL;
        }
    }

    //printf("\n"); 
    
    //printf("maze at (%d, %d) is %d\n", x, y+1, maze[y-1][x]-'0');
    if(y!=HEIGHT){
        if(maze[y+1][x]!=49 && maze[y+1][x]==50){
            if(prev!=NULL){
                prev->up=n;
            }
            n->down=NULL;
            //printf("(%d, %d) prev below has been set \n", n->x, n->y);
        }else if(maze[y+1][x]==48){
            //printf("(%d, %d) has an down node \n", n->x, n->y);
            recursive(n, y+1, x, maze);
        }else{
            //printf("(%d, %d) has a wall below it \n", n->x, n->y);
            n->down=NULL;
        }
    }

    return n;
}

// Compute the graph for the given maze and add it to the given graph set.
Graph *computeGraph(char maze[HEIGHT][WIDTH]) {
    Graph* g;
    int x=0;
    int y=0;
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            if(maze[i][j]==0){
                y=i;
                x=j;
                break;
            }
        }
    }
    Node* head= recursive(NULL, head->y, head->x, maze);
    g-> rootNode=head;

    // Create the initially-empty graph

    // Find a starting node, then trace out the maze recursively.  A starting node can be
    // found by searching from top to bottom, left to right, for a non-wall maze location.
    // You MUST NOT hard-code this start location ... it must be determined by your code.

    // To trace out the maze recursively, you will likely want to create a recursive
    // procedure that is called by this one.   It should take parameters to indicate
    // the location in the maze to start tracing from, the maze itself and also the node
    // that led to this node (i.e., the previous one in the tree that led here).  If you
    // start with the root node, then the previous node should be NULL.
    //
    // As you go through the maze, make sure to mark off maze locations that you have
    // visited (perhaps by putting a '2' character at that location) so that you do not
    // go back to that location again and end up with infinite recursion.  So you can
    // stop the recursion when you reach a wall (i.e., a '0' character in the maze) or a
    // '2' character.  A '1' character means that it is a free space that you just arrived
    // at for the first time.   Make sure to check recursively in all directions.  In my
    // solutions (shown on the assignment), I used an ordering of up/down/left/right.  So
    // if you want solutions to look like mine, you should follow that ordering as well.
    //
    // As you traverse the maze, make sure to connect the previous node to the current one.
    // You'll have to check which direction you can from (i.e., x and y values) so that
    // you know whether it is the up/down/left or right pointer to set.

    // You need not do this recursively, but it will lkely be a lot harder to do it non-
    // recursively.
    
    return &g; //Remove this line when you write your code
}



// This procedure must clean up graph by removing all nodes in which the previous and
// next nodes have the same x or y value as it.
void cleanUpGraph(Node *n, Node *previousNode) {
  
}



// This is where it all begins
int main() {
    char mazes[5][HEIGHT][WIDTH] = {
        {"111111111111111111111",
        "100000001000100000001",
        "101111111010111011111",
        "100000000010000010001",
        "101110111111101110111",
        "100010001000000000001",
        "111011111111111110111",
        "101010001000100000001",
        "101110111011101011101",
        "100010000000001010001",
        "101010111011111111111",
        "101000001000100000001",
        "101111111110101111101",
        "100010100000100000101",
        "111110101110101111101",
        "100010001000000010101",
        "101010111111111010111",
        "101010001000000010001",
        "101111111010111011101",
        "100000000010001000001",
        "111111111111111111111"},
        
        {"111111111111111111111",
        "100000000000000000001",
        "101111111111111111111",
        "100000000000000000001",
        "101111111111111111111",
        "100000000000000000001",
        "111111111111111111101",
        "100000000000000000001",
        "101111111111111111111",
        "100000000000000000001",
        "111111111111111111101",
        "100000000000000000001",
        "101111111111111111111",
        "101111111111111111101",
        "101111111111111111101",
        "101000100010001000101",
        "101010101010101010101",
        "101010101010101010101",
        "101010101010101010101",
        "100010001000100010001",
        "111111111111111111111"},
        
        {"111111111111111111111",
        "100000000000000000001",
        "101010101010101010101",
        "100000000000000000001",
        "101110111011101110111",
        "100000000000000000001",
        "101111101111101111101",
        "100000000000000000001",
        "101111111001111111101",
        "100000000000000000001",
        "101111111111111111101",
        "100111111111111111001",
        "100011111111111110001",
        "100001111111111100001",
        "100000111111111000001",
        "100000011111110000001",
        "100000001111100000001",
        "100000000111000000001",
        "100000000010000000001",
        "100000000000000000001",
        "111111111111111111111"},

        {"111111111111111111111",
        "111111111111111111111",
        "111111111111111111111",
        "111111111111111111111",
        "111111111111111111111",
        "111111111111111111111",
        "111111111111111111111",
        "111111111111111111111",
        "111111111111111111111",
        "111111111111111111111",
        "111111111110111111111",
        "111111111111111111111",
        "111111111111111111111",
        "111111111111111111111",
        "111111111111111111111",
        "111111111111111111111",
        "111111111111111111111",
        "111111111111111111111",
        "111111111111111111111",
        "111111111111111111111",
        "111111111111111111111"},
        
        {"111111111111111111111",
        "111100000000000000001",
        "111000000000000000001",
        "100000000000000000001",
        "100000000000000000001",
        "100000000000000000001",
        "100000000000000000001",
        "100000000000000000001",
        "100000000000000000001",
        "100000000000000000001",
        "100000000000000000001",
        "100000000000000000001",
        "100000000000000000001",
        "100000000000000000001",
        "100000000000000000001",
        "100000000000000000001",
        "100000000000000000001",
        "100000000000000000001",
        "100000000000000000001",
        "100000000000000000001",
        "111111111111111111111"}};
    
    // Open a display window
    openDisplayWindow();

    
    
    // Allocate a GraphSet to store the graphs for each maze
    GraphSet *gSet=malloc(5*sizeof(Graph));

    // Compute the graphs for each maze and add them to a Graph Set
    for (int i=0; i<5; i++) {
        Graph *g = computeGraph(mazes[i]);
        if(i==0){
            gSet->firstGraph=g;
        }else if(i==1){
            gSet->firstGraph->nextGraph=g;
        }else if(i==2){
            gSet->firstGraph->nextGraph->nextGraph=g; 
        }else if(i==3){
            gSet->firstGraph->nextGraph->nextGraph->nextGraph=g;
        }else{
            gSet->lastGraph=g;
            gSet->firstGraph->nextGraph->nextGraph->nextGraph->nextGraph=g;
        }
        // Add g to gSet properly
        // ...
    }
    
    // Show the graphs
    Graph *g= gSet->firstGraph; // ... set this to the first graph in gSet ...
    
    for (int i=0; i<5; i++) {
        //drawMaze(mazes[i]);  // Draw the maze
        // drawGraph(g->rootNode);    // Draw the graph
      
        getchar();  // Wait for user to press enter
      
        // cleanUpGraph(g->rootNode, NULL);   // Clean up the graph
        // drawMaze(mazes[i]);
        // drawGraph(g->rootNode);

        g= g->nextGraph;
        // ... get the next graph in the set ...
        // ... INSERT A LINE OF CODE HERE ...
      
       getchar();  // Wait again for the user to press ENTER before going on to the next maze
    }

    // Free up all allocated memory
    // ...

    // Close the display window
    closeDisplayWindow();
}

#include <stdio.h>
#include <stdlib.h>

#include "graphSet.h"
#include "mazeDisplay.h"


Node* recursive(Node* prev, int y, int x, char maze[HEIGHT][WIDTH]){

  //set maze[y][x] to '2' which means visited
  maze[y][x]=50;

  //creates pointer to new node, allocates memory for it, and sets it equal to x and y
  Node *n;
  n=malloc(sizeof(Node));
  n->x=x;
  n->y=y;

  //check bounds
  if(x!=0){

    /*if we've visited it and the previous x and y are equal,
    it means it's the previous node so set values */
    if(prev!=NULL && maze[y][x-1]==50 && prev->x==x-1 && prev->y==y){
      prev->right=n;
      n->left=NULL;

    //if maze[y][x] has not been visited aka '0' then calls itself
    }else if(maze[y][x-1]==48){
      recursive(n, y, x-1, maze);

    //means we've hit a wall so set side to NULL
    }else{
      n->left=NULL;
    }
  }

  //check bounds
  if(x!=WIDTH){

    /*if we've visited it and the previous x and y are equal,
    it means it's the previous node so set values */
    if(prev!=NULL&& maze[y][x+1]==50 && prev->x==x+1 && prev->y==y){
      prev->left=n;
      n->right=NULL;

    //if maze[y][x] has not been visited aka '0' then calls itself
    }else if(maze[y][x+1]==48){
      recursive(n, y, x+1, maze);

    //means we've hit a wall so set side to NULL
    }else{
      n->right=NULL;
    }
  }

  //check bounds
  if(y!=0){

    /*if we've visited it and the previous x and y are equal,
    it means it's the previous node so set values */
    if(prev!=NULL && maze[y-1][x]==50 && prev->x==x && prev->y==y-1){
      prev->down=n;
      n->up=NULL;

    //if maze[y][x] has not been visited aka '0' then calls itself
    }else if(maze[y-1][x]==48){
      recursive(n, y-1, x, maze);

    //means we've hit a wall so set side to NULL
    }else{
      n->up=NULL;
    }
  }

  //check bounds
  if(y!=HEIGHT){

    /*if we've visited it and the previous x and y are equal,
    it means it's the previous node so set values */
    if(prev!=NULL && maze[y+1][x]==50 && prev->x==x && prev->y==y+1){
      prev->up=n;
      n->down=NULL;

    //if maze[y][x] has not been visited aka '0' then calls itself
    }else if(maze[y+1][x]==48){
      recursive(n, y+1, x, maze);

    //means we've hit a wall so set side to NULL
    }else{
      n->down=NULL;
    }
  }

  //returns n aka current Node;
  return n;
}


// Compute the graph for the given maze and add it to the given graph set.
Graph *computeGraph(char maze[HEIGHT][WIDTH]) {

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

  //allocates for graph
  Graph* g=malloc(sizeof(Graph));

  //intializes x and y
  int x=0;
  int y=0;

  //found means we've found the starting spot aka first '0'
  int found=0;

  //loops through maze to find spot and once found breaks
  for(int i=0; i<HEIGHT; i++){
    for(int j=0; j<WIDTH; j++){
      if(maze[i][j]==48){
          y=i;
          x=j;
          found=1;
          break;
      }
    }
    if(found==1){
      break;
    }
  }

  //creates head and sets it to be Node found from recursion
  Node* head;
  head= recursive(NULL, y, x, maze);

  //sets head to be rootNode
  g-> rootNode=head;

  return g;
}



// This procedure must clean up graph by removing all nodes in which the previous and
// next nodes have the same x or y value as it.
void cleanUpGraph(Node *n, Node *previousNode) {

  //out counts connections
  int out=0;

  //counting connections
  if(n->up!=NULL){
    out++;
  }
  if(n->left!=NULL){
    out++;
  }
  if(n->right!=NULL){
    out++;
  }
  if(n->down!=NULL){
    out++;
  }

  //checks if n has been removed
  int check=0;

  //checks if conditions for node to be removed have been met
  if(out==1 && previousNode!=NULL && (previousNode->y > n->y) && n->up!=NULL){

    //remove n, recursively call to next node, free n, sets check
    previousNode->up=n->up;
    cleanUpGraph(n->up, previousNode);
    free(n);
    check=1;
  }

  //checks if conditions for node to be removed have been met
  if(out==1 && previousNode!=NULL && (previousNode->y < n->y) && n->down!=NULL){

    //remove n, recursively call to next node, free n, sets check
    previousNode->down=n->down;
    cleanUpGraph(n->down, previousNode);
    free(n);
    check=1;
  }

  //checks if conditions for node to be removed have been met
  if(out==1 && previousNode!=NULL && (previousNode->x > n->x)  && n->left!=NULL){

    //remove n, recursively call to next node, free n, sets check
    previousNode->left=n->left;
    cleanUpGraph(n->left, previousNode);
    free(n);
    check=1;
  }

  //checks if conditions for node to be removed have been met
  if(out==1 && previousNode!=NULL && (previousNode->x < n->x) && n->right!=NULL){

    //remove n, recursively call to next node, free n, sets check
    previousNode->right=n->right;
    cleanUpGraph(n->right, previousNode);
    free(n);
    check=1;
  }

  //if n hasn't been removed then recursively check all four directions
  if(check==0){
    if(n->up!=NULL){
      cleanUpGraph(n->up, n);
    }
    if(n->left!=NULL){
      cleanUpGraph(n->left, n);
    }
    if(n->right!=NULL){
      cleanUpGraph(n->right, n);
    }
    if(n->down!=NULL){
      cleanUpGraph(n->down, n);
    }
  }
}

//recursives through nodes and frees them
void freeNodes(Node *n){

  //if any nodes in each direction are not null, recursives to them
  if(n->up!=NULL){
    freeNodes(n->up);
  }
  if(n->left!=NULL){
    freeNodes(n->left);
  }
  if(n->right!=NULL){
    freeNodes(n->right);
  }
  if(n->down!=NULL){
    freeNodes(n->down);
  }

  //frees node
  free(n);
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
  GraphSet *gSet=malloc(sizeof(GraphSet));

  // Compute the graphs for each maze and add them to a Graph Set
  for (int i=0; i<5; i++) {
    Graph *g = computeGraph(mazes[i]);
    // Add g to gSet properly

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
  }

  // Show the graphs
  Graph *g=gSet->firstGraph; // ... set this to the first graph in gSet ...

  for (int i=0; i<5; i++) {
    drawMaze(mazes[i]);  // Draw the maze

    drawGraph(g->rootNode);    // Draw the graph

    getchar();  // Wait for user to press enter

    cleanUpGraph(g->rootNode, NULL);   // Clean up the graph
    drawMaze(mazes[i]);
    drawGraph(g->rootNode);

    // ... get the next graph in the set ...
    // ... INSERT A LINE OF CODE HERE ...
    g=g->nextGraph;

    getchar();  // Wait again for the user to press ENTER before going on to the next maze
  }

  // Free up all allocated memory
  // ...
  Graph *gr =gSet->firstGraph;
  Graph *gr2;
  for(int i=0; i<5; i++){
    freeNodes(gr->rootNode);
    gr2=gr->nextGraph;
    free(gr);
    gr=gr2;
  }
  free(gSet);

  // Close the display window
  closeDisplayWindow();
}

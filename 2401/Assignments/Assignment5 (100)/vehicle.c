#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "simulator.h"

// Define PI value
#define PI 3.14159265358979323846

// GPS Data for this client as well as the connected tower ID
short  x;
short  y;
short  direction;
char  connectionID;
char  connectedTowerID;



int main(int argc, char * argv[]) {

  // Set up the random seed
  srand(time(NULL));

  // Get the starting coordinate and direction from the command line arguments
  x = atoi(argv[1]);
  y = atoi(argv[2]);
  direction = atoi(argv[3]);

  // To start, this vehicle is not connected to any cell towers
  connectionID = -1;
  connectedTowerID = -1;

  int clientSocket;
  struct sockaddr_in serverAddress;
  int status, bytesRcv, bytesRcvs;

  // while the vehicle is still in city bounds or connected to server
  while(x>=0 && x<=CITY_WIDTH && y>=0 && y<=CITY_HEIGHT || connectionID!=-1){

    usleep(50000);  // A delay to slow things down a little

    // Gets random number between 0-2
    int r= rand() % 3;

    // Changes direction based on random number
      if(r==0){
        x= x+ VEHICLE_SPEED*cos(direction*PI/180);
        y= y+ VEHICLE_SPEED*sin(direction*PI/180);
      }else if(r==1){
        x= x+ VEHICLE_SPEED*cos(direction+VEHICLE_TURN_ANGLE*PI/180);
        y= y+ VEHICLE_SPEED*sin(direction+VEHICLE_TURN_ANGLE*PI/180);
      }else{
        x= x+ VEHICLE_SPEED*cos(direction-VEHICLE_TURN_ANGLE*PI/180);
        y= y+ VEHICLE_SPEED*sin(direction-VEHICLE_TURN_ANGLE*PI/180);
      }


    // If vehicle is not connected to server tried to connect to all 7 servers
    if(connectionID==-1){
      for(int i=0; i<NUM_TOWERS; i++){

        // Create the client socket
        clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (clientSocket < 0) {
          printf("*** CLIENT ERROR: Could not open socket.\n");
          exit(-1);
        }
        //Setup address
        memset(&serverAddress, 0, sizeof(serverAddress));
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_addr.s_addr = inet_addr(SERVER_IP);
        serverAddress.sin_port = htons((unsigned short) SERVER_PORT+i);

        // Connect to server
        status = connect(clientSocket, (struct sockaddr *) &serverAddress,
        sizeof(serverAddress));
        if (status < 0) {
          printf("*** CLIENT ERROR: Could not connect.\n");
          exit(-1);
        }
        // Buffer to send information to server
        unsigned char buffer1[6];

        // Sends CONNECT command to server with corrdinates
        buffer1[0]=CONNECT;
        unsigned char x1= x%256;
        buffer1[1]=x1;
        unsigned char x2= x/256;
        buffer1[2]=x2;
        unsigned char y1= y%256;
        buffer1[3]=y1;
        unsigned char y2= y/256;
        buffer1[4]=y2;
        buffer1[5]='0';
        send(clientSocket, buffer1, sizeof(buffer1), 0);

        // Buffer to for receive information from server
        unsigned char bufferResponse[4];

        // Receives response from server
        bytesRcv = recv(clientSocket, bufferResponse, sizeof(bufferResponse), 0);

        // If server response YES then saves ID and tower and closes connection
        if(bufferResponse[0]==YES){
          int ID=bufferResponse[2];
          int IDTower=bufferResponse[1];
          connectionID=ID;
          connectedTowerID=IDTower;
          close(clientSocket);
          break;

        // Closes connection
        }else{
          close(clientSocket);
        }
      }
    }else{

      // Create the client socket
      clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
      if (clientSocket < 0) {
        printf("*** CLIENT ERROR: Could not open socket.\n");
        exit(-1);
      }
      //Setup address
      memset(&serverAddress, 0, sizeof(serverAddress));
      serverAddress.sin_family = AF_INET;
      serverAddress.sin_addr.s_addr = inet_addr(SERVER_IP);
      serverAddress.sin_port = htons((unsigned short) SERVER_PORT+connectedTowerID);

      // Connect to server
      status = connect(clientSocket, (struct sockaddr *) &serverAddress,
      sizeof(serverAddress));
      if (status < 0) {
        printf("*** CLIENT ERROR: Could not connect.\n");
        exit(-1);
      }

      // Buffer to send information to server
      unsigned char buffer2[7];

      // Sends CONNECT command to server along with coordinates and ID
      buffer2[0]=UPDATE;
      unsigned char x1= x%256;
      buffer2[1]=x1;
      unsigned char x2= x/256;
      buffer2[2]=x2;
      unsigned char y1= y%256;
      buffer2[3]=y1;
      unsigned char y2= y/256;
      buffer2[4]=y2;
      buffer2[5]=connectionID;
      buffer2[6]='0';
      send(clientSocket, buffer2, sizeof(buffer2), 0);

      // Buffer to hold response from server
      unsigned char bufferResponse2[4];

      // Receives response from server
      bytesRcvs = recv(clientSocket, bufferResponse2, sizeof(bufferResponse2), 0);

      // If received YES from server then closes client socket
      if(bufferResponse2[0]==YES){
        close(clientSocket);

      // If not in radius then sets connectionID and towerID back to -1
      }else{
        connectionID=-1;
        connectedTowerID=-1;
        close(clientSocket);
      }

      // If out of bounds then close client
      if(x<=0 || x>=800 || y<=0 || y>=600){
        connectionID=-1;
        connectedTowerID=-1;
        close(clientSocket);
      }
    }
  }


}

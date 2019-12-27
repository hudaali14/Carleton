#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <math.h>



// Handle client requests coming in through the server socket.  This code should run
// indefinitiely.  It should wait for a client to send a request, process it, and then
// close the client connection and wait for another client.  The requests that may be
// handles are SHUTDOWN, CONNECT and UPDATE.  A SHUTDOWN request causes the tower to
// go offline.   A CONNECT request contains 4 additional bytes which are the high and
// low bytes of the vehicle's X coordinate, followed by the high and low bytes of its
// Y coordinate.  If within range of this tower, the connection is accepted and a YES
// is returned, along with a char id for the vehicle and the tower id.   If UPDATE is
// received, the additional 4 byes for the (X,Y) coordinate are also received as well
// as the id of the vehicle.   Then YES is returned if the vehicle is still within
// the tower range, otherwise NO is returned.
void *handleIncomingRequests(void *ct) {

  CellTower       *tower = ct;
  int serverSocket, clientSocket;
  struct sockaddr_in serverAddress, clientAddr;
  int status, addrSize, bytesRcv;

   // Create the server socket
   serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
   if (serverSocket < 0) {
     printf("*** SERVER ERROR: Could not open socket.\n");
     exit(-1);
   }

   // Setup the server address
   memset(&serverAddress, 0, sizeof(serverAddress)); // zeros the struct
   serverAddress.sin_family = AF_INET;
   serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
   serverAddress.sin_port = htons((unsigned short) SERVER_PORT + (tower->id));

   // Bind the server socket
   status = bind(serverSocket, (struct sockaddr *)&serverAddress,
   sizeof(serverAddress));
   if (status < 0) {
     printf("*** SERVER ERROR: Could not bind socket.\n");
     exit(-1);
   }

   // Set up the line-up to handle up to 5 clients in line
   status = listen(serverSocket, 5);
   if (status < 0) {
   printf("*** SERVER ERROR: Could not listen on socket.\n");
   exit(-1);
   }

   // Wait for clients now
   while (1) {

      addrSize = sizeof(clientAddr);
      clientSocket = accept(serverSocket,(struct sockaddr *)&clientAddr,&addrSize);
      if (clientSocket < 0) {
       printf("*** SERVER ERROR: Could accept incoming client connection.\n");
       exit(-1);
      }

      // Get the message from the client
      unsigned char buffer[7];
      bytesRcv = recv(clientSocket, buffer, sizeof(buffer), 0);

      short x=(short) (buffer[1] + (buffer[2]*256));
      short y=(short) (buffer[3] + (buffer[4]*256));

      // If SHUTDOWN command is sent close socket and break
      if(buffer[0]==SHUTDOWN){
        close(clientSocket);
        break;
      }

      // Buffer to hold information sent to client
      unsigned char buffersend[6];

      // If CONNECT command is sent trys to connect with client
      if(buffer[0]==CONNECT){

        // If tower has reached MAX CONNECTIONS then send NO back to client and close socket
        if(tower->numConnectedVehicles >= MAX_CONNECTIONS){
          buffersend[0]= NO;
          buffersend[1]='0';
          send(clientSocket, buffersend, sizeof(buffersend), 0);
          close(clientSocket);
        }else{

          //calculates distance from center of the tower to vehicle
          int dist= sqrt(pow(tower->x-x, 2)+pow(tower->y-y, 2));

          // If the vehicle is outside the radius the send NO back to client and close socket
          if(dist>=tower->radius){
            buffersend[0]= NO;
            buffersend[1]='0';
            send(clientSocket, buffersend, sizeof(buffersend), 0);
            close(clientSocket);

          // If it's inside the radius then we can connect
          }else{

            //creates connected vehicle and store x and y values
            ConnectedVehicle vehicle;
            vehicle.x=x;
            vehicle.y=y;
            vehicle.connected='1';

            // Buffer to for sending information to client
            unsigned char bufsend[4];
            bufsend[0]= YES;
            bufsend[1]=tower->id;

            // Loops through vehicle array to find empty spot
            for(int i=0; i<MAX_CONNECTIONS; i++){

              // If this spot in the array has no connections then add here
              if(tower->connectedVehicles[i].connected==0){
                bufsend[2]=i;
                bufsend[3]='0';
                tower->connectedVehicles[i]=vehicle;
                break;
              }
            }

            // Once connected close client socket
            send(clientSocket, bufsend, sizeof(bufsend), 0);
            close(clientSocket);
          }
        }
      }

      // Buffer to for sending information to client
      unsigned char bufsend2[2];
      int index= buffer[5];

      // If UPDATE command is sent updates clients position
      if(buffer[0]==UPDATE){

        //calculates distance from center of the tower to vehicle
        int dist= sqrt(pow(tower->x-x, 2)+pow(tower->y-y, 2));

        // If the vehicle is outside the radius the send NO back to client and close socket
        if(dist>=tower->radius){
          bufsend2[0]=NO;
          bufsend2[1]='0';
          tower->connectedVehicles[index].connected=0;
          send(clientSocket, bufsend2, sizeof(bufsend2), 0);
          close(clientSocket);

        // Else updates position and sends YES to client
        }else{
          bufsend2[0]=YES;
          bufsend2[1]='0';
          tower->connectedVehicles[index].x=x;
          tower->connectedVehicles[index].y=y;
          send(clientSocket, bufsend2, sizeof(bufsend2), 0);
          close(clientSocket);
        }

        // If out of bounds then take off of connected vehicle array
        if(x<=0 || x>=800 || y<=0 || y>=600){
          tower->connectedVehicles[index].connected=0;
          close(clientSocket);
        }
      }
  }

   // Don't forget to close the sockets!
  close(serverSocket);


}

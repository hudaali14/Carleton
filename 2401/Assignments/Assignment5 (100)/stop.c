#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "simulator.h"


void main() {
  int                 clientSocket;  // client socket id
  struct sockaddr_in  serverAddress; // client address
  int                 status, bytesRcv;
  unsigned char       command = SHUTDOWN;
  char inStr[80]; // stores user input from keyboard
  char buffer[80]; // stores user input from keyboard

  // Contact all the cell towers and ask them to shut down

  // Create the client socket
  for(int i=0; i<7; i++){
    clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket < 0) {
      printf("*** CLIENT ERROR: Could not open socket.\n");
      exit(-1);
    }
    // Setup address
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

    // Sends command SHUTDOWN to servers
    buffer[0]=command;
    send(clientSocket, buffer, strlen(buffer), 0);

    // Get response from server, should be "OK"
    bytesRcv = recv(clientSocket, buffer, 80, 0);

    if ((strcmp(inStr,"done") == 0) || (strcmp(inStr,"stop") == 0))
     break;

  }
  close(clientSocket); // Don't forget to close the socket !


}

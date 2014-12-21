#include "celest.h"

string hey()
{
    string a = "hello world\n";
    return a;
}

void error (const char *msg)
{
    perror(msg);
    exit(1);
}

void process_connection (int sock)
{
    int n;
    char buffer[256];
    char reply[256];
    
    // Keep the connection open until done
    while (1) {
	bzero(buffer, 256);
	n = recv(sock, buffer, 255, 0);
	if (n < 0) error("ERROR reading from socket");
	
	cout << buffer << endl;
	
	cout << "response: ";
	fgets(reply, 255, stdin);
	n = send(sock, reply, strlen(reply), 0);
	
	if (n < 0) error("ERROR writing to socket");
    }
}


#include "celest.h"

string hey()
{
    string a = "hello world\n";
    return a;
}

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

void dostuff (int sock, ostream& logfile)
{
    int n;
    char buffer[256];

    bzero(buffer,256);
    n = read(sock,buffer,255);
    if (n < 0) error("ERROR reading from socket");
    
    printf("Here is the message: %s\n",buffer);
    n = write(sock,"I got your message",18);
    logfile << buffer << endl;
    
    if (n < 0) error("ERROR writing to socket");
}


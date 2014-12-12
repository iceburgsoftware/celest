#include "celest.h"

int main(int argc, char* argv[])
{
    int sockfd, newsockfd, portno, pid;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
	fprintf(stderr,"ERROR, no port provided\n");
	exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) 
    error("ERROR opening socket");
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
	    sizeof(serv_addr)) < 0) 
	    error("ERROR on binding");
    
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    
    // Beginning main code
    ofstream logfile;
    logfile.open("celest.log");
    signal(SIGCHLD, SIG_IGN); // Quick and dirty fix to get rid of zombies.  
    
    daemon(0, 0);
    while (1) {
	newsockfd = accept(sockfd, 
	    (struct sockaddr *) &cli_addr, &clilen);
	
	if (newsockfd < 0) 
	    error("ERROR on accept");
	
	pid = fork();
	
	if (pid < 0)
	    error("ERROR on fork");
	
	else if (pid == 0)  {
	    close(sockfd);
	    dostuff(newsockfd, logfile);
	    exit(0);
	}
	
	else {
	    close(newsockfd);
	}
    }
    close(sockfd);
    
    logfile.close();
    
    return 0;
}
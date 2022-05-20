#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char **argv)
{
    int n_client = 0;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(4444);

    pid_t pid;

    pid = fork();
    if (pid == 0)
    {

        printf("\nthis is child process and my pid is %d and my parents id is %d\n", getpid(), getppid());

        // use this process to listen on client process
    }

    else
    {
        printf("\n this is parent process and my pid is %d\n", getpid());
        // use this process to listen on parent process
    }

    close(sockfd);
    return 0;
}
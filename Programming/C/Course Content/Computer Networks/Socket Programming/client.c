//Client
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT	 8080
#define MAXLINE 1024

int main() {
	int sock_id;
	char buffer[MAXLINE];
	char *hello = "Hello from client";
	struct sockaddr_in	 servaddr;

	sock_id = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock_id == -1){printf("Error in socket()\n");exit(0);}


	memset(&servaddr, 0, sizeof(servaddr));
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = INADDR_ANY;
	
	int n;
    socklen_t len;
	
	sendto(sock_id, (const char *)hello, strlen(hello),0, (const struct sockaddr *) &servaddr, sizeof(servaddr));
	printf("Hello message sent.\n");
		
	n = recvfrom(sock_id, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *) &servaddr,&len);
	buffer[n] = '\0';
	printf("Server : %s\n", buffer);

    n = recvfrom(sock_id, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *) &servaddr,&len);
    buffer[n] = '\0';
	printf("%s\n", buffer);

    char op;
    op = getchar();
    printf("Operator taken\n");
    fflush(stdin);

    int a,b;
    scanf("%d %d",&a,&b);

    int arr[2];
    arr[0] = a;
    arr[1] = b; 

    sendto(sock_id, &op, 1,0, (const struct sockaddr *) &servaddr, sizeof(servaddr));

    sendto(sock_id, arr, sizeof(arr),0, (const struct sockaddr *) &servaddr, sizeof(servaddr));

    int answer[1];

    n = recvfrom(sock_id, answer, sizeof(answer), MSG_WAITALL, (struct sockaddr *) &servaddr,&len);
	printf("Result: %d\nProgram ends", answer[0]);

	close(sock_id);
	return 0;
}
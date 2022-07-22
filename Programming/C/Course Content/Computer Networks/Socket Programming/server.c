// Server side implementation of UDP client-server model
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
	char *hello = "Hello from server";
	struct sockaddr_in servaddr, cliaddr;
	
	sock_id = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock_id == -1){printf("Error in socket()\n");exit(0);}
	
	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));
    servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
	
	int b = bind(sock_id, (const struct sockaddr *)&servaddr,sizeof(servaddr));
	if(b == -1){printf("Error in bind()\n");exit(0);}
	
	int n;
	socklen_t len = sizeof(cliaddr);

	n = recvfrom(sock_id, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len);
	buffer[n] = '\0';
	printf("Client : %s\n", buffer);

	sendto(sock_id, (const char *)hello, strlen(hello), 0, (const struct sockaddr *) &cliaddr,len);
	printf("Hello message sent.\n");


    char *menu = "Press + for Addition\nPress - for Subtraction\nPress * for Multiplication\nPress \\ for Division\nand then enter 2 numbers: ";
    sendto(sock_id, (const char *)menu, strlen(menu), 0, (const struct sockaddr *) &cliaddr,len);

    int arr[2];

    n = recvfrom(sock_id, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len);
	buffer[n] = '\0';
    
    n = recvfrom(sock_id, arr, sizeof(arr), MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len);

    int result;

    switch(buffer[0]){
        case '+':
            result = arr[0] + arr[1];
            printf("Sum is %d\n",result);
            sendto(sock_id, &result, sizeof(result), 0, (const struct sockaddr *) &cliaddr,len);
            break;
        case '-':
            result = arr[0] - arr[1];
            printf("Difference is %d\n",result);
            sendto(sock_id, &result, sizeof(result), 0, (const struct sockaddr *) &cliaddr,len);
            break;
        case '*':
            result = arr[0] * arr[1];
            printf("Product is %d\n",result);
            sendto(sock_id, &result, sizeof(result), 0, (const struct sockaddr *) &cliaddr,len);
            break;
        case '/':
            if(!arr[1]){printf("Division by zero\n");exit(0);}
            result = arr[0] / arr[1];
            printf("Quotient is %d\n",result);
            sendto(sock_id, &result, sizeof(result), 0, (const struct sockaddr *) &cliaddr,len);
            break;
        default:
            printf("Operator invalid\n");
            exit(0);
            break;
    }

	
	return 0;
}

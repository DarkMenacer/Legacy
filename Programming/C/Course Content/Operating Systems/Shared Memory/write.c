#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define MEM_SIZE 1024
#define KEY (key_t)7777

int main(){
	int shmid;
	void *shared_memory;
	char input[100];
	shmid = shmget(KEY,MEM_SIZE,0666|IPC_CREAT);
	shared_memory = shmat(shmid,NULL,0);
	printf("ID and Location of the shared memory are:- %d and %p respectively\n",shmid,shared_memory);
	printf("Enter an input: ");	
	scanf("%[^\n]s",input);
	strcpy(shared_memory,input);
	printf("Input is stored in the shared memory\n");
	return 0;
}
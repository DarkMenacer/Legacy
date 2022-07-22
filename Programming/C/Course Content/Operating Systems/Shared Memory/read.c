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
	shmid = shmget(KEY,MEM_SIZE,0666);
	shared_memory = shmat(shmid,NULL,0);
	printf("ID and Location of the shared memory are:- %d and %p respectively\n",shmid,shared_memory);
	printf("The input stored by the writer was '%s'\n",(char*)shared_memory);
	return 0;
}
/*
Create one parent process and two immediate child process. The parent process will only print
the process id of its child process. Among the two child processes, one will print its own id and
its parent id and the other child process should load a new program from the memory (for
example, there is a separate program in the memory for addition of two numbers) and executes
the same.
Hint: use execlp()
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int child1, child2;
    child1 = fork();
    if(child1){
        //parent process
        child2 = fork();
        if(child2){
            //parent process
            printf("Child pIDs are %d and %ds\n",child1,child2);
        }
        else{
            //child 2
            execlp("/Users/pranavchatur/Local Docs/GitHub/DarkMenacer/VS Code/C/test","test",NULL);
            printf("This is never printed\n");
        }
    }
    else {
        //child 1
        printf("My ID is :%d & my parent ID is: %d\n",getpid(),getppid());
    }
    return 0;
}
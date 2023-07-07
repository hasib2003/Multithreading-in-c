#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
 #include <errno.h>
 #include <sys/wait.h>

__pid_t pid;

int main()
{
    // printf("this should be executed only once \n"); 
    // the above line of code gets executed only once that means the child process excutes instructions only after the fork() call
    pid = fork();
    printf("the process id of running process is %d\n ",getpid()); 
    printf("the process id of child of current process is %d\n ",pid); 

    if (pid < 0)
    {
        printf("unexpected error occured during child process creation.\nError Code %d\n", errno);
        return -1;
    }
    else if (pid == 0)
    {
        printf("executing the child process\n");
        
    }
    else{
        printf("parent process waiting for the child process to be terminated \n");
        int childProcessStatus = 0;
        waitpid(0,&childProcessStatus,0);
    }
    printf("Terminated process %d\n ",getpid()); 

    return 0;
}
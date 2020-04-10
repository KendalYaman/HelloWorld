#include <stdio.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <memory.h>
#include <unistd.h>

int main() 
{ 
    

    
    int fd[2];
    pipe(fd);
    pid_t i = fork();

    if (i == 0)
    {
         /* close the unused write side */
        dup2(fd[0], STDIN_FILENO); /* connect the read side with stdin */
        close(fd[1]);
        close(fd[0]);
        char *argv1[2];
        argv1[0] = "test";
        argv1[1] = NULL;
        execv("/Users/nraxa/Documents/TestC/test", argv1);
        _exit(1);
    }
    else if (i > 0)
    {
        char buffer[BUFSIZ];
        close(fd[0]);
        //dup2(fd[1], 1);
        strcpy(buffer, "Hello World");
        write(fd[1], buffer, BUFSIZ);
        close(fd[1]); /* close the pipe */

        wait(NULL);
        printf("C'est bon fils\n");
        _exit(2);
    }
    else
    {
        perror("fork failed");
        _exit(3);
    }
} 
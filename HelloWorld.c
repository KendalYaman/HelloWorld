#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <sys/wait.h> 
#define MAX_NAME_SZ 256

void forkexample() 
{ 
    // child process because return value zero 
    if (fork() == 0){
    	printf("Hello from Child!\n");
    	char word[20];
    	//fgets(word, MAX_NAME_SZ, stdin);`
    	scanf("%s",word);
    	printf("Voici: %s\n", word);
  
    // parent process because return value non-zero. 
    }else{
        printf("Hello from Parent!\n"); 
        wait(NULL);
    }
}


int main() 
{ 
	/*char word[20];
    scanf("%s", word);
    printf("Voici: %s\n", word);
    */
    forkexample(); 
    return 0; 
} 
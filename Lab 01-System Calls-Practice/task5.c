#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t cpid , g1, g2, g3;
    cpid = fork();

    if (cpid > 0){
        printf("Parent process ID : %d\n", getpid());
        wait(NULL);
    }
    
    else if (cpid==0){
        printf("Child process ID : %d\n", getpid());

        g1=fork();
        if(g1==0){
            printf("Grand Child process ID : %d\n", getpid());
            exit(0);
        }

        g2=fork();
        if(g2==0){
            printf("Grand Child process ID : %d\n", getpid());
            exit(0);
        }

        g3 = fork();
        if(g3==0){
            printf("Grand Child process ID : %d\n", getpid());
            exit(0);
        }
    }
}

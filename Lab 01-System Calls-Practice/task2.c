#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){

    pid_t c_pid;
    c_pid = fork();

    if (c_pid == 0){
        pid_t g_pid = fork();

        if (g_pid == 0){
            printf("I am Grandchild\n");
        }

        else{
            wait(NULL);
            printf("I am Child\n");
        }
    }

    else{
        wait(NULL);
        printf("I am Parent\n");
    }
    
    return 0;

}
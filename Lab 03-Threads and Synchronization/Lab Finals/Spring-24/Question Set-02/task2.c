#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <string.h>

int main(){

    pid_t cpid;
    cpid = fork();

    if (cpid==0){
        int c_temp = getpid();
        pid_t gpid = fork();

        if (gpid==0){
            exit(0);
        }
        else if (gpid>0){
            wait(NULL);
            printf("c:%d  g:%d\n", c_temp, gpid);
            int mod = gpid % c_temp ;
            if (mod%2 == 0){
                printf("Hello the remainder is EVEN\n");
            }
            else{
                printf("Hello the remainder is ODD\n");
            }
        }
    }

    else{
        wait(NULL);
    }

    return 0;

    }
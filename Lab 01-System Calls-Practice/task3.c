#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int count = 1;  // count the original parent process
    pid_t a, b, c;

    a = fork();
    count+=1;

    if (a==0){
        exit(1);
    }
    if (a>0){ 
        wait(NULL);
        if (a%2 !=0){
            count+=1;
            pid_t extra = fork();
            if (extra==0){
                exit(1);
            }
            else if (extra>0){
                wait(NULL);
            }
        }

    }

    c = fork();
    count+=1;

    if (c==0){
        exit(1);
    }
    if (c>0){ 
        wait(NULL);
        if (c%2 !=0){
            count+=1;
            pid_t extra = fork();
            if (extra==0){
                exit(1);
            }
            else if (extra>0){
                wait(NULL);
            }
        }

    }

    b = fork();
    count+=1;

    if (b==0){
        exit(1);
    }
    if (b>0){ 
        wait(NULL);
        if (b%2 !=0){
            count+=1;
            pid_t extra = fork();
            if (extra==0){
                exit(1);
            }
            else if (extra>0){
                wait(NULL);
            }
        }

    }

    printf("%d , %d, %d, %d", a,b,c, count);

    return 0;
}

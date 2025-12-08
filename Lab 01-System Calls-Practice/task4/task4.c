#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    char arr[4][10];

    strcpy(arr[0], "25");
    strcpy(arr[1], "75");
    strcpy(arr[2], "50");
    strcpy(arr[3], "100");

    pid_t a = fork();

    if (a==0){
        execl("/home/nusayba/System_Calls/sort","sort", arr[0], arr[1], arr[2], arr[3], NULL);
    }

    if (a>0){
        wait(NULL);
        execl("/home/nusayba/System_Calls/oddeven","oddeven", arr[0], arr[1], arr[2], arr[3], NULL);
    }

    return 0;

}



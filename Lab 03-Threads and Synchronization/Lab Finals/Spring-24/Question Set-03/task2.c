#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <string.h>
#include <math.h>

int main(){
    int n;
    pid_t cpid;
    printf("Enter an Integer:");
    scanf("%d", &n);
    cpid = fork();

    if (cpid==0){
        if(n%2 !=0){
            int sum_squares=0;
            for(int i = 0; i<=n; i++){
                sum_squares+=(int)pow(i,2);}
            printf("Squares of the integers is %d\n", sum_squares);}

        else{
            pid_t gpid;
            gpid = fork();
            if (gpid==0){
                int sum_cubes=0;
                for(int i=0; i<=n; i++){                   
                    sum_cubes+=(int)pow(i,3);}
                printf("Cubes of the integers is %d\n", sum_cubes);}
            else if(gpid>0){
                wait(NULL);
            }
        }
    }
    else if (cpid>0){
        wait(NULL);
        printf("Parent process: End of process\n");
    }}
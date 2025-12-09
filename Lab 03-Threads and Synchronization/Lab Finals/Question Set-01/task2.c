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
    int a, b;
    printf("Enter two integers:");
    scanf("%d %d", &a, &b);
    printf("%d %d", a, b);

    pid_t cpid;
    cpid = fork();

    if (cpid==0){

        int mul = a*b;
        printf("Child Process: The product of %d and %d is %d\n", a, b, mul);
        
        if (mul%2==0){
            pid_t gpid;

            gpid=fork();

            if (gpid==0){

                int temp;

                if (a<b){
                    temp=a;
                }
                else{
                    temp=b;
                }

                int fact = temp;

                for(int i=(temp-1); i>0; i--){
                    fact*=i;
                }
                printf("GrandChild Process: Factorial of %d is %d\n", temp, fact);
            }


            else{
                wait(NULL);
            }
        }

        else{
            
            int temp;
            if (a>b){
                    temp=a;
                }
                else{
                    temp=b;
                }
            int fact = temp;

                for(int i=(temp-1); i>0; i--){
                    fact*=i;
                }
            printf("Child Process: Factorial of %d is %d\n", temp, fact);

        }
    }

    
        else if(cpid>0){
            wait(NULL);
            printf("Parent Process: End of Process\n");
        }
    }
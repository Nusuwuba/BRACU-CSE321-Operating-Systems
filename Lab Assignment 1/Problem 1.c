
//PROBLEM-1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int fibonacciSequence(int *n);
void ValueSearch(void* args); 
int *t_ret1;
void *t_ret2;
struct data{
    int *arr;   
    int length; };

int main(){
    int n;
    int s;
    printf("Enter nth Term:\n");
    scanf("%d", &n);
    while (n < 0 || n > 40){
        printf("n must be greater than or equal to 0 or less than or equal to 40\nEnter nth Term:\n");
        scanf("%d", &n);
    }

    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, fibonacciSequence, &n);

    pthread_join(t1,&t_ret1);
    for(int i=0;i<=n;i++){
        printf("a[%d]: %d\n",i,t_ret1[i]);
    }

    struct data search  = { t_ret1, n }; 

    pthread_create(&t2, NULL, ValueSearch, &search);
    pthread_join(t1,&t_ret2);
    free(t_ret1);
    return 0;
}

int fibonacciSequence(int *n) { 

    int *a = malloc(sizeof(int)*(*n));

    a[0]=0;
    a[1]=1;
    
    for(int i = 2; i <= *(n); i++){
            a[i] = a[i-1] + a[i-2];
}

      return a; 
	}

void ValueSearch(void* args){

    struct data *d = (struct data *) args;
    int *a = (*d).arr;
    int length = (*d).length;

    int s;
    printf("How many numbers you are willing to search?:\n");
    scanf("%d", &s);

    if (s>0){
    for(int i=0; i<s;i++){
        if(i<=length){
            int temp;
            printf("Enter Search %d:\n", i+1);
            scanf("%d", &temp);
            if (temp<=length){
                printf("result of search #%d = %d\n",i+1,a[temp]);}
            else{
                printf("result of search #%d = -1\n",i+1);}
            }
        }     
    }
}


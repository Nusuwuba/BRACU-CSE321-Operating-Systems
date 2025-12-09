#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <string.h>

void *bookseat(void *arg);
sem_t sA;
int seats = 10;
int n;

int main(){

    sem_init(&sA, 0, 1); 
    pthread_t tA;

    do{
        printf("How many seats will you book?");
        scanf("%d", &n);} while((seats-n)<0 || n<=0);

    pthread_create(&tA, NULL, bookseat, &n);
    pthread_join(tA, NULL);
    sem_destroy(&sA);


}

void *bookseat(void *arg){  
    sem_wait(&sA);
    int n = *(int*)arg; 
    int temp = n;
    seats-=temp;
    sem_post(&sA);
    printf("%d",seats);
    

}
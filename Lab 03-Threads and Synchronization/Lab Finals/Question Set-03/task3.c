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

void *airport(void *arg);
sem_t s1,s2,sTrain;
int t_id[]={1,2,3,4,5,6};
int train=4;

int main(){
    pthread_t t[6];

    sem_init(&s1,0,15);
    sem_init(&s2,0,1);
    sem_init(&sTrain,0,4);


    for(int i = 0; i < 6; i++) {
        pthread_create(&t[i], NULL, airport, &t_id[i]);
    }

    for(int i = 0; i < 6; i++) {
        pthread_join(t[i], NULL);
    }
}

void *airport(void *arg){
    int id = *(int*)arg;

    sem_wait(&s1);
    printf("Passenger %d is checking in....\n", id);
    sleep(1);
    sem_post(&s1);

    sem_wait(&s2);
    printf("Passenger %d had moved to the immigration counter...\n", id);
    sleep(2);
    sem_post(&s2);

    sem_wait(&sTrain);
    printf("Passenger %d is using the train...\n", id);
    sleep(3);
    sem_post(&sTrain);
    }
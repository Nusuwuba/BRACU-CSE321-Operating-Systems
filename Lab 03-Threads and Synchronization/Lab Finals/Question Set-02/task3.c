#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <string.h>

void *stockupdate(void *arg);
void *salestransaction(void *arg);

int max_inventory = 50;
int stock = 20;
pthread_mutex_t lockStock;
pthread_mutex_t inputlock;
sem_t s1;
sem_t s2;

int main(){
    int n, sales;
    printf("Enter total product to add to inventory:\n");
    scanf("%d", &n);

    printf("Enter total product sold from inventory:\n");
    scanf("%d", &sales);

    pthread_t t1;
    pthread_t t2;

    pthread_mutex_init(&lockStock, NULL);
    pthread_mutex_init(&inputlock, NULL);
    sem_init(&s1, 0, max_inventory-stock);
    sem_init(&s2, 0, stock);

    pthread_create(&t1, NULL, stockupdate, &n);
    pthread_create(&t2, NULL, salestransaction, &sales);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Final stock in inventory: %d\n", stock);
    return 0;}

void *stockupdate(void *arg){
    
    int n = *(int*)arg;

    printf("Adding %d products to inventory.\n", n); 

    for(int i = 0; i<n; i++){
        sem_wait(&s1);
        pthread_mutex_lock(&lockStock);
        
        stock+=1;
        printf("[Stock Update] Added 1 product. Current stock: %d\n", stock);

        pthread_mutex_unlock(&lockStock);
        sem_post(&s2);}

    return 0;
    }

void *salestransaction(void *arg){
   
    int sold_count;
    int sales = *(int*)arg;

    printf("Selling %d products from inventory.\n", sales);

    for(int i=0; i<sales; i++){
        sem_wait(&s2);
        pthread_mutex_lock(&lockStock);

        stock-=1;
        printf("[Sales] Sold 1 product. Current stock: %d\n", stock); 

        pthread_mutex_unlock(&lockStock);
        sem_post(&s1);}

    return 0;
}
//PROBLEM-2

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void supplier(void* arg) ;
void makerA(void* arg);
void makerB(void* arg);
void makerC(void* arg);

char table[2][8];

int n;
sem_t sA;
sem_t sB;
sem_t sC;
sem_t empty; 
pthread_mutex_t lockTable;

int main(){

    printf("Enter number: ");
    scanf("%d", &n);

   srand(time(NULL));

   sem_init(&empty, 0, 1); 
   sem_init(&sA, 0, 0); 
   sem_init(&sB, 0, 0); 
   sem_init(&sC, 0, 0);
   pthread_mutex_init(&lockTable, NULL);
   pthread_t sup;   
   pthread_t tA;
   pthread_t tB;
   pthread_t tC;

   pthread_create(&sup, NULL,supplier,&n);
   pthread_create(&tA, NULL, makerA, &n);
   pthread_create(&tB, NULL, makerB, &n);
   pthread_create(&tC, NULL, makerC, &n);

   pthread_join(sup, NULL);
   pthread_join(tA, NULL);
   pthread_join(tB, NULL);
   pthread_join(tC, NULL);

   return 0;
}
   
void supplier(void* arg) {
    int n = *(int*)arg;

    char *items[3];

    items[0] = "Bread";
    items[1] = "Cheese";
    items[2]= "Lettuce";

    for(int i=0; i < n; i++){

        sem_wait(&empty);

        pthread_mutex_lock(&lockTable);

        int i1 = rand()%3;
        int i2;
        do{
            i2 = rand() % 3;
        }while(i1==i2);

        strcpy(table[0], items[i1]);
        strcpy(table[1], items[i2]);

        printf("Supplier places : %s and %s\n", items[i1], items[i2]);

        if(strcmp(table[0], "Bread") != 0 && strcmp(table[1], "Bread") != 0){
            sem_post(&sA);
        }

        else if((strcmp(table[0], "Cheese") != 0 && strcmp(table[1], "Cheese") != 0)){
            sem_post(&sB);
        }

        else if((strcmp(table[0], "Lettuce") != 0 && strcmp(table[1], "Lettuce") != 0)){
            sem_post(&sC);        
        }

        pthread_mutex_unlock(&lockTable);
        
    }
   }
    
void makerA(void* arg) {
    int n = *(int*)arg; 

    for (int i = 0; i < n; i++){

        sem_wait(&sA);
        pthread_mutex_lock(&lockTable);

        printf("Maker A picks up Cheese and Lettuce\n");
        printf("Maker A is making the sandwich...\n");

        strcpy(table[0], "");
        strcpy(table[1], "");

        printf("Maker A finished making the sandwich and eats it\n");
        
        printf("Maker A signals Supplier\n");

        pthread_mutex_unlock(&lockTable); 
        sem_post(&empty);
    }
}
void makerB(void* arg) {
    int n = *(int*)arg; 

    for (int i = 0; i < n; i++){

        sem_wait(&sB);
        pthread_mutex_lock(&lockTable);

        printf("Maker B picks up Bread and Lettuce\n");
        printf("Maker B is making the sandwich...\n");

        strcpy(table[0], "");
        strcpy(table[1], "");

        printf("Maker B finished making the sandwich and eats it\n");
    
        printf("Maker B signals Supplier\n");

        pthread_mutex_unlock(&lockTable); 
        sem_post(&empty);
    }    

}
void makerC(void* arg) {
    int n = *(int*)arg; 

    for (int i = 0; i < n; i++){

        sem_wait(&sC);
        pthread_mutex_lock(&lockTable);

        printf("Maker C picks up Bread and Cheese\n");
        printf("Maker C is making the sandwich...\n");

        strcpy(table[0], "");
        strcpy(table[1], "");

        printf("Maker C finished making the sandwich and eats it\n");
        
        printf("Maker C signals Supplier\n");

        pthread_mutex_unlock(&lockTable); 
        sem_post(&empty);
    }

}
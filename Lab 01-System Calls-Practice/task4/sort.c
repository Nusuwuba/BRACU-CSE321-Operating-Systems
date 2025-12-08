#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

    int arr[argc-1];
    
    for(int i=1; i<argc; i++){
        arr[i-1]= atoi(argv[i]);
    }
    
    int n = argc-1;

    for(int i=0; i<n; i++){

        for(int j=0; j<n-1 ;j++){
            
            if (arr[j]<arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
    
for(int i=0; i<n; i++){
        printf("%d\n", arr[i]);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char *argv[]){

    int arr[argc-1]; //because argv contains ./sort a b c d like this, we do not want the first letter
    int n = argc-1;  

    for(int i=1; i<argc; i++){
        arr[i-1]= atoi(argv[i]);   //arr er 0 index te boshbe but argv er 1 index theke shuru hocche
    }

    for(int j=0; j<n; j++){
        if (arr[j]%2 ==0 ){
            printf("%d : Even\n", arr[j]);
        }
        else{
            printf("%d : Odd\n", arr[j]);
        }
    }
}
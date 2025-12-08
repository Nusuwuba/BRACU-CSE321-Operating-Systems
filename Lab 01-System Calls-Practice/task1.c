#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
    int fd;

    char a[100];

    int number;

    fd = open("task1.txt" , O_WRONLY | O_CREAT | O_TRUNC, 0777);  //create a file named task1.txt, empties the file if run again

    do{

    printf("Enter a String:\n");

    fgets(a, sizeof(a), stdin);     //fgets adds a "/n" at the end so the string will look like: -1\n\0
    
    if(strcmp(a, "-1\n")!=0){

        write(fd, a,  strlen(a));}  //using strlen instead of sizeof because write() writes everything in the file, the whole char a[100] even if the input word is only 10
    
    } while(strcmp(a, "-1\n")!=0);

    close(fd);

}
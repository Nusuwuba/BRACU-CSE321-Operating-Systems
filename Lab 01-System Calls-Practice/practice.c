#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//----------- read()

int main(){
    char a[100]
    printf("Give Input:\n");
    read(0, a, sizeof(a));  //0 means it is reading the input
    printf("%s", a);
    return 0
}

//----------- write()

int main(){
    char b[]="I like OS labs";
    write(1, b, sizeof(b));  //1 means it is writing
    return 0
}

//-----------open(), O_CREAT, O_WRONLY, O_RDONLY

int main(){
    int fd;
    char a[100];
    char b[]="I like OS labs";

    fd= open("test1.txt", O_CREAT | O_WRONLY, 0777); //created then opened a file named test1.txt,  O_WRONLY | O_CREAT dibo if file thakle write but na thakle create then write
    write(fd, b, sizeof(b)); 
    close(fd);

    fd= open("test1.txt", O_RDONLY);
    read(fd, a, sizeof(a)); //Test1 read kore a te store koweshe
    printf("Data Read : %s\n",a);
    close(fd);

    return 0;
}

//---------lseek, O_RDWR

int main(){
    int fd;
    char a[100];
    char b[]="I like OS labs";

    fd= open("test1.txt", O_RDWR); //read and write the file
    write(fd, b, sizeof(b)); 
   
    lseek(fd, 0, SEEK_SET);//SEEK_SET:cursor file er shuru te chole jay then 0 offset e nijeke rakhe
    fd= open("test1.txt", O_RDONLY);
    read(fd, a, sizeof(a));
    printf("Data Read : %s\n",a);

    lseek(fd, -5, SEEK_CUR); //SEEK_CUR:current curser position theke -5 offset projonto cursor chole jacche. Remember ekhon current position ekdom sheshe after data read.
    read(fd, a, sizeof(a));
    printf("Data Read : %s\n",a);

    close(fd);

    return 0;
}
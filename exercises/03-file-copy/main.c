#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        exit(127);
    }

    char* file1 = argv[1];
    char* file2 = argv[2];

    int fd1 = open(file1, O_RDONLY);

    if(fd1 == -1){
        perror("open source");
        exit(127);
    }

    char buf;
    ssize_t n;
   
    int fd2 = open(file2, O_WRONLY | O_CREAT |O_TRUNC, 0644);
    if(fd2 == -1){
        perror("open destination");
        exit(127);
    }
    printf("File Content: \n");

    while ((n = read(fd1, &buf, 1)) > 0) {

        if (write(fd2, &buf, 1) == -1) {
            perror("write");
            exit(127);
        }
        printf("%c",buf);
    }
    if(n == -1){
        perror("read source");
        exit(127);
    }

    

    close(fd1);


    close(fd2);

    exit(0);
}
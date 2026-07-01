#define _POSIX_C_SOURCE 2008090L //feature test macro

#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

void alarm_sig(int sig);

int main(int argc, char* argv[]){

    if (argc < 2 || argc > 2){
        fprintf(stderr, "Usage: %s <time in seconds>\n", argv[0]);
        exit(EXIT_FAILURE);
    }  


    struct sigaction sa;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = alarm_sig;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    
    if(sigaction(SIGALRM, &sa, NULL) == -1){
        perror("signalaction");
        return 1;
    }


    char* endptr;
    long long_time = strtol(argv[1], &endptr, 10);
    int time_sec;

    if(endptr == argv[1]){
        fprintf(stderr, "Error: No digits were found\n");
        exit(EXIT_FAILURE);
    } else if(*endptr!='\0' && *endptr != '\n'){
        fprintf(stderr, "Error: Trailing non-numeric characters left: %s\n", endptr);
        exit(EXIT_FAILURE);
    } else{
       time_sec = (int)long_time;

       printf("Program starts\n\n");

       printf("%d sec\n", time_sec);
       alarm(time_sec);
    }

    for(;;) pause();


    return 0;
}

void alarm_sig(int sig){

    if(sig == SIGALRM){
        char buffer[] = "Time's up!\n";
        write(STDOUT_FILENO, buffer, sizeof(buffer)-1);
    }else{
        perror("alarm");
    }

    exit(0);
}
#define _POSIX_C_SOURCE 200809L //feature test macro

#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include<stdlib.h>

volatile sig_atomic_t terminate_flag = 0;

void terminate(int sig);

int main(){

    struct sigaction sa;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = terminate;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    char buffer[] = "Running ...\n";
    write(STDOUT_FILENO, buffer, sizeof(buffer)-1);

    /* wait for signals */
    while(!terminate_flag){
        pause();
    }

    return 0;
}

void terminate(int sig){

    if(sig == SIGINT){
        char buffer[] = "Caught Control+C\n";
        write(STDOUT_FILENO, buffer, sizeof(buffer)-1);

    }else{
        perror("signal");
    }

    terminate_flag = 1;
}
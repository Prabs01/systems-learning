#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/time.h>

int main(int argc, char* argv[]){

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [args...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Launcher PID: %d\n", getpid());

    struct timeval start, end;

    for(int i = 1; i<argc; i++){

        gettimeofday(&start,NULL);

        pid_t pid = fork();


        if(pid<0){
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if(pid == 0){

            printf("Running %s ...\n\n", argv[i]);

            pid_t cpid = getpid();
            pid_t ppid = getppid();

            printf("Child PID:%d\n", cpid);
            printf("Parent Pid:%d\n\n",ppid);

            execvp(argv[i], &argv[i]);
            
            perror("exec");
            exit(EXIT_FAILURE);
        }

        printf("Parent created child %d\n\n",pid);

        int status;

        if(waitpid(pid, &status, 0) != pid){
            perror("Wait");
            exit(EXIT_FAILURE);
        }

        gettimeofday(&end,NULL);

        long seconds = end.tv_sec - start.tv_sec;
        long microseconds = end.tv_usec - start.tv_usec;
        double total_time = seconds + microseconds / 1000000.0;

        printf("\nFinished in: %.2f seconds\n", total_time);

        printf("(done)\n");

        if(WIFEXITED(status)){
            printf("\nChild exited normally, exit status %d\n\n",WEXITSTATUS(status));
        }else if(WIFSIGNALED(status)){
            printf("\nChild exited abnormally, signal status %d\n\n",WTERMSIG(status));
        }


    }
        

    printf("Launcher exiting...\n");
    exit(0);
}
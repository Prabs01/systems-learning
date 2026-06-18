#include <stdio.h>
#include <unistd.h>

// terminate this process manually in terminal using kill <PID>
int main(void) {
    printf("Hello from systems-learning!!\n");
    int x = getpid();
    printf("My process ID is: %d\n", x);
    while(1);
    printf("done");
    return 0;
}


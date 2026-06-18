#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x[5];

    for(int i = 0; i < 5; i++) {
        x[i] = i;
    }

    printf("x[4] = %d\n", x[4]);

    int *y = malloc(5 * sizeof(int));

    if(y == NULL)
        return 1;

    for(int i = 0; i < 5; i++) {
        y[i] = i;
    }

    int *tmp = realloc(y, 10 * sizeof(int));

    if(tmp == NULL) {
        free(y);
        return 1;
    }

    y = tmp;

    for(int i = 5; i < 10; i++) {
        y[i] = i;
    }

    printf("y[6] = %d\n", y[6]);

    free(y);

    return 0;
}
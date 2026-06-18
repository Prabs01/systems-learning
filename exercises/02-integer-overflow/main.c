#include<stdio.h>
#include<stdlib.h>

int main(void){
    int x = __INT_MAX__;
    printf("---Signed INT---\n");
    printf("Before %d\n",x);
    x++;
    printf("After %d\n", x);

    unsigned int y = __UINT16_MAX__;
    printf("---Unsigned INT---\n");
    printf("Before %d\n",y);
    y++;
    printf("After %d\n", y);

    return 0;
}
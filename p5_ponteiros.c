#include <stdio.h>

int main(){

    int *ptr = malloc(sizeof(int));

    if (ptr != NULL) {
        *ptr = 10;
        printf("%d", *ptr);
    }

    free(ptr);

    return 0;
}

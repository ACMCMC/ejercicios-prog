#include <stdlib.h>
#include <stdio.h>

int main() {
    void* a = 0x78883904;
    int* x = 0x78883932;

    int n = (int) 5.4;

    printf("a %d, x %d\n", *((int*) a), *x);
}
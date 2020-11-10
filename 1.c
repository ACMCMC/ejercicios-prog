#include <stdlib.h>
#include <stdio.h>

int main()
{
    int x = 5;
    char* p;
    char aux;
    p = &x;
    for (int i = 0; i < 4; i++) {
        aux = *p;
        printf("CHAR %d: %c\n", i, aux+'0');
        p++;
    }

    return 0;
}

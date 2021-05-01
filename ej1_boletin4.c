#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    if (argc!=4) {
        printf("Error, hay que especificar los argumentos. Uso correcto: %s [tamaño] [paso] [numero de busquedas]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int tam_max = atoi(argv[1]);
    printf("%d\n", tam_max);

    for (int i = 0; i < argc; i++) {
        printf("Argumento %d: %s\n",i, argv[i]);
    }

    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define COSA 3

int* contar_mayoresque2_menoresque2(int* x, int num) {
    int* resultado; // el primer valor es <2 y el segundo >2
    int i;

    printf("%p, i\n", &i);

    resultado = (int*) malloc(2*sizeof(int));
    printf("%p, vector malloc\n", resultado);

    for (i = 0; i < num; i++) {
        if (x[i] < 2) {
            resultado[0]++;
        } else if (x[i] > 2) {
            resultado[1]++;
        }
    }

    return resultado;
}

int main() {
    int x[3] = {1,2,3};

    int* resultado_funcion;

    resultado_funcion = contar_mayoresque2_menoresque2(x, 3);

    sleep(1);

    printf("RES 1: %d, RES 2: %d\n", resultado_funcion[0], resultado_funcion[1]);

    free(resultado_funcion);
    resultado_funcion = 0;
}

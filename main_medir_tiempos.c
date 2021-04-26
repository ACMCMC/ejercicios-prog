#include <stdio.h>
#include <stdlib.h>
#include "vectordinamico.h"
#include <time.h>

int main(int argc, char **argv) {
    vectorD vector;
    unsigned long j = 0;
    unsigned long f = 0;
    char opcion;
    FILE *fp;
    fp = fopen("tiempos.txt", "w");
    unsigned long tamanho_maximo;
    unsigned long paso;
    unsigned long numero_busqueda;

    if (argc == 5) {
        tamanho_maximo = atol(argv[1]);
        numero_busqueda = atol(argv[2]);
        paso = atol(argv[3]);
        opcion = *argv[4];

    } else {
        printf("Número de argumentos incorrecto");
        exit(1);
    }

    //printf("Tamaño maximo %lu\n", tamanho_maximo);
    //printf("Num_busqueda %lu \n", numero_busqueda);
    //printf("paso %lu\n", paso);

    //for (f = 1; f <= tamanho_maximo; f += paso) {
    for (f = 100; f <= tamanho_maximo; f += paso) {


        crear(&vector, f);

        inicializar(vector);
            clock_t inicio = clock();

        switch (opcion) {
            //clock_t inicio = clock();
            case 's':
                //clock_t inicio = clock();


                for (j = 1; j <= numero_busqueda; j++) {
                    busquedaSecuencial(vector, rand());
                }
                //clock_t fin = clock();

                break;
                //clock_t fin = clock();
            case 'b':
                //clock_t inicio = clock();

                ordenar(vector);
                for (j = 1; j <= numero_busqueda; j++) {
                    busquedaBinariaRecursiva(vector, rand());
                }
                //clock_t fin = clock();

        }
                        clock_t fin = clock();

        //printf("%lu %lu %d %d %lf \n", j, f, (int) fin, (int) inicio, (fin - inicio) / (double) CLOCKS_PER_SEC * numero_busqueda);
        
                        fprintf(fp, "u\t%.41f\n", j, (fin - inicio) / (double) CLOCKS_PER_SEC * numero_busqueda);
        //printf("n:%lu		inicio.:%d	fin:%d		tiempo:%.11lf", j, f, (int) fin, (int) inicio, (fin - inicio) / (double) CLOCKS_PER_SEC * numero_busqueda);

        liberar(&vector);

    }

    fclose(fp);

    return (EXIT_SUCCESS);
}
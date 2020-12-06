#include <stdio.h>
#include <stdlib.h>

int y = 6;

int main() {
    int i = 23;
    double d = 10.0;
    char cadena[] = {'H','o','l','a','\0'};

    printf("Tamaño de un int: %lu, tamaño de un double: %lu\n", sizeof(int), sizeof(double));

    printf("El valor de y es: %d\n", y);
    printf("La direccion de memoria de y es: %p\n", &y);

    printf("El valor de i es: %d\n", i);
    printf("La direccion de memoria de i es: %p\n", &i);

    printf("El valor de d es %lf\n", d);
    printf("La direccion de memoria de d es %p\n", &d);


    printf("Cadena: %s\n", cadena);
    printf("La direccion de la cadena es %p", cadena);

    return 0;
}
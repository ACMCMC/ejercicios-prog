#include <stdio.h>
#include <stdlib.h>
#define V 100

char *BuscarChar(char *cadena, char ch) {
    char *c = cadena;
    //Avanzo por el string hasta que aparezca el caracter nulo
    while (*c != ch && *c != '\0') {//Bucle while con dos condiciones
        c += 1;
    }
    if (*c=='\0') {
        printf("caracter non atopado\n");
        c = NULL;
    }

    return c;
}

int main() {
    char cadena[V], ch, *buscar_cadena;
    // Leo un string y un caracter y los transmito a la función
    printf("Introduce una frase: "); gets(cadena);
    printf("Introduce una letra: "); scanf("%c", &ch);

    buscar_cadena = BuscarChar(cadena, ch);
    printf("Frase: %s\n", buscar_cadena);
    printf("Direccion de memoria: %p", buscar_cadena);

    return 0;
}

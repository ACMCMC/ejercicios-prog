/*
Escribir un programa cunha función que teña unha cadea de caracteres como parámetro formal,
que elimine espazos extra entre palabras desa cadea, e devolva o número de espazos eliminados.
A frase modificada, así como o número de cambios feitos téñense que impirmir dende main(), non
dentro da función que fai os cambios.
*/
#include <stdlib.h>
#include <stdio.h>
int compactar(char f[])
{
    int i, j;  // i es el índice actual de la cadena y j es el índice de lo que vamos moviendo
    int e = 0; // e es el número de veces que compactamos
    j = 0;

    for (i = 0; f[i] != '\0'; i++) // vamos recorriendo la cadena
    {
        while (f[i] == ' ' && f[i + 1] == ' ')
        {           // cuando tenemos dos espacios...
            e += 1; // incrementamos el número de errores

            // vamos a compactar la cadena
            for (j = i + 1; f[j] != '\0'; j++)
            {
                f[j] = f[j + 1];
            }
        }
    }
    return e;
}

int main()
{
    char frase[100];
    int num_espacios;
    printf("introduce unha frase:");
    gets(frase);

    num_espacios = compactar(frase);
    printf("frase corregida: \"%s\", numero de espacios %d\n", frase, num_espacios);
    return 0;
}
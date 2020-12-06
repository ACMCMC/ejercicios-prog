#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int tamano;
    float *datos;
} vector;

vector *suma(vector u, vector v)
{ // vectores = int---12
    vector *resultado;
    int i;

    if (u.tamano != v.tamano)
    {
        return NULL;
    }
    resultado = (vector *)malloc(sizeof(vector));
    resultado->datos = (float *)malloc(u.tamano * sizeof(float)); // *(resultado).datos
    for (i = 0; i < u.tamano; i++)
    {
        *(resultado->datos + i) = *(u.datos + i) + *(v.datos + i);
    }
    resultado->tamano = u.tamano;

    return resultado;
}

float* prodEscalar(vector u, vector v)
{
    float* resultado;
    int i;

    if(u.tamano != v.tamano) {
        return NULL;
    }
    resultado = (float*)malloc(sizeof(float));
    *resultado = 0;
    for(i = 0; i < u.tamano; i++) {
        *resultado += (*(u.datos + i)) * (*(v.datos + i));
    }

    return resultado;
}

int main()
{
    FILE *fp;
    vector u, v;
    int i;
    int opcion;
    vector *resultadoSuma;
    float *resultadoProducto;
    fp = fopen("datos_prod.txt", "r");
    if (fp == NULL)
        printf("ERRO abrindo o arquivo");
    else
    {
        fscanf(fp, "%d", &(u.tamano));
        u.datos = (float *)malloc(u.tamano * sizeof(float));
        for (i = 0; i < u.tamano; i++)
        {
            fscanf(fp, "%f", u.datos + i);
        }

        fscanf(fp, "%d", &(v.tamano));
        v.datos = (float *)malloc(v.tamano * sizeof(float));
        for (i = 0; i < v.tamano; i++)
        {
            fscanf(fp, "%f", v.datos + i);
        }
        printf("El vector u es: ");
        for (i = 0; i < u.tamano; i++)
        {                                  //Para imprimir todos los datos
            printf("%f ", *(u.datos + i)); // datos es punteros
        }
        printf("\n");

        printf("El vector v es: ");
        for (i = 0; i < v.tamano; i++)
        {                                  //Para imprimir todos los datos
            printf("%f ", *(v.datos + i)); // datos es punteros
        }
        printf("\n");

        do
        {
            printf("Que quieres hacer, sumar (1) o multiplicar (2), 0 para salir? ");
            scanf("%d", &opcion);

            switch (opcion)
            {
            case 1:
                resultadoSuma = suma(u, v);
                if (resultadoSuma == NULL)
                {
                    printf("Los tamaños no coinciden\n");
                }
                printf("La suma es: ");
                for (i = 0; i < resultadoSuma->tamano; i++)
                {                                           //Para imprimir todos los datos
                    printf("%f ", *(resultadoSuma->datos + i)); // datos es punteros
                }
                printf("\n");

                free(resultadoSuma->datos);
                free(resultadoSuma);

                break;
            case 2:
                resultadoProducto = prodEscalar(u, v);
                if (resultadoProducto == NULL) {
                    printf("Los tamaños no coinciden\n");
                }
                printf("El producto es: %f\n", *(resultadoProducto));

                free(resultadoProducto);
                break;
            }
        } while (opcion != 0);

        fclose(fp);
    }

    return 0;
}
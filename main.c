#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "lista.h"
#include "constantes.h"

typedef struct {
    char nombre[15];
    char localizacion[15];
} TIPOELEMENTOCOLA;

void _asignarTarea(TIPOELEMENTOCOLA* tarea)
{
    int habitacion;
    habitacion = _aleatorio(1, 6);
    switch (habitacion) {
        case 1:
            sprintf(&(tarea->nombre), "Arreglar goteras");
            sprintf(&(tarea->localizacion), "Aula A1");
        break;
        case 2:
            sprintf(&(tarea->nombre), "Arreglar goteras");
            sprintf(&(tarea->localizacion), "Aula A1");
        break;
        case 3:
            sprintf(&(tarea->nombre), "Arreglar goteras");
            sprintf(&(tarea->localizacion), "Aula A1");
        break;
        case 4:
            sprintf(&(tarea->nombre), "Arreglar goteras");
            sprintf(&(tarea->localizacion), "Aula A1");
        break;
        case 5:
            sprintf(&(tarea->nombre), "Arreglar goteras");
            sprintf(&(tarea->localizacion), "Aula A1");
        break;
        case 6:
            sprintf(&(tarea->nombre), "Arreglar goteras");
            sprintf(&(tarea->localizacion), "Aula A1");
        break;
    }
}

void _insertarTareas(TIPOELEMENTOLISTA* jugador) {
    TIPOELEMENTOCOLA tarea;
    for (int i = 0; i < NUM_TAREAS; i++) {
        _asignarTarea(&tarea);
        //void anadirElementoCola(TCOLA *q, TIPOELEMENTOCOLA e);
        anadirElementoCola(&(jugador->tareas), tarea);
    }
}

int _asignarRolesYTareas(TLISTA *listajugadores)
{
    TIPOELEMENTOLISTA jugador;
    TIPOELEMENTOCOLA tareas;
    TPOSICION posicion;
    unsigned int random;

    posicion = primeroLista(*listajugadores);

    random = _aleatorio(0, longitudLista(*listajugadores)-1);
    for (int i = 0; i < longitudLista(*listajugadores); i++)
    {
        recuperarElementoLista(*listajugadores, posicion, &jugador);
        if (random == i)
        {
            jugador.rol = 'I';
        }
        _insertarTareas(&jugador);
        posicion = siguienteLista(*listajugadores, posicion);
    }
}

void _nuevoJugador(TLISTA *lista, TIPOELEMENTOLISTA jugador)
{
    jugador.rol = ROL_ESTUDIANTE;
    crearCola(&(jugador.tareas));
    if (longitudLista(*lista) < 10)
    {
        insertarElementoLista(lista, finLista(*lista), jugador);
    }
}

void nuevoJugador(TLISTA *lista)
{
    TIPOELEMENTOLISTA jugador;
    scanf("%s", &(jugador.alias));
    if (_esusernamevalido(jugador.alias))
    {
        _nuevoJugador(lista, jugador);
    }
}

void inicializar(TLISTA *lista, int argc, char **argv)
{
    int i;
    TIPOELEMENTOLISTA jugador;
    crearLista(lista);
    for (i = 1; i < argc; i++)
    {
        strncpy(&(jugador.alias), argv[i], sizeof(char) * MAX_NAME_LENGTH);
        _nuevoJugador(lista, jugador);
    }
}

void liberarListaJugadores(TLISTA *lista)
{
    TPOSICION pos;
    TIPOELEMENTOLISTA jugador;
    pos = primeroLista(*lista); // POSICION DEL PRIMERO

    while (pos != finLista(*lista))
    {
        recuperarElementoLista(*lista, pos, &jugador);
        destruirCola(&(jugador.tareas));
        pos = siguienteLista(*lista, pos);
    }

    destruirLista(lista);
}

int main(int argc, char **argv)
{
    TLISTA lista;
    inicializar(&lista, argc, argv);

    TIPOELEMENTOLISTA jugador;
    _nuevoJugador(&lista, jugador);

    switch ()
    {
    }
}
​
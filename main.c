#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "lista.h"
#include "constantes.h"

void _asignarTarea(TIPOELEMENTOCOLA *tarea)
{
    int habitacion;
    habitacion = _aleatorio(1, 6);
    switch (habitacion)
    {
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

void _insertarTareas(TIPOELEMENTOLISTA *jugador)
{
    TIPOELEMENTOCOLA tarea;
    for (int i = 0; i < NUM_TAREAS; i++)
    {
        _asignarTarea(&tarea);
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

    random = _aleatorio(0, longitudLista(*listajugadores) - 1);
    for (int i = 0; i < longitudLista(*listajugadores); i++)
    {
        recuperarElementoLista(*listajugadores, posicion, &jugador);
        if (random == i)
        {
            jugador.rol = 'I';
        }
        _insertarTareas(&jugador);
        modificarElementoLista(listajugadores, posicion, jugador);
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

int _comprobarVictoria(TLISTA lista)
{
    TPOSICION pos;
    TIPOELEMENTOLISTA jugador;
    TIPOELEMENTOCOLA tareaPrimera;
    int numE = 0, numI = 0, flagHayEstudiantesConTarea;
    while (pos != finLista(lista))
    {
        recuperarElementoLista(lista, pos, &jugador);

        if (jugador.rol = 'E')
        {
            numE++;
        }
        else if (jugador.rol = 'I')
        {
            numI++;
        }

        pos = siguienteLista(lista, pos);
    }

    if (numI >= numE)
    {
        return 1;
    }

    if (numI == 0)
    {
        return 1;
    }

    recuperarElementoLista(lista, primeroLista(lista), &jugador);

    if (esColaVacia(jugador.tareas))
    {
        return 1;
    }

    return 0;
}

TIPOELEMENTOCOLA _buscarHabImp(TLISTA lista)
{
    TPOSICION pos;
    TIPOELEMENTOLISTA jugador;
    TIPOELEMENTOCOLA tareaPrimera;
    pos = primeroLista(lista); // POSICION DEL PRIMERO

    while (pos != finLista(lista))
    {
        recuperarElementoLista(lista, pos, &jugador);

        if (jugador.rol = 'I')
        {
            consultarPrimerElementoCola(jugador.tareas, &tareaPrimera);
            return tareaPrimera;
        }

        pos = siguienteLista(lista, pos);
    }
}

void _procesarExpulsiones(TLISTA *lista, TIPOELEMENTOCOLA tareaImpostor)
{
    TPOSICION pos;
    TIPOELEMENTOLISTA jugador;
    TIPOELEMENTOCOLA tareaJug;

    while (pos != finLista(lista))
    {
        recuperarElementoLista(lista, pos, &jugador);
        consultarPrimerElementoCola(jugador.tareas, &tareaJug);

        if (jugador.rol == 'E' && strncmp(tareaJug.localizacion, tareaImpostor.localizacion, 15) == 0)
        {
            if (_aleatorio(0, 1))
            {
                printf("Expulsado %s en %s\n", jugador.alias, tareaJug.localizacion);
                suprimirElementoLista(lista, pos);
            }
        }

        pos = siguienteLista(lista, pos);
    }
}

void imprimirListaJugadores(TLISTA listajugadores, int imprimirRol)
{
    TIPOELEMENTOLISTA jugador;
    TPOSICION posicion;

    posicion = primeroLista(listajugadores);

    printf("\nJugadores: ");

    while (posicion != finLista(listajugadores))
    {
        recuperarElementoLista(listajugadores, posicion, &jugador);
        printf("\nUsername: %s", jugador.alias);
        if (imprimirRol)
        {
            printf("\nRol: %c", jugador.rol);
        }
        _imprimirPrimeroCola(jugador.tareas);
        posicion = siguienteLista(listajugadores, posicion);
    }
    printf("\n");
}

void _imprimirPrimeroCola(TCOLA tareas)
{
    TIPOELEMENTOCOLA c;

    consultarPrimerElementoCola(tareas, &c);
    printf("\nTareas: No hay tareas pendientes");
}

void _actualizarTareas(TLISTA listajugadores)
{
    TIPOELEMENTOLISTA jugador;
    TPOSICION posicion;

    posicion = primeroLista(listajugadores);

    while (posicion != finLista(listajugadores))
    {
        recuperarElementoLista(listajugadores, posicion, &jugador);

        suprimirElementoCola(&(jugador.tareas));

        posicion = siguienteLista(listajugadores, posicion);
    }
}

void _expulsarJugador(TLISTA *listajugadores)
{
    char expulsa_alias[20];
    TPOSICION posicion;
    TIPOELEMENTOCOLA tareas;
    int flagSeHaExpulsadoJugador;

    posicion = primeroLista(*listajugadores);

    printf("¿A qué jugador quieres expulsar? (Inserta 'skip' para saltar)");
    scanf(" %s", expulsa_alias);

    if (strncmp("skip", expulsa_alias, 15) && _esUsernameValido(expulsa_alias))
    {
        TIPOELEMENTOLISTA jugador;
        TPOSICION posicion;

        flagSeHaExpulsadoJugador = 0; // suponemos que no se expulsa nadie

        posicion = primeroLista(*listajugadores);

        while (posicion != finLista(*listajugadores))
        {
            recuperarElementoLista(*listajugadores, posicion, &jugador);

            if (strncmp(expulsa_alias, jugador.alias, 15) == 0)
            {
                suprimirElementoLista(listajugadores, posicion);
                flagSeHaExpulsadoJugador = 1; // hemos expulsado a alguien, cambiamos el valor de la variable
            }

            posicion = siguienteLista(*listajugadores, posicion);
        }

        if (flagSeHaExpulsadoJugador == 1)
        {
            printf("Expulsado %s\n", expulsa_alias);
        }
        else if (flagSeHaExpulsadoJugador == 0)
        {
            printf("No se ha encontrado al jugador.\n");
        }
    }
}

void jugar(TLISTA *lista)
{
    _asignarRolesYTareas(lista);

    while (!_comprobarVictoria(*lista))
    {
        _procesarExpulsiones(lista, _buscarHabImp(*lista));

        imprimirListaJugadores(*lista, 0);

        _actualizarTareas(*lista);

        if (!_comprobarVictoria(*lista)) {
            _expulsarJugador(lista);
        }
    }
}

void nuevoJugador(TLISTA *lista)
{
    TIPOELEMENTOLISTA jugador;
    scanf("%s", &(jugador.alias));
    if (_esUsernameValido(jugador.alias))
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
}
​
# include "cola.h"

// Prototipos de funciones privadas
void iniciar_cola(PCola cola);

// Funciones privadas
void iniciar_cola(PCola cola) {
    cola->primero = cola->ultimo = NULL;
    cola->tam = 0;
}

// Funciones publicas
Cola cola_crear(void) {
    Cola nueva_cola;

    iniciar_cola(&nueva_cola);

    return nueva_cola;
}

void cola_agregar(PCola cola, T dato) {
    PNodo elem = (PNodo)malloc(sizeof(Nodo));

    if (elem == NULL) {
        printf("Error al asignar espacio en memoria");
        exit(1);
    }

    elem->dato = dato;
    elem->siguiente = NULL;

    if (cola->primero == NULL) {
        cola->primero = elem;
        cola->ultimo = elem;
    }
    else {
        cola->ultimo->siguiente = elem;
        cola->ultimo = elem;
    }

    cola->tam += 1;
}

T cola_quitar(PCola cola) {
    if (cola->primero == NULL) return NULL;

    PNodo temp = cola->primero;
    T dato = temp->dato;

    cola->primero = temp->siguiente;

    free(temp);

    cola->tam -= 1;

    return dato;
}

void cola_destruir(PCola cola) {
    T dato_cola = (T)cola_quitar(cola);
    while (dato_cola != NULL) {
        dato_cola = (T)cola_quitar(cola);
    }

    cola->primero = cola->ultimo = NULL;
}
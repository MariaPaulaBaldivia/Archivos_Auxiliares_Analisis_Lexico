#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nodo {
    char* info;
    int repeticion;
    struct nodo* siguiente;
} Nodo;


void vaciarLista(Nodo* lista);
void insertarOrdenadoAlfabeticamente(Nodo** lista, char* cadenaLeida);
Nodo* buscar(Nodo* lista, char* cadenaLeida);
void buscarOInsertarOrdenadoAlfabeticamente(Nodo** lista, char* cadenaLeida);

int main() {
    Nodo* lista= NULL;
    buscarOInsertarOrdenadoAlfabeticamente(&lista, "paula");
    buscarOInsertarOrdenadoAlfabeticamente(&lista, "hola");
    buscarOInsertarOrdenadoAlfabeticamente(&lista, "chau");
    buscarOInsertarOrdenadoAlfabeticamente(&lista, "hola");
    buscarOInsertarOrdenadoAlfabeticamente(&lista, "paula");
    buscarOInsertarOrdenadoAlfabeticamente(&lista, "cookie");

    while(lista != NULL) {
        printf("%s , repeticion %i \n", lista->info, lista->repeticion);
        lista = lista->siguiente;
    }

    vaciarLista(lista);

    return 0;
}

void insertarOrdenadoAlfabeticamente(Nodo** lista, char* cadenaLeida) {
    Nodo* p = (Nodo*) malloc(sizeof(Nodo));
    
    p->info = cadenaLeida;
    p->repeticion = 1;

    if((*lista) == NULL || (strcmp(cadenaLeida, (*lista)->info) < 0)) {  // Si la lista esta vacia o la cadena a guardar es menor alfabeticamente a la primer cadena guardada
        p->siguiente = (*lista);
        (*lista) = p;
    } else {
        Nodo* q = (*lista);

        while(q->siguiente != NULL && (strcmp(cadenaLeida, q->siguiente->info) > 0)) { // Mientras el nodo sgte que apunta la lista no sea NULL y la cadena leida sea mayor alfabeticamente a la cadena guardada del nodo siguiente que apunta la lista
            q = q->siguiente; // Avanzo en la lista
        }

        p->siguiente = q->siguiente; 
        q->siguiente = p;   
    }
}

Nodo* buscar(Nodo* lista, char* cadenaLeida) {
    Nodo* aux = lista;

    while(aux != NULL && (strcmp(cadenaLeida, aux->info) > 0)) { // Mientra no sea fin de lista y la cadena sea mayor que la que esta guardada
        aux = aux->siguiente;
    }

    if(aux != NULL && (strcmp(aux->info, cadenaLeida) == 0)) { // Si no es fin de lista y cadenaLeida es igual a una cadena guardada
        return aux;
    } else {
        return NULL;
    }
}

void buscarOInsertarOrdenadoAlfabeticamente(Nodo** lista, char* cadenaLeida) {
    Nodo* p = buscar((*lista), cadenaLeida);

    if(p == NULL) {    // No lo encontró guardado en la lista
        insertarOrdenadoAlfabeticamente(lista, cadenaLeida);
    } else {
        p->repeticion = p->repeticion + 1; // Agrego una repeticion
    }
}

void vaciarLista(Nodo* lista) {
    if(lista != NULL) {
        vaciarLista(lista->siguiente);
        free(lista);
    }
}

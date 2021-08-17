#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo* siguiente;
} Nodo;

void insertarPorLongitudAscendente(Nodo** lista, int n);
void vaciarLista(Nodo* lista);

int main() {
    Nodo* lista = NULL;
    insertarPorLongitudAscendente(&lista, 25);
    insertarPorLongitudAscendente(&lista, 50);
    insertarPorLongitudAscendente(&lista, 80);
    insertarPorLongitudAscendente(&lista, 35);
    insertarPorLongitudAscendente(&lista, 5);
    insertarPorLongitudAscendente(&lista, 25);


    while(lista != NULL) {
        printf("%i \n", lista->info);
        lista = lista->siguiente;
    }

    vaciarLista(lista);

    return 0;
}

void insertarPorLongitudAscendente(Nodo** lista, int n) {
    Nodo* p = (Nodo*) malloc(sizeof(Nodo));
    p->info = n;

    if((*lista) == NULL || n <= (*lista)->info) {  // Si la lista esta vacia o la longitud de la cadena a guardar es menor a la de la primer cadena guardada
        p->siguiente = (*lista);                   // Nuevo nodo pasa a ser primer elemento
        (*lista) = p;
    } else {
        Nodo* q = (*lista);

        while(q->siguiente != NULL && n > (*lista)->siguiente->info) { // Mientras la lista tenga elementos y la cadena leida sea de mayor longitud a la de la cadena guardada del nodo siguiente 
            q = q->siguiente;                                          // Avanzo en la lista
        }

        p->siguiente = q->siguiente;                                                    
        q->siguiente = p;   
    }
}

void vaciarLista(Nodo* lista) {
    if(lista != NULL) {
        vaciarLista(lista->siguiente);
        free(lista);
    }
}
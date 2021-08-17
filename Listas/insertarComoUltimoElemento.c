#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo* siguiente;
} Nodo;

void insertarComoUltimoElemento(Nodo** lista, int n);
void vaciarLista(Nodo* lista);

int main() {
    Nodo* lista = NULL;
    insertarComoUltimoElemento(&lista, 25);
    insertarComoUltimoElemento(&lista, 50);
    insertarComoUltimoElemento(&lista, 80);
    insertarComoUltimoElemento(&lista, 35);
    insertarComoUltimoElemento(&lista, 5);
    insertarComoUltimoElemento(&lista, 25);


    while(lista != NULL) {
        printf("%i \n", lista->info);
        lista = lista->siguiente;
    }

    vaciarLista(lista);
  
    return 0;
}

void insertarComoUltimoElemento(Nodo** lista,int n) {
    Nodo* q = (*lista);
    Nodo* p = (Nodo*) malloc(sizeof(Nodo));
    
    p->info = n;

    if((*lista) == NULL) {          // Si la lista esta vacia 
        p->siguiente = (*lista);    // Nuevo nodo pasa a ser primer elemento
        (*lista) = p;
    } else {
        

        while(q->siguiente != NULL) { // Mientras la lista tenga elementos y la cadena leida sea de mayor longitud a la de la cadena guardada del nodo siguiente 
            q = q->siguiente;         // Avanzo en la lista
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
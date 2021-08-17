#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    int repeticion;
    char* info;
    struct nodo* siguiente;
} Nodo;

void insertarComoUltimoElemento(Nodo** lista, char* n);
void vaciarLista(Nodo* lista);
void buscarOInsertarAlFinalDeLaLista(Nodo** lista, char* n);
Nodo* buscarCadena(Nodo* lista, char* cadenaLeida);

int main() {
    Nodo* lista = NULL;

    buscarOInsertarAlFinalDeLaLista(&lista, "++");
    buscarOInsertarAlFinalDeLaLista(&lista, "(");
    buscarOInsertarAlFinalDeLaLista(&lista, ")");
    buscarOInsertarAlFinalDeLaLista(&lista, ";");
    buscarOInsertarAlFinalDeLaLista(&lista, "+");
    buscarOInsertarAlFinalDeLaLista(&lista, "-");
    buscarOInsertarAlFinalDeLaLista(&lista, ";");
    buscarOInsertarAlFinalDeLaLista(&lista, "*");
    buscarOInsertarAlFinalDeLaLista(&lista, "(");
    buscarOInsertarAlFinalDeLaLista(&lista, ")");
    buscarOInsertarAlFinalDeLaLista(&lista, ";");
    buscarOInsertarAlFinalDeLaLista(&lista, ",");
    buscarOInsertarAlFinalDeLaLista(&lista, ";");
    buscarOInsertarAlFinalDeLaLista(&lista, "++");

     while(lista != NULL) {
        printf("%s , repeticion %i \n", lista->info, lista->repeticion);
        lista = lista->siguiente;
    }

    vaciarLista(lista);

    return 0;
}

void buscarOInsertarAlFinalDeLaLista(Nodo** lista, char* cadenaLeida) {
    Nodo* p = buscarCadena(*lista, cadenaLeida);

    if(p == NULL) {
        insertarComoUltimoElemento(lista, cadenaLeida);
    } else {
        p->repeticion = p->repeticion + 1;
    }
}

Nodo* buscarCadena(Nodo* lista, char* cadenaLeida) {
    Nodo* aux = lista;

    while(aux != NULL && (strcmp(cadenaLeida, aux->info) != 0)) { // Mientra no sea fin de lista y la cadena sea distista a la guardada 
        aux = aux->siguiente;                                     // Avanzo en la lista
    }

    if(aux != NULL && strcmp(aux->info, cadenaLeida) == 0) { // Si no es fin de lista y cadenaLeida es igual a una cadena guardada
        return aux;
    } else {
        return NULL;
    }
}

void insertarComoUltimoElemento(Nodo** lista, char* n) {
    Nodo* q = (*lista);
    Nodo* p = (Nodo*) malloc(sizeof(Nodo));
    
    p->info = n;
    p->repeticion = 1;

    if((*lista) == NULL) {          // Si la lista esta vacia 
        p->siguiente = (*lista);    // Nuevo nodo pasa a ser primer elemento
        (*lista) = p;
    } else {
        

        while(q->siguiente != NULL) { // Mientras la lista tenga elementos
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
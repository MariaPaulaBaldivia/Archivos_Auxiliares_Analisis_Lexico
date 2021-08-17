#include <stdio.h>

int cuadrado(int x);

int main() {
    int a=0123, B=123, C=0x567, D=0x123D;
    float h = 0.12e-14;
    int i,resultado;
    
    for (i=0;i<10;i++) {
        resultado = cuadrado (i);
        printf("Cuadrado de %d: %d\n",i,resultado);
    }
    return 0;
    $;
    #;
}
// JComentario simple
/* Comentario
    multilinea*/

int cuadrado(int x) {
    int r;
    r=x*x;
    
    return r;
}
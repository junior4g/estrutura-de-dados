#include <stdio.h>
#define MAXL 100

typedef struct cx {
    int n;
    struct nodo *prox;
}Caixa;

    Caixa *q, *r, *s;

    struct nodo t;
    int g;

/*
printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem); //2 - 3 - 4
Q = Q->Prox; //A
printf("%d - %d - Perde-se a posicao de 2 \n",Q->Elem, Q->Prox->Elem); // 3 - 4
*/

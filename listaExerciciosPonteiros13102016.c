#include <stdio.h>

typedef struct cx {
    int Elem;
    struct cx *prox;
}Caixa;

typedef Caixa *Ponteiro;

int main(){
    Caixa A, B, C, D, E, T;
    Ponteiro Q, R, S;
    int g, n;
    A.Elem = 1;
    B.Elem = 2;
    C.Elem = 3;
    D.Elem = 4;
    E.Elem = 5;
    T.Elem = 6;

    A.prox = &B;
    B.prox = &C;
    C.prox = &D;
    D.prox = NULL;
    E.prox = NULL;

    Q = &B;
    R = &D;
    S = &E;


    printf("Q = %d, R = %d, S = %d", Q, R, S);
    printf("\n%d %d %d %d %d %d", A.Elem, B.Elem, C.Elem, D.Elem, E.Elem, T.Elem);

//Exercicio 01
/*
printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem); //2 - 3 - 4
Q = Q->Prox; //A
printf("%d - %d - Perde-se a posicao de 2 \n",Q->Elem, Q->Prox->Elem); // 3 - 4


Letra H) Da erro de compilação, pois um é ponteiro e outro não
*/

/*Exercicio 03
Assuma as declarações e condições iniciais do problema 1. Escreva as sequências de comandos que
convertem a situação, diagramada na fig. 1, para cada uma das configurações (a - h) mostradas nas figuras
seguintes: */

/*Letra A
g = T.n;
S->prox=S;
T = *Q;
*Q = *S;
*S = T;
S = Q;
Q = Q->prox->prox;
T.n = g;*/

/*Letra C
R->prox = S;
R = Q->prox;
Q->prox = R->prox;
R->prox = Q;*/

/*Letra F
S->prox = Q->prox;
Q->prox = R;
R->prox = S;
S->prox->prox = NULL;*/

/*Letra G
S->prox = R;
R = Q->prox;
R->prox = S;
Colocou a caixa 5 entre 3 e 4.*/

/*Letra H
S->prox = Q->prox;
R->prox = Q;
Q->prox = S;
T.prox = NULL;
Perde o endereço da caixa 3*/

}


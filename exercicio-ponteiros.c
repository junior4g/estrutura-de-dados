/*	Aluno: Orlando Da Cruz Pereira Junior
 * 	Data: 25/12/2016 Semestre 2016-2
 *  Matriz Triangular Superior
 * */

#include <stdio.h>

typedef struct CX{	int Elem;
					struct CX *Prox;
} Caixa;

typedef Caixa *Ponteiro;

int main(void){
	
	Caixa A, B, C, D, E, T;
	Ponteiro Q, R, S;
	
	A.Elem = 1;
	B.Elem = 2;
	C.Elem = 3;
	D.Elem = 4;
	E.Elem = 5;
	T.Elem = 6;
	A.Prox = &B;
	B.Prox = &C;
	C.Prox = &D;
	D.Prox = NULL;
	E.Prox = NULL;
	Q = &B;
	R = &D;
	S = &E;
	
	//Letra A
	printf("Lista de exercicios de Ponteiros\n");
	printf("Letra A\n");
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);
	Q = Q->Prox;
	printf("%d - %d Perde-se a posicao de 2\n", Q->Elem, Q->Prox->Elem);
	
	//Letra B
	/*printf("Letra B\n");
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);
	*Q = *(Q->Prox);*/
	
	//Letra C
	/*printf("Letra C\n");
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);
	Q->Prox = Q->Prox->Prox;
	printf("%d - %d Perde-se o endereco de 3\n", Q->Elem, Q->Prox->Elem);*/
	
	//Letra D
	/*printf("Letra D\n");
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);
	Q = R->Prox;
	printf("Perde-se a posicao de 2 e 3\n");*/
	
	//Letra E
	/*printf("Letra E\n");
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);
	printf("Erro de execucao, nao tem o que fazer\n");
	*Q = *(R->Prox);*/
	
	//Letra F
	/*printf("Letra F\n");
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);
	S->Prox = Q->Prox;
	Q->Prox = S;
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);*/
	
	
	//Letra G
	/*printf("Letra G\n");
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);
	S->Prox = S;
	T = *Q;
	*Q = *S;
	*S = T;	
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);*/
	
	//Letra H
	/*printf("Letra H\n");
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);
	Q = T;
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);*/
	
	//Letra I
	/*printf("Letra I\n");
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);
	R->Prox = Q;
	Q = Q->Prox->Prox->Prox;
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);*/
	
	//Letra J
	/*printf("Letra J\n");
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);
	S = R;
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);*/
	
	//Letra K
	/*printf("Letra K\n");
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);
	R = &T;
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);*/
	
	//Letra J
	/*printf("Letra J\n");
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);*/
	
	//Letra L
	/*printf("Letra L\n");
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);
	Q->Prox = &T;
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);*/
	
	//Letra M
	/*printf("Letra M\n");
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);
	R->Prox = R;
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);*/
	
	//Letra N
	/*printf("Letra N\n");
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);
	S->Prox = Q->Prox;
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);*/
	
	//Letra O
	/*printf("Letra O\n");
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);
	R->N = G;
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);*/
	
	//Letra P
	/*printf("Letra P\n");
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);
	Q->Prox->N = S->N;
	printf("%d - %d - %d\n", Q->Elem, Q->Prox->Elem, Q->Prox->Prox->Elem);*/
	
	return 0;
}

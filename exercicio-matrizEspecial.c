/*	Aluno: Orlando Da Cruz Pereira Junior
 * 	Materia : Estrutura de Dados
 * 	Professor: Edmundo Sergio Spoto
 * 	Data: 01/09/2016 Semestre 2016-2
 *  Matriz Triangular Superior
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 15
typedef int vetor[N];

void LerMatriz(vetor X){
	int i=1, j=1, k=0;
	
	for(i=1; i<5; i++){
		for(j=1; j<5; j++){
			//printf("Digite o elemento M[%d][%d]: ", i, j);
			//scanf("%d",&X[k]);
			if(j>i || i==j){
				X[k] = 3;
			}
			else{
				X[k] = 0;
			}
			//X[k] = 3;
			k++;
		}
	}
}

void ExibirElementoMatriz(vetor X){
	int i, j, k=0;
	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			printf(" %d ", X[k]);
			k++;
		}
		printf("\n");
	}
}

void SomaMatriz(vetor A, vetor B, vetor C){
	int i, j, k=0;
		for(i=1; i<=N; i++){
			for(j=1; j<5; j++){
				if(j>i || i==j){
					C[k] = A[k] + B[k];
				}
				if(j<i){
					C[k] = 0;
				}
		k++;
		}
	}
}

void ProdutoMatriz(vetor A, vetor B, vetor D){
	int i, j, k=0;
		for(i=1; i<=N; i++){
			for(j=1; j<5; j++){
				if(j>i || i==j){
					D[k] = A[k] * B[k];
				}
				if(j<i){
					D[k] = 0;
				}
		k++;
		}
	}
}

void Consultar_Elemento (vetor A, int x, int y){ 
	int i, j, k=0;
	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if((x==i) && (y==j)){
					printf ("O elemento escolhido eh: %d\n", A[k]);
				}
			k++;
		}
	}
}


int main(){
	int i=0;
	vetor A, B, C, D;
	do 
		{
		printf ("\n##################################");
		printf ("\nEscolha o que deseja fazer com a matriz especial:\n\n");
        printf ("1 - Subtracao\n");
        printf ("2 - Multiplicacao\n");
        printf ("3 - Exibir\n");
        printf ("4 - Consultar\n");
        printf ("6 - Sair\n\n");
        scanf("%d",&i);

        if(i == 1){	
			LerMatriz(A); //sempre usar vetor nas matrizes especiais
			LerMatriz(B);
			
			SomaMatriz(A, B, C);
			printf("\nSoma dos elementos da matriz A e B = C\n");
			ExibirElementoMatriz(C);
		}
		if(i == 2){
			LerMatriz(A); //sempre usar vetor nas matrizes especiais
			LerMatriz(B);
			
			ProdutoMatriz(A, B, D);
			printf("\nProduto dos elementos da matriz A e B = D\n");
			ExibirElementoMatriz(D);
		}
		if(i == 3){
			LerMatriz(A); //sempre usar vetor nas matrizes especiais
			LerMatriz(B);
			printf("Elementos da matriz A\n");
			ExibirElementoMatriz(A);
			printf("\nElementos da matriz B\n");
			ExibirElementoMatriz(B);
		}
		if(i == 4){
			int x, y;
			printf("\nDigite a posicao do elemento");
			printf("\nLinha: ");
			scanf("%d",&x);
			printf("Coluna: ");
			scanf("%d",&y);
			LerMatriz(A); //sempre usar vetor nas matrizes especiais
			LerMatriz(B);
			Consultar_Elemento (A, x, y);
		}

	} while (i<5);
	
	return 0;
}

/*	Aluno: Orlando Da Cruz Pereira Junior
 * 	Data: 25/12/2016 Semestre 2016-2
 *  Matriz Triangular Superior
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#define N 15

typedef int vetor[N];

void LerMatriz(vetor X){
	int i=1, j=1, k=0, cont=0;
	
	for(i=1; i<5; i++){
		for(j=1; j<5; j++){
			//printf("Digite o elemento M[%d][%d]: ", i, j);
			//scanf("%d",&X[k]);
			if(j>i || i==j){
				X[k] = cont;
			}
			else{
				X[k] = 0;
			}
			k++;
			cont++;
		}
	}
}

void ExibirElementoMatriz(vetor X){
	int i, j, k=0;
	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			printf(" %3.2d ", X[k]);
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
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			if((x==i) && (y==j)){
					printf ("O elemento escolhido eh: %d\n", A[k]);
			}
			k++;
		}
	}
}
void Consultar_Elemento1 (){ 
	printf ("O elemento escolhido e: \n");
}


int main(){
	int i=0, x=0, y=0, a, b;
	vetor A, B, C, D;
	int j=1, k=0;
	
	do 
		{
		printf ("\n########## MATRIZES ESPECIAIS ###########\n");
				
		printf ("\nDigite a opcao desejada:\n");
        printf ("1 - Subtracao\n");
        printf ("2 - Multiplicacao\n");
        printf ("3 - Exibir\n");
        printf ("4 - Consultar\n");
        printf ("6 - Sair\n\n");
        printf ("Opcao:__");
        scanf("%d",&i);
		
		switch ( i ){
	    	case 1 :
				LerMatriz(A);
				LerMatriz(B);
				
				SomaMatriz(A, B, C);
				printf("\nSoma dos elementos da matriz A e B = C\n");
				ExibirElementoMatriz(C);
	    	break;
			
			case 2 :
				LerMatriz(A); 
				LerMatriz(B);
				
				ProdutoMatriz(A, B, D);
				printf("\nProduto dos elementos da matriz A por B = D\n");
				ExibirElementoMatriz(D);
	    	break;
			
			case 3 :
				LerMatriz(A); 
				LerMatriz(B);
				
				printf("\nElementos da matriz A\n");
				ExibirElementoMatriz(A);
				printf("\nElementos da matriz B\n");
				ExibirElementoMatriz(B);
	    	break;
			
			case 4 :
				printf("\nDigite a posicao do elemento");
				printf("\nLinha: ");
				scanf("%d",&a);
				printf("Coluna: ");
				scanf("%d",&b);
				LerMatriz(A); //sempre usar vetor nas matrizes especiais
				LerMatriz(B);
				Consultar_Elemento (A, a, b);
		    break;
			
			default :
       			printf ("Valor invalido!\n");
  		}
		printf ("\n#########################################\n");    	
	} while (i<5);
	
	return 0;
}


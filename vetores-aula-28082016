
/*	Aluno: Orlando Da Cruz Pereira Junior
 * 	Materia : Estrutura de Dados
 * 	Professor: Edmundo Spoto
 * 	Data: 28/08/2016 Semestre 2016-2
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
typedef int vetor[N];
typedef float vetor1[N];

int main(){
	vetor A, B, C;
	float M;
	
	PreencherVetor(A, B);
	SomarVetores(A, B, C);
	MostrarVetor(A, B, C);
	SubtracaoVetor(A, B, C);
	EmitirVetor(A, B, M);
	
	return 0;
}

void PreencherVetor(vetor A, vetor B){
	int i = 0;
	for(i=0; i<20; i++){
		A[i] = rand() % 100;
		B[i] = rand() % 100;
	}
}

void SomarVetores(vetor A, vetor B, vetor C){
	int i = 0;
	for(i=0; i<20; i++){
		C[i] = A[i] + B[i];
	}
}

void MostrarVetor(vetor A, vetor B, vetor C){
	int i;
	printf("Vetor A \n");
	for(i=0; i<20; i++){
		printf(" %3d ",A[i]);
	}
	printf("\n\n Vetor B \n");
	for(i=0; i<20; i++){
		printf(" %3d ",B[i]);
	}
	printf("\n\n Soma de A + B = Vetor C \n");
	for(i=0; i<20; i++){
		printf(" %3d ",C[i]);
	}
}

SubtracaoVetor(vetor A, vetor B, vetor C){
	int i = 0;
	for(i=0; i<20; i++){
		C[i] = A[i] - B[i];
	}
	
	printf("\n\n Subtracao de A - B = Vetor C \n");
	for(i=0; i<20; i++){
		printf(" %3d ",C[i]);
	}
}

void EmitirVetor(vetor A, vetor B, vetor1 M){
	int i = 0;
	for(i=0; i<20; i++){
		M[i] = A[i] + rand() % (B[i] - A[i]);
	}
	
	printf("\n\nVetor float M entre A e B = Vetor M \n");
	for(i=0; i<20; i++){
		printf(" %.1f ",M[i]);
	}
}

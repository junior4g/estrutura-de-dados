
/*	Aluno: Orlando Da Cruz Pereira Junior
 * 	Materia : Estrutura de Dados
 * 	Professor: Edmundo Sergio Spoto
 * 	Data: 01/09/2016 Semestre 2016-2
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4
typedef float vetorDiag[N];

int main(){
	vetorDiag mda, mdb, mdc;
	
	LerMatrizDiagonal(mda); //sempre usar vetor nas matrizes especiais
	LerMatrizDiagonal(mdb);
	SomaMatrizDiagonal(mda, mdb, mdc);
	SubtracaoMatrizDiagonal(mda, mdb, mdc);
	ProdutoMatrizDiagonal(mda, mdb, mdc);
	ConsultarElementoMatrizDiagonal(mdc);
	ExibirElementoMatrizDiagonal(mdc);
	
	return 0;
}

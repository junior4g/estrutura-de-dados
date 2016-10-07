#include <stdio.h>
#define MAXP 100

typedef struct {	int cod;
					char Nome[40];
					char Tel[15]; //(xx) 9xxxx-xxxx
					char dataNascimento[10]; // dd/mm/yyyy
}T_Agenda;

typedef struct {	T_Agenda Item[MAXP];
					int topo;
}Pilha_est;

void Criar_Pilha_Vazia(Pilha_est *P){
	P->topo = 0;
}

int main(){ 
	int op;
	T_Agenda X;
	Pilha_est P;
	Criar_Pilha_Vazia(&P);
			
	do{
	
	}while (op != 8);
	
	return 0;	
}

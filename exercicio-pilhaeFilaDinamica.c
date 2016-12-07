/*
	Name: Orlando da Cruz Pereira Junior
	Date: 07/12/16 11:00
	Description: Exercicio de pilha e fila dinamica 
	Registro de chamados para suporte tecnico - Servidor de hospedagem
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct { 
	int codigo;                
	char nome[40];
	char dominioPrimario[20];
	char problemaOcorrido[40];
}T_Pessoa;

typedef struct Cx{ 
	T_Pessoa Item;
    struct Cx *Prox;
}Caixa;
                 
typedef Caixa *Ponteiro;
typedef struct { 
	Ponteiro Inicio;
	Ponteiro Fim;
	int Tam;
}Fila_din_enc;

typedef struct { 
	Ponteiro Topo;
	int Tam;
}Pilha_din_enc;

void Criar_Fila_Vazia(Fila_din_enc *F){ 
   Ponteiro A;
   A = (Caixa *) malloc(sizeof(Caixa));
   A->Prox = NULL;
   F->Inicio = A;
   F->Fim = A;
   F->Tam = 0;
}	
             
void Criar_Pilha_Vazia(Pilha_din_enc *P){ 
   Ponteiro A;
   A = (Ponteiro) malloc(sizeof (Caixa));
   A->Prox=NULL;
   P->Topo= A;
   P->Tam = 0;
}

int Verifica_Fila_Vazia(Fila_din_enc F){ 
	return (F.Inicio == F.Fim);
}

int Verifica_Pilha_Vazia(Pilha_din_enc P){ 
	return(P.Tam == 0);
}

void Enfileirar(Fila_din_enc *F, T_Pessoa X){ 
   Ponteiro A;
   A = (Ponteiro) malloc(sizeof (Caixa));
   A->Item = X;
   A->Prox = F->Fim->Prox;
   F->Fim->Prox = A;
   F->Fim = A;
   F->Tam++; 
}

void Desenfileirar(Fila_din_enc *F, T_Pessoa *X){
  Ponteiro A;
  if(Verifica_Fila_Vazia(*F))
     printf("Fila vazia - Desenfileirar\n");
    else { A = F->Inicio;  
		   F->Inicio = A->Prox;
		   *X = F->Inicio->Item;
		   F->Tam--;
		   free(A); 
    }		
}
 
void Empilhar(Pilha_din_enc *P, T_Pessoa X){ 
   Ponteiro A;
   A = (Ponteiro) malloc(sizeof (Caixa));
   A->Item = X;
   A->Prox = P->Topo->Prox;
   P->Topo->Prox = A;
   P->Tam++; 
}
 
void Desempilhar(Pilha_din_enc *P, T_Pessoa *X){
  Ponteiro A;
  if(Verifica_Pilha_Vazia(*P))
     printf("Pilha vazia - Desempilhar\n");
    else { A= P->Topo->Prox;          
		   *X = A->Item;             
		   P->Topo->Prox = A->Prox; 
		   P->Tam--;                
		   free(A);                
	}		
}
 
void Exibir_Elemento(T_Pessoa X){  
	printf("\nCodigo: %5d \nNome: %s \nDominio: %s \nProblema ocorrido: %s\n",X.codigo, X.nome, X.dominioPrimario, X.problemaOcorrido);
}
 
void Inverter_Fila(Fila_din_enc *F1){
   Pilha_din_enc P;
   T_Pessoa X;
   Criar_Pilha_Vazia(&P);
   while (!Verifica_Fila_Vazia(*F1))
     { Desenfileirar(&(*F1),&X);
	   Empilhar(&P,X);
	  }
	Criar_Fila_Vazia(&(*F1));
	while (!Verifica_Pilha_Vazia(P))
	    { Desempilhar(&P,&X);
	      Enfileirar(&(*F1),X);
	     }
}

void Exibir_Fila(Fila_din_enc *F){   
	    T_Pessoa X;
		Fila_din_enc F1;
		Criar_Fila_Vazia(&F1);
		if(Verifica_Fila_Vazia(*F))
		  printf("Fila vazia - Exibir Fila\n");
		 else { while(F->Inicio != F->Fim)
			      { Desenfileirar(&(*F),&X);
					Enfileirar(&F1,X);
					Exibir_Elemento(X);
		          }
		         Criar_Fila_Vazia(&(*F));
		         while((F1.Inicio)!= (F1.Fim))
			      { Desenfileirar(&F1,&X);
					Enfileirar(&(*F),X);
		          }
         }
}
   
void Inverter_Pilha(Pilha_din_enc *P){   
	    Fila_din_enc F;
		T_Pessoa X;
		Criar_Fila_Vazia(&F);
		if(Verifica_Pilha_Vazia(*P))
		  printf("Pilha vazia - Exibir Pilha\n");
		 else { while(!Verifica_Pilha_Vazia(*P))
			      { Desempilhar(&(*P),&X);
					Enfileirar(&F,X);
		          }
		          Criar_Pilha_Vazia(&(*P));
		          while(!Verifica_Fila_Vazia(F))
		            { Desenfileirar(&F,&X);
					  Empilhar(&(*P),X);
				     }
         }
}

void Exibir_Pilha(Pilha_din_enc *P){
   Pilha_din_enc P1;
   T_Pessoa X;
   Criar_Pilha_Vazia(&P1);
   while (!Verifica_Pilha_Vazia(*P))
     { Desempilhar(&(*P),&X);
	   Exibir_Elemento(X);
	   Empilhar(&P1,X);
	  }
    while(!Verifica_Pilha_Vazia(P1))
        {Desempilhar(&P1,&X);
		 Empilhar(&(*P),X);
		}
}     
       
void Ler(T_Pessoa *X){
	  printf("\nEntre com o Codigo: ");
	  scanf("%d",&(X->codigo));
	  printf("Entre com o nome : ");
	  scanf("%s",X->nome);
	  printf("Entre com o dominio : ");
	  scanf("%s",X->dominioPrimario);
	  printf("Descreva o problema ocorrido : ");
	  scanf("%s",X->problemaOcorrido);
}

void Menu(){
	   printf("\n### MENU - REGISTRO DE CHAMADOS SERVIDOR DE HOSPEDAGEM ###\n");
	   printf("1 - Enfileirar chamado\n");
	   printf("2 - Desenfileirar chamado\n");
	   printf("3 - Exibir Fila\n");
	   printf("4 - Empilhar chamado\n");
	   printf("5 - Desempilhar chamado\n");
	   printf("6 - Exibir Pilha\n");
	   printf("7 - Inverter Fila\n");
	   printf("8 - Inverter Pilha\n");
	   printf("9 - Sair\n");
	   printf("Opcao:  ");
}
   
int main(){
	 T_Pessoa X;
	 Fila_din_enc F;
	 Pilha_din_enc P;
	 int op;
	 Criar_Fila_Vazia(&F);
	 Criar_Pilha_Vazia(&P);
	  do { Menu();
	   scanf("%d",&op);
	   switch (op) {
		  case 1:Ler(&X);
	             Enfileirar(&F,X);
	             break;
		  case 2:Desenfileirar(&F,&X);
		         printf("Chamado de codigo = %d saiu da fila\n",X.codigo);
		         Exibir_Elemento(X);
		         printf("\n");
		         break;
		  case 3: 
		          Exibir_Fila(&F);
		          printf("Fim - Exibir Fila\n");
		         break;
		  case 4: Ler(&X);
		          Empilhar(&P,X);
		         break;
		   case 5:Desempilhar(&P,&X);
		         printf("Chamado de codigo = %d saiu da Pilha\n",X.codigo);
		         Exibir_Elemento(X);
		         printf("\n");
		         break;
		  case 6:Exibir_Pilha(&P);
		         printf("Fim - Exibir Pilha\n");
		         break;
		  case 7: Exibir_Fila(&F);
		          Inverter_Fila(&F);
		          printf("FILA INVERTIDA :  \n ");
		          Exibir_Fila(&F);
		          break;
		  case 8: Exibir_Pilha(&P);
		          Inverter_Pilha(&P);
		          printf("PILHA INVERTIDA :  \n ");
		          Exibir_Pilha(&P);
		          break;
		  case 9: printf("\nFim - software encerrado\n");
		         break;
		  default : printf("Opção não existente\n");
		         break;
		   }
	   	  
  }while(op!=9);
	 return 0;	
}

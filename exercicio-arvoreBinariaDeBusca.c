/*
	Name: Orlando da Cruz Pereira Júnior
	Date: 03/12/16 19:08
	Software para registro de processos - Tribunal de Justiça
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct { char numeroProcesso[40];
                 char oabAdvogado[40];
                 char estado[11];
                 char nomeParte[40];
}T_ProcessoEletronicoJudicial;

typedef struct nd{ T_ProcessoEletronicoJudicial Elem;
                   struct nd *esq, *dir;
}Nodo;
                 
typedef Nodo *Arvore_Binaria;

typedef struct Cx{ Arvore_Binaria Item;
                   struct Cx *Prox;
}Caixa;
                 
typedef Caixa *Ponteiro;

typedef struct { Ponteiro Inicio;
	             Ponteiro Fim;
	             int Tam;
}Fila_nodo;

int Verifica_Arvore_Vazia(Arvore_Binaria T){ 
	return (T == NULL);
} 
   
int Verifica_Fila_Vazia(Fila_nodo F){
	return (F.Inicio == F.Fim);
}

void Criar_Fila_Vazia(Fila_nodo *F){ 
   Ponteiro A;
   A = (Caixa *) malloc(sizeof(Caixa));
   A->Item = NULL;
   A->Prox = NULL;
   F->Inicio = A;
   F->Fim = A;
   F->Tam = 0;
}	

void Enfileirar(Fila_nodo *F, Arvore_Binaria X){ 
   Ponteiro A;
   A = (Ponteiro) malloc(sizeof (Caixa));
   A->Item = X;
   A->Prox = F->Fim->Prox;
   F->Fim->Prox = A;
   F->Fim = A;
   F->Tam++; 
}

void Desenfileirar(Fila_nodo *F, Arvore_Binaria *X){
  Ponteiro A;
  if(Verifica_Fila_Vazia(*F))
     printf("A Fila esta vazia - Desenfileirar\n");
    else { A = F->Inicio;
		   F->Inicio = A->Prox;
		   *X = F->Inicio->Item;
		   F->Tam--;
		   free(A);
	}		
 }
                 
void Insere_Elemento_Arvore(Arvore_Binaria *T, T_ProcessoEletronicoJudicial X){  
    if ((*T)==NULL){ 
	  (*T) = (Arvore_Binaria) malloc(sizeof (Nodo));
	  (*T)->dir = NULL;
	  (*T)->esq = NULL;
	  (*T)->Elem = X;
	}else if ((*T)->Elem.numeroProcesso > X.numeroProcesso)
	           Insere_Elemento_Arvore(&((*T)->esq), X);
	          else if ((*T)->Elem.numeroProcesso < X.numeroProcesso) 
	                   Insere_Elemento_Arvore(&((*T)->dir), X);
	                  else (*T)->Elem = X;
}
				  
void Exibir_Elemento(T_ProcessoEletronicoJudicial X){  
     printf("\nProcesso: %s",X.numeroProcesso);
  	 printf("\nRegistro OAB advogado: %s",X.oabAdvogado);
  	 printf("\nEstado: %s",X.estado);
  	 printf("\nNome parte: %s\n",X.nomeParte); 
}

void pre_ordem(Arvore_Binaria T){
	if(T != NULL){
		Exibir_Elemento(T->Elem);
		pre_ordem(T->esq);
		pre_ordem(T->dir);
	}
}

void in_ordem(Arvore_Binaria T){
	if(T != NULL){
		in_ordem(T->esq);
		Exibir_Elemento(T->Elem);
		in_ordem(T->dir);
	}
}

void pos_ordem(Arvore_Binaria T){
	if(T != NULL){
		pos_ordem(T->esq);
		pos_ordem(T->dir);
		Exibir_Elemento(T->Elem);
		
	}
}

void por_nivel(Arvore_Binaria T, Fila_nodo *F){
   Arvore_Binaria A;
   if(T!=NULL){
      Exibir_Elemento(T->Elem);
	  if(T->esq != NULL)
	      Enfileirar(&(*F),T->esq);
	  if(T->dir != NULL)
	    Enfileirar(&(*F),T->dir);
	  if (!Verifica_Fila_Vazia(*F))
	     { Desenfileirar(&(*F),&A);
	       por_nivel(A,&(*F));
	      }
	}
}

void busca_elem_arvore(Arvore_Binaria T, T_ProcessoEletronicoJudicial X){
	if(T == NULL)
		printf("\nElemento não encontrado.\n");
	else if(X.numeroProcesso < T->Elem.numeroProcesso)
		   busca_elem_arvore(T->esq,X);
	    else if(X.numeroProcesso > T->Elem.numeroProcesso)
		       busca_elem_arvore(T->dir,X);
		     else Exibir_Elemento(T->Elem);
}

T_ProcessoEletronicoJudicial maiorMenores(Arvore_Binaria Q, T_ProcessoEletronicoJudicial *R){
    while (Q->dir != NULL){
        Q = Q->dir;
    }
    *R = Q->Elem;
    return (Q->Elem);
}

void removeElemArvore(Arvore_Binaria *T, T_ProcessoEletronicoJudicial *X){
    Arvore_Binaria A;

    if ((*T) == NULL){
        printf("\nElemento não existe\n");
    } else if (X->numeroProcesso < (*T)->Elem.numeroProcesso){
        removeElemArvore(&((*T)->esq), &(*X));
    } else if (X->numeroProcesso > (*T)->Elem.numeroProcesso) {
        removeElemArvore(&((*T)->dir), &(*X));
    } else if ((*T)->dir == NULL){
        *X = (*T)->Elem;
        A = (*T);
        (*T) = (*T)->esq;
        free(A);
    } else if ((*T)->esq == NULL){
        *X = (*T)->Elem;
        A = (*T);
        (*T) = (*T)->dir;
        free(A);
    } else {
        (*T)->Elem = maiorMenores((*T)->esq, &(*X));
        removeElemArvore(&((*T)->esq), X);
    }
    printf("\nElemento Removido\n");
}

void Ler(T_ProcessoEletronicoJudicial *X){
	  printf("\nProcesso: ");
	  scanf("%s",&(X->numeroProcesso));
	  printf("Registro do advogado junto a OAB: ");
	  scanf("%s",X->oabAdvogado);
	  printf("Estado: ");
	  scanf("%s",X->estado);
	  printf("Nome parte: ");
	  scanf("%s",X->nomeParte);
}

 void Menu(){
	   printf("\nPODER JUDICIARIO - TRIBUNAL DE JUSTICA DO ESTADO DE GOIAS");
	   printf("\n1 - Inserir Novo Processo na Lista");
	   printf("\n2 - Remover Processo da Lista");
	   printf("\n3 - Percorrer Pre-Ordem");
	   printf("\n4 - Percorrer In-Ordem");
	   printf("\n5 - Percorrer Pos-Ordem");
	   printf("\n6 - Percorrer Por-Nivel");
	   printf("\n7 - Consultar um Processo");
	   printf("\n8 - Sair");
	   printf("\nOpcao:  ");	   
}
             
int main(int argc, char **argv){ 
  Arvore_Binaria T;
  Fila_nodo F;
  int op;
  T_ProcessoEletronicoJudicial X;
  T = NULL; 
  Criar_Fila_Vazia(&F);
  do { Menu();
	   scanf("%d",&op);
	   switch (op) {
		  case 1:Ler(&X);
	             Insere_Elemento_Arvore(&T,X);
	             break;
		  case 2:Ler(&X);
		         removeElemArvore(&T,&X);
		         printf("\n Elemento removido : \n");
	             Exibir_Elemento(X);
		         break;
		  case 3:pre_ordem(T);
		         break;
		  case 4: in_ordem(T);
		         break;
		  case 5: pos_ordem(T);
		          break;
		  case 6: por_nivel(T,&F);
		          break;
		  case 7: Ler(&X);
		          busca_elem_arvore(T,X);
		          break;
		  case 8: printf("\nFinalizando o software\n");
		          break;
		  default : printf("Nao existe esta opcao\n");
		         break;
		   }   	  
  }while(op!=8);
  return 0;
}


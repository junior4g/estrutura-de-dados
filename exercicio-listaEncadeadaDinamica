/*
	Name: Orlando da Cruz Pereira Júnior
	Date: 01/12/16 10:30
	Description: Lista encadeada dinamica
	Registro de trocas e devoluções efetuadas em loja virtual
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct { int numeroPedido;
                 char nomeProduto[40];
                 char dataCompra[11];
                 char email[40];
                 char telefone[11];
                 }T_TrocaDevolucao;

typedef struct Cx{ T_TrocaDevolucao Item;
                   struct Cx *Prox;
                 }Caixa;
                 
typedef Caixa *Ponteiro;
typedef struct { Ponteiro Prim, Ult;
	             int Tam;
	            }Lista_din_enc;

void Criar_Lista_Vazia(Lista_din_enc *L){ 
   Ponteiro P;
   P = (Ponteiro) malloc(sizeof (Caixa));
   L->Prim = P;
   L->Ult = L->Prim;
   L->Tam = 0;
}

int Verifica_Lista_Vazia(Lista_din_enc L){  
	return(L.Prim == L.Ult);
}

void Insere_Elemento_Lista(Lista_din_enc *L, T_TrocaDevolucao X){ 
     Ponteiro P, A;
	 P = (Ponteiro) malloc(sizeof (Caixa));
	 P->Item = X;
	 A = L->Prim;
	 while((A!=L->Ult)&&(X.numeroPedido>A->Prox->Item.numeroPedido))
	    A = A->Prox;
	  P->Prox = A->Prox;
	  A->Prox = P;
	  if(A==L->Ult)
		 L->Ult = P;
	  L->Tam++;
}
	 
void Exibir_Elemento(T_TrocaDevolucao X){  
	printf("Codigo: %5d \nNome: %s \nData de compra: %s \nE-mail: %s \nTelefone: %s \n",X.numeroPedido, X.nomeProduto, X.dataCompra, X.email, X.telefone);
}
	 
void Remove_Elemento_Lista(Lista_din_enc *L, T_TrocaDevolucao *X){ 
	Ponteiro P, A;
    if(Verifica_Lista_Vazia (*L))
      printf("A Lista esta vazia - remove\n");
     else { P = L->Prim;
            while((P!=L->Ult)&&(X->numeroPedido > P->Prox->Item.numeroPedido))
                P=P->Prox;
            if ((P==L->Ult)||(X->numeroPedido!=P->Prox->Item.numeroPedido))
              printf("Nao existe na lista - Remove\n");
             else { *X = P->Prox->Item;
				 	printf("\n Elemento removido : \n");
				    Exibir_Elemento(*X);
                    A = P->Prox;
                    if (A==L->Ult)
                      L->Ult = P;
					P->Prox=A->Prox;
					free(A);
					L->Tam--;
                 }
          }
}
   
void Exibir_Lista(Lista_din_enc L){ 
 	Ponteiro P;
	
	if(Verifica_Lista_Vazia(L))
	   printf("Lista Vazia - nada para exibir \n\n");
	  else { P = L.Prim;
		     while(P!=L.Ult)
		       { Exibir_Elemento(P->Prox->Item);
				 P=P->Prox;
			    }
			 }
}
 
void Consulta_Elemento(Lista_din_enc L, int numeroPedido){ 
	Ponteiro P;
    if(Verifica_Lista_Vazia (L))
      printf("Lista vazia - consulta\n");
     else { P = L.Prim->Prox;
            while((P!=NULL)&&(numeroPedido > P->Item.numeroPedido))
                P=P->Prox;
            if ((P==NULL)||(numeroPedido!=P->Item.numeroPedido))
              printf("Nao encontrado para consulta\n");
             else  Exibir_Elemento(P->Item);   
     }
}
  
void Ler(T_TrocaDevolucao *X){
	  printf("\nEntre com o codigo do pedido: ");
	  scanf("%d",&(X->numeroPedido));
	  printf("\nEntre com o nome do produto : ");
	  scanf("%s",&X->nomeProduto);
	  printf("\nEntre com a data de compra : ");
	  scanf("%s",&X->dataCompra);
	  printf("\nEntre com o e-mail : ");
	  scanf("%s",&X->email);
	  printf("\nEntre com telefone: ");
	  scanf("%s",&X->telefone);
}


void Menu(){
	   printf("### M E N U - LISTA ENCADEADA DINAMICA - TROCAS ECOMMERCE\n");
	   printf("1 - Inserir troca devolucao \n");
	   printf("2 - Remover troca devolucao \n");
	   printf("3 - Consultar\n");
	   printf("4 - Exibir\n");
	   printf("5 - Sair\n");
	   printf("Opcao:  ");
}
   
int main(){
	 T_TrocaDevolucao X;
	 Lista_din_enc L;
	 Ponteiro P;
	 int op,numeroPedido;
	 FILE *arq;
	 Criar_Lista_Vazia(&L);
	  do { Menu();
	   scanf("%d",&op);
	   switch (op) {
		  case 1:Ler(&X);
	             Insere_Elemento_Lista(&L,X);
	             break;
		  case 2:printf("Digite o codigo a consultar: \n");
		         scanf("%d",&X.numeroPedido);
		         Remove_Elemento_Lista(&L,&X);
		         break;
		  case 3:printf("Digite o codigo a consultar: \n");
		         scanf("%d",&numeroPedido);
		         Consulta_Elemento(L,numeroPedido);
		         break;
		  case 4: Exibir_Lista(L);
		         break;

		  case 5: printf("\nObrigado por usar nosso Software\n");
		         break;
		  default : printf("Opção não existente\n");
		         break;
		}
	   	  
  }while(op!=7);
	 return 0;	
}

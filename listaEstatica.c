#include <stdio.h>
#define MAX 100

typedef struct { int cod;
                 char Nome[40];
                 char Tel[15]; //(xx) 9xxxx-xxxx
                 char data_nasc[10]; // dd/mm/yyyy
                 }T_Agenda;
                 
typedef struct { T_Agenda Item[MAX];
                 int Prim, Ult;
                }Lista_est;

void Criar_Lista_Vazia (Lista_est *L)
 { L->Prim = 0;
   L->Ult = 0;
 }
 
 int Verifica_Lista_Vazia(Lista_est L)
   { 
	   return (L.Prim==L.Ult);
   }

int Verifica_Lista_Cheia(Lista_est L)
   { 
	   return (L.Ult==MAX);
   }

void Insere_Elemento_Lista(Lista_est *L, T_Agenda X)
{ int p;
  
  if (Verifica_Lista_Cheia(*L))
       printf("A Lista está Cheia \n");
   else {p = L->Prim;
	     while ((p < L->Ult) && (X.cod > L->Item[p].cod))
	        p++;
	     if (p==L->Ult)
	       { L->Item[p] = X;
			 L->Ult++;
			} else if (X.cod != L-> Item[p].cod)
			       { int i;
					for(i = L->Ult; i>p; i--)
					  L->Item[i] = L->Item[i-1];
					L->Item[p] = X;
					L->Ult++;
	              }
	              else printf(" ELEMENTO JÁ EXISTE NA LISTA \n");
	     }
}

void Remove_Elemento_Lista (Lista_est *L, T_Agenda *X)
  { int p, i;
	if(Verifica_Lista_Vazia(*L))
	  printf("A Lista está vazia - Remocao negada \n");
	 else { p = L->Prim;
		    while ((p < L->Ult) && (X->cod > L->Item[p].cod))
		      p++;
		    if ((p==L->Ult) || (X->cod != L->Item[p].cod))
		       printf("Elemento nao foi encontrado na Lista - Remove \n");
		      else { 
				     *X = L->Item[p];
				     for (i=p; i<L->Ult; i++)
				       L->Item[i]=L->Item[i+1];
				     L->Ult--;
				    }
	     }
 }


void Exibir_Elemento (T_Agenda X)
 { printf("\nELEMENTO DE COD = %4d \n",X.cod);
   printf(" ===================== \n");
   printf(" NOME: %s \n",X.Nome);
   printf(" TELEFONE: %s \n",X.Tel);
   printf(" DATA DE NASCIMENTO: %s \n",X.data_nasc);
   printf(" ================= \n");
}

void Consulta_Elemento(Lista_est L, int cod)
  { int p;
	if (Verifica_Lista_Vazia(L))
	  printf("\n Lista está vazia - consulta elemento\n");
	 else { p = L.Prim;
		    while ((p < L.Ult) && (cod > L.Item[p].cod))
	           p++;
            if ((p==L.Ult) || (cod != L.Item[p].cod))
               printf("Elemento nao Encontrado na lista \n ");
              else 
                Exibir_Elemento(L.Item[p]);
           }
    }
void Exibir_Lista(Lista_est L)
  { int p;
	if (Verifica_Lista_Vazia(L))
	   printf("\n LISTA VAZIA - SEM EXIBIR \n");
	  else { p = L.Prim;
		     while (p < L.Ult)
		       {Exibir_Elemento(L.Item[p]);
		        p++;
			    }
	        printf("\n FIM DA LISTA ******* FIM DA LISTA \n");
	       }
  }
  
  void Ler_Elemento (T_Agenda *X)
    { printf("\n Entre com o Codigo : ");
	  scanf("%d",&X->cod);
	  printf("\n Entre com o Nome : ");
	  scanf("%s",X->Nome);
	  printf("\n Entre com o Telefone : ");
	  scanf("%s",X->Tel);
	  printf("\n Entre com o Data de Nascimento : ");
	  scanf("%s",X->data_nasc);
	 }

void MENU()
   { printf("\n M E N U   F U N C I O N A L\n ");
	 printf(" = = = = = = = = = = = = = =\n"); 
	 printf("1 - Insere Elemento na Lista \n");
	 printf("2 - Remove Elemento da Lista \n");
	 printf("3 - Consultar Elemento na Lista \n");
	 printf("4 - Exibir a Lista \n");
	 printf("5 - Encontrar o Antescessor de um Elemento \n");
	 printf("7 - Sair do Programa \n");
	 printf(" = = = = = = = = = = = = = =\n "); 
	 printf("Opcao: ");  
   }

int main()
  { int op;
	T_Agenda X;
	Lista_est L;
	Criar_Lista_Vazia(&L);
	do {
		MENU();
		scanf("%d",&op);
		getchar();
		switch (op) {
		  case 1:printf("\n Entre com o Elemento a ser Inserido \n");
		         Ler_Elemento(&X);
		         Insere_Elemento_Lista(&L, X);
		         break;
		  case 2:printf("\n Entre com o codigo do Elemento a ser Removido \n");
		         scanf("%d",&X.cod);
		         Remove_Elemento_Lista(&L, &X);
		         printf("\n Elemento a ser Removido \n");
		         Exibir_Elemento(X);
		         break;
		  case 3 : printf("\n Entre com o codigo do Elemento a ser Consultado \n");
		         scanf("%d",&X.cod);
	 	         Consulta_Elemento(L, X.cod);
		         break;
		   case 4 : Exibir_Lista(L);
		         break;
		   case 5 : printf("\n Entre com o codigo do Elemento a ser Consultado o antecessor \n");
		         scanf("%d",&X.cod);
		  //       Consulta_Antecessor(L, X.cod);
		         break;
		   case 7 : printf(" FIM...OBRIGADO POR USAR NOSSO SOFTWARE \n");
		         break;
		    default : printf("\n Opcao nao existe escolha outra correta \n");
		         break;
		}
	}while (op !=7);  
	return 0;
}

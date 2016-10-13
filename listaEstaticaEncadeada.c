/*
    Aula do dia 12/10/2016
    Lista Estatica Encadeada
*/

#include <stdio.h>
#define MAXL 100

typedef struct { int cod;
                 char Nome[40];
                 char Tel[15]; //(xx) 9xxxx-xxxx
                 char data_nasc[10]; // dd/mm/yyyy
                 int Prox;
                 }T_Agenda;

typedef struct { T_Agenda Item[MAXL];
                 int Prim, Ult, Dispo,Tam;
                }Lista_est_enc;

void Criar_Lista_Vazia (Lista_est_enc *L)
 { int i;
   L->Prim = -1;
   L->Ult = -1;
   L->Dispo = 0; L->Tam=0;
   for (i=0;i< MAXL-1; i++)
      L->Item[i].Prox = i+1;
   L->Item[i].Prox = -1;
 }

 int Verifica_Lista_Vazia(Lista_est_enc L)
   {
	   return (L.Prim==-1);
   }

int Verifica_Lista_Cheia(Lista_est_enc L)
   {
	   return (L.Dispo==-1);
   }

void Insere_Elemento_Lista(Lista_est_enc *L, T_Agenda X)
{ int P, A, J;
  if(L->Dispo==-1)
    printf("A Lista esta cheia - Insere\n");
   else {  J = L->Dispo;
	       L->Dispo = L->Item[J].Prox;
	       L->Item[J]=X;
	      P= L->Prim;
	      while((P!=L->Ult)&&(X.cod > L->Item[P].cod))
              { A = P;
                P=L->Item[P].Prox;
               }
          if(L->Prim==-1)   // a lista esta vazia
            {L->Item[J].Prox = L->Prim;
			 L->Prim = J;
		     L->Ult = J;
		    }else if(L->Ult==L->Prim) //so tem um elemento na lista
		             { if(X.cod < L->Item[P].cod)
						  { L->Item[J].Prox=L->Prim;
						    L->Prim = J;
					      }else {L->Item[J].Prox = L->Item[P].Prox;
							     L->Item[P].Prox=J;
							     L->Ult=J;
							    }
					   }else if(P==L->Ult)
					             {if(X.cod > L->Item[P].cod)
						             { L->Item[J].Prox=L->Item[P].Prox;
									   L->Item[P].Prox=J;
						               L->Ult = J;
					                }else {L->Item[J].Prox = L->Item[A].Prox;
							               L->Item[A].Prox=J;
							              }
							  }else if(P==L->Prim)
							           if(X.cod < L->Item[P].cod)
						                   { L->Item[J].Prox=P;
						                     L->Prim = J;
						                   }
					                      else {L->Item[J].Prox = L->Item[P].Prox;
							                    L->Item[P].Prox=J;
							                   }
							          else {L->Item[J].Prox = L->Item[A].Prox;
							                    L->Item[A].Prox=J;
							                }
	         L->Tam++;
			}
}

void Remove_Elemento_Lista(Lista_est_enc *L, T_Agenda *X){
    int P, A;
    if(L->Prim == -1)
      printf("A Lista esta vazia - remove\n");
     else { P = L->Prim; //P e A são ponteiros
            while((P!=L->Ult)&&(X->cod > L->Item[P].cod))
              { A = P;
                P=L->Item[P].Prox;
               }
            if (X->cod!=L->Item[P].cod)
              printf("Elemento NAO EXISTE na lista - Remove\n");
             else { *X = L->Item[P];
                    if((P==L->Prim)&&(P==L->Ult)) //Se verdade = nao tem o anterior e so tem 1 na lista
                       { L->Prim = -1; L->Ult =  -1;

                        } else if (P==L->Prim)
                                   {L->Prim=L->Item[P].Prox;
                                    } else {if (P==L->Ult)
                                               L->Ult = A;
                                            L->Item[A].Prox=L->Item[P].Prox;
                                            }
                        L->Item[P].Prox = L->Dispo;
                        L->Dispo = P;
                        L->Tam--;
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

void Consulta_Elemento(Lista_est_enc L, int cod)
  { int p;
	if (Verifica_Lista_Vazia(L))
	  printf("\n Lista está vazia - consulta elemento\n");
	 else { p = L.Prim;
		    while ((p != -1) && (cod > L.Item[p].cod))
	           p=L.Item[p].Prox;
            if ((p==-1) || (cod != L.Item[p].cod))
               printf("Elemento nao Encontrado na lista \n ");
              else
                Exibir_Elemento(L.Item[p]);
           }
    }

void Exibir_Lista(Lista_est_enc L)
  { int p;
	if (Verifica_Lista_Vazia(L))
	   printf("\n LISTA VAZIA - SEM EXIBIR \n");
	  else { p = L.Prim;
		     while (p != -1)
		       {Exibir_Elemento(L.Item[p]);
		        p=L.Item[p].Prox;
			    }
	        printf("\n FIM DA LISTA ******* FIM DA LISTA \n");
	       }
  }
 void Consulta_Antecessor(Lista_est_enc L, int cod)
  { int p,a;
	if (Verifica_Lista_Vazia(L))
	  printf("\n Lista está vazia - consulta elemento\n");
	 else { p = L.Prim;
		    while ((p != -1) && (cod > L.Item[p].cod))
	           { a=p;
				 p=L.Item[p].Prox;
				}
            if ((p==-1) || (cod != L.Item[p].cod))
               printf("Elemento nao Encontrado na lista \n ");
              else if (p==L.Prim)
                        printf("Elemento não tem antecessor \n");
                       else Exibir_Elemento(L.Item[a]);
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
	Lista_est_enc L;
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
		         Consulta_Antecessor(L, X.cod);
		         break;
		   case 7 : printf(" FIM...OBRIGADO POR USAR NOSSO SOFTWARE \n");
		         break;
		    default : printf("\n Opcao nao existe escolha outra correta \n");
		         break;
		}
	}while (op !=7);
	return 0;
}

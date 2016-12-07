/*
	Name: Orlando da Cruz Pereira Júnior
	Date: 27/11/16 09:27
	Description: Lista encadeada estatica
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXL 100
                 
typedef struct { int numeroPedido;
                 char nome[40];
                 char enderecoEntrega[150];
                 char email[40];
                 char cpf[11];
                 int prox;
                 }T_PedidoLojaVirtual;

typedef struct { T_PedidoLojaVirtual Elem[MAXL];
                 int Prim, Ult;
                 int Tam;
                 int Dispo;
                 }Lista_est_enc;

void Criar_Lista_Vazia(Lista_est_enc *L){ 
   int P;
   L->Prim = -1;
   L->Ult = -1;
   for(P=0;P<MAXL-1;P++)
     L->Elem[P].prox = P+1;
   L->Elem[P].prox = -1;
   L->Dispo = 0;
   L->Tam = 0;
}

void Insere_Elemento_Lista(Lista_est_enc *L, T_PedidoLojaVirtual X){ 
  int P, A, J;
  if(L->Dispo==-1)
    printf("Lista cheia - Insere\n");
   else {  J = L->Dispo;
	       L->Dispo = L->Elem[J].prox;
	       L->Elem[J]=X;
	      P= L->Prim;
	      while((P!=L->Ult)&&(X.numeroPedido > L->Elem[P].numeroPedido))
              { A = P;
                P=L->Elem[P].prox;
               }
          if(L->Prim==-1)
            {L->Elem[J].prox = L->Prim;
			 L->Prim = J; 
		     L->Ult = J;
		    }else if(L->Ult==L->Prim)
		             { if(X.numeroPedido < L->Elem[P].numeroPedido)
						  { L->Elem[J].prox=L->Prim;
						    L->Prim = J;
					      }else {L->Elem[J].prox = L->Elem[P].prox;
							     L->Elem[P].prox=J;
							     L->Ult=J;
							    }
					   }else if(P==L->Ult)
					             {if(X.numeroPedido > L->Elem[P].numeroPedido)
						             { L->Elem[J].prox=L->Elem[P].prox;
									   L->Elem[P].prox=J;
						               L->Ult = J;
					                }else {L->Elem[J].prox = L->Elem[A].prox;
							               L->Elem[A].prox=J; 
							              }
							  }else if(P==L->Prim)
							           if(X.numeroPedido < L->Elem[P].numeroPedido)
						                   { L->Elem[J].prox=P;
						                     L->Prim = J;
						                   }
					                      else {L->Elem[J].prox = L->Elem[P].prox;
							                    L->Elem[P].prox=J; 
							                   }
							          else {L->Elem[J].prox = L->Elem[A].prox;
							                    L->Elem[A].prox=J; 
							                }
	         L->Tam++;
			}
}

void Remove_Elemento_Lista(Lista_est_enc *L, T_PedidoLojaVirtual *X){ 
    int P, A;
    if(L->Prim == -1)
      printf("A Lista esta vazia - remove\n");
     else { P = L->Prim;
            while((P!=L->Ult)&&(X->numeroPedido > L->Elem[P].numeroPedido))
              { A = P;
                P=L->Elem[P].prox;
               }
            if (X->numeroPedido!=L->Elem[P].numeroPedido)
              printf("Elemento NAO EXISTE na lista - Remove\n");
             else { *X = L->Elem[P];  
                    if((P==L->Prim)&&(P==L->Ult))
                       { L->Prim = -1; L->Ult =  -1;
                         
                        } else if (P==L->Prim)
                                   {L->Prim=L->Elem[P].prox;
                                    } else {if (P==L->Ult)
                                               L->Ult = A;
                                            L->Elem[A].prox=L->Elem[P].prox;
                                            }
                        L->Elem[P].prox = L->Dispo;
                        L->Dispo = P;                    
                        L->Tam--;
                       }
     } 
}
void Exibir_Elemento(T_PedidoLojaVirtual X){
    printf("\nNumero do pedido = %d ",X.numeroPedido);
    printf("\nNome do cliente = %s ",X.nome);
    printf("\nEndereco de entrega = %s ",X.enderecoEntrega );
    printf("\nE-mail = %s \n",X.email);
    printf("\nCPF = %s \n",X.cpf);
}
   
void Exibir_Lista(Lista_est_enc L){ 
    int P;
	if (L.Prim ==-1)
	   printf("Lista Vazia - Exibir \n");
	  else
	    { P = L.Prim;
		  while(P != L.Ult)
		    { Exibir_Elemento(L.Elem[P]);
		      P=L.Elem[P].prox;
		    }
		    Exibir_Elemento(L.Elem[P]);
        }
}

void Consulta_Elemento(Lista_est_enc L, int numeroPedido){ 
	  int P;
	  if (L.Prim ==-1)
	     printf("Lista Vazia - Exibir \n");
	    else
	      { P = L.Prim;
	  	    while((P !=L.Ult)&&(numeroPedido>L.Elem[P].numeroPedido))
		          P=L.Elem[P].prox;
		    if ((numeroPedido != L.Elem[P].numeroPedido))
		       printf("Nao encontrado - Consultar\n\n");  
		      else  Exibir_Elemento(L.Elem[P]);
	     }
}

int numeroPedido;
char nome[40];
char enderecoEntrega[150];
char email[40];
char cpf[11];

void Ler(T_PedidoLojaVirtual *X){
	  printf("\nDigite o numero do pedido: ");
	  scanf("%d",&(X->numeroPedido));
	  printf("Nome do cliente: ");
	  scanf("%s",(X->nome));
	  printf("Endereco: ");
	  scanf("%s",(X->enderecoEntrega));
	  printf("E-mail: ");
	  scanf("%s",(X->email));
	  printf("CPF: ");
	  scanf("%s",(X->cpf));
}

void Menu(){
	   printf("### MENU LISTA ENCADEADA ESTATICA - REGISTRO DE VENDAS ECOMMERCE ###\n");
	   printf("1 - Inserir nova venda\n");
	   printf("2 - Remover venda - troca ou devolucao\n");
	   printf("3 - ConsultaR\n");
	   printf("4 - Exibir Lista de pedidos\n");
	   printf("5 - Sair\n");
	   printf("Opcao:  ");
}

int main(){ 
  int op,numeroPedido;
  Lista_est_enc LE;
  T_PedidoLojaVirtual X;
  Criar_Lista_Vazia(&LE);
  do { Menu();
	   scanf("%d",&op);
	   switch (op) { 
		   case 1:Ler(&X); 
		          Insere_Elemento_Lista(&LE, X);
		          break;
		   case 2: printf("Codigo que deseja remover \n"); 
		           scanf("%d",&X.numeroPedido);
		           Remove_Elemento_Lista(&LE, &X);
		           break;
		   case 3: printf("Codigo que deseja consultar \n"); 
		           scanf("%d",&numeroPedido); 
	               Consulta_Elemento(LE,numeroPedido);
	               break;
	       case 4: Exibir_Lista(LE);
	               break;
	       case 5: printf("Fim - Programa encerrado \n\n");
	               break;
	       default : printf("Nao existe \n");
	               break;
	       }
	
  }while(op!=5);
  return(0);
}

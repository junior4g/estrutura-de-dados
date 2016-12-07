/*
	Name: Orlando da Cruz Pereira Júnior	
	Date: 27/11/16 09:13
	Description: Trabalho de Pilha e Fila - Estática
*/


#include <stdio.h>
#define MAXF 100
#define MAXP 100
                 
typedef struct { char placa[7];
                 char nomeProprietario[40];
                 char marca[15];
                 char modelo[10];
                 }T_Lava_Jato;
                 
typedef struct { T_Lava_Jato Item[MAXF];
                 int Inicio, Fim, Total;
                }Fila_estatica;

typedef struct { T_Lava_Jato Item[MAXP];
                 int Topo;
                }Pilha_estatica;

void Criar_Fila_Vazia(Fila_estatica *F)
  { F-> Inicio = 0;
    F-> Fim = 0;
    F-> Total = 0;
  }

void Criar_Pilha_Vazia(Pilha_estatica *P)
  { P-> Topo = 0;
  }
int Verifica_Fila_Vazia(Fila_estatica F)
  {
    return(F.Inicio == F.Fim);
  }
  
int Verifica_Pilha_Vazia(Pilha_estatica P)
  {
    return(P.Topo == 0);
  }
  
 int Verifica_Fila_Cheia(Fila_estatica F)
  {
    return((F.Fim+1)%MAXF == F.Fim);
  }
  
int Verifica_Pilha_Cheia(Pilha_estatica P)
  {
    return(P.Topo == MAXP);
  }

void Enfileirar (Fila_estatica *F, T_Lava_Jato X){  
	 if(Verifica_Fila_Cheia(*F))
      printf("Fila cheia - Enfileirar\n");
     else { F->Item[F->Fim] = X;
            F->Fim = (F->Fim + 1)% MAXF;
            F->Total++;
           }
}

void Empilhar (Pilha_estatica *P, T_Lava_Jato X){  
	  if(Verifica_Pilha_Cheia(*P))
      printf("Pilha cheia - Empilhar\n");
      else { P->Item[P->Topo] = X;
            P->Topo++;
           }
}

void Desenfileirar(Fila_estatica *F, T_Lava_Jato *X){ 
	 if(Verifica_Fila_Vazia(*F))
	  printf("Fila Vazia - Desenfileirar\n ");
	 else { *X = F->Item[F->Inicio];
		    F->Inicio = (F->Inicio + 1)%MAXF;
		    F->Total--;
		   }
}

void Desempilhar(Pilha_estatica *P, T_Lava_Jato *X){ 
	 if(Verifica_Pilha_Vazia(*P))
	  printf("Pilha Vazia - Desempilhar\n ");
	 else { P->Topo --;
		    *X = P->Item[P->Topo];
		   }
}

void Exibir_Elemento (T_Lava_Jato X){ 
   printf(" ================= \n");
   printf("\n PLACA DO AUTOMOVEL = %s\n",X.placa);
   printf(" NOME DO PROPRIETARIO: %s \n",X.nomeProprietario);
   printf(" MARCA: %s \n",X.marca); 
   printf(" MODELO: %s \n",X.modelo);
   printf(" ================= \n");
}

void Ler_Elemento (T_Lava_Jato *X){ 
	  printf("\n Entre com a placa: ");
	  scanf("%s",&X->placa);
	  printf("\n Entre com o nome do proprietario: ");
	  scanf("%s",&X->nomeProprietario);
	  printf("\n Entre com a marca do carro: ");
	  scanf("%s",&X->marca);
	  printf("\n Entre com o modelo do carro: ");
	  scanf("%s",&X->modelo);
}

void MENU(){ 
	 printf("\n ########### MENU PILHA E FILA ############\n");
	 printf("1 - Enfileirar Elemento \n");
	 printf("2 - Empilhar Elemento\n");
	 printf("3 - Desenfileirar  \n");
	 printf("4 - Desempilhar \n");
	 printf("5 - Inverter Fila \n");
	 printf("6 - Inverter Pilha \n");
	 printf("7 - Consultar elemento no Inicio da Fila \n");
	 printf("8 - Consultar Elemento no Topo da Pilha \n");
	 printf("9 - Sair \n");
	 printf("###########################################\n "); 
	 printf("Opcao: ");  
}

void Inverter_Pilha (Pilha_estatica *P){
	Pilha_estatica Aux; 
	T_Lava_Jato X;
	Criar_Pilha_Vazia(&Aux); 
	while( !Verifica_Pilha_Vazia(*P)){
		Desempilhar(&(*P),&X); 
		Empilhar(&Aux,X);
	}
	*P = Aux;
}

void Inverter_Fila (Fila_estatica *F)
{
  Pilha_estatica Aux; 
  T_Lava_Jato X;
  Criar_Pilha_Vazia(&Aux); // para usar para inverter a outra pilha
  while( !Verifica_Fila_Vazia(*F)) {
      Desenfileirar(&(*F),&X); // tira da fila e tras pro x
      Exibir_Elemento(X);
      Empilhar(&Aux,X);
      }
 while(!Verifica_Pilha_Vazia(Aux))
    {
      Desempilhar(&Aux,&X);
      Exibir_Elemento(X);
      Enfileirar(&(*F),X);
     }
}

int main(){ 
	int op;
	T_Lava_Jato X;
	Fila_estatica F;
	Pilha_estatica P;
	Criar_Fila_Vazia(&F);
	Criar_Pilha_Vazia(&P);
	do {
		MENU();
		scanf("%d",&op);
		getchar();
		switch (op) {
		  case 1:printf("\n Entre com o Elemento que vai ser Enfileirado \n");
		         Ler_Elemento(&X);
		         Enfileirar(&F, X);
		         break;
		  case 2:printf("\n Entre com o Elemento que vai ser Empilhado \n");
		         Ler_Elemento(&X);
		         Empilhar(&P, X);
		         break;
		   case 3: Desenfileirar(&F, &X);
		         printf("\n Elemento que vai ser Desenfileirado:\n");
		         Exibir_Elemento(X);
		         break;
		  case 4: Desempilhar(&P, &X);
		         printf("\n Elemento que vai ser Desempilhado: \n");
		         Exibir_Elemento(X);
		         break;
		  case 5 : Inverter_Fila(&F);
		         break;
		   case 6 : Inverter_Pilha(&P);
		         break;
		   case 7 :printf("O Elemento que esta no Inicio da Fila: \n "); 
		         if(Verifica_Fila_Vazia(F))
		            	printf("A Fila Está Vazia - Consulta\n");
		              else  Exibir_Elemento(F.Item[F.Inicio]);
		         break; 
		   case 8 :printf("O Elemento que esta no Topo da Pilha: \n "); 
		           if(Verifica_Pilha_Vazia(P))
		               printf("Pilha Vazia - Consulta\n");
		              else  Exibir_Elemento(P.Item[P.Topo-1]);
		         break; 
		   case 9: printf(" Fim - Programaq encerrado \n");
		         break;
		    default : printf("\n Opcao nao existe\n");
		         break;
		}
	}while (op !=9);  
	return 0;
}

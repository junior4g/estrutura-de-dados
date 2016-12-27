/*
 * 
 * Aluno: Orlando da Cruz Pereira Junior
 * Sistemas de Informaçao
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#define MAX 100

typedef struct { 
				int  CodigoDeBarras;
                char Nome[30];
                char Marca[11]; 
                char Distribuidor[50];
                char TelefoneDistribuidor[14]; 
} T_Produto;

typedef struct { 
				T_Produto Elem[MAX];
                int Prim, Ult;
} Lista_Estatica;
                  
void Criar_Lista_Vazia(Lista_Estatica *L){ 
				L -> Prim = 0;
    			L -> Ult = L -> Prim;	   

}

int verifica_lista_vazia (Lista_Estatica L){ 
	   			return(L.Prim == L.Ult);
}

int verifica_lista_cheia (Lista_Estatica L){ 
	   			return(L.Ult == MAX);
}

void Insere_Elemento_Lista(Lista_Estatica *L, T_Produto X){ 
	 int A, P = L -> Prim;
     if (verifica_lista_cheia(*L))
        printf("\n a lista esta cheia\n ");
       else {
		       while ((P < L -> Ult) && (X.CodigoDeBarras > L -> Elem[P].CodigoDeBarras))
                   P++;
               if(P == L-> Ult)
                 { L -> Elem[P] = X;
                   L -> Ult ++;
                  }
                else {
						for(A=L -> Ult; A > P; A--)
					         L -> Elem[A] = L -> Elem[A-1];
				        L -> Elem[P] = X;
				        L -> Ult ++;
                      }      
       }       
}   
   
void Remove_Elemento_Lista(Lista_Estatica *L, T_Produto *X){ 
	printf("Removendo elementos...\n" );
    int A, P = L -> Prim;
    if (verifica_lista_vazia(*L))
      printf("\n A lista esta vazia\n " );
    else{ 
		  while ((P < L -> Ult) && (X->CodigoDeBarras > L->Elem[P].CodigoDeBarras))
                   P = P +1;
          if ((P == L->Ult) || (L->Elem[P].CodigoDeBarras != X -> CodigoDeBarras))
              printf("\n Elemento nao encontrado\n " );
            else { 
				    *X = L -> Elem[P];
				    for (A = P; A < L -> Ult; A++)
				       L -> Elem[A] = L -> Elem[A+1];
				    L -> Ult --;  
				    printf("Elemento de codigo: %d foi removido", X->CodigoDeBarras);   
			   }
    }
}

void Exibir_Elemento(T_Produto X){ 
	printf("\n\n###########################################################\n\n");
	printf("Codigo de barras: %d\n", X.CodigoDeBarras);
    printf("Nome: %s\n",X.Nome);
    printf("Marca: %s\n",X.Marca);
    printf("Distribuidor: %s\n",X.Distribuidor);
    printf("Telefone: %s\n",X.TelefoneDistribuidor);
    printf("\n###########################################################\n ");
}

void Ler_Produto(T_Produto *X){  
	 printf("#################### CADASTRO DE PRODUTOS ################\n\n");
     printf("Codigo de barras: ");
     scanf("%d",&(X->CodigoDeBarras));
     getchar();
     printf("Nome: ");
     scanf("%s", X -> Nome);
     printf("Marca: ");
     scanf("%s", X -> Marca);
     printf("Distribuidor: ");
     scanf("%s", X -> Distribuidor);
     printf("Telefone: ");
     scanf("%s", X -> TelefoneDistribuidor);
}

int main(){ 
	 Lista_Estatica L;
     T_Produto X;
     Criar_Lista_Vazia(&L);
     Ler_Produto(&X);
     Insere_Elemento_Lista(&L,X);
     printf("#########################################################\n\n");
     Remove_Elemento_Lista(&L, &X);
     Exibir_Elemento(X);
     system("pause");
     return (0);
}


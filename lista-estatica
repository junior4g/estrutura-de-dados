/*
 * 
 * Aluno: Orlando da Cruz Pereira Júnior
 * Matricula: 131679
 * Sistemas de Informação
 * 
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct{	int codigo;
				char nome[30];
				char endereco[30];
				char telefone[14];
				char email[30];
			  } tipo_pessoa;

void Criar_Lista_Vazia(Lista_Est *L)
   { L -> Prim = 0;
     L -> Ult = L -> Prim;	   
   }
int verifica_lista_vazia (Lista_Est L)
   { 
	   return(L.Prim == L.Ult); 
   }

int verifica_lista_cheia (Lista_Est L)
   { 
	   return(L.Ult == MAX); 
   }
   


// Procedimento que Insere um Amigo na Lista de Agenda   
void Insere_Elemento_Lista(Lista_Est *L, Tipo_Amigo X)    
   { int A, P = L -> Prim;
     if (verifica_lista_cheia(*L))
        printf("\n A LISTA ESTÁ CHEIA, AUMENTE A CAPACIDADE \n ");
       else {
		       while ((P < L -> Ult) && (X.codigo > L -> Elem[P].codigo))
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
   
void Remove_Elemento_Lista(Lista_Est *L, tipo_pessoa *X)
  { int A, P = L -> Prim;
    if (verifica_lista_vazia(*L))
      printf("\n LISTA ESTÁ VAZIA \n " );
    else
      { 
		  while ((P < L -> Ult) && (X->codigo > L->Elem[P].codigo))
                   P = P +1;
          if ((P == L->Ult) || (L->Elem[P].codigo != X -> codigo))
              printf("\n  Elemento não Encontrado na Lista \n " );
            else { 
				    *X = L -> Elem[P];
				    for (A = P; A < L -> Ult; A++)
				       L -> Elem[A] = L -> Elem[A+1];
				    L -> Ult --;  
				    printf("\n ELEMENTO REMOVIDO COM SUCESSO * Codigo:  %d", X->codigo);   
			   }
      }
   }
			  
void ler_tipo_pessoa( tipo_pessoa *x){
	printf("Digite o codigo:");
	scanf("%d",&(x->codigo));
	getchar();
	printf("Digite o nome:");
	gets(x -> nome);
	printf("Digite o endereco:");
	gets(x -> endereco);
	printf("Digite o telefone:");
	gets(x -> telefone);
	printf("Digite o e-mail:");
	gets(x -> email);
}

void exibir_lista( tipo_pessoa x ){
	printf("\n\nCodigo: %d", x.codigo);
	printf("\nNome: %s", x.nome);
	printf("\nEndereco: %s", x.endereco);
	printf("\nTelefone: %s", x.telefone);
	printf("\nE-mail: %s", x.email);
}

int main()
   { Lista_Est L;
     tipo_pessoa X;
     
     Criar_Lista_Vazia(&L);
     ler_tipo_pessoa(&X);
     Insere_Elemento_Lista(&L,X);
     Remove_Elemento_Lista(&L, &X);

     return (0);
  }

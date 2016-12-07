/*
	Name: Orlando da Cruz Pereira Júnior      
  Date: 10/09/16 11:56
	Description: Matriz Diagonal
*/

#include<stdio.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

void menu();
void menu(){
    printf("\n         MENU             \n");
    printf("============================\n");
    printf("| 1-Consultar              |\n");
    printf("| 2-Listar                 |\n");
    printf("| 3-Sair                   |\n");
    printf("============================\n");
    printf("Opcao:___");
}

int main()
{
int matriz[5][5];
int x, y, cont=1,operacao,elemento,a,b;

//matriz

for(x=0 ; x<5 ; x++){
    for(y=0 ; y<5 ; y++){
    	if(x>y || x<y){
    		matriz[x][y] = 0;
    	}
    	else{
			matriz[x][y] = cont;
		}
    cont++;
    }
}

for(x=0 ; x<5 ; x++){
    for(y=0 ; y<5 ; y++){
        printf(" %3.2d",matriz[x][y]);
        
    }
    printf("\n");
}
printf("\n");
cont=50;

//Consultar um elemento
//chamando função menu de informações
do{
	menu();
    scanf("%d",&operacao);
    switch (operacao)
	{
    	case 1:
    		printf("Consultando elemento:");
    		printf("\nDigite a posicao do elemento:\n");
    		scanf("%d",&elemento);
    		a=elemento/10;
    		b=elemento%10;
    		printf("\nO numero solicitado eh: %.2d",matriz[a][b]);
    		
    	break;
    	case 2:
    		printf("Listando elementos:");
    		printf("\n");
    		for(x=0 ; x<5 ; x++){
    			for(y=0 ; y<5 ; y++){
        			printf(" %3.2d",matriz[x][y]);
    			}
    			printf("\n");
			}
    	break;

      	default:
    		printf("ERRORrrrr");
    }
}while (operacao!=3);

return 0;
}

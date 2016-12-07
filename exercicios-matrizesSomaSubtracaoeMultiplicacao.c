/*
	Name: Orlando da Cruz Pereira Júnior      
    Date: 10/09/16 15:56
	Description: soma, subtração e multiplicação de matrizes
*/

#include<stdio.h>
#include<math.h>
int main()
{
int matriz[5][5], matriz2[5][5], matriz_soma[5][5], matriz_subtracao[5][5], matriz_multiplicacao[5][5];
int x=0, y=0, cont=50;

// primeira matriz
for(x=0 ; x<5 ; x++){
    for(y=0 ; y<5 ; y++){
    matriz[x][y]=cont;
    cont++;
    }
}
printf("Primeira matriz\n");
for(x=0 ; x<5 ; x++){
    for(y=0 ; y<5 ; y++){
        printf(" %3.2d",matriz[x][y]);
        
    }
    printf("\n");
}
printf("\n");
cont=1;

//segunda matriz
for(x=0 ; x<5 ; x++){
    for(y=0 ; y<5 ; y++){
    matriz2[x][y]=cont;
    cont++;
    }
}
printf("Segunda matriz\n");
for(x=0 ; x<5 ; x++){
    for(y=0 ; y<5 ; y++){
        printf(" %3.2d",matriz2[x][y]);
        
    }
    printf("\n");
}

//somando duas matrizes
for(x=0 ; x<5 ; x++){
    for(y=0 ; y<5 ; y++){
    	matriz_soma[x][y]= matriz[x][y] + matriz2[x][y];
    
    }
}
printf("\n\n------RESULTADO------\n");
printf("Soma de duas matrizes\n");
for(x=0 ; x<5 ; x++){
    for(y=0 ; y<5 ; y++){
        printf(" %3.2d",matriz_soma[x][y]);
        
    }
    printf("\n");
}

//subtração entre as matrizes
for(x=0 ; x<5 ; x++){
    for(y=0 ; y<5 ; y++){
    	matriz_subtracao[x][y]= matriz[x][y] - matriz2[x][y];
    
    }
}
printf("\nSubtracao de duas matrizes\n");
for(x=0 ; x<5 ; x++){
    for(y=0 ; y<5 ; y++){
        printf(" %4.4d",matriz_subtracao[x][y]);
        
    }
    printf("\n");
}

//multiplicando duas matrizes
for(x=0 ; x<5 ; x++){
    for(y=0 ; y<5 ; y++){
    	matriz_multiplicacao[x][y]= matriz[x][y] * matriz2[x][y];
    
    }
}
printf("\nMultiplicacao de duas matrizes\n");
for(x=0 ; x<5 ; x++){
    for(y=0 ; y<5 ; y++){
        printf(" %4.4d",matriz_multiplicacao[x][y]);
        
    }
    printf("\n");
}

return 0;
}

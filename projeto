#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#define MAX 100
#define VS 18 //valor da sessao

typedef struct{
	char nome[45];
	int status;
	int posicao;
} Poltrona;

typedef struct{
    int dia;
    int mes;
    int ano;
} data;

typedef struct{
	int codigo;
	char NomeEspetaculo[20];
	char horario[6];
	data dataSessao;
	int tamanho;
	float valor;
	Poltrona poltronas[MAX];
} Sessao;

typedef struct{
	Sessao sessao[MAX];
	int prim,ult;
	int numSessoes;
} Teatro;

/* ---------------------------- Teatro --------------------------------------------*/
void Criar_Teatro(Teatro *T){
	T->prim = 0;
	T->ult = T->prim;
	T->sessao->tamanho = 0;
	T->numSessoes = 0;
}

//verifica teatro vazio
int VerificaTVazio(Teatro T){
	return (T.prim == T.ult);
}

//verifica teatro cheio
int VerificaTCheio(Teatro T){
	return(T.ult == MAX);
}

//verificar se codigo de sessao existe
int VerificaSessao(Teatro *T, int cod){
	int i;
	int p = 0;

	for(i = T->prim; i < T->ult; i++)
        if(cod == T->sessao[i].codigo)
			p++;

    if(p == 0)
        return 1;
    else
		return 0;
}

//verifica ocupacao de assento
int VerificaPoltrona(Teatro *T, int pos){
	int i;
	int p = 0;

	for(i = 0; i < T->sessao->tamanho; i++)
		if(pos == T->sessao->poltronas[i].posicao)
			p++;

    if(p == 0)
		return 1;
	else
		return 0;
}

//Exibir layout do teatro
void LayoutTeatro(Teatro *T, int codigo){
    int s = 0, indi, indj, k, vtam, vpos;

    if (VerificaSessao(T, codigo) == 0)
		while(T->sessao[s].codigo != codigo)
			s++;

    Titulo_Tela();
    printf(" GERENCIAMENTO DE RESERVAS DA SESSAO %d. PECA %s", T->sessao[s].codigo, &T->sessao[s].NomeEspetaculo);
    printf(" Data: %d/%d/%d as %shs. Valor R$ %.2f", T->sessao[s].dataSessao.dia, T->sessao[s].dataSessao.mes, T->sessao[s].dataSessao.ano, T->sessao[s].horario, T->sessao[s].valor);
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("Fileira      Cadeiras Lado Esquerdo                 Cadeiras Lado Direito     |\n");
    printf("------------------------------------------| |----------------------------------\n");
    for(indi = 1; indi <= 18; indi++){
        printf("| %d  \t ", indi);

        for(indj = 10; indj > 0; indj--){
            vpos = ((indi-1) * 20) + indj ;
            vtam = 0;
            for(k = 0; k < T->sessao[s].tamanho; k++)
                if(vpos ==  T->sessao[s].poltronas[k].posicao){
                    vtam++;
                    break;
                }

            if(vtam == 0)
                printf(" %d ",indj);
            else{
                if(indj == 10)
                    printf(" ");

                if(T->sessao[s].poltronas[k].status == 0)
                    printf("[R]");
                else
                    printf("[V]");
            }
        }

        printf("  | |  ");

        for(indj = 1; indj < 11; indj++){
            vpos = ((indi-1) * 20) + indj + 10;
            vtam = 0;
            for(k = 0; k < T->sessao[s].tamanho; k++)
                if(vpos ==  T->sessao[s].poltronas[k].posicao){
                    vtam++;
                    break;
                }

            if(vtam == 0)
                printf(" %d ",indj);
            else{
                if(indj == 10)
                    printf(" ");

                if(T->sessao[s].poltronas[k].status == 0)
                    printf("[R]");
                else
                    printf("[V]");
            }
        }

        printf("|\n");
    }
    printf("-------------------------------------------------------------------------------\n");
}
/* ---------------------------------------- Sessao -------------------------------------------*/
//Cadastrar nova sessão
void InserirSessao(Teatro *T, Sessao S){
	int A, P = T->prim;
	if(VerificaTCheio(*T))
		Mens("Teatro com horarios lotados", 3, 0);
	else{
		while((P < T->ult) && (S.codigo > T->sessao[P].codigo))
			P++;

        if(P == T->ult){
			T->sessao[P] = S;
			T->ult++;
		}
		else{
			for(A = T->ult; A > P; A--)
                T->sessao[A] = T->sessao[A-1];

			T->sessao[P] = S;
			T->ult++;
		}
		T->sessao->tamanho++;
		Mens("Sessao cadastrada com sucesso!", 3, 0);
	}
}

//Excluir sessao criada
void RemoverSessao(Teatro *T, Sessao *S){
	int A, P = T->prim;

		while ((P < T->ult) && (S->codigo > T->sessao[P].codigo))
			P++;

		if ((P == T->ult) || (T->sessao[P].codigo != S->codigo))
			Mens("Sessao não encontrada", 3, 0);
		else{
			*S = T->sessao[P];
			for (A = P; A < T->ult; A++)
				T->sessao[A] = T->sessao[A+1];
			T ->ult--;
			Mens("Sessao removida com sucesso!", 3, 0);
		}
}

// Exibe todas as sessoes cadastradas
void ExibirTotalSessoes(Teatro *T, int num){
	int i;
	if(num >= 1){
        printf("\n Codigo\t Data    \t Horario \t Valor \t\t Peca\n");
		for(i = 0; i < T->ult; i++)
        {
            printf("\n %d \t %d/%d/%d \t %s \t\t %.2f \t %s", T->sessao[i].codigo, T->sessao[i].dataSessao.dia, T->sessao[i].dataSessao.mes, T->sessao[i].dataSessao.ano, T->sessao[i].horario, T->sessao[i].valor, T->sessao[i].NomeEspetaculo);
        }
        Mens("Fim da Exibicao. Pressione Enter", 3, 0);
    }
	else
		Mens("Nao existe nenhuma sessao cadastrada", 3, 0);
}

// Exibir sessao escolhida
void ExibirSessao(Teatro *T, int codigo){
	int i = 0;
	//int pos = 0;

	if (VerificaSessao(T,codigo) == 0){
		while(T->sessao[i].codigo != codigo)
			i++;

        printf("\n Codigo da sessao...: %d\n", T->sessao[i].codigo);
        printf(" Nome da peca.......: %s\n", T->sessao[i].NomeEspetaculo);
        printf(" Data...............: %d/%d/%d\n", T->sessao[i].dataSessao.dia, T->sessao[i].dataSessao.mes, T->sessao[i].dataSessao.ano);
        printf(" Horario............: %s\n", T->sessao[i].horario);
        printf(" Valor..............: %.2f\n\n", T->sessao[i].valor);
	}
	else
        Mens("Este codigo nao esta cadastrado", 3, 0);
}

// Faz a leitura dos dados de uma sessao
void LerSessao(Teatro *T, Sessao *S){
	printf("\n\n Entre com o codigo da sessao..............: ");
	scanf("%d", &S->codigo);
	getchar();
	if (VerificaSessao(T, S->codigo) == 1){
		printf("\n Entre com o nome da peca..................: ");
		fgets(S->NomeEspetaculo,50,stdin);

		printf("\n Entre com a data da sessao (dd/mm/aaaa)...: ");
		char dataAux[11];
		scanf("%s", dataAux);
		getchar();

        S->dataSessao.dia = (dataAux[0]-48)*10 + (dataAux[1]-48);
        S->dataSessao.mes = (dataAux[3]-48)*10 + (dataAux[4]-48);
        S->dataSessao.ano = (dataAux[6]-48)*1000 + (dataAux[7]-48)*100 + (dataAux[8]-48)*10 + (dataAux[9]-48);

		printf("\n Entre com o horario da sessao (hh:mm).....: ");
		scanf("%s",&S->horario);

		printf("\n Entre com o valor da sessao.............R$: ");
		scanf("%f",&S->valor);
    }
	else
		Mens("Este codigo ja foi cadastrado!", 3, 0);
}
/* ------------------------------------------------ Cliente --------------------------------------- */
// faz a leitura do nome do cliente
void LerCliente(Teatro *T, Poltrona *A, int pos){
	A->posicao = pos;
	if(VerificaPoltrona(T, A->posicao) == 1){
		printf(" Digite o nome do cliente..: ");
		fgets(A->nome,30,stdin);
		A->status = 0; // Reserva
		getchar();
	}
}

//insere o cliente em determinada sessao
void InserirCliente(Teatro *T, Poltrona A){
	int P = T->sessao->tamanho;

	if(VerificaTCheio(*T))
		Mens("Teatro cheio!", 3, 0);
	else{
		T->sessao->poltronas[P] = A;
		T->sessao->tamanho++;
		Mens("Reserva Efetuada", 3, 0);
	}
}

//remove um cliente de uma sessao
void RemoveCliente(Teatro *T, Poltrona A){
	int P = 0, B;
	if(VerificaPoltrona(T,A.posicao) == 0){
		if (VerificaTVazio(*T))
			Mens("Teatro Vazio!", 3, 0);
		else{
			while((P < T->sessao->tamanho) && (T->sessao->poltronas->posicao != A.posicao))
				P++;

			A = T->sessao->poltronas[P];

			for (B = P; B < T->sessao->tamanho; B++)
				T->sessao->poltronas[B] = T->sessao->poltronas[B+1];

			T->sessao->tamanho--;
			Mens("Lugar cancelado com sucesso", 3, 0);
		}
	}
	else
		Mens("Este codigo nao esta na lista", 3, 0);
}

//exibe os dados do cliente e a sessao que esta vinculado
void ExibeCliente(Teatro *T, int posicao){
	int i = 0,cliente = 0;
	if (VerificaPoltrona(T, posicao) == 0){
		while(T->sessao->poltronas[i].posicao != posicao){
			cliente++;
			i++;
        }
        printf("\n\n Nome do Cliente.................................: %s\n", T->sessao->poltronas[cliente].nome);
		printf("\n Cadeira escolhido pelo cliente..................: %d\n", T->sessao->poltronas[cliente].posicao);
		printf("\n Situacao do Poltrona: (0-Reservado / 1-Vendido)..: %d\n", T->sessao->poltronas[cliente].status);
		Mens("Fim da exibicao", 2, 0);
	}
	else
		Mens("Esta posicao nao esta cadastrada", 3, 0);
}

void ConfirmaVenda(Teatro *T, int pos){
	int i = 0, cliente = 0;
	if (VerificaPoltrona(T, pos) == 0){
		while(T->sessao->poltronas[i].posicao != pos){
			cliente++;
			i++;
        }
        T->sessao->poltronas[cliente].status = 1;
    }
}

/* ============= Funcoes de Apresentacao ============= */
void Centraliza(char Mensagem[]){
    int i;
    for(i = 0; i < ((80 - strlen(Mensagem)) / 2); i++)
        printf(" ");
    printf("%s\n", Mensagem);
}

void Mens(char Mensagem[], int Espaco_Antes, int Espaco_Depois){
    int i;
    for(i = 0; i < Espaco_Antes; i++)
        printf("\n");
    Centraliza(Mensagem);
    for(i = 0; i < Espaco_Depois; i++)
        printf("\n");
    system("Pause > nul");
}

bool comparaData ( data data1, data data2 ){
    if ( data1.ano < data2.ano ) return true;
    else if ( data1.ano > data2.ano ) return false;
    else{
        if ( data1.mes < data2.mes ) return true;
        else if ( data1.ano > data2.ano ) return false;
        else{
            if ( data1.dia <= data2.dia ) return true;
            else
                return false;
        }
    }
}

void Titulo_Tela(){
    system("color 1F");
    system("cls");
    printf(" TEATRO\n");
    printf(" ------------------------------------------------------------------------------ \n\n\n");
    Centraliza("T E A T R O    U F G");
    Centraliza("====================");
    printf("\n\n\n");
}

void Menu(){
    Titulo_Tela();
    printf("\t\t\t[1] - Inserir Sessao\n\n");
    printf("\t\t\t[2] - Remover Sessao\n\n");
    printf("\t\t\t[3] - Informacoes das Sessoes\n\n\n");
    printf("\t\t\t[4] - Efetuar Reserva\n\n");
    printf("\t\t\t[5] - Cancelar Reserva\n\n");
    printf("\t\t\t[6] - Exibir Reserva\n\n");
    printf("\t\t\t[7] - Converter Reserva em Venda\n\n\n");
    printf("\t\t\t[8] - Limpar Sessoes Realizadas\n\n\n");
    printf("\t\t\t[0] - Finalizar o Sistema \n\n\n\n");
    printf("\t\t\t\tOpcao:   ");
}
/* ============= Main ============= */

void gravar ( Teatro T ){
    FILE *arq;
    arq = fopen("dados.bin", "wb");
    fwrite(&T, sizeof(T), 1, arq);
    fclose(arq);
}

void ler ( Teatro *T ){
    FILE *arq;
    arq = fopen("dados.bin", "rb");
    fread(&(*T), sizeof(*T), 1, arq);
    fclose(arq);
}

int main(){
    Teatro T;
    Poltrona L;
    Sessao S;
    Criar_Teatro(&T);
    ler(&T);
    int saida = 0, opcao, codigo, num_cliente = 0, posicao, cadeira, fileira, ind;
    int ladofileira;
    data datalimpeza;

    int Opcao;
    do{
        Menu();
        scanf("%d",&Opcao);

        Titulo_Tela();
        switch (Opcao){
            case 0:
                gravar(T);
                Mens("Ate a proxima", 1, 0);
		        break;
            case 1:
                Centraliza("INSERIR SESSAO");
                LerSessao(&T,&S);
                if(VerificaSessao(&T,S.codigo) == 1){
                    InserirSessao(&T,S);
                    T.numSessoes++;
                }
	            break;
            case 2:
                Centraliza("REMOVER SESSAO");
                if (VerificaTVazio(T))
                    Mens("Não existem sessoes cadastradas. Favor Inserir", 3, 0);
                else{
                    printf("\n\n\n Digite o codigo da sessao a ser removida..: ");
                    scanf("%d",&S.codigo);
                    getchar();
                    if(VerificaSessao(&T, S.codigo) == 0){
                        ExibirSessao(&T, S.codigo);
                        RemoverSessao(&T,&S);
                        T.numSessoes--;
                    }
                    else
                        Mens("Essa sessao nao esta cadastrada", 3, 0);
                }
		        break;
            case 3:
                Centraliza("INFORMACOES DAS SESSOES");
                ExibirTotalSessoes(&T, T.numSessoes);
		        break;
            case 4:
                Centraliza("GERENCIAMENTO DE RESERVAS");
                if(T.numSessoes!=0){
                    printf("\n\n\n Digite o codigo da sessao.................: ");
                    scanf("%d",&S.codigo);
                    getchar();
                    if(VerificaSessao(&T, S.codigo) == 0){
                        LayoutTeatro(&T, S.codigo);
                        printf(" Digite a fileira escolhida pelo cliente............: ");
                        scanf("%d",&fileira);
                        getchar();
                        if((fileira > 0) && (fileira < 19)){
                            printf(" Digite a cadeira escolhida pelo cliente............: ");
                            scanf("%d",&cadeira);
                            getchar();
                            if((cadeira > 0) && (cadeira < 11)){
                                printf(" Digite o lado da fileira (0-Esquerda / 1-Direita)..: ");
                                scanf("%d",&ladofileira);
                                getchar();
                                if((ladofileira != 0) || (ladofileira != 1)){
                                    if(ladofileira == 0)
                                        posicao = ((fileira-1) * 20) + cadeira ;
                                    else
                                        posicao = ((fileira-1) * 20) + (cadeira + 10);

                                    L.posicao = posicao;
                                    if(VerificaPoltrona(&T, L.posicao) == 1){
                                        LerCliente(&T, &L, posicao);
                                        InserirCliente(&T, L);
                                        num_cliente++;
                                    }
                                    else
                                        Mens("Este lugar ja esta ocupado.", 3, 0);
                                }
                                else
                                    Mens("Lado da Fileira Invalido. Digite 0 ou 1", 3, 0);
                            }
                            else
                                Mens("Cadeira Invalida. Insira de 1 a 10.", 3, 0);
                        }
                        else
                            Mens("Fileira Invalida. Insira de 1 a 18.", 3, 0);
                    }
                    else
                        Mens("Essa sessao nao esta cadastrada.", 3, 0);
                }
                else
                    Mens("E necessario cadastrar uma sessao primeiro.", 3, 0);
		        break;
            case 5:
                Centraliza("CANCELAR RESERVA");
                if(T.numSessoes!=0){
                    printf("\n\n\n Digite a fileira do lugar a ser cancelado..........: ");
                    scanf("%d",&fileira);
                    printf(" Digite a cadeira a ser cancelada...................: ");
                    scanf("%d",&cadeira);
                    getchar();
                    printf(" Digite o lado da fileira (0-Esquerda / 1-Direita)..: ");
                    scanf("%d",&ladofileira);
                    getchar();
                    if(ladofileira == 0)
                        posicao = ((fileira-1) * 20) + cadeira ;
                    else
                        posicao = ((fileira-1) * 20) + (cadeira + 10);
                    L.posicao = posicao;
                    if(VerificaPoltrona(&T,L.posicao) == 0){
                        RemoveCliente(&T, L);
                        num_cliente--;
                    }
                    else
                        Mens("Esta posicao nao esta cadastrada. Impossivel remover.", 3, 0);
                }
                else
                    Mens("E necessario cadastrar uma sessao primeiro.", 3, 0);
		        break;
            case 6:
                Centraliza("CONSULTAR RESERVAS");
                if(T.numSessoes!=0){
                    if(num_cliente!=0){
                        printf("\n\n\n Digite a fileira do lugar do cliente a ser exibido..: ");
                        scanf("%d",&fileira);
                        printf(" Digite a cadeira do cliente a ser exibido...........: ");
                        scanf("%d",&cadeira);
                        getchar();
                        printf(" Digite o lado da fileira (0-Esquerda / 1-Direita)...: ");
                        scanf("%d",&ladofileira);
                        getchar();
                        if(ladofileira == 0)
                            posicao = ((fileira-1) * 20) + cadeira ;
                        else
                            posicao = ((fileira-1) * 20) + (cadeira + 10);

                        ExibeCliente(&T, posicao);
                    }
                    else
                        Mens("Nao ha clientes cadastrados", 3, 0);
                }
                else
                    Mens("E necessario cadastrar uma sessao primeiro.", 3, 0);
                break;
            case 7:
                Centraliza("CONVERTER RESERVA EM VENDA");
                if(T.numSessoes!=0){
                    if(num_cliente!=0){
                        printf("\n\n\n Digite a fileira do lugar do cliente a ser exibido..: ");
                        scanf("%d",&fileira);
                        printf(" Digite a cadeira do cliente a ser exibido...........: ");
                        scanf("%d",&cadeira);
                        getchar();
                        printf(" Digite o lado da fileira (0-Esquerda / 1-Direita)...: ");
                        scanf("%d",&ladofileira);
                        getchar();
                        if(ladofileira == 0)
                            posicao = ((fileira-1) * 20) + cadeira ;
                        else
                            posicao = ((fileira-1) * 20) + (cadeira + 10);

                        ConfirmaVenda(&T, posicao);
                        ExibeCliente(&T, posicao);
                        Mens("Venda confirmada com sucesso!", 3, 0);
                    }
                    else
                        Mens("Nao ha clientes cadastrados", 3, 0);
                }
                else
                    Mens("E necessario cadastrar uma sessao primeiro.", 3, 0);

		        break;
            case 8:
                Centraliza("LIMPAR SESSOES REALIZADAS");
                if (VerificaTVazio(T))
                    Mens("Não existem sessoes cadastradas.", 3, 0);
                else{
                    printf("\n\n\n Excluir todas as sessoes ate a data: (dd/mm/aaaa)...: ");
                    char dataAux[11];
                    scanf("%s",dataAux);
                    getchar();
                    datalimpeza.dia = (dataAux[0]-48)*10 + (dataAux[1]-48);
                    datalimpeza.mes = (dataAux[3]-48)*10 + (dataAux[4]-48);
                    datalimpeza.ano = (dataAux[6]-48)*1000 + (dataAux[7]-48)*100 + (dataAux[8]-48)*10 + (dataAux[9]-48);

                    printf("\n\n Codigo\t Data    \t Horario \t Valor \t\t Peca\n");
                    for(ind = 0; ind < T.numSessoes; ind++){
                        if(comparaData(T.sessao[ind].dataSessao, datalimpeza)){
                            S.codigo = T.sessao[ind].codigo;
                            if(VerificaSessao(&T, S.codigo) == 0){
                                printf("\n %d \t %2d/%2d/%4d \t %s \t\t %.2f \t %s", T.sessao[ind].codigo, T.sessao[ind].dataSessao.dia, T.sessao[ind].dataSessao.mes, T.sessao[ind].dataSessao.ano, T.sessao[ind].horario, T.sessao[ind].valor, T.sessao[ind].NomeEspetaculo);
                                RemoverSessao(&T,&S);
                                T.numSessoes--;
                            }
                        }
                    }
                    Mens("Fim da Limpeza. Pressione Enter", 3, 0);
                }
                break;
            default:
                Mens("Opcao invalida!", 4, 0);
		        break;
        }
    } while(Opcao != 0);
	return 0;
}

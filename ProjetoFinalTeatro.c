/*
	Universidade Federal de Goias - UFG 
	Disciplina: INF0061 - Estrutura de Dados (2016 .2 - TA)
	Professor: Edmundo Sergio Spoto  
	Projeto Final da Disciplina - Teatro
	Alunos: Gustavo Antunes Rocha 		Matrícula: 201513444 
		Orlando da Cruz Pereira Júnior  Matrícula: 201301679
		Bianca Raissa Ferreira Nunes 	Matrícula: 201404918
*/

#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <conio.h>
#define MAX 100

typedef struct{ 
    int dia;
    int mes;
    int ano;
} Data;

typedef struct{
	char nome[45];
	int status;
	int posicao;
} Poltrona;

typedef struct{
	int cod;
	char nomePeca[20];
	char horario[6];
	Data dataSessao;
	int tamanho;
	float valor;
	Poltrona poltronas[MAX];
} Sessao;

typedef struct{
	Sessao sessao[MAX];
	int prim,ult;
	int numSessoes;
} Teatro;

void Criar_Teatro(Teatro *T){
	T->prim = 0;
	T->ult = T->prim;
	T->sessao->tamanho = 0;
	T->numSessoes = 0;
}

int VerificaTeatroCheio(Teatro T){
	return(T.ult == MAX);
}

int VerificaTeatroVazio(Teatro T){
	return (T.prim == T.ult);
}

int VerificaPoltrona(Teatro *T, int pos){
	int i;
	int p = 0;

	for(i = 0; i < T->sessao->tamanho; i++)
		if(pos == T->sessao->poltronas[i].posicao) //Verifica ocupação de um assento
			p++;

    if(p == 0)
		return 1;
	else
		return 0;
}

int VerificaSessao(Teatro *T, int cod){
	int i;
	int p = 0;

	for(i = T->prim; i < T->ult; i++)
        if(cod == T->sessao[i].cod)
			p++;

    if(p == 0)
        return 1;
    else
		return 0;
}

void LayoutTeatro(Teatro *T, int cod){ // Tela de exibição das poltronas
    int s = 0, posi, posj, k, vtam, vpos;

    if (VerificaSessao(T, cod) == 0)
		while(T->sessao[s].cod != cod)
			s++;

    MensagemSuperior(); //Titulo superior da tela
    Centraliza("ESCOLHA AS POLTRONAS");
    printf("******************************************************************************\n");
    printf("FILEIRA             LADO ESQUERDO                      LADO DIREITO           \n");
    printf("                                           |                                  \n");
    for(posi = 1; posi <= 18; posi++){ //Fileiras e poltronas
        printf(" %d  \t ", posi);

        for(posj = 10; posj > 0; posj--){
            vpos = ((posi-1) * 20) + posj ;
            vtam = 0;
            for(k = 0; k < T->sessao[s].tamanho; k++)
                if(vpos ==  T->sessao[s].poltronas[k].posicao){
                    vtam++;
                    break;
                }

            if(vtam == 0)
                printf(" %d ",posj);
            else{
                if(posj == 10)
                    printf(" ");

                if(T->sessao[s].poltronas[k].status == 0)
                    printf("[R]");
                else
                    printf("[V]");
            }
        }

        printf("   |   ");

        for(posj = 1; posj < 11; posj++){
            vpos = ((posi-1) * 20) + posj + 10;
            vtam = 0;
            for(k = 0; k < T->sessao[s].tamanho; k++)
                if(vpos ==  T->sessao[s].poltronas[k].posicao){
                    vtam++;
                    break;
                }

            if(vtam == 0)
                printf(" %d ",posj);
            else{
                if(posj == 10)
                    printf(" ");

                if(T->sessao[s].poltronas[k].status == 0)
                    printf("[R]");
                else
                    printf("[V]");
            }
        }

        printf("\n");
    }
}

void InserirNovaSessao(Teatro *T, Sessao S){ 
	int A, P = T->prim;
	if(VerificaTeatroCheio(*T))
		Mensage("Teatro com horarios lotados", 3, 0);
	else{
		while((P < T->ult) && (S.cod > T->sessao[P].cod)) //Cadastrar uma nova sessao
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
		Mensage("Sessao cadastrada, pressione ENTER para continuar!", 3, 0);
	}
}

void RemoverSessao(Teatro *T, Sessao *S){
	int A, P = T->prim;

		while ((P < T->ult) && (S->cod > T->sessao[P].cod))
			P++;

		if ((P == T->ult) || (T->sessao[P].cod != S->cod))
			Mensage("Nao encontrada", 3, 0);
		else{
			*S = T->sessao[P];
			for (A = P; A < T->ult; A++)
				T->sessao[A] = T->sessao[A+1];
			T ->ult--;
			Mensage("Sessao removida!", 3, 0);
		}
}

void ExibirSessao(Teatro *T, int cod){
	int i = 0;
	if (VerificaSessao(T,cod) == 0){
		while(T->sessao[i].cod != cod)
			i++;

        printf("\n Codigo da sessao: %d\n", T->sessao[i].cod);
        printf(" Nome da peca: %s\n", T->sessao[i].nomePeca);
        printf(" Data: %d/%d/%d\n", T->sessao[i].dataSessao.dia, T->sessao[i].dataSessao.mes, T->sessao[i].dataSessao.ano);
        printf(" Horario: %s\n", T->sessao[i].horario);
        printf(" Valor: %.2f\n\n", T->sessao[i].valor);
	}
	else
        Mensage("Este codigo nao esta cadastrado", 3, 0);
}

void LerSessao(Teatro *T, Sessao *S){
	printf("\n\n Informe o codigo da sessao: ");
	scanf("%d", &S->cod);
	getchar();
	if (VerificaSessao(T, S->cod) == 1){
		printf(" Nome da peca: ");
		fgets(S->nomePeca,50,stdin);

		printf(" Data da sessao dd/mm/aaaa: ");
		char dataAux[11];
		scanf("%s", dataAux);
		getchar();

        S->dataSessao.dia = (dataAux[0]-48)*10 + (dataAux[1]-48);
        S->dataSessao.mes = (dataAux[3]-48)*10 + (dataAux[4]-48);
        S->dataSessao.ano = (dataAux[6]-48)*1000 + (dataAux[7]-48)*100 + (dataAux[8]-48)*10 + (dataAux[9]-48);

		printf(" Horario da sessao hh:mm: ");
		scanf("%s",&S->horario);

		printf(" Valor da sessao R$: ");
		scanf("%f",&S->valor);
    }
	else
		Mensage("Codigo ja cadastrado!", 3, 0);
}

void ExibirTodasSessoes(Teatro *T, int num){ //Tela de exibição de todas as sessoes
	int i;
	if(num >= 1){
		Centraliza(" ##############################################################################\n");
        printf    ("Codigo\t Data    \t Horario \t Valor \t Peca\n");
		for(i = 0; i < T->ult; i++)
        {
            printf(" %d \t %d/%d/%d \t %s \t\t %.2f \t %s", T->sessao[i].cod, T->sessao[i].dataSessao.dia, T->sessao[i].dataSessao.mes, T->sessao[i].dataSessao.ano, T->sessao[i].horario, T->sessao[i].valor, T->sessao[i].nomePeca);
            Centraliza("------------------------------------------------------------------------------");
        }
        Centraliza(" ##############################################################################\n");
        Mensage("Fim, Pressione Enter para Continuar", 3, 0);
    }
	else
		Mensage("Nao existe nenhuma sessao cadastrada", 3, 0);
}

void InserirCliente(Teatro *T, Poltrona A){
	int P = T->sessao->tamanho;

	if(VerificaTeatroCheio(*T))
		Mensage("Teatro cheio!", 3, 0);
	else{
		T->sessao->poltronas[P] = A;
		T->sessao->tamanho++;
		Mensage("Reserva Efetuada", 3, 0);
	}
}

void LerCliente(Teatro *T, Poltrona *A, int pos){
	A->posicao = pos;
	if(VerificaPoltrona(T, A->posicao) == 1){ //Efetua a leitura de um cliente
		printf(" Digite o nome do cliente: ");
		fgets(A->nome,30,stdin);
		A->status = 0; // Reserva
		getchar();
	}
}

void RemoveCliente(Teatro *T, Poltrona A){
	int P = 0, B;
	if(VerificaPoltrona(T,A.posicao) == 0){
		if (VerificaTeatroVazio(*T))
			Mensage("Teatro Vazio!", 3, 0);
		else{
			while((P < T->sessao->tamanho) && (T->sessao->poltronas->posicao != A.posicao))
				P++;

			A = T->sessao->poltronas[P];

			for (B = P; B < T->sessao->tamanho; B++)
				T->sessao->poltronas[B] = T->sessao->poltronas[B+1];

			T->sessao->tamanho--;
			Mensage("Lugar cancelado!", 3, 0);
		}
	}
	else
		Mensage("Este codigo nao esta na lista", 3, 0);
}

void ConfirmaVendaEfetuada(Teatro *T, int pos){
	int i = 0, cliente = 0;
	if (VerificaPoltrona(T, pos) == 0){
		while(T->sessao->poltronas[i].posicao != pos){
			cliente++;
			i++;
        }
        T->sessao->poltronas[cliente].status = 1;
    }
}

void ExibeCliente(Teatro *T, int posicao){
	int i = 0,cliente = 0;
	if (VerificaPoltrona(T, posicao) == 0){
		while(T->sessao->poltronas[i].posicao != posicao){
			cliente++;
			i++;
        }
        printf("\nNome: %s\n", T->sessao->poltronas[cliente].nome);
		printf("Poltrona escolhida: %d\n", T->sessao->poltronas[cliente].posicao);
		printf("Situacao da Poltrona: 0 Reservado / 1 Vendido : %d\n", T->sessao->poltronas[cliente].status);
		Mensage("Fim", 2, 0);
	}
	else
		Mensage("Posicao nao cadastrada", 3, 0);
}

void MensagemSuperior(){
    system("color 5F");
    system("mode con:cols=80 lines=30");
    //system ("color 17");
    system("cls");
    printf("Teatro Goiania - Unidade da Seduce-GO\n");
    printf("Rua 23, numero 252 - Centro\n");
    printf("Telefones: 3201-4684 e 3201-4685 www.secult.go.gov.br\n");
    printf(" ------------------------------------------------------------------------------ \n");
    Centraliza("TEATRO GOIANIA - GOVERNO DO ESTADO DE GOIAS");
    Centraliza("MENU DEMO Version 1.0");
    Centraliza("Desenvolvido pela Universidade Federal de Goias");
    printf("\n");
}

void Centraliza(char Mensagem[]){ //Centraliza as mensagem na tela
    int i;
    for(i = 0; i < ((80 - strlen(Mensagem)) / 2); i++)
        printf(" ");
    printf("%s\n", Mensagem);
}

bool comparaData( Data data1, Data data2 ){ //Verificando data informada
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

void Mensage(char Mensagem[], int Espaco_Antes, int Espaco_Depois){ //Configurações das mensagens exibidas
    int i;
    for(i = 0; i < Espaco_Antes; i++)
        printf("\n");
    Centraliza(Mensagem);
    for(i = 0; i < Espaco_Depois; i++)
        printf("\n");
    system("Pause > nul");
}

void gravar( Teatro T ){ //Gravando em arquivo
    FILE *arq;
    arq = fopen("database.bin", "wb");
    fwrite(&T, sizeof(T), 1, arq);
    fclose(arq);
}

void ler( Teatro *T ){
    FILE *arq;
    arq = fopen("database.bin", "rb");
    fread(&(*T), sizeof(*T), 1, arq);
    fclose(arq);
}

void Menu(){
    MensagemSuperior();
    printf(" ##############################################################################\n");
    printf(" |   1 - Insere Nova Sessao                                                   |\n");
    printf(" |   2 - Remove Sessao Existente                                              |\n");
    printf(" |   3 - Informacoes das Sessoes                                              |\n");
    printf(" |   4 - Efetuar Reserva em uma Sessao                                        |\n");
    printf(" |   5 - Cancelar Reserva em uma Sessao                                       |\n");
    printf(" |   6 - Exibir Reserva Efetuadas                                             |\n");
    printf(" |   7 - Converter Reserva em Venda                                           |\n");
    printf(" |   8 - Eliminar Sessoes Cadastradas                                         |\n");
    printf(" |   0 - Sair do sistema                                                      |\n");
    printf(" ##############################################################################\n");
    printf("  Digite a opcao escolhida: \n");
}

int main(){
    Sessao S;
    Teatro T;
    Poltrona L;
    Criar_Teatro(&T);
    ler(&T);
    int saida = 0, opcao, cod, num_cliente = 0, posicao, poltrona, fileira, pos;
    int ladofileira;
    Data datalimpeza;
	MensagemSuperior();
    int Opcao;
    do{
        Menu();
        scanf("%d",&Opcao);
        MensagemSuperior();
        switch (Opcao){
            case 0:
                gravar(T);
                Mensage("Ate a proxima", 1, 0);
		        break;
            case 1:
                Centraliza("INSERIR SESSAO");
                LerSessao(&T,&S);
                if(VerificaSessao(&T,S.cod) == 1){
                    InserirNovaSessao(&T,S);
                    T.numSessoes++;
                }
	            break;
            case 2:
                Centraliza("REMOVER SESSAO");
                if (VerificaTeatroVazio(T))
                    Mensage("Nao possue sessoes cadastradas. Insira novas sessoes!", 3, 0);
                else{
                    printf("\n\n\n Entre com o codigo da sessao a ser removida: ");
                    scanf("%d",&S.cod);
                    getchar();
                    if(VerificaSessao(&T, S.cod) == 0){
                        ExibirSessao(&T, S.cod);
                        RemoverSessao(&T,&S);
                        T.numSessoes--;
                    }
                    else
                        Mensage("Sessao nao cadastrada", 3, 0);
                }
		        break;
            case 3:
                Centraliza("SESSOES EM CARTAZ");
                ExibirTodasSessoes(&T, T.numSessoes);
		        break;
            case 4:
                Centraliza("RESERVAS");
                if(T.numSessoes!=0){
                    printf("\n\n\n Digite o codigo da sessao: ");
                    scanf("%d",&S.cod);
                    getchar();
                    if(VerificaSessao(&T, S.cod) == 0){
                        LayoutTeatro(&T, S.cod);
                        printf(" Digite o numero da fileira: ");
                        scanf("%d",&fileira);
                        getchar();
                        if((fileira > 0) && (fileira < 19)){
                            printf(" Digite o numero da poltrona: ");
                            scanf("%d",&poltrona);
                            getchar();
                            if((poltrona > 0) && (poltrona < 11)){
                                printf(" Digite o lado escolhido (0 Esquerda e 1 Direita): ");
                                scanf("%d",&ladofileira);
                                getchar();
                                if((ladofileira != 0) || (ladofileira != 1)){
                                    if(ladofileira == 0)
                                        posicao = ((fileira-1) * 20) + poltrona ;
                                    else
                                        posicao = ((fileira-1) * 20) + (poltrona + 10);

                                    L.posicao = posicao;
                                    if(VerificaPoltrona(&T, L.posicao) == 1){
                                        LerCliente(&T, &L, posicao);
                                        InserirCliente(&T, L);
                                        num_cliente++;
                                    }
                                    else
                                        Mensage("Esta poltrona ja esta ocupada.", 3, 0);
                                }
                                else
                                    Mensage("Fileira Invalida. Digite 0 ou 1", 3, 0);
                            }
                            else
                                Mensage("Poltrona Invalida. Insira de 1 a 10.", 3, 0);
                        }
                        else
                            Mensage("Fileira Invalida. Insira de 1 a 18.", 3, 0);
                    }
                    else
                        Mensage("Sessao nao cadastrada.", 3, 0);
                }
                else
                    Mensage("Voce deve cadastrar uma nova sessao.", 3, 0);
		        break;
            case 5:
                Centraliza("CANCELAR RESERVA");
                if(T.numSessoes!=0){
                    printf("\n\n\n Digite a fileira do lugar a ser cancelado: ");
                    scanf("%d",&fileira);
                    printf(" Digite a poltrona a ser cancelada: ");
                    scanf("%d",&poltrona);
                    getchar();
                    printf(" Digite o lado da fileira - 0 Esquerda / 1 Direita: ");
                    scanf("%d",&ladofileira);
                    getchar();
                    if(ladofileira == 0)
                        posicao = ((fileira-1) * 20) + poltrona ;
                    else
                        posicao = ((fileira-1) * 20) + (poltrona + 10);
                    L.posicao = posicao;
                    if(VerificaPoltrona(&T,L.posicao) == 0){
                        RemoveCliente(&T, L);
                        num_cliente--;
                    }
                    else
                        Mensage("Posicao nao esta cadastrada.", 3, 0);
                }
                else
                    Mensage("E necessario cadastrar uma sessao primeiro.", 3, 0);
		        break;
            case 6:
                Centraliza("CONSULTAR RESERVAS");
                if(T.numSessoes!=0){
                    if(num_cliente!=0){
                        printf("\n\n\n Digite a fileira do lugar do cliente a ser exibido..: ");
                        scanf("%d",&fileira);
                        printf(" Digite a poltrona do cliente a ser exibido...........: ");
                        scanf("%d",&poltrona);
                        getchar();
                        printf(" Digite o lado da fileira (0-Esquerda / 1-Direita)...: ");
                        scanf("%d",&ladofileira);
                        getchar();
                        if(ladofileira == 0)
                            posicao = ((fileira-1) * 20) + poltrona ;
                        else
                            posicao = ((fileira-1) * 20) + (poltrona + 10);

                        ExibeCliente(&T, posicao);
                    }
                    else
                        Mensage("Nao ha clientes cadastrados", 3, 0);
                }
                else
                    Mensage("E necessario cadastrar uma sessao primeiro.", 3, 0);
                break;
            case 7:
                Centraliza("CONVERTER RESERVA EM VENDA");
                if(T.numSessoes!=0){
                    if(num_cliente!=0){
                        printf("\n\n\n Digite a fileira do lugar do cliente a ser exibido..: ");
                        scanf("%d",&fileira);
                        printf(" Digite a poltrona do cliente a ser exibido...........: ");
                        scanf("%d",&poltrona);
                        getchar();
                        printf(" Digite o lado da fileira (0-Esquerda / 1-Direita)...: ");
                        scanf("%d",&ladofileira);
                        getchar();
                        if(ladofileira == 0)
                            posicao = ((fileira-1) * 20) + poltrona ;
                        else
                            posicao = ((fileira-1) * 20) + (poltrona + 10);

                        ConfirmaVendaEfetuada(&T, posicao);
                        ExibeCliente(&T, posicao);
                        Mensage("Venda confirmada!", 3, 0);
                    }
                    else
                        Mensage("Nao ha clientes cadastrados", 3, 0);
                }
                else
                    Mensage("E necessario cadastrar uma sessao primeiro.", 3, 0);

		        break;
            case 8:
                Centraliza("LIMPAR SESSOES");
                if (VerificaTeatroVazio(T))
                    Mensage("Não existem sessoes cadastradas.", 3, 0);
                else{
                    printf("\n\n\n Excluir todas as sessoes ate a data (dd/mm/aaaa): ");
                    char dataAux[11];
                    scanf("%s",dataAux);
                    getchar();
                    datalimpeza.dia = (dataAux[0]-48)*10 + (dataAux[1]-48);
                    datalimpeza.mes = (dataAux[3]-48)*10 + (dataAux[4]-48);
                    datalimpeza.ano = (dataAux[6]-48)*1000 + (dataAux[7]-48)*100 + (dataAux[8]-48)*10 + (dataAux[9]-48);

                    printf("\n\n Codigo\t Data    \t Horario \t Valor \t\t Peca\n");
                    for(pos = 0; pos < T.numSessoes; pos++){
                        if(comparaData(T.sessao[pos].dataSessao, datalimpeza)){
                            S.cod = T.sessao[pos].cod;
                            if(VerificaSessao(&T, S.cod) == 0){
                                printf("\n %d \t %2d/%2d/%4d \t %s \t\t %.2f \t %s", T.sessao[pos].cod, T.sessao[pos].dataSessao.dia, T.sessao[pos].dataSessao.mes, T.sessao[pos].dataSessao.ano, T.sessao[pos].horario, T.sessao[pos].valor, T.sessao[pos].nomePeca);
                                RemoverSessao(&T,&S);
                                T.numSessoes--;
                            }
                        }
                    }
                    Mensage("Fim", 3, 0);
                }
                break;
            default:
                Mensage("Opcao invalida!", 4, 0);
		        break;
        }
    } while(Opcao != 0);
	return 0;
}

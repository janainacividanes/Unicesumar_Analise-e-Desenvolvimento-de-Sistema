#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

struct cliente
{
    char nome[200];
    char telefone[11];
    char email[30];
};
struct cliente cadastro[5];
int id = 0;

char menu() {

    int op;
    int resp;

	printf("\n ========---- Menu ----======== \n");
	printf(" 1 - Cadastrar um novo Cliente\n");
    printf(" 2 - Listar clientes cadastrados\n");
	printf(" 0 - Encerrar\n");
    printf("\n ============================== \n");
	printf(" Por favor, selecione uma opcao.\n");
	scanf("%d", &op);

switch (op)
    {
        case 0:
            printf("\n");
            printf(" Finalizando o programa...\n");
            printf(" Ate mais!\n");
            break;
        case 1:
            system("@cls||clear");
            novo_cadastro();
            break;
        case 2:
            system("@cls||clear");
            lista_cadastro();
            break;
        default:
            printf("\n");
            printf(" Opção inválida!\n");
            printf("\n");
            menu();
            break;
    }
};

int novo_cadastro() {

    if (id <= 4) {

        id++;
        printf("\n");
        printf(" =======--- Cadastro novo cliente ---======= \n");
        printf("\n");
        getchar();
        printf(" Insira o nome:\n");
        fgets(cadastro[id].nome, 200, stdin);
        fflush(stdin);
        printf(" Insira o telefone:\n");
        fgets(cadastro[id].telefone, 11, stdin);
        fflush(stdin);
        printf(" Insira o e-mail:\n");
        fgets(cadastro[id].email, 30, stdin);
        fflush(stdin);

        continuar();


    } else {
        printf(" Memoria cheia!\n");
        continuar();
    }
};

void continuar(){
    int resp;

    printf(" Voce deseja realizar outra operacao?\n");
    printf(" 1 - Sim\n");
    printf(" 2 - Nao\n");
    printf(" -> ");
    scanf("%d", &resp);

    if (resp == 1) {
			system("@cls||clear");
            menu();
    } else if (resp == 2) {
            printf("\n");
            printf(" Finalizando o programa...\n");
			printf(" Até mais!\n");
    } else {
            printf(" Opção inválida!\n");
            continuar();
    }
};

void lista_cadastro(){
    int i=1;

    if (id==0) {
        printf(" Memória vazia!\n");
        continuar();
    } else {
            printf("\n");
            printf(" =======--- Lista de Clientes ---======= \n");
        while (i <= id){
            printf(" Código: %i\n", i);
            printf(" Nome: %s", cadastro[i].nome);
            printf(" Telefone: %s", cadastro[i].telefone);
            printf(" Email: %s", cadastro[i].email);
            printf(" \n --------------------------------------- \n");
            printf("\n");
            i++;
	    }
    continuar();
    }
};

int main() {
    setlocale(LC_ALL, "Portuguese");

    menu();
    return 0;
}

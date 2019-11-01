#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define SIZE 50
#define MAX_STRING 50

typedef struct Aluno {

    char nome[MAX_STRING],cpf[36];
    int id,dia,mes,ano,situacao;

}TAluno;

void cadastrar(TAluno estudantes[],int posicao) {

    int ok;

    system("cls");
    do {
        printf("Entre com o nome completo:\n");
        fgets(estudantes[posicao].nome, MAX_STRING-1, stdin);
        printf("\n%s\n\n",estudantes[posicao].nome);
        printf("Seu nome está correto?\n");
        printf("1 --> Sim.\n2 --> Não.\n");
        scanf("%i",&ok);
        if(ok == 1) {
            printf("Nome cadastrado com sucesso.\n");
        }
        else {
            printf("\n\nTente novamente.\n\n");
        }
    }while(ok!=1);
    ok=0;
    do {
        printf("Entre com seu CPF(apenas números):\n");
        fgets(estudantes[posicao].cpf, MAX_STRING-1, stdin);
        printf("\n%s\n\n",estudantes[posicao].cpf);
        if((strlen(estudantes[posicao].cpf)) != 11) {
            printf("CPF inválido!\n");
        }
        else {
            printf("CPF cadastrado com sucesso.\n");
        }
    }while(ok!=1);
    printf("Entre com a sua data de nascimento:\n");
    do {
        printf("Entre com o dia:\n");
        scanf("%i", &estudantes[posicao].dia);
        if((estudantes[posicao].dia > 31) || (estudantes[posicao].dia < 1)) {
            printf("Dia inválido!");
        }
        else {
            ok = 1;
        }
    }while(ok!=1);
    ok=0;
    do {
        printf("Entre com o mes:\n");
        scanf("%i", &estudantes[posicao].mes);
        if((estudantes[posicao].mes > 12) || (estudantes[posicao].mes < 1)) {
            printf("Mês inválido!");
        }
        else {
            ok = 1;
        }
    }while(ok!=1);
    do {
        printf("Entre com o mes:\n");
        scanf("%i", &estudantes[posicao].mes);
        if((estudantes[posicao].mes > 12) || (estudantes[posicao].mes < 1)) {
            printf("Mês inválido!");
        }
        else {
            ok = 1;
        }
    }while(ok!=1);
    ok=0;
    do {
        printf("Entre com o ano:\n");
        scanf("%i", &estudantes[posicao].ano);
        if(estudantes[posicao].ano < 1) {
            printf("Ano inválido!");
        }
        else {
            ok = 1;
        }
    }while(ok!=1);
    printf("Data de nascimento cadastrada com sucesso.\n");
    estudantes[posicao].id = posicao;
    estudantes[posicao].situacao = 1;
}

int listar() {



}

void imprime_vetor(TAluno estudantes[], int posicao) {
    int i;
    for (i=0; i<1; i++) {
        printf("\nDados da pessoa %d:\n", i+1);
        printf("nome = %s", estudantes[0].nome);
    }
}

int main() {

    setlocale(LC_ALL, "Portuguese");
    TAluno estudantes[SIZE];
    int opcao,ponteiro=0;

    printf("\n\n\nCadastro de pessoas.\n\n\n");
    do {
        printf("\n1 --> Cadastrar.\n");
        printf("\n2 --> Listar.\n");
        printf("\n3 --> Pesquisar.\n");
        printf("\n4 --> Atualizar.\n");
        printf("\n5 --> Remover.\n");
        printf("\n6 --> Sair.\n");
        scanf("%i",&opcao);
        switch(opcao) {

            case 1:
                cadastrar(estudantes,ponteiro);
                ponteiro++;
            break;

            case 2:

            break;

            case 3:

            break;

            case 4:

            break;

            case 5:

            break;

            case 6:
                printf("\n\n\nEncerrando...\n\n\n");
            break;

            default:
                printf("Opção inválida!");

        }
    }
    while(opcao!=6);

    return 0;
}

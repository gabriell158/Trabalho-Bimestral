#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
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
        fgets(estudantes[posicao].nome, MAX_STRING-1, stdin);
        printf("\nNome: %s\n\n",estudantes[posicao].nome);
        printf("Seu nome está correto?\n");
        printf("1 --> Sim.\n2 --> Não.\n");
        scanf("%i",&ok);
        if(ok == 1) {
            printf("Nome cadastrado com sucesso.\n\n");
        }
        else {
            printf("\n\nTente novamente.\n\n");
        }
    }while(ok!=1);
    ok=0;
    do {
        printf("Entre com seu CPF:\n");
        fgets(estudantes[posicao].cpf, MAX_STRING-1, stdin);
        fgets(estudantes[posicao].cpf, MAX_STRING-1, stdin);
        printf("\nCPF: %s\n\n",estudantes[posicao].cpf);
        printf("Seu CPF está correto?\n");
        printf("1 --> Sim.\n2 --> Não.\n");
        scanf("%i",&ok);
        if(ok == 1) {
            printf("CPF cadastrado com sucesso.\n\n");
        }
        else {
            printf("\n\nTente novamente.\n\n");
        }
    }while(ok!=1);
    printf("Entre com a sua data de nascimento.\n\n");
    ok=0;
    do {
        printf("Entre com o dia:\n");
        scanf("%i", &estudantes[posicao].dia);
        if((estudantes[posicao].dia > 31) || (estudantes[posicao].dia < 1)) {
            printf("Dia inválido!\n");
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
            printf("Mês inválido!\n");
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
            printf("Ano inválido!\n");
        }
        else {
            ok = 1;
        }
    }while(ok!=1);
    printf("Data de nascimento cadastrada com sucesso.\n");
    estudantes[posicao].id = posicao;
    estudantes[posicao].situacao = 1;
    printf("Cadastro finalizado.\n\n");
    printf("Nome: %s\n",estudantes[posicao].nome);
    printf("CPF: %s\n",estudantes[posicao].cpf);
    printf("Data de nascimento: %i/%i/%i\n",estudantes[posicao].dia,estudantes[posicao].mes,estudantes[posicao].ano);
}

int listar(TAluno estudantes[],int posicao) {

    int i;

    for(i=1;i<=posicao;i++) {
        if((estudantes[i].situacao) == 1) {
            printf("ID: %i\n",estudantes[i].id);
            printf("Nome: %s\n",estudantes[i].nome);
            printf("CPF: %s\n",estudantes[i].cpf);
            printf("Data de nascimento: %i/%i/%i\n",estudantes[i].dia,estudantes[i].mes,estudantes[i].ano);
        }

    }
}

void pesquisar(TAluno estudantes[],int posicao) {

    int i;
    char busca[MAX_STRING];

    system("cls");
    printf("Digite o nome do estudante cujo cadastro deseja localizar: \n\n");
    fgets(busca,MAX_STRING-1,stdin);
    fgets(busca,MAX_STRING-1,stdin);
    for(i=1;i<=posicao;i++) {
        if((estudantes[i].situacao) == 1) {
            if(strcmp(busca,estudantes[i].nome) == 0) {
                printf("\n\nID: %i\n\n",estudantes[i].id);
                printf("Nome: %s\n",estudantes[i].nome);
                printf("CPF: %s\n",estudantes[i].cpf);
                printf("Data de nascimento: %i/%i/%i\n",estudantes[i].dia,estudantes[i].mes,estudantes[i].ano);
            }
        }
    }
}

void atualizar(TAluno estudantes[],int posicao) {

    int i,id,ok=0,existe=0;

    do {
        system("cls");
        printf("\nInforme a ID do usuário que deseja alterar: ");
        scanf("%i",&id);
        for(i=0;i<posicao;i++) {
            if(id == estudantes[i].id) {
                existe = 1;
            }
        }
        if(existe == 1) {
            cadastrar(estudantes,id);
        }
        printf("\nDeseja alterar outro cadastro?");
        printf("\n1 --> Sim.\n2 --> Não.\n");
        scanf("%i",&ok);
    }while(ok!=2);


}

void remover(TAluno estudantes[]) {

    int id;

    system("cls");
    printf("\nDigite a ID do usuário que deseja remover: ");
    scanf("%i",&id);
    estudantes[id].situacao = 0;
    printf("\nUsuário desativado.");

}

int main() {

    setlocale(LC_ALL, "Portuguese");
    TAluno estudantes[MAX_STRING];
    int opcao,ponteiro=1;

    printf("\n\n\nCadastro de pessoas.\n\n\n");
    do {
        printf("\n1 --> Cadastrar.\n");
        printf("\n2 --> Listar.\n");
        printf("\n3 --> Pesquisar.\n");
        printf("\n4 --> Atualizar.\n");
        printf("\n5 --> Remover.\n");
        printf("\n6 --> Sair.\n\n\n");
        scanf("%i",&opcao);
        switch(opcao) {

            case 1:
                if(ponteiro >50) {
                    printf("\nLimite de cadastros atingidos! Não é mais possível cadastrar.");
                }
                else {
                    cadastrar(estudantes,ponteiro);
                    ponteiro++;
                }
            break;

            case 2:
                listar(estudantes,ponteiro);
            break;

            case 3:
                pesquisar(estudantes,ponteiro);
            break;

            case 4:
                atualizar(estudantes,ponteiro);
            break;

            case 5:
                remover(estudantes);
            break;

            case 6:
                printf("\n\n\nEncerrando...\n\n\n");
            break;

            default:
                printf("\nOpção inválida!");

        }
    }
    while(opcao!=6);

    return 0;
}

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

    int ok,onze;

    system("cls");
    do {
        printf("\nEntre com o nome completo:\n");
        fgets(estudantes[posicao].nome, MAX_STRING-1, stdin);
        fgets(estudantes[posicao].nome, MAX_STRING-1, stdin);
        printf("\n\nNome: %s\n\n",estudantes[posicao].nome);
        printf("\nSeu nome está correto?");
        printf("\n1 --> Sim.\n2 --> Não.\n");
        scanf("%i",&ok);
        if(ok == 1) {
            printf("\nNome cadastrado com sucesso.");
        }
        else {
            printf("\nTente novamente.");
        }
    }while(ok!=1);
    ok=0;
    do {
        printf("\nEntre com seu CPF(apenas números):\n");
        fgets(estudantes[posicao].cpf, MAX_STRING-1, stdin);
        fgets(estudantes[posicao].cpf, MAX_STRING-1, stdin);
        onze = strlen(estudantes[posicao].cpf);
        if(onze != 12) {
            printf("CPF inválido!");
        }
        else {
            printf("\nCPF: %c%c%c.%c%c%c.%c%c%c-%c%c\n",estudantes[posicao].cpf[0],estudantes[posicao].cpf[1],estudantes[posicao].cpf[2],
            estudantes[posicao].cpf[3],estudantes[posicao].cpf[4],estudantes[posicao].cpf[5],estudantes[posicao].cpf[6],
            estudantes[posicao].cpf[7],estudantes[posicao].cpf[8],estudantes[posicao].cpf[9],estudantes[posicao].cpf[10]);
            printf("\nSeu CPF está correto?");
            printf("\n1 --> Sim.\n2 --> Não.\n");
            scanf("%i",&ok);
            if(ok == 1) {
                printf("\nCPF cadastrado com sucesso.");
            }
            else {
                printf("\nTente novamente.");
            }
        }

    }while(ok!=1);
    printf("\nEntre com a sua data de nascimento.");
    ok=0;
    do {
        printf("\nEntre com o dia:\n");
        scanf("%i", &estudantes[posicao].dia);
        if((estudantes[posicao].dia > 31) || (estudantes[posicao].dia < 1)) {
            printf("\nDia inválido!");
        }
        else {
            ok = 1;
        }
    }while(ok!=1);
    ok=0;
    do {
        printf("\nEntre com o mes:\n");
        scanf("%i", &estudantes[posicao].mes);
        if((estudantes[posicao].mes > 12) || (estudantes[posicao].mes < 1)) {
            printf("\nMês inválido!");
        }
        else {
            ok = 1;
        }
    }while(ok!=1);
    ok=0;
    do {
        printf("\nEntre com o ano:\n");
        scanf("%i", &estudantes[posicao].ano);
        if(estudantes[posicao].ano < 1) {
            printf("\nAno inválido!");
        }
        else {
            ok = 1;
        }
    }while(ok!=1);
    printf("\nData de nascimento cadastrada com sucesso.");
    estudantes[posicao].id = posicao;
    estudantes[posicao].situacao = 1;
    printf("\nCadastro finalizado.");
    printf("\nNome: %s",estudantes[posicao].nome);
    printf("\nCPF: %c%c%c.%c%c%c.%c%c%c-%c%c\n",estudantes[posicao].cpf[0],estudantes[posicao].cpf[1],estudantes[posicao].cpf[2],
    estudantes[posicao].cpf[3],estudantes[posicao].cpf[4],estudantes[posicao].cpf[5],estudantes[posicao].cpf[6],
    estudantes[posicao].cpf[7],estudantes[posicao].cpf[8],estudantes[posicao].cpf[9],estudantes[posicao].cpf[10]);
    printf("\nData de nascimento: %i/%i/%i",estudantes[posicao].dia,estudantes[posicao].mes,estudantes[posicao].ano);
}

int listar(TAluno estudantes[],int posicao) {

    int i;

    for(i=1;i<=posicao;i++) {
        if((estudantes[i].situacao) == 1) {
            printf("\nID: %i",estudantes[i].id);
            printf("\nNome: %s",estudantes[i].nome);
            printf("\nCPF: %c%c%c.%c%c%c.%c%c%c-%c%c\n",estudantes[i].cpf[0],estudantes[i].cpf[1],estudantes[i].cpf[2],
            estudantes[i].cpf[3],estudantes[i].cpf[4],estudantes[i].cpf[5],estudantes[i].cpf[6],
            estudantes[i].cpf[7],estudantes[i].cpf[8],estudantes[i].cpf[9],estudantes[i].cpf[10]);
            printf("\nData de nascimento: %i/%i/%i",estudantes[i].dia,estudantes[i].mes,estudantes[i].ano);
        }
    }
}

void pesquisar(TAluno estudantes[],int posicao) {

    int i,existe=0,ok=0;
    char busca[MAX_STRING];

    do {
        system("cls");
        printf("\nDigite o nome do estudante cujo cadastro deseja localizar: \n\n");
        fgets(busca,MAX_STRING-1,stdin);
        fgets(busca,MAX_STRING-1,stdin);
        for(i=1;i<=posicao;i++) {
            if((estudantes[i].situacao) == 1) {
                if(strcmp(busca,estudantes[i].nome) == 0) {
                    printf("\n\nID: %i\n\n",estudantes[i].id);
                    printf("\nNome: %s",estudantes[i].nome);
                    printf("\nCPF: %c%c%c.%c%c%c.%c%c%c-%c%c\n",estudantes[i].cpf[0],estudantes[i].cpf[1],estudantes[i].cpf[2],
                    estudantes[i].cpf[3],estudantes[i].cpf[4],estudantes[i].cpf[5],estudantes[i].cpf[6],
                    estudantes[i].cpf[7],estudantes[i].cpf[8],estudantes[i].cpf[9],estudantes[i].cpf[10]);
                    printf("\nData de nascimento: %i/%i/%i",estudantes[i].dia,estudantes[i].mes,estudantes[i].ano);
                    existe = 1;
                }
            }
        }
        if(existe == 0) {
            printf("\nUsuário não encontrado.");
        }
            printf("\nDeseja pesquisar novamente?");
            printf("\n1 --> Não.\n2 --> Sim.\n");
            scanf("%i",&ok);
    }while(ok!=1);

}

void atualizar(TAluno estudantes[],int posicao) {

    int i,id,ok=0,existe=0;

    do {
        system("cls");
        printf("\nInforme a ID do usuário que deseja alterar: \n");
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
    printf("\nDigite a ID do usuário que deseja remover: \n\n");
    scanf("%i",&id);
    estudantes[id].situacao = 0;
    printf("\n\nUsuário desativado.");

}

int main() {

    setlocale(LC_ALL, "Portuguese");
    TAluno estudantes[MAX_STRING];
    int opcao,ponteiro=1;

    printf("\n\n\nCadastro de pessoas.\n\n\n");
    do {
        printf("\n1 --> Cadastrar.");
        printf("\n2 --> Listar.");
        printf("\n3 --> Pesquisar.");
        printf("\n4 --> Atualizar.");
        printf("\n5 --> Remover.");
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

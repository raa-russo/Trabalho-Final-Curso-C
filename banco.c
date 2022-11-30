#include <stdio.h>
#include <stdlib.h>
#include "banco.h"
#include <string.h>


struct conta {
    int numero, especial;
    float saldo;
    char cliente[51];
};

void inicializar(p_conta pConta[], int tamanho){
    for(int i=0; i<tamanho; i++){
        pConta[i] = NULL;
    }
}

void inserir(p_conta p_Conta[], int posicao) {

    //reservar 1 (um) espaco na memoria para uma conta
    p_Conta[posicao] = (p_conta) malloc(sizeof(struct conta));

    p_Conta[posicao]->numero = posicao+1;

    fflush(stdin);
    printf("Digite o nome do cliente: ");
    gets(p_Conta[posicao]->cliente);

    fflush(stdin);
    while(1) {
        printf("\nSe for cliente especial, digite (1), senao (0): ");
        scanf("%i", &p_Conta[posicao]->especial);

        if (p_Conta[posicao]->especial == 0 || p_Conta[posicao]->especial == 1) break;

        printf("\nValor invalido, digite (1) para especial e (0) para regular.\n\n");
    };

    p_Conta[posicao]->saldo = 0.;

    puts("\nCliente inserido com sucesso.\n");

}

void listar(p_conta pConta[], int tamanho) {

    //passar pelo vetor, listando cada item pelo ponteiro
    for(int i=0; i<tamanho; i++) {
        printf("\n");
        printf("Numero da conta: %d\n", pConta[i]->numero);
        printf("Cliente: %s\n", pConta[i]->cliente);
        if (pConta[i]->especial == 1) {
            printf("Status: cliente especial\n");
        } else {
            printf("Status: cliente regular\n");
        }
        printf("Saldo: %.2lf\n", pConta[i]->saldo);
    }
}

void imprimir(p_conta pConta[], int tamanho) {
    int conta_procurada;
    printf("Digite o numero da conta: ");
    scanf("%d", &conta_procurada);
    int flag_encontrado = 0;

    //passar pelo vetor, listando cada item pelo ponteiro
    for(int i=0; i<tamanho; i++) {

        if(conta_procurada == pConta[i]->numero) {
            printf("\n");
            printf("Numero da conta: %d\n", pConta[i]->numero);
            printf("Cliente: %s\n", pConta[i]->cliente);
            if (pConta[i]->especial == 1) {
                printf("Status: cliente especial\n");
            } else {
                printf("Status: cliente regular\n");
            }
            printf("Saldo: %.2lf\n", pConta[i]->saldo);
            flag_encontrado = 1;
            break;
        }
    }
    if(flag_encontrado == 0) {
        printf("Numero de conta nao encontrado.\n");
    }
}

void depositar(p_conta pConta[], int tamanho) {
    int conta_procurada;
    printf("Digite o numero da conta: ");
    scanf("%d", &conta_procurada);
    int flag_encontrado = 0;
    float valor_deposito;

    //passar pelo vetor, listando cada item pelo ponteiro
    for(int i=0; i<tamanho; i++) {

        if(conta_procurada == pConta[i]->numero) {
            printf("\n");
            printf("Digite o valor a ser depositado: ");
            scanf("%f", &valor_deposito);

            pConta[i]->saldo += valor_deposito;
            flag_encontrado = 1;
            printf("\nDeposito realizado com sucesso.\n");
            break;
        }
    }

    if(flag_encontrado == 0) {
        printf("Numero de conta nao encontrado.\n");
    }
}

void sacar(p_conta pConta[], int tamanho) {
    int conta_procurada;
    printf("Digite o numero da conta: ");
    scanf("%d", &conta_procurada);
    int flag_encontrado = 0;
    float valor_saque;

    //passar pelo vetor, listando cada item pelo ponteiro
    for(int i=0; i<tamanho; i++) {

        if(conta_procurada == pConta[i]->numero) {

            printf("\n");
            printf("Digite o valor do saque: ");
            scanf("%f", &valor_saque);

            if (pConta[i]->saldo >= valor_saque) {
                pConta[i]->saldo -= valor_saque;
                printf("\nSaque realizado com sucesso.\n");
            } else {
                printf("\nSaldo insuficiente.\n");
            }

            flag_encontrado = 1;
            break;
        }
    }

    if(flag_encontrado == 0) {
        printf("Numero de conta nao encontrado.\n");
    }
}

void saldoGeral(p_conta pConta[], int tamanho) {

    float soma = 0;
    //passar pelo vetor, listando cada item pelo ponteiro
    for(int i=0; i<tamanho; i++) {
        soma += pConta[i]->saldo;
    }
    printf("O saldo total de todas as contas cadastradas e %.2f reais\n\n", soma);

}

void alterar(p_conta pConta[], int tamanho) {
    int conta_procurada;
    printf("Digite o numero da conta a ser alterada: ");
    scanf("%d", &conta_procurada);
    int flag_encontrado = 0;

    //passar pelo vetor, listando cada item pelo ponteiro
    for(int i=0; i<tamanho; i++) {
        int option=0;

        if(conta_procurada == pConta[i]->numero) {

            while (option !=  5) {

                system("cls");
                printf("Qual dado sera alterado?\n");
                printf("1. Numero da conta\n");
                printf("2. Nome do cliente\n");
                printf("3. Status do cliente\n");
                printf("4. Saldo do cliente\n");
                printf("5. Voltar ao menu principal\n\n");
                printf("Digite sua opcao: ");
                scanf("%d", &option);
                printf("\n");

                switch(option) {

                    case 1:
                        printf("Digite o novo numero da conta: ");
                        scanf("%i", &pConta[i]->numero);
                        printf("\n");
                        system("pause");
                        break;

                    case 2:
                        printf("Digite o novo nome do cliente: ");
                        scanf("%s", &pConta[i]->cliente);
                        printf("\n");
                        system("pause");
                        break;

                    case 3:
                        printf("Digite o novo status da conta\n");
                        printf("(1) para cliente especial e (0) para cliente regular\n");
                        scanf("%i", &pConta[i]->especial);
                        printf("\n");
                        system("pause");
                        break;

                    case 4:
                        printf("Digite o novo saldo da conta: ");
                        scanf("%f", &pConta[i]->saldo);
                        printf("\n");
                        system("pause");
                        break;

                    case 5:
                        printf("Voltando ao menu principal.\n\n");
                        system("pause");
                        break;

                    default:
                        printf("Valor invalido.\n\n");
                        system("pause");
                }

                flag_encontrado = 1;
            }
        }
    }
    if(flag_encontrado == 0) {
        printf("Numero de conta nao encontrado.\n");
        system("pause");
    }
}

void procurar(p_conta pConta[], int tamanho) {
    int conta_procurada;
    printf("Digite o numero da conta: ");
    scanf("%d", &conta_procurada);
    int flag_encontrado = 0;

    //passar pelo vetor, listando cada item pelo ponteiro
    for(int i=0; i<tamanho; i++) {

        if(conta_procurada == pConta[i]->numero) {
            printf("\n");
            printf("A conta foi encontrada na posicao %d do vetor\n\n", i);
            flag_encontrado = 1;
            break;
        }
    }
    if(flag_encontrado == 0) {
        printf("Numero de conta nao encontrado.\n");
    }
}
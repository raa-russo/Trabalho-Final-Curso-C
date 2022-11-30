#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"
#define MAX 1000

int main() {
    p_conta vtrContas[MAX];

    //indica posicao (quantidade)
    int p = 0;

    inicializar(vtrContas, MAX);

    // Mostrar menu de opcoes
    int opcao = 0;

    while(opcao != 9) {

        system("cls");
        printf("Gerenciador de contas \n");
        printf("1. Inserir conta\n");
        printf("2. Alterar conta\n");
        printf("3. Procurar conta\n");
        printf("4. Listar contas\n");
        printf("5. Depositar\n");
        printf("6. Sacar\n");
        printf("7. Imprimir conta\n");
        printf("8. Mostrar saldo geral\n");
        printf("9. Sair\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        switch(opcao) {

            case 1:
                inserir(vtrContas, p);
                p++;
                system("pause");
                break;

            case 2:
                alterar(vtrContas, p);
                break;

            case 3:
                procurar(vtrContas, p);
                system("pause");
                break;

            case 4:
                listar(vtrContas, p);
                printf("\n");
                system("pause");
                break;

            case 5:
                depositar(vtrContas, p);
                printf("\n");
                system("pause");
                break;

            case 6:
                sacar(vtrContas, p);
                printf("\n");
                system("pause");
                break;

            case 7:
                imprimir(vtrContas, p);
                printf("\n");
                system("pause");
                break;

            case 8:
                saldoGeral(vtrContas, p);
                system("pause");
                break;

            case 9:
                printf("Fim do programa\n\n");
                system("pause");
                break;

            default:
                printf("Valor invalido.\n");
                system("pause");
        }
    }
    return 0;
}
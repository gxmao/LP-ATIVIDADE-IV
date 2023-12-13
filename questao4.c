#include <stdio.h>
#include <stdlib.h>


struct ContaBancaria {
    int numeroConta;
    char nomeTitular[50];
    float saldo;
    char tipoConta[20]; 
};


void depositar(struct ContaBancaria *conta, float valor) {
    if (valor > 0) {
        conta->saldo += valor;
        printf("Depósito de R$%.2f realizado com sucesso.\n", valor);
    } else {
        printf("Valor inválido para depósito.\n");
    }
}


void sacar(struct ContaBancaria *conta, float valor) {
    if (valor > 0 && valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque de R$%.2f realizado com sucesso.\n", valor);
    } else {
        printf("Saldo insuficiente ou valor inválido para saque.\n");
    }
}


void imprimirSaldo(struct ContaBancaria conta) {
    printf("Saldo atual da conta: R$%.2f\n", conta.saldo);
}

int main() {
    struct ContaBancaria conta;

   
    printf("Informe o número da conta: ");
    scanf("%d", &conta.numeroConta);

    printf("Informe o nome do titular da conta: ");
    scanf("%s", conta.nomeTitular);

    printf("Informe o tipo de conta (poupança ou corrente): ");
    scanf("%s", conta.tipoConta);

    conta.saldo = 0.0; 

    int opcao;
    float valor;

    
    do {
        printf("\nMenu:\n");
        printf("1 - Depositar dinheiro\n");
        printf("2 - Sacar dinheiro\n");
        printf("3 - Imprimir saldo\n");
        printf("4 - Sair\n");
        printf("Escolha a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe o valor para depósito: ");
                scanf("%f", &valor);
                depositar(&conta, valor);
                break;
            case 2:
                printf("Informe o valor para saque: ");
                scanf("%f", &valor);
                sacar(&conta, valor);
                break;
            case 3:
                imprimirSaldo(conta);
                break;
            case 4:
                printf("Saindo do programa. Até mais!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
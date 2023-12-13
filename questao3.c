#include <stdio.h>
#include <stdlib.h>


struct Produto {
    char nome[50];
    float preco;
    int quantidadeEstoque;
};


float calcularValorTotal(struct Produto produto) {
    return produto.preco * produto.quantidadeEstoque;
}


void realizarCompra(struct Produto *produto) {
    int quantidadeComprada;

    printf("Informe a quantidade a ser comprada: ");
    scanf("%d", &quantidadeComprada);

    if (quantidadeComprada > 0) {
        produto->quantidadeEstoque += quantidadeComprada;
        printf("Compra realizada com sucesso!\n");
    } else {
        printf("Quantidade inválida. A compra não foi realizada.\n");
    }
}


void consultarEstoque(struct Produto produto) {
    printf("Nome do produto: %s\n", produto.nome);
    printf("Preço unitário: R$%.2f\n", produto.preco);
    printf("Quantidade em estoque: %d\n", produto.quantidadeEstoque);
    printf("Valor total em estoque: R$%.2f\n", calcularValorTotal(produto));
}

int main() {
    struct Produto produto;

    
    printf("Informe o nome do produto: ");
    scanf("%s", produto.nome);

    printf("Informe o preço unitário do produto: ");
    scanf("%f", &produto.preco);

    printf("Informe a quantidade em estoque do produto: ");
    scanf("%d", &produto.quantidadeEstoque);

    int opcao;

    
    do {
        printf("\nMenu:\n");
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa\n");
        printf("Escolha a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                realizarCompra(&produto);
                break;
            case 2:
                consultarEstoque(produto);
                break;
            case 3:
                printf("Saindo do programa. Até mais!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
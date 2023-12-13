#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 3
#define MAX_NOME 50
#define MAX_TELEFONE 15
#define MAX_EMAIL 50


struct Contato {
    char nome[MAX_NOME];
    char telefone[MAX_TELEFONE];
    char email[MAX_EMAIL];
};


char* buscarTelefone(struct Contato contatos[], int numContatos, const char* nome) {
    for (int i = 0; i < numContatos; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            return contatos[i].telefone;
        }
    }
    return NULL; 
}

int main() {
    struct Contato contatos[MAX_CONTATOS];

    
    for (int i = 0; i < MAX_CONTATOS; i++) {
        printf("Informe o nome do contato %d: ", i + 1);
        scanf("%s", contatos[i].nome);

        printf("Informe o número de telefone do contato %d: ", i + 1);
        scanf("%s", contatos[i].telefone);

        printf("Informe o email do contato %d: ", i + 1);
        scanf("%s", contatos[i].email);
    }

    
    char nomeBusca[MAX_NOME];
    printf("\nInforme o nome do contato para buscar o número de telefone: ");
    scanf("%s", nomeBusca);

    char* telefoneEncontrado = buscarTelefone(contatos, MAX_CONTATOS, nomeBusca);

    if (telefoneEncontrado != NULL) {
        printf("O número de telefone de %s é: %s\n", nomeBusca, telefoneEncontrado);
    } else {
        printf("Contato não encontrado.\n");
    }

    return 0;
}
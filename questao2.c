#include <stdio.h>
#include <string.h>

#define MAX_NOME 50


struct Aluno {
    char nome[MAX_NOME];
    char dataNascimento[11]; 
    float nota1;
    float nota2;
    float media;
};


float calcularMedia(struct Aluno aluno) {
    return (aluno.nota1 + aluno.nota2) / 2.0;
}


void verificarAprovacao(struct Aluno aluno) {
    if (aluno.media >= 7.0) {
        printf("%s está APROVADO!\n", aluno.nome);
    } else {
        printf("%s está REPROVADO!\n", aluno.nome);
    }
}

int main() {
    struct Aluno alunos[5];

   
    for (int i = 0; i < 5; i++) {
        printf("Informe o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);

        printf("Informe a data de nascimento do aluno %d (dd/mm/aaaa): ", i + 1);
        scanf("%s", alunos[i].dataNascimento);

        printf("Informe a nota 1 do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota1);

        printf("Informe a nota 2 do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota2);

       
        alunos[i].media = calcularMedia(alunos[i]);
    }

    
    printf("\nMédia de cada aluno:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: %.2f\n", alunos[i].nome, alunos[i].media);
    }

    
    printf("\nSituação de cada aluno:\n");
    for (int i = 0; i < 5; i++) {
        verificarAprovacao(alunos[i]);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;
    char endereco[100];
} Cadastro;

Cadastro* criarCadastro(int N) {
    Cadastro* vetor = (Cadastro*) malloc(N * sizeof(Cadastro));
    if (vetor == NULL) {
        printf("Erro: nao foi possivel alocar memoria.\n");
        exit(1);
    }
    for (int i = 0; i < N; i++) {
        printf("Digite o nome da pessoa %d: ", i+1);
        scanf("%s", vetor[i].nome); 
        printf("Digite a idade da pessoa %d: ", i+1);
        scanf("%d", &vetor[i].idade);
        printf("Digite o endereco da pessoa %d: ", i+1);
        scanf("%s", vetor[i].endereco); 
        getchar();
    }
    return vetor;
}

int main() {
    int N;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);
    Cadastro* vetor_cadastros = criarCadastro(N);
    printf("\n-- DADOS --\n\n");
    for(int i = 0; i < N; i++){
        printf("Pessoa %d:\nNome: %s\nIdade: %d\nEndereco: %s\n\n", i+1, vetor_cadastros[i].nome, vetor_cadastros[i].idade, vetor_cadastros[i].endereco);
    }
    free(vetor_cadastros);
    return 0;
}

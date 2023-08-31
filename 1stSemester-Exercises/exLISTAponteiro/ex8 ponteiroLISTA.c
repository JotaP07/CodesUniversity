#include <stdio.h>

void parametros(int *vetor, int *valor, int *tamanho_vetor);

int main() {
    int vetor[30];
    int valor;
    int tamanho_vetor;

    parametros(vetor, &valor, &tamanho_vetor);

    for (int i = 0; i < tamanho_vetor; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}

void parametros(int *vetor, int *valor, int *tamanho_vetor) {
    printf("digite um tamanho pro vetor: ");
    scanf("%d", tamanho_vetor);
    printf("digite o valor que sera preenchido: ");
    scanf("%d", valor);

    int tamanho_vetor_aux = *tamanho_vetor;
    while (tamanho_vetor_aux--) {
        *vetor = *valor;
        vetor++;
    }
}

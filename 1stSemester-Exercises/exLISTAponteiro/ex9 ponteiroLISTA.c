#include <stdio.h>

void imprime_vetor(int *vetor, int tamanho);


int main() {
    int vetor[5] = {22, 22, 22, 22, 22};

    imprime_vetor(vetor, 5 /*tamanho do vetor*/ );

    return 0;
}

void imprime_vetor(int *vetor, int tamanho) {
    int *pontey = vetor;

    while (pontey < vetor + tamanho) {
        printf("%d ", *pontey);
        pontey++;
    }
}

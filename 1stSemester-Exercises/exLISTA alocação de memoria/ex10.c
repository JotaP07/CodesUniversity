#include <stdio.h>
#include <stdlib.h>

int* alocar_e_preencher_vetor(int N, int valor) {
    if (N <= 0) {
        return NULL;
    }
   
    int* vetor = (int*) malloc(N * sizeof(int));
    if (vetor == NULL) {
        return NULL;
    }
   
    for (int i = 0; i < N; i++) {
        vetor[i] = valor;
    }
   
    return vetor;
}

int main() {
    int N = 5;
    int valor = 10;
   
    int* vetor = alocar_e_preencher_vetor(N, valor);
    if (vetor == NULL) {
        printf("Erro: não foi possível alocar o vetor.\n");
        return 1;
    }
   
    printf("Vetor alocado e preenchido:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
   
    free(vetor);
   
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int* arrayPOSITIVA(int N) {
    if (N <= 0) {
        return NULL;
    }
    int* arr = (int*) malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        return NULL;
    }
    for (int i = 0; i < N; i++) {
        arr[i] = 0;
    }
    return arr;
}

int main() {
    int N = 8;
    int* arr = arrayPOSITIVA(N);
    if (arr == NULL) {
        printf("Erro: Valor de N inválido.\n");
        return 1;
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
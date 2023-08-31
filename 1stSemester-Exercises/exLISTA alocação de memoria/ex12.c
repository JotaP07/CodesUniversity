
JotaPe - <john.canhete@gmail.com>
01:50 (há 5 horas)
para joaopcanhete

#include <stdio.h>
#include <stdlib.h>

int** alocar_matriz_diagonal_secundaria(int N) {
    if (N <= 0) {
        return NULL;
    }
   
    int** matriz = (int**) malloc(N * sizeof(int*));
    if (matriz == NULL) {
        return NULL;
    }
   
    for (int i = 0; i < N; i++) {
        matriz[i] = (int*) malloc(N * sizeof(int));
        if (matriz[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz);
            return NULL;
        }
       
        for (int j = 0; j < N; j++) {
            if (i + j == N - 1) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
   
    return matriz;
}

int main() {
    int N = 5;
   
    int** matriz = alocar_matriz_diagonal_secundaria(N);
    if (matriz == NULL) {
        printf("Erro: não foi possível alocar a matriz.\n");
        return 1;
    }
   
    printf("Matriz alocada e preenchida:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
   
    for (int i = 0; i < N; i++) {
        free(matriz[i]);
    }
    free(matriz);
   
    return 0;
}
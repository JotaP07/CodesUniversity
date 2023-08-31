#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
   
    printf("Digite o valor de N: ");
    scanf("%d", &N);
   
    int** matriz = (int**) malloc(N * sizeof(int*));
    if (matriz == NULL) {
        printf("Erro: não foi possível alocar a matriz.\n");
        return 1;
    }
   
    for (int i = 0; i < N; i++) {
        matriz[i] = (int*) malloc(N * sizeof(int));
        if (matriz[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz);
            printf("Erro: não foi possível alocar a matriz.\n");
            return 1;
        }
       
        for (int j = 0; j < N; j++) {
            if (i == j) {
                matriz[i][j] = 0;
            } else if (i < j) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = -1;
            }
        }
    }
   
    printf("Matriz criada:\n");
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
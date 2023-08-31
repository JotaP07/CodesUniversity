#include <stdio.h>
#include <stdlib.h>

int* arrayy(int N);

int main() {
    int N = 10;
    int* arr = arrayy(N);
    if (arr == NULL) {
        return 1;
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}

int* arrayy(int N) {
    int* arr = (int*) malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Erro na alocação de memoria.\n");
        return NULL;
    }
    for (int i = 0; i < N; i++) {
        arr[i] = i;
        }
    return arr;
}
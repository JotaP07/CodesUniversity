#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    do {
        printf("Digite o valor de N (deve ser maior ou igual a 0): ");
        scanf("%d", &n);
    } while (n < 0);
    if(n == 0){
        printf("Valor igual a 0, nao ha valores para atribuir.");
        return 1;
       
    }
    int *v = (int*) malloc(n * sizeof(int));
    if (v == NULL) {
        printf("Erro ao alocar memoria para o vetor.");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        do {
            printf("Digite um valor inteiro maior ou igual a 2 para a posicao %d: ", i+1);
            scanf("%d", &v[i]);
            getchar();
        } while (v[i] < 2);
    }

    printf("\nVetor lido: [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("]\n");

    free(v);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;
   
    printf("digite o tamanho para o vetor:\n --> ");
    scanf("%d", &tamanho);
    getchar();
   
    int* vetor = (int*) malloc(tamanho * sizeof(int));
    if (vetor == NULL){
        printf("ERRO NA ALOCACAO");
        return 1;
    }
   
    for(int i = 0; i < tamanho; i++){
        printf ("Digite um valor(numero inteiro) pro vetor num%d:\n --> ", i+1);
        scanf("%d", &vetor[i]);
       
    }
   
    printf("\n\tVALORES ATRIBUIDOS AO VETOR\n");
    for (int i = 0; i < tamanho; i++) {
        printf("VETOR %d --> %d \n",i+1, vetor[i]);
    }
    printf("\n");
   
    free(vetor);
    return 0;
}
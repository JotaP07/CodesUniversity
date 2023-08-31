#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverteString(char* str) {
    if (str == NULL) {
        return NULL;
    }
    int len = strlen(str);
    char* reverte = (char*) malloc((len+1) * sizeof(char)); // alocando memória para a nova string
    if (reverte == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        return NULL;
    }
    reverte[len] = '\0'; // adicionando o caractere nulo ao final da string
    for (int i = len-1; i >= 0; i--) { // percorrendo a string original de trás para frente
        reverte[len-i-1] = str[i]; // adicionando cada caractere na nova string
    }
    return reverte;
}

int main() {
    char str[] = "Hello, world!";
    char* reverte = reverteString(str);
    printf("%s\n", reverte);
    free(reverte); // liberando a memória alocada
    return 0;
}
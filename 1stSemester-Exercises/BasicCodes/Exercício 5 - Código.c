#include <stdio.h>

int main() {
    int num1, num2, soma;

    printf("Digite o primeiro numero:  ");
    scanf("%d", &num1);

    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    soma = (num1 + num2) * (num1 + num2);

    printf("A soma dos numeros ao quadrado e: %d \n\n", soma);
    printf("            Operacao finalizada.\n           ");


    return 0;
}

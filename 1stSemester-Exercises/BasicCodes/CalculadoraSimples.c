#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char opera;
    float a, b, r;

    printf("digite o valor de A: ");
    scanf("%f", &a);
    printf("digite o valor de B: ");
    scanf("%f", &b);

    printf("\nEscolha a opçao de operação desejada\n");
    printf(" a - adição\n");
    printf(" b - subtração\n");
    printf(" c - divisão\n");
    printf(" d - multiplicação\n");

    printf("\ndigite a letra da operação que deseja: ");
    scanf(" %c", &opera);

    switch (opera)
    {
    case 'a':
        r = a + b;
        printf("CALCULO = %.2f", r);
        break;

    case 'b':
        r = a - b;
        printf("CALCULO = %.2f", r);
        break;

    case 'c':
        r = a / b;
        printf("CALCULO = %.2f", r);
        break;

    case 'd':
        r = a * b;
        printf("CALCULO = %.2f", r);
        break;

    default:
        printf("Letra Inválida");
    }

    printf("\n\n\tPrograma Finalizado\n\n");

    return 0;
}
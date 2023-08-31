#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char frase[] = "Engenharia de Software 2022";

    // imprime o caractere que está na 5ª posição
    printf("Caractere da 5ª posicao: %c\n", frase[4]);

    // imprime o caractere que está na 3ª posição
    printf("Caractere da 3ª posicao: %c\n", frase[2]);

    return 0;
}

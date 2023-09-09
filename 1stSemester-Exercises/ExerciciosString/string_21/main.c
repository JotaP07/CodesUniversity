#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char frase[] = "Engenharia de Software 2022";
 
    // imprime o caractere que est� na 5� posi��o
    printf("Caractere da 5� posicao: %c\n", frase[4]);

    // imprime o caractere que est� na 3� posi��o
    printf("Caractere da 3� posicao: %c\n", frase[2]);

    return 0;
}

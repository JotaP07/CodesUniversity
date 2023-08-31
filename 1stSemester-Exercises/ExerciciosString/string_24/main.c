#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_LEN 25

int main()
{

    setlocale(LC_ALL, "Portuguese");

    char palavra[MAX_LEN+1];
    int i, j, len, palindromo;

    printf("Digite uma palavra ou frase de até %d letras: ", MAX_LEN);
    fgets(palavra, MAX_LEN+1, stdin);

    // Remover o caractere '\n' da entrada lida pelo fgets
    len = strlen(palavra);
    if (palavra[len-1] == '\n')
    {
        palavra[len-1] = '\0';
        len--;
    }

    palindromo = 1;

    for (i = 0, j = len-1; i < j; i++, j--)
    {
        if (palavra[i] != palavra[j])
        {
            palindromo = 0;
            break;
        }
    }
    if (palindromo)
    {
        printf("A palavra/frase \"%s\" é um palíndromo!\n", palavra);
    }
    else
    {
        printf("A palavra/frase \"%s\" não é um palíndromo.\n", palavra);
    }
    return 0;
}

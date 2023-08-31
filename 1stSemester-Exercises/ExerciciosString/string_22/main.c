#include <stdio.h>
#include <locale.h>

int
main ()
{
    setlocale(LC_ALL, "Portuguese");

    char frase[100];

    printf ("Digite a frase que você gostaria de contar os caracteres: ");
    fgets (frase, 100, stdin);	// Lê a frase

    int comprimento = strlen (frase);	// calcula o comprimento da frase

    printf ("A frase tem %d caracteres.\n", comprimento);

    return 0;
}

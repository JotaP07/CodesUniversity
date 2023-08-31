#include <stdio.h>
#include <locale.h>

int main()
{

    setlocale (LC_ALL, "Portuguese");

    char frase[100];
    int i;

    printf("Digite uma frase: ");
    fgets(frase, 100, stdin);

    for(i = 0; frase[i] != '\0'; i++)
    {
        if(frase[i] == ' ')
        {
            printf("O primeiro espaço está na posição %d.\n", i);
            break;
        }
    }
    return 0;
}

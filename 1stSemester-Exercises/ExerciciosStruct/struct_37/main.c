#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    char nome[50];
    char esporte[50];
    int idade;
    float altura;
} Atleta;

int main()
{

    setlocale(LC_ALL, "Portuguese");

    Atleta atletas[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Digite os dados do atleta %d:\n", i+1);
        printf("Nome: ");
        scanf(" %[^\n]", atletas[i].nome);
        printf("Esporte: ");
        scanf(" %[^\n]", atletas[i].esporte);
        printf("Idade: ");
        scanf("%d", &atletas[i].idade);
        printf("Altura: ");
        scanf("%f", &atletas[i].altura);
        printf("\n");
    }

    Atleta mais_alto = atletas[0];
    Atleta mais_velho = atletas[0];
    for (int i = 1; i < 5; i++)
    {
        if (atletas[i].altura > mais_alto.altura)
        {
            mais_alto = atletas[i];
        }
        if (atletas[i].idade > mais_velho.idade)
        {
            mais_velho = atletas[i];
        }
    }

    printf("O atleta mais alto e: %s\n", mais_alto.nome);
    printf("O atleta mais velho e: %s\n", mais_velho.nome);

    return 0;
}

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
        printf("Digite o nome do atleta %d: ", i+1);
        scanf("%s", atletas[i].nome);
        printf("Digite o esporte do atleta %d: ", i+1);
        scanf("%s", atletas[i].esporte);
        printf("Digite a idade do atleta %d: ", i+1);
        scanf("%d", &atletas[i].idade);
        printf("Digite a altura do atleta %d: ", i+1);
        scanf("%f", &atletas[i].altura);
        printf("\n");
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = i+1; j < 5; j++)
        {
            if (atletas[i].idade < atletas[j].idade)
            {
                Atleta temp = atletas[i];
                atletas[i] = atletas[j];
                atletas[j] = temp;
            }
        }
    }

    printf("Atletas ordenados por idade (do mais velho para o mais novo):\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s, %d anos, %.2f m, pratica %s\n", atletas[i].nome, atletas[i].idade, atletas[i].altura, atletas[i].esporte);
    }

    return 0;
}

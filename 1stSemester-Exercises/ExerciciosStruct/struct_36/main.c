#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    char nome[50];
    int dia_nasc;
    int mes_nasc;
    int ano_nasc;
} Pessoa;

int main()
{

    setlocale(LC_ALL, "Portuguese");

    Pessoa pessoas[6];
    int i, mais_nova_idx, mais_velha_idx;
    int dia_atual, mes_atual, ano_atual;
    int idade_atual, mais_nova_idade = 100, mais_velha_idade = 0;

    for (i = 0; i < 6; i++)
    {
        printf("Digite o nome da pessoa %d: ", i+1);
        fgets(pessoas[i].nome, 50, stdin);
        printf("Digite a data de nascimento da pessoa %d (DD/MM/AAAA): ", i+1);
        scanf("%d/%d/%d", &pessoas[i].dia_nasc, &pessoas[i].mes_nasc, &pessoas[i].ano_nasc);
        getchar();
    }

    printf("Digite a data atual (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &dia_atual, &mes_atual, &ano_atual);
    getchar();

    for (i = 0; i < 6; i++)
    {
        idade_atual = ano_atual - pessoas[i].ano_nasc;
        if (mes_atual < pessoas[i].mes_nasc ||
                (mes_atual == pessoas[i].mes_nasc && dia_atual < pessoas[i].dia_nasc))
        {
            idade_atual--;
        }
        if (idade_atual < mais_nova_idade)
        {
            mais_nova_idade = idade_atual;
            mais_nova_idx = i;
        }
        if (idade_atual > mais_velha_idade)
        {
            mais_velha_idade = idade_atual;
            mais_velha_idx = i;
        }
    }

    printf("\nA pessoa mais nova é: %s", pessoas[mais_nova_idx].nome);
    printf("Data de nascimento: %02d/%02d/%04d\n", pessoas[mais_nova_idx].dia_nasc,
           pessoas[mais_nova_idx].mes_nasc, pessoas[mais_nova_idx].ano_nasc);
    printf("\nA pessoa mais velha é: %s", pessoas[mais_velha_idx].nome);
    printf("Data de nascimento: %02d/%02d/%04d\n", pessoas[mais_velha_idx].dia_nasc,
           pessoas[mais_velha_idx].mes_nasc, pessoas[mais_velha_idx].ano_nasc);

    return 0;
}

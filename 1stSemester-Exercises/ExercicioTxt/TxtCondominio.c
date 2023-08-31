#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//No momento estou sem o txt para realizar a leitura

struct aluno
{
    char nome[70];
    float nota[4];
    char debug[50];
    float media_calculo[4][4];
    float media[4];
};

int main(void)
{
    struct aluno aluno[100];
    float pesos[4][4];
    FILE *ponteiro_aluno = NULL;

    ponteiro_aluno = fopen("Alunos.txt", "r");

    if (ponteiro_aluno == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    int quantidade_alunos = 0;

    for (int i = 0; feof(ponteiro_aluno) == 0; i++)
    {
        char *divisor_nota;
        fgets(aluno[i].nome, 70, ponteiro_aluno);

        int n = strlen(aluno[i].nome);
        aluno[i].nome[n - 2] = '\0';

        fgets(aluno[i].debug, 50, ponteiro_aluno);

        divisor_nota = strtok(aluno[i].debug, " ");

        for (int j = 0; j < 4; j++)
        {
            float aux = atof(divisor_nota);
            aluno[i].nota[j] = aux;
            divisor_nota = strtok(NULL, " ");
        }

        quantidade_alunos = i + 1;
    }

    fclose(ponteiro_aluno);

    char *divisor_pesos;
    char aux2[20];

    ponteiro_aluno = fopen("Pesos.txt", "r");

    if (ponteiro_aluno == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    for (int op = 0; op < 4; op++)
    {
        fgets(aux2, 20, ponteiro_aluno);
        divisor_pesos = strtok(aux2, " ");

        for (int a = 0; a < 4; a++)
        {
            float aux = atof(divisor_pesos);
            pesos[op][a] = aux;
            divisor_pesos = strtok(NULL, " ");
        }
    }

    fclose(ponteiro_aluno);

    int aprovados[4] = {0};

    for (int i = 0; i < quantidade_alunos; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                aluno[i].media_calculo[j][k] = pesos[j][k] * aluno[i].nota[k];
                aluno[i].media[j] += aluno[i].media_calculo[j][k];
            }

            if (aluno[i].media[j] >= 7)
            {
                aprovados[j]++;
            }
        }
    }

    int posicao = 0;

    for (int cont = 1; cont < 4; cont++)
    {
        if (aprovados[cont] < aprovados[posicao])
        {
            posicao = cont;
        }
    }

    ponteiro_aluno = fopen("Simula.txt", "w");

    fprintf(ponteiro_aluno, "Nomes | N1 | N2 | N3 | N4 | M1 | M2 | M3 | M4 |\n");

    for (int i = 0; i < quantidade_alunos; i++)
    {
        fprintf(ponteiro_aluno, "%-2i- ", i + 1);
        fprintf(ponteiro_aluno, "%-50s", aluno[i].nome);
        fprintf(ponteiro_aluno, "\t| %4.1f | %4.1f | %4.1f | %4.1f | %4.1f | %4.1f | %4.1f | %4.1f |\n ",
                aluno[i].nota[0], aluno[i].nota[1], aluno[i].nota[2], aluno[i].nota[3],
                aluno[i].media[0], aluno[i].media[1], aluno[i].media[2], aluno[i].media[3]);
    }

    fprintf(ponteiro_aluno, "Aprovados: | %i | %i | %i | %i |", aprovados[0], aprovados[1], aprovados[2], aprovados[3]);
    fclose(ponteiro_aluno);

    ponteiro_aluno = fopen("Final.txt", "w");

    if (ponteiro_aluno == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    fputs("Relatório Final\n", ponteiro_aluno);
    fprintf(ponteiro_aluno, "Nomes | N1 | N2 | N3 | N4 | Média |\n");
    fprintf(ponteiro_aluno, " | (%.1f) | (%.1f) | (%.1f) | (%.1f) | |\n",
            pesos[posicao][0], pesos[posicao][1], pesos[posicao][2], pesos[posicao][3]);

    for (int i = 0; i < quantidade_alunos; i++)
    {
        fprintf(ponteiro_aluno, "%-2i- ", i + 1);
        fprintf(ponteiro_aluno, "%-50s", aluno[i].nome);
        fprintf(ponteiro_aluno, "\t| % .2f | % .2f | % .2f | % .2f | % .2f |\n ",
                aluno[i].media_calculo[posicao][0], aluno[i].media_calculo[posicao][1],
                aluno[i].media_calculo[posicao][2], aluno[i].media_calculo[posicao][3],
                aluno[i].media[posicao]);
    }

    fclose(ponteiro_aluno);

    return 0;
}

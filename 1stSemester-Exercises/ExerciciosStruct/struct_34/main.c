#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    int matricula;
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
} Aluno;

int main()
{

    setlocale(LC_ALL, "Portuguese");

    Aluno alunos[5];

    for(int i=0; i<5; i++)
    {
        printf("Digite os dados do aluno %d:\n", i+1);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);
        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);
        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);
        printf("Nota 3: ");
        scanf("%f", &alunos[i].nota3);
        printf("\n");
    }

    int maior_media_indice = 0;
    float maior_media = (alunos[0].nota1 + alunos[0].nota2 + alunos[0].nota3) / 3;
    for(int i=1; i<5; i++)
    {
        float media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;
        if(media > maior_media)
        {
            maior_media = media;
            maior_media_indice = i;
        }
    }

    printf("Aluno com a maior media geral:\n");
    printf("Nome: %s\n", alunos[maior_media_indice].nome);
    printf("Nota 1: %.2f\n", alunos[maior_media_indice].nota1);
    printf("Nota 2: %.2f\n", alunos[maior_media_indice].nota2);
    printf("Nota 3: %.2f\n", alunos[maior_media_indice].nota3);
    printf("Media geral: %.2f\n", maior_media);

    return 0;
}

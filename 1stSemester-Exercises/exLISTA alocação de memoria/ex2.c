#include <stdio.h>

struct Aluno{
    char nome[50];
    int CODmatricula15;
    float prova1,prova2,prova3;
};
int main()
{
    struct Aluno aluno;
    printf("Tamanho da struct Aluno %ld", sizeof(aluno));

    return 0;
}
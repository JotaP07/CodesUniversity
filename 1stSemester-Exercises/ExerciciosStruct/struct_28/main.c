#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//ESTRUTURA QUE VAI AMARZENAR OS DADOS
struct Dados
{
    char NOME[50];
    char IDADE[10];
    char ENDERECO[100];
};
int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct Dados entrada;

    //LEITURA DOS DADOS
    printf("Digite seu nome: \n");
    fgets(entrada.NOME, 50, stdin);
    printf("\n");

    printf("Digite sua idade: \n");
    fgets(entrada.IDADE, 10, stdin);
    printf("\n");

    printf("Digite seu endereco: \n");
    fgets(entrada.ENDERECO, 100, stdin);
    printf("\n");

    //IMPRESSÃO DOS DADOS
    printf("- SEUS DADOS -");
    printf("\n");
    printf("NOME: %s", entrada.NOME);
    printf("IDADE: %s", entrada.IDADE);
    printf("ENDERECO: %s", entrada.ENDERECO);
    printf("\n");

    return 0;
}

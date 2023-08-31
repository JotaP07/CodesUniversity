#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h> //usada pra busca de dados
#include <stddef.h>  //usada pra ponteiros NULL - apontam pra nada


struct Dados
{ //Pessoa

    int cod;
    char nome[20];
    char telefone[50];
    int idade;
    float altura;
};

struct No
{
    struct Dados *pessoa;
    struct No *prox; //proximo dado
};

struct Fila
{ //fila dos dados - Lista -
    struct No *primeiro;
};

struct Dados criarPessoa(int codigo, char *nome, char *telefone, int idade, float altura)
{
    //atribui as variaveis pra struct

    struct Dados pessoa;
    pessoa.cod = codigo;
    strcpy(pessoa.nome, nome);
    strcpy(pessoa.telefone, telefone);
    pessoa.idade = idade;
    pessoa.altura = altura;

    return pessoa;
}

void adicionarPessoa(struct Fila *fila, struct Dados pessoa)
{
    struct No *novoNo = (struct No *)malloc(sizeof(struct No));
    novoNo->pessoa = (struct Dados *)malloc(sizeof(struct Dados));
    *(novoNo->pessoa) = pessoa;
    novoNo->prox = NULL;

    if (fila->primeiro == NULL)
    {
        fila->primeiro = novoNo;
    }
    else
    {
        struct No *atual = fila->primeiro;
        while (atual->prox != NULL)
        {
            atual = atual->prox;
        }
        atual->prox = novoNo;
    }

    printf("Pessoa adicionada com sucesso!\n");
    ordenarFila(fila); // Ordena a fila pelo código após adicionar a pessoa
}
void ordenarFila(struct Fila *fila)
{
    if (fila->primeiro == NULL || fila->primeiro->prox == NULL)
    {
        return; // Fila vazia ou possui apenas um elemento, não precisa ordenar
    }

    struct No *atual, *aux;
    int trocou;

    do
    {
        trocou = 0;
        atual = fila->primeiro;

        while (atual->prox != NULL)
        {
            if (atual->pessoa->cod > atual->prox->pessoa->cod)
            {
                // Realiza a troca de posições dos nós
                if (atual == fila->primeiro)
                {
                    fila->primeiro = atual->prox;
                }
                else
                {
                    aux->prox = atual->prox;
                }

                atual->prox = atual->prox->prox;
                fila->primeiro->prox = atual;
                aux = fila->primeiro;

                trocou = 1;
            }
            else
            {
                aux = atual;
                atual = atual->prox;
            }
        }

    } while (trocou);
}
bool buscarPessoa(struct Fila *fila, int codigo)
{

    struct No *atual = fila->primeiro;
    //inicializa com o primeiro No(dados) da fila

    while (atual != NULL)
    {
        //percorre o ate o final da lista

        if (atual->pessoa->cod == codigo)
        {
            //se o codigo digitado for encontrado -->
            printf("Pessoa encontrada:\n");
            printf("Código: %d\n", atual->pessoa->cod);
            printf("Nome: %s\n", atual->pessoa->nome);
            printf("Telefone: %s\n", atual->pessoa->telefone);
            printf("Idade: %d\n", atual->pessoa->idade);
            printf("Altura: %.2f\n", atual->pessoa->altura);

            return true;
        }

        atual = atual->prox;
    
    }

    printf("Pessoa não encontrada!\n");
    return false; //retorna true se for encontrada
}
bool removerPessoa(struct Fila *fila, int codigo)
{

    struct No *atual = fila->primeiro;
    struct No *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->pessoa->cod == codigo)
        {
            if (anterior == NULL)
            {
                //se for nulo significa que a pessoa a ser removida é o primeiro da fila
                fila->primeiro = atual->prox;
                // aqui apontamos o ponteiro para o priximo da fila pqo anterior é nulo
            }
            else
            {
                //se ñ for nulo quer dizer q o dado a ser removido esta no meio da lista
                anterior->prox = atual->prox;
                //aqui passa o anterior para o prox dado da lista
            }

            free(atual->pessoa);
            free(atual);
            //libera

            printf("Pessoa removida com sucesso!\n");
            return true;
        }

        anterior = atual; //vai passar para o proximo no(dado) ate achar o codigo
        atual = atual->prox; //tbm - sdds do ++ -
    }

    printf("Pessoa não encontrada!\n");
    return false;
}
void SalvarTxt(struct Fila *fila)
{ //so pra relembrar

    if (fila->primeiro == NULL)
    { //caso n tenha nada de dados
        printf("Nenhum dado para salvar!\n");
        return;
    }

    FILE *arquivo;

    arquivo = fopen("dados.txt", "w");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    struct No *atual = fila->primeiro; //pega o primeiro dado da fila
    while (atual != NULL)
    {

        fprintf(arquivo, "Codigo: %d\n", atual->pessoa->cod);
        fprintf(arquivo, "Nome: %s\n", atual->pessoa->nome);
        fprintf(arquivo, "Telefone: %s\n", atual->pessoa->telefone);
        fprintf(arquivo, "Idade: %d\n", atual->pessoa->idade);
        fprintf(arquivo, "Altura: %.2f\n\n", atual->pessoa->altura);
        atual = atual->prox; //passa pra proxima pessoa
    }

    fclose(arquivo);
    printf("Dados salvos em dados.txt\n");
}
int main()
{

    int op = -1;
    struct Fila fila;
    fila.primeiro = NULL; //aponta pra nada -NULL-
    struct Dados pessoa;

    while (op != 0)
    {

        system("clear");
        printf("1. Adicionar pessoa\n");
        printf("2. Buscar pelo codigo\n");
        printf("3. Remover pessoa\n");
        printf("4. Imprimir dados de uma pessoa\n");
        printf("5. Imprimir todas as pessoas\n");
        printf("6. Salvar dados em .txt(TESTE)\n");
        printf("0. Sair\n\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &op);

        getchar();

        switch (op)
        {

        case 1:
        {

            int codigo;
            char nome[20];
            char telefone[50];
            int idade;
            float altura;

            printf("Digite o codigo: ");

            scanf("%d", &codigo);

            printf("Digite o nome: ");

            scanf("%s", nome);

            printf("Digite o telefone: ");

            scanf("%s", telefone);

            printf("Digite a idade: ");

            scanf("%d", &idade);

            printf("Digite a altura: ");

            scanf("%f", &altura);

            pessoa = criarPessoa(codigo, nome, telefone, idade, altura);

            adicionarPessoa(&fila, pessoa);

            sleep(1);

            break;
        }

        case 2:
        {

            int codigo;

            if (fila.primeiro == NULL)
            { //verifica se as lista esta vazia

                printf("A lista está vazia!\n");

                break;
            }

            printf("Digite o código da pessoa a ser buscada: ");

            scanf("%d", &codigo);

            buscarPessoa(&fila, codigo);

            sleep(1);

            break;
        }

        case 3:
        {

            int codigo;

            if (fila.primeiro == NULL)
            { //verifica se as lista esta vazia

                printf("A lista está vazia!\n");

                break;
            }

            printf("Digite o código da pessoa a ser removida: ");

            scanf("%d", &codigo);

            removerPessoa(&fila, codigo);

            sleep(1);

            break;
        }

        case 4:
        {

            int codigo;

            if (fila.primeiro == NULL)
            { //verifica se as lista esta vazia

                printf("A lista está vazia!\n");

                break;
            }

            printf("Digite o código da pessoa para imprimir seus dados: ");
            scanf("%d", &codigo);
            buscarPessoa(&fila, codigo);
            sleep(3);
            break;
        }

        case 5:
        {
            if (fila.primeiro == NULL)
            { //verifica se as lista esta vazia
                printf("A lista está vazia!\n");
                break;
            }

            struct No *atual = fila.primeiro;
            while (atual != NULL)
            {
                printf("Codigo: %d\n", atual->pessoa->cod);
                printf("Nome: %s\n", atual->pessoa->nome);
                printf("Telefone: %s\n", atual->pessoa->telefone);
                printf("Idade: %d\n", atual->pessoa->idade);
                printf("Altura: %.2f\n\n", atual->pessoa->altura);
                atual = atual->prox;
            }
            sleep(1);
            break;
        }

        case 6:
        {
            SalvarTxt(&fila);
            sleep(1);
            break;
        }
        case 0:
        {
            exit(0);
            break;
        }
        default:
            printf("Opcao inválida!\n");
            break;
        }
        printf("Pressione Enter para continuar.\n");
        getchar();
    }

    return 0;
}
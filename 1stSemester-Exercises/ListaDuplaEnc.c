#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
struct Dados
{

    int cod;

    char nome[20];

    char telefone[50];

    int idade;

    float altura;
};
struct No
{

    struct Dados pessoa;

    struct No *anterior; //para lista dupla

    struct No *proximo;
};
struct Fila
{

    struct No *primeiro;
};
struct Dados criarPessoa(int codigo, char *nome, char *telefone, int idade, float altura)
{

    struct Dados pessoa;

    pessoa.cod = codigo;

    strcpy(pessoa.nome, nome);

    strcpy(pessoa.telefone, telefone);

    pessoa.idade = idade;

    pessoa.altura = altura;

    return pessoa;
}

void ordenarFila(struct Fila *fila)
{

    if (fila->primeiro == NULL || fila->primeiro->proximo == NULL)
    {

        return; // Fila vazia ou possui apenas um elemento, não precisa ordenar
    }

    struct No *atual;

    struct No *aux;

    int trocou;

    do
    {

        trocou = 0;

        atual = fila->primeiro;

        while (atual->proximo != NULL)
        {

            if (atual->pessoa.cod > atual->proximo->pessoa.cod)
            {

                // Realiza a troca de posições dos nós

                struct No *proximo = atual->proximo;

                struct No *anterior = atual->anterior;

                if (anterior != NULL)
                {

                    anterior->proximo = proximo;
                }
                else
                {

                    fila->primeiro = proximo;
                }

                proximo->anterior = anterior;

                atual->anterior = proximo;

                atual->proximo = proximo->proximo;

                if (proximo->proximo != NULL)
                {

                    proximo->proximo->anterior = atual;
                }

                proximo->proximo = atual;

                aux = proximo;

                trocou = 1;
            }
            else
            {

                aux = atual;

                atual = atual->proximo;
            }
        }

    } while (trocou);
}

void adicionarPessoa(struct Fila *fila, struct Dados pessoa)
{

    struct No *novoNo = (struct No *)malloc(sizeof(struct No));

    novoNo->pessoa = pessoa;

    novoNo->anterior = NULL;

    novoNo->proximo = NULL;

    if (fila->primeiro == NULL)
    {

        fila->primeiro = novoNo;
    }
    else
    {

        struct No *atual = fila->primeiro;

        while (atual->proximo != NULL)
        {

            atual = atual->proximo;
        }

        atual->proximo = novoNo;

        novoNo->anterior = atual;
    }

    printf("Pessoa adicionada com sucesso!\n");

    ordenarFila(fila); // Chama a função para reordenar os dados
}

bool buscarPessoa(struct Fila *fila, int codigo)
{

    struct No *atual = fila->primeiro;

    while (atual != NULL)
    {

        if (atual->pessoa.cod == codigo)
        {

            printf("Pessoa encontrada:\n");

            printf("Código: %d\n", atual->pessoa.cod);

            printf("Nome: %s\n", atual->pessoa.nome);

            printf("Telefone: %s\n", atual->pessoa.telefone);

            printf("Idade: %d\n", atual->pessoa.idade);

            printf("Altura: %.2f\n", atual->pessoa.altura);

            return true;
        }

        atual = atual->proximo;
    }

    printf("Pessoa não encontrada!\n");

    return false;
}
bool removerPessoa(struct Fila *fila, int codigo)
{

    struct No *atual = fila->primeiro;

    while (atual != NULL)
    {

        if (atual->pessoa.cod == codigo)
        {

            if (atual->anterior == NULL)
            {

                fila->primeiro = atual->proximo;

                if (atual->proximo != NULL)
                {

                    atual->proximo->anterior = NULL; //.
                }
            }
            else
            {

                atual->anterior->proximo = atual->proximo; //.

                if (atual->proximo != NULL)
                {

                    atual->proximo->anterior = atual->anterior; //.
                }
            }

            free(atual);

            printf("Pessoa removida com sucesso!\n");

            return true;
        }

        atual = atual->proximo;
    }

    printf("Pessoa não encontrada!\n");

    return false;
}

void SalvarTxt(struct Fila *fila)
{

    if (fila->primeiro == NULL)
    {

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

    struct No *atual = fila->primeiro;

    while (atual != NULL)
    {

        fprintf(arquivo, "Codigo: %d\n", atual->pessoa.cod);

        fprintf(arquivo, "Nome: %s\n", atual->pessoa.nome);

        fprintf(arquivo, "Telefone: %s\n", atual->pessoa.telefone);

        fprintf(arquivo, "Idade: %d\n", atual->pessoa.idade);

        fprintf(arquivo, "Altura: %.2f\n\n", atual->pessoa.altura);

        atual = atual->proximo;
    }

    fclose(arquivo);
    printf("Dados salvos em dados.txt\n");
}

int validar(int opcao, int minimo, int maximo) // função diferencial, de tamanho dinâmico e recursiva. Apenas para ints!
{
    scanf("%d", &opcao);
    if (opcao<minimo || opcao> maximo)
    {
        getchar(); // evita loop infinito caso um char seja digitado
        printf("Inválido! Insira de %i até %i.\n-> ", minimo, maximo);
        return validar(opcao, minimo, maximo);
    }

    return opcao;
}

int main()
{

    int op = -1;
    struct Fila fila;
    fila.primeiro = NULL;
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

        op = validar(op, 0, 6);

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
            scanf("%*c");                     // Isso aqui é pra garantir que ele nao leia coisa errada, ele Limpa
            fgets(nome, sizeof(nome), stdin); //aceitar nomes com space
            nome[strcspn(nome, "\n")] = '\0'; // Remove o caractere de nova linha '\n'

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
                sleep(2);
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

                printf("Codigo: %d\n", atual->pessoa.cod);
                printf("Nome: %s\n", atual->pessoa.nome);
                printf("Telefone: %s\n", atual->pessoa.telefone);
                printf("Idade: %d\n", atual->pessoa.idade);
                printf("Altura: %.2f\n\n", atual->pessoa.altura);
                atual = atual->proximo;
            }
            sleep(3);
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

    }
        return 0;
}
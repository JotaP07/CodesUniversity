#include <time.h>

void menu();
void sub_menu_produtos();
void sub_menu_vendas();
int validar(int opcao, int minimo, int maximo);

void escolha_main();
void escolha_menu_produtos();
void escolha_sub_menu_vendas();
void escolha_exibir_estoque();
void voltar_para_menu();

void menu()
{
    system("clear");// limpa a tela quando executado.
    const time_t timer = time(NULL);

    printf("\n");
    printf("Padaria da Berenice. Menu principal.\n");
    printf("|-----------------|\n");
    printf("|  1   | Produtos |\n");
    printf("|  2   | Vendas   |\n");
    printf("|  3   | Sair     |\n");
    printf("|-----------------|\n");
    printf("\nGrupo13 Enterprises ltda  v2.1                      %s", ctime(&timer)); // mostra o dia, mes e horário
    printf("Digite um código para entrar em seu respectivo menu.\n-> ");

    return;
}

void sub_menu_produtos()
{
    system("clear");
    const time_t timer = time(NULL);

    printf("\n");
    printf("|---------------------------|\n");
    printf("|  1   | Exibir             |\n");
    printf("|  2   | Cadastrar          |\n");
    printf("|  3   | Atualizar          |\n");
    printf("|  4   | Excluir            |\n");
    printf("|  5   | Voltar             |\n");
    printf("|---------------------------|\n");
    printf("\nGrupo13 Enterprises ltda  v2.1                      %s", ctime(&timer)); // mostra o dia, mes e horário
    printf("Digite o código da opção que deseja realizar.\n-> ");

    return;
}

void sub_menu_vendas()
{
    const time_t timer = time(NULL);

    system("clear");
    printf("\n");
    printf("|-----------------------------|\n");
    printf("|  1   | Realizar venda       |\n");
    printf("|  2   | Relatório de Vendas  |\n");
    printf("|  3   | Voltar               |\n");
    printf("|-----------------------------|\n");
    printf("\nGrupo13 Enterprises ltda  v2.1                      %s", ctime(&timer)); // mostra o dia, mes e horário
    printf("Digite o código da opção que deseja realizar.\n-> ");

    return;
}

int validar(int opcao, int minimo, int maximo)
{
    scanf("%d",&opcao);
    if (opcao < minimo || opcao > maximo)
    {
        getchar(); // evita loop infinito caso um char seja digitado
        printf("Inválido! Insira de %i até %i.\n-> ", minimo, maximo);
        return validar(opcao, minimo, maximo);
    }
    return opcao;
}
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>"
#include <math.h>
#include <unistd.h>
#include <ctype.h>

#include "menu.h"
#include "independentes.h"
#include "dependentes.h"
#include "cadastrar.h"
#include "atualizar.h"
#include "excluir.h"
#include "relatorio.h"


void escolha_main();
void escolha_menu_produtos();
void escolha_exibir_estoque();
void cadastrar_estoque();
void escolha_sub_menu_vendas();

void realizar_venda();
void pagamento();

void voltar_para_menu();


int main (void)
{
    // pensar em uma verificação pra criar txt caso nao existir nenhum
    FILE *ponteiro_iniciar = NULL; // descobrir onde colocar isso, nao vai ficar na main
    ponteiro_iniciar = fopen("venda.txt", "r");
    if (ponteiro_iniciar == NULL)
    {
        ponteiro_iniciar = fopen("venda.txt", "w");
        if (ponteiro_iniciar == NULL)
        {
            printf("Erro ao abrir arquivo!\n");
            exit(1);
        }
    }
    fclose(ponteiro_iniciar);

    ponteiro_iniciar = fopen("produtos.txt", "r");
    if (ponteiro_iniciar == NULL)
    {
        ponteiro_iniciar = fopen("produtos.txt", "w");
        if (ponteiro_iniciar == NULL)
        {
            printf("Erro ao abrir arquivo!\n");
            exit(1);
        }
    }
    fclose(ponteiro_iniciar);


    menu();
    escolha_main();
}

void escolha_main()
{
    int cod = 0;
    cod = validar(cod, 1, 3);

    switch (cod)
    {
    case 1:
        sub_menu_produtos();
        escolha_menu_produtos();
        break;

    case 2:
        sub_menu_vendas();
        escolha_sub_menu_vendas();
        break;

    case 3:
        remove("relatorio.txt");// apagar relatorio para nao ler o relatorio anterior
        sair();
        break;

    }
    return;
}



void escolha_menu_produtos()
{
    int cod = 0;
    int quantidadeproduto = 0;

    cod = validar(cod, 1, 7);
    switch (cod)
    {
    case 1:
        printf("\nO estoque é:\n");
        visualizar_estoque();
        escolha_exibir_estoque();

        break;

    case 2:
        cadastrar_estoque();
        printf("Cadastrado com sucesso!\n");
        sub_menu_produtos(); // pra nao fechar dps de cadastrar
        escolha_menu_produtos();
        break;

    case 3:
        atualizar();
        printf("Salvando alterações...!\n"); // apenas abstrato, nao é salvo aqui
        sleep(1);
        sub_menu_produtos(); // pra nao fechar dps de cadastrar
        escolha_menu_produtos();
        break;

    case 4:
        excluir_produto();
        printf("Salvando alterações...!\n"); // apenas abstrato, nao é salvo aqui
        sleep(1);
        sub_menu_produtos(); // pra nao fechar dps de retornar
        escolha_menu_produtos();
        break;

    case 5:
        //salvar_txt();
        printf("Salvo com sucesso!\n");
        sleep(1);
        sub_menu_produtos(); // pra nao fechar dps de retornar
        escolha_menu_produtos();
        break;

    case 6:
        quantidadeproduto = descobrir_tamanho();
        estoque_global = aloca_vetor(quantidadeproduto);
        ler_txt(estoque_global, quantidadeproduto);
        printf("Lido com sucesso!\n");
        free(estoque_global);
        sleep(1);
        sub_menu_produtos(); // pra nao fechar dps de retornar
        escolha_menu_produtos();
        break;

    case 7:
        voltar_para_menu();
        break;
    }

    return;
}

void escolha_sub_menu_vendas()
{
    int cod = 0;
    cod = validar(cod, 1, 3);

    switch (cod)
    {
    case 1:
        realizar_venda();
        sub_menu_vendas();
        escolha_sub_menu_vendas();
        break;

    case 2:
        relatorio_vendas();
        sub_menu_vendas();
        escolha_sub_menu_vendas();
        break;

    case 3:
        voltar_para_menu();
        sub_menu_vendas();
        escolha_sub_menu_vendas();
        break;

    }

    return;
}

void escolha_exibir_estoque()//essa aqui so vai ser usada pra quando for exibido o estoque pelo menu opcao Exibir
{
    int opcao = 0;
    printf("\nDigite:\n[1] para voltar ao menu principal.\n[2] para voltar ao menu de produtos.\n[3] para reimprimir o estoque.\n--> ");
    opcao = validar(opcao, 1, 3);
    switch(opcao)
    {
    case 1:
        voltar_para_menu();
        break;

    case 2:
        printf("Retornando ao menu de produtos...");
        sleep(1);
        sub_menu_produtos();
        escolha_menu_produtos();
        break;

    case 3:
        printf("Reimprimindo estoque...");
        sleep(1);
        visualizar_estoque();
        escolha_exibir_estoque();
        break;

    }
}

void voltar_para_menu() // candidato pra ir pra .h ou .c
{
    printf("Retornando ao menu principal..");
    sleep(1);
    menu();
    escolha_main();
}

void realizar_venda() // candidato pra ir pra .h ou .c
{
    int indice = 0;
    int continuar = 0;
    int produto_vender = 0;
    FILE *ponteiro_vender = NULL;
    printf("Realizar venda escolhido.\n");

    visualizar_estoque();

    printf("Bem vindo a Padaria da Berenice.\n");
    do
    {
        printf("Digite o código válido do produto a ser vendido.\n-> ");
        scanf("%d", &produto_vender);
        getchar();
        indice = verificar_cod_cadastro(produto_vender); // o retorno dessa função dá o ínice caso sucesso
        if (indice == -1)
        {
            printf("Código não cadastrado.\n");
        }
    }
    while (indice == -1);

    int max_produtos = descobrir_tamanho();
    estoque_global = aloca_vetor(max_produtos);
    ler_txt(estoque_global, max_produtos);

    printf("%s escolhido!\n", estoque_global[indice].nome_item);
    if (estoque_global[indice].quantidade_item < 1)
    {
        printf("\nNenhuma unidade deste item no estoque!\n");
        printf("Escolha outro item!\n");
        sleep(3);
        realizar_venda(); // ver se n crasha
    }
    float preco_total = 0;

    printf("\nPreço unitário: R$%.2f.\n",estoque_global[indice].preco_item); // exibe o preço unitário.
    printf("Selecione a quantidade a ser vendida. Ps: estoque: %i\n-> ", estoque_global[indice].quantidade_item); // mostra o estoque para melhor nortear a venda.

    estoque_global[indice].quantidade_vendida = validar(estoque_global[indice].quantidade_vendida, 1, estoque_global[indice].quantidade_item); // garante que a quantidade escolhida seja maior que 0 e que esteja dentro do estoque
    preco_total = estoque_global[indice].preco_item * estoque_global[indice].quantidade_vendida; // calcula o preço total da compra

    ponteiro_vender = fopen("venda_temp.txt", "w"); // cria aqui e é apagado depois de selecioar o item
    if (ponteiro_vender == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    fprintf(ponteiro_vender, "%i\n", estoque_global[indice].codigo_item);
    fprintf(ponteiro_vender, "%s\n", estoque_global[indice].nome_item);
    fprintf(ponteiro_vender, "%.2f\n", estoque_global[indice].preco_item);
    fprintf(ponteiro_vender, "%i\n", estoque_global[indice].quantidade_item);
    fprintf(ponteiro_vender, "%i\n", estoque_global[indice].quantidade_vendida);

    fclose(ponteiro_vender);

    ponteiro_vender = fopen("venda.txt", "a"); // cria e é apagada após o pagamento
    if (ponteiro_vender == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    fprintf(ponteiro_vender, "%i\n", estoque_global[indice].codigo_item);
    fprintf(ponteiro_vender, "%s\n", estoque_global[indice].nome_item);
    fprintf(ponteiro_vender, "%.2f\n", estoque_global[indice].preco_item);
    fprintf(ponteiro_vender, "%i\n", estoque_global[indice].quantidade_item);
    fprintf(ponteiro_vender, "%i\n", estoque_global[indice].quantidade_vendida);

    fclose(ponteiro_vender);

    ponteiro_vender = fopen("relatorio.txt", "a"); // cria para o relatorio
    if (ponteiro_vender == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    fprintf(ponteiro_vender, "%i\n", estoque_global[indice].codigo_item);
    fprintf(ponteiro_vender, "%s\n", estoque_global[indice].nome_item);
    fprintf(ponteiro_vender, "%.2f\n", estoque_global[indice].preco_item);
    fprintf(ponteiro_vender, "%i\n", estoque_global[indice].quantidade_item);
    fprintf(ponteiro_vender, "%i\n", estoque_global[indice].quantidade_vendida);

    fclose(ponteiro_vender);

    int tamanho = 0;
    estoque *estoque_auxiliar;
    ponteiro_vender = fopen("venda_temp.txt", "r");
    if (ponteiro_vender == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    estoque_auxiliar = aloca_vetor(1); // pois só vende 1 item por vez

    // ler as informaçoes do venda.txt

    fscanf(ponteiro_vender, "%i", &estoque_auxiliar[0].codigo_item);
    fgetc(ponteiro_vender);
    fgets(estoque_auxiliar[0].nome_item, 25, ponteiro_vender);
    int n = strlen(estoque_auxiliar[0].nome_item); // isso tira o \n
    estoque_auxiliar[0].nome_item[n-1] = '\0';
    fscanf(ponteiro_vender, "%f %d %d", &estoque_auxiliar[0].preco_item,
                                                &estoque_auxiliar[0].quantidade_item,
                                                &estoque_auxiliar[0].quantidade_vendida);
    fgetc(ponteiro_vender);

    fclose(ponteiro_vender);

    //subtrai a quatidade escolhida do estoque
    int apagar = verificar_cod_cadastro(estoque_auxiliar[0].codigo_item);
    estoque_global[apagar].quantidade_item -= estoque_auxiliar[0].quantidade_vendida;
    estoque_global[apagar].quantidade_vendida += estoque_auxiliar[0].quantidade_vendida;

    int tamanho_txtprodutos = descobrir_tamanho();
    reescrever_txt(tamanho_txtprodutos);
    free(estoque_auxiliar);

    system("clear");

    printf("Preço total: R$%.2f\n", preco_total);
    printf("Deseja adicionar mais um produto para a compra?\n[1] para sim \n[2] para não.\n-> ");//precisa reescrever o txt casoseja add mais produto
    continuar = validar(continuar, 1, 2);

    if (continuar == 1)
    {
        realizar_venda();
    }
    else
    {
        pagamento();
    }

}

void pagamento()
{
    FILE *ponteiro_pagamento = NULL;
    int indice = 0;
    int tamanho = 0;
    int opcao_pagamento = 0;
    float total_pagar = 0;
    int parcelas = 0;
    float preco_final = 0;
    float valor_parcela = 0;
    float variacao = 0;
    int opcao_vista = 0;
    float valor_pago = 0;

    estoque *estoque_auxiliar;
    ponteiro_pagamento = fopen("venda.txt", "r");
    if (ponteiro_pagamento == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    for (int i = 0; feof(ponteiro_pagamento) == 0; i++) // descobrir quantos itens para vender
    {
        char temp[25];
        fgets(temp, 25, ponteiro_pagamento); // só pra pular a linha
        tamanho = i;
    }
    tamanho = tamanho / 5;
    estoque_auxiliar = aloca_vetor(tamanho);
    rewind(ponteiro_pagamento); // volta pra 1 linha
    while(!feof(ponteiro_pagamento)) // ler as informaçoes do venda.txt
    {
        fscanf(ponteiro_pagamento, "%i", &estoque_auxiliar[indice].codigo_item);
        fgetc(ponteiro_pagamento);
        fgets(estoque_auxiliar[indice].nome_item, 25, ponteiro_pagamento);
        int n = strlen(estoque_auxiliar[indice].nome_item); // isso tira o \n
        estoque_auxiliar[indice].nome_item[n-1] = '\0';
        fscanf(ponteiro_pagamento, "%f %d %d", &estoque_auxiliar[indice].preco_item,
                                                &estoque_auxiliar[indice].quantidade_item,
                                                &estoque_auxiliar[indice].quantidade_vendida);
        fgetc(ponteiro_pagamento);
        indice++;
    }
    fclose(ponteiro_pagamento);
    system("clear");
    printf("\t-- CUPOM FISCAL --\n"); // mostrar o recibo
    for (int i = 0; i < tamanho; i++)
    {
       printf("Item %i : %s  unitário: R$%.2f x %i: R$%.2f \n", i+1, estoque_auxiliar[i].nome_item,
                                                    estoque_auxiliar[i].preco_item, estoque_auxiliar[i].quantidade_vendida,
                                                    estoque_auxiliar[i].preco_item * estoque_auxiliar[i].quantidade_vendida);
        total_pagar += estoque_auxiliar[i].preco_item * estoque_auxiliar[i].quantidade_vendida;
    }
    printf("\t\t\tValor total a pagar: R$%.2f\n", total_pagar);

    printf("\nQual será o método de pagamento?\n [1] para a prazo no cartão de crédito (até 12x).\n [2] para à vista com desconto.\n-> ");
    opcao_pagamento = validar(opcao_pagamento, 1, 2);
    switch (opcao_pagamento)
    {
    case 1: // método a prazo, não calcula troco por ser no cartão
        printf("Selecione quantas parcelas.\n-> ");
        parcelas = validar(parcelas, 1, 12); // ----

        if (parcelas <= 3) // nao é preciso colocar o && > 0 pois a função 'validar' garante que o número inserido não seja 0.
        {
            preco_final = total_pagar * 1.05; // acréscimo de 5%
            valor_parcela = preco_final / parcelas;
            variacao = total_pagar * 0.05;
        }
        else if (parcelas > 3) // nao é preciso colocar o && < 12 pois a função 'validar' garante que o número inserido seja igual ou menor que 12.
        {
            preco_final = total_pagar * 1.08; // acréscimo de 8%
            valor_parcela = preco_final / parcelas;
            variacao = total_pagar * 0.08;
        }
        printf("\nO preço final é R$%.2f, com R$%.2f de acréscimo, e o preço da primeira parcela é R$%.2f.\n",preco_final, variacao, valor_parcela);
        break;
    case 2: // método à vista com desconto, será calculado troco.
        if (total_pagar <= 50)
        {
            preco_final = total_pagar * 0.95; // desconta 5%
            variacao = total_pagar * 0.05;
        }
        else if (total_pagar > 50 && total_pagar < 100)
        {
            preco_final = total_pagar * 0.90; // desconta 10%
            variacao = total_pagar * 0.10;
        }
        else
        {
            preco_final = total_pagar * 0.82; // desconta 18%
            variacao = total_pagar * 0.18;
        }
        preco_final = round(preco_final * 100.0) / 100.0; // arredonda para ter apenas 2 casas decimais
        printf("\nO preço final é R$%.2f, com R$%.2f de desconto.\n", preco_final, variacao);
        printf("Como deseja fazer o pagamento? \n[1] Cartão de crédito/débito. \n[2] Dinheiro.\n-> ");
        opcao_vista = validar(opcao_vista, 1, 2); // retorna a opção escolhida, entre 1 a 2 apenas.
        if (opcao_vista == 1)
        {
            printf("\nPagamento efetuado. Obrigado e volte sempre! Compra finalizada.\n");
        }
        else
        {
            int bool_verificador = 0;
            printf("\nInsira o valor pago pelo cliente: \n-> ");
            do
            {
                bool_verificador = 0;
                scanf("%f",&valor_pago); // tivemos que utilizar esse scan f para um float :( nossa função "validar" retorna apenas inteiros.
                getchar();
                if (valor_pago < 0)
                {
                    printf("Inválido, valor não pode ser menor que 0!\n");
                    bool_verificador++;
                }
            }
            while (bool_verificador != 0);
            if (valor_pago < preco_final)
            {
                int refazer_pagamento = 0;
                printf("Valor insuficiente! Faltam R$%.2f.\n", preco_final - valor_pago);
                printf("Deseja refazer o pagamento? \n[1] para sim \n[2] para não(Cancelamento da compra).\n");
                refazer_pagamento = validar(refazer_pagamento, 1, 2);
                if (refazer_pagamento == 1)
                {
                    pagamento();
                }
                estoque_global[indice].quantidade_item += estoque_global[indice].quantidade_vendida; // devolve o item nao comprado para o estoque
                int tamanho_txtprodutos = descobrir_tamanho();
                reescrever_txt(tamanho_txtprodutos);
                printf("\nPagamento cancelado!\n"); // com o txt reescrito precisamos readicionar o estoque devolta aos produtos
                sleep(1);
                remove("venda.txt"); // remove o txt pra liberar
                voltar_para_menu();
            }
            else if (valor_pago > preco_final)
            {
                printf("Pagamento efetuado! O troco é R$%.2f.\n", valor_pago - preco_final);
            }
            else if (valor_pago == preco_final)
            {
                printf("Pagamento efetuado sem troco!\n");
            }
        }
        break;
    }// switch

    remove("venda.txt"); // remove o txt pra liberar

    sleep(3);

    system("clear");
    printf("Compra finalizada..\n");

    sleep(1);
    voltar_para_menu();
}


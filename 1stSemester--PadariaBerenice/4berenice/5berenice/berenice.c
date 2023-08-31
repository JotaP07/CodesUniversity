#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "menu.h"
#include "listas_related.h"
#include "vendas.h"

int main (void)
{

    if (lista == NULL)
    {
        ler_txt();
    }

    while (0 != 1)
    {
        menu();
        escolha_main();
    }

    return 0;
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
            destruirLista(lista);
            printf("Saindo..\n");
            exit(0);
            break;
    }

}

void escolha_menu_produtos()
{
    int cod = 0;
    int quantidadeproduto = 0;

    cod = validar(cod, 1, 5);
    switch (cod)
    {
        case 1:
            mostrarlista();
            break;

        case 2:
            adicionar_node();
            salvar_txt();
            break;

        case 3:
            alterar();
            break;

        case 4:
            removerNode();
            break;

        case 5:
            return;
            break;

    }
}

void escolha_sub_menu_vendas()
{
    int cod = 0;
    cod = validar(cod, 1, 3);

    switch (cod)
    {
        case 1:
            realizar_venda();
            //sub_menu_vendas();
            //escolha_sub_menu_vendas();
            break;

        case 2:
            relatorio();
            break;

        case 3:
            return;
            break;

    }

    return;
}
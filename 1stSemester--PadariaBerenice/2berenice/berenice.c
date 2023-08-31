#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



//variaveis de estoque e produto.
#define NUM_PRODUTOS 5
int estoque[NUM_PRODUTOS] = {0,5,2,3,0};
float valor_produto[NUM_PRODUTOS] = {7.5, 8.69, 5.0, 4.5, 3.25};
int quantidadeVendida[NUM_PRODUTOS] = {0};
int quantidadeVendidaRELATORIO[NUM_PRODUTOS] = {0};
float valorVendidoRELATORIO[NUM_PRODUTOS] = {0};
int codigos[NUM_PRODUTOS];
float *valor_total = 0;
float valor_total_relatorio = 0.0;
//funções
void exibirMenu();
int cadastrarEstoque(int estoque[]);
int visualizarEstoque(int estoque []);
void exibirRELATORIO(int quantidadeVendidaRELATORIO[],float valorVendidoRELATORIO[], float valor_total_relatorio );
int realizarVenda(int estoque[], float valor_produto[], int codigos[], int quantidadeVendida[]);
//funções que fazem parte do realizarVenda
void exibirLista(int estoque[]);
int pedirCodigo();
int pedirQuantidade(int estoque[], int codigo, int quantidadeVendida[]);
int adicionarCompra(int codigo, int quantidadeVendida[], float valor_produto[]);
float pedirPagamento(float valor_total_sem_desconto, float* valor_total);
void exibirCupomFiscal(int vendasRealizadas[], float valor_produto[], int codigos[]);

//ESTRUTURA DOS PRODUTOS E CODIGOS.
struct Produto
{
    int codigo;
    char nome[50];
};
struct Produto produtos[] =
{
    {1, "PÂO DE FORMA"},
    {2, "PÂO DE CENTEIO"},
    {3, "BROA DE MILHO"},
    {4, "SONHO"},
    {5, "TUBAÍNA"}
};


void exibirMenu()
{
    system("cls");
    printf("  -- BEM VINDO A PADARIA DA BERENICE--          \n\n");
    printf("\t-- Menu Principal --\n");
    printf("\t1. Cadastrar estoque\n");
    printf("\t2. Visualizar estoque\n");
    printf("\t3. Realizar venda\n");
    printf("\t4. Sair\n");
    printf("\tEscolha uma opcao: ");
}
int main ()
{

    setlocale(LC_ALL, "Portuguese");
    system("color f0");

    int opMENU;
    do
    {

        float* valor_total = 0;
        exibirMenu();
        scanf("%d", &opMENU);
        getchar();
        switch(opMENU)
        {
        case 1:
            system("cls");
            cadastrarEstoque(estoque);
            break;
        case 2:
            system("cls");
            visualizarEstoque(estoque);
            break;
        case 3:
            system("cls");
            realizarVenda(estoque, valor_produto, codigos, quantidadeVendida);
            break;
        case 4:
            system("cls");
            exibirRELATORIO(quantidadeVendidaRELATORIO, valorVendidoRELATORIO, valor_total_relatorio);
            printf("Obrigado por usar nosso sistema.\n");
            printf("Programa Finalizado.");
            break;

        default:
            printf("Opcao invalida. Digite novamente.\n");
            break;
        }
    }
    while(opMENU != 4);

    return 7;
}
int cadastrarEstoque(int estoque[])
{
    int codigo, estoqueProduto = 0;
    char opcao, entrada[50];
    printf("\nOpção selecionada: - CADASTRAR ESTOQUE -\n\n");
    do
    {
        printf("-- CASO QUEIRA VOLTAR AO MENU DIGITE 'X' -- \n\n");
        int numProdutos = sizeof(produtos) / sizeof(produtos[0]); // Número de produtos no array
        // Exibição dos dados dos produtos usando um loop for
        printf("   |---------|-------|---------------|\n");
        printf("     P.VETOR   CÓDIGO      ITEM      \n");
        for (int i = 0; i < numProdutos; i++)
        {
            printf("        %02d       %02d    %-14s \n", i, produtos[i].codigo, produtos[i].nome); // Exibição da posição do vetor
        }
        printf("   |---------|-------|---------------|\n");

        printf("Digite o código do item que deseja alterar o estoque: ");
        if (fgets(entrada, sizeof(entrada), stdin) == NULL)
        {
            printf("\n\tCÓDIGO INVÁLIDO!\n");
            return 0;
        }

        if (entrada[0] == 'x' || entrada[0] == 'X')
        {
            printf("\nVoltando ao menu principal...\n");
            sleep(1);
            return 7;
        }

        if (sscanf(entrada, "%d", &codigo) != 1)
        {
            printf("\n\tCÓDIGO INVÁLIDO!\n\n");
            continue;
        }

        if (codigo < 1 || codigo > NUM_PRODUTOS)
        {
            printf("\n\tCÓDIGO INVÁLIDO!\n\n");
            continue;
        }

        do
        {
            printf("Digite a quantidade a ser cadastrada: ");
            if (fgets(entrada, sizeof(entrada), stdin) == NULL)
            {
                printf("\n\t“QUANTIDADE INVÁLIDA, A MESMA DEVE SER MAIOR OU IGUAL A ZERO.\n");
                printf("\n");
                continue;
            }

            if (entrada[0] == 'x' || entrada[0] == 'X')
            {
                printf("\nVoltando ao menu principal...\n");
                sleep(1.5);
                return 0;
            }

            if (sscanf(entrada, "%d", &estoqueProduto) != 1)
            {
                printf("\n\tQUANTIDADE INVÁLIDA, A MESMA DEVE SER MAIOR OU IGUAL A ZERO.\n");
                printf("\n");
                continue;
            }

            if (estoqueProduto < 0)
            {
                printf("\n\tQUANTIDADE INVÁLIDA, A MESMA DEVE SER MAIOR OU IGUAL A ZERO.\n");
                printf("\n");
                continue;
            }

            break;
        }
        while (1);


        estoque[codigo - 1] += estoqueProduto;

        printf("\nA quantidade de %d itens do produto %d foi atualizada com sucesso!\n\n", estoqueProduto, codigo);

        char opcao;

        while (1)
        {
            printf("S - CADASTRAR MAIS ITENS \n");
            printf("X - VOLTAR AO MENU\n");
            printf("Digite a opção que deseja: ");
            printf("\n");

            if (fgets(entrada, sizeof(entrada), stdin) == NULL)
            {
                printf("\n\tOPÇÃO INVÁLIDA!\n");
                printf("\n");
                continue; // volta ao início do loop
            }

            if (sscanf(entrada, " %c", &opcao) != 1)
            {
                printf("\n\tOPÇÃO INVÁLIDA!\n");
                printf("\n");
                continue; // volta ao início do loop
            }
            if (opcao == 's' || opcao == 'S')
            {
                break; // sai do loop
            }
            if (opcao == 'X' || opcao == 'x')
            {
                return 7; // sai do loop
            }
        }

        printf("\n"); // só para deixar uma linha em branco no final
    }
    while (1);

    return 1;
}
/*Essa condição de loop while é usada para garantir que a entrada do código de produto seja lida corretamente,
convertida em um número inteiro válido e esteja dentro do intervalo permitido de códigos de produtos,
repetindo o loop até que uma entrada válida seja fornecida pelo usuário..*/
int visualizarEstoque(int estoque [])
{

    char op;
    printf("\nOpção selecionada: - VISUALIZAR ESTOQUE -\n\n");
    printf("   |---------|----------------|---------|\n");
    printf("     CÓDIGO        ITEM         ESTOQUE \n");
    for(int i = 0; i < NUM_PRODUTOS; i++)
    {
        printf("       %d       %-16s    %d     \n", produtos[i].codigo, produtos[i].nome, estoque[i]);
    }
    printf("   |---------|----------------|---------|\n");
    printf("Digite qualquer tecla para voltar ao menu: ");
    scanf(" %c", &op);
    while (getchar() != '\n'); // limpa o buffer de entrada

    return 7;
}
void exibirLista(int estoque[])
{
    printf("                 MENU DE ITENS:                      \n");
    printf(" |------|-----------------|-----------------|-------|\n");
    printf("    CÓD        ITEM          VALOR (UND)       ESTQ \n");

    for (int i = 0; i < 5; i++)
    {
        printf("    %02d     %-15s   R$%.2f             %d    \n", i + 1, produtos[i].nome, valor_produto[i], estoque[i]);
    }
    printf(" |------|-----------------|-----------------|-------|\n");
}
int pedirCodigo()
{
    int codigo;
    char lerEntrada[50];
    do
    {
        printf("Digite o código do produto a ser vendido: ");
        if (fgets(lerEntrada, sizeof(lerEntrada), stdin) == NULL)
        {
            while (getchar() != '\n');//limpa a tela.
            printf("CÓDIGO INVÁLIDO!\n\n");
            return 0;
        }


        if (lerEntrada[0] == 'x' || lerEntrada[0] == 'X')
        {
            printf("\nVoltando ao menu principal...\n");
            sleep(1);
            return 7;
        }

        if (sscanf(lerEntrada, "%d", &codigo) != 1)
        {
            while (getchar() != '\n');
            printf("CÓDIGO INVÁLIDO\n\n");
            continue;
        }

        if (codigo < 1 || codigo > 5)
        {
            printf("CÓDIGO INVÁLIDO\n\n");
            continue;
        }

        // Verifica se há estoque suficiente
        if (estoque[codigo - 1] == 0)
        {
            printf("ESTOQUE INSUFICIENTE DO PRODUTO SELECIONADO\n\n");
            continue;
        }



        switch(codigo)
        {
        case 1:
            printf("Produto selecionado: Pão de Forma\n");
            printf("Valor: R$%.2f\n", valor_produto[codigo - 1]);
            break;
        case 2:
            printf("Produto selecionado: Pão de Centeio\n");
            printf("Valor: R$%.2f\n", valor_produto[codigo - 1]);
            break;
        case 3:
            printf("Produto selecionado: Broa de Milho\n");
            printf("Valor: R$%.2f\n", valor_produto[codigo - 1]);
            break;
        case 4:
            printf("Produto selecionado: Sonho\n");
            printf("Valor: R$%.2f\n", valor_produto[codigo - 1]);
            break;
        case 5:
            printf("Produto selecionado: Tubaína\n");
            printf("Valor: R$%.2f\n", valor_produto[codigo - 1]);
            break;
        }
        break;
    }
    while (1);
    return codigo;
}
int pedirQuantidade(int estoque[], int codigo, int quantidadeVendida[])
{
    char lerEntrada[50];
    while (1)
    {
        printf("Digite a quantidade do produto (em estoque: %d): ", estoque[codigo - 1]);
        if (fgets(lerEntrada, sizeof(lerEntrada), stdin) == NULL)
        {
            printf("\nQUANTIDADE INVÁLIDA!\n\n");
            continue;
        }
        if (lerEntrada[0] == 'x' || lerEntrada[0] == 'X')
        {
            printf("\nVoltando ao menu principal...\n");
            sleep(1);
            return 7;
        }
        if (sscanf(lerEntrada, "%d", &quantidadeVendida[codigo - 1]) != 1 || quantidadeVendida[codigo - 1] <= 0)
        {
            printf("\nQUANTIDADE INVÁLIDA\n\n");
            continue;
        }
        if (quantidadeVendida[codigo - 1] > estoque[codigo - 1])
        {
            printf("\nQUANTIDADE INSUFICIENTE NO ESTOQUE\n\n");
            continue;
        }
        break;
    }
    return 1;
}
int adicionarCompra(int codigo, int quantidadeVendida[], float valor_produto[])
{
    float valor_total_sem_desconto = 0;

    float valorXquantidade = valor_produto[codigo - 1] * quantidadeVendida[codigo - 1];
    valor_total_sem_desconto += valorXquantidade;
    int opcao;
    char entrada[50];
    int addCOMPRA;

    printf("\nvalor:R$%.2f", valorXquantidade);
    if (valor_total_sem_desconto > valorXquantidade)
    {
        printf("\nValor total da compra:R$%.2f", valor_total_sem_desconto);
    }

    do
    {
        printf("\nAdicionar compra à lista? (S/N)\n");
        if (fgets(entrada, sizeof(entrada), stdin) == NULL)
        {
            printf("\n\tOPÇÃO INVÁLIDA\n");
            printf("\n");
            return 0;
        }
        opcao = entrada[0];

        if (entrada[0] == 'x' || entrada[0] == 'X')
        {
            printf("\nVoltando ao menu principal...\n");
            sleep(1);
            return 7;
        }
        if (opcao == 's' || opcao == 'S')
        {
            addCOMPRA = 1;
            break; // Alteração 3: usar continue para voltar ao início do loop
        }
        else if (opcao == 'n' || opcao == 'N')
        {
            addCOMPRA = 0;
            break;
        }
        else
        {
            printf("\n\tOPÇÃO INVÁLIDA\n");
            printf("\n");
        }
    }
    while (1);

    return addCOMPRA;
}
float pedirPagamento(float valor_total_sem_desconto, float* valor_total)
{
    char entrada[50];
    int Tipo_Pagamento = 0;
    float valor_pago, troco;
    *valor_total = 0.0;

    do
    {
        printf("\nEscolha a forma de pagamento:\n");
        printf("1. À vista\n");
        printf("2. À prazo\n");
        if (fgets(entrada, sizeof(entrada), stdin) == NULL)
        {
            printf("\nOPÇÃO DE PAGAMENTO INVÁLIDA\n");
            printf("\n");
            continue;
        }
        if (entrada[0] == 'x' || entrada[0] == 'X')
        {
            printf("\nVoltando ao menu principal...\n");

            sleep(1);
            return 7;
        }
        if (sscanf(entrada, "%d", &Tipo_Pagamento) != 1)
        {
            printf("\nOPÇÃO DE PAGAMENTO INVÁLIDA\n");
            printf("\n");
            continue;
        }
        switch (Tipo_Pagamento)
        {
        case 1:
            printf("\nPagamento à vista selecionado.\n");
            if (valor_total_sem_desconto <= 50.0)
            {
                *valor_total = valor_total_sem_desconto * 0.95;
            }
            else if (valor_total_sem_desconto < 100.0)
            {
                *valor_total = valor_total_sem_desconto * 0.9;
            }
            else
            {
                *valor_total = valor_total_sem_desconto * 0.82;
            }
            printf("\nValor total com desconto: R$%.2f\n", *valor_total);

            do
            {
                printf("\nO cliente precisa de troco? (S/N)\n");
                if (fgets(entrada, sizeof(entrada), stdin) == NULL)
                {
                    return 1;
                }

                if (entrada[0] == 'x' || entrada[0] == 'X')
                {
                    printf("\nVoltando ao menu principal...\n");
                    sleep(1.5);
                    return 7;
                }

                if (entrada[0] == 'S' || entrada[0] == 's' || entrada[0] == 'N' || entrada[0] == 'n')
                {
                    break;
                }

                printf("\nOpção inválida. Digite S ou N.\n");
            }
            while (1);

            if (entrada[0] == 'N' || entrada[0] == 'n')
            {

                return 0;
            }
            do
            {
                printf("\nDigite o valor pago pelo cliente: R$");
                if (fgets(entrada, sizeof(entrada), stdin) == NULL)
                {
                    printf("\nVALOR INVÁLIDO\n");
                    continue;
                }
                if (sscanf(entrada, "%f", &valor_pago) != 1 || valor_pago < *valor_total)
                {
                    printf("\nVALOR INVÁLIDO\n");
                }
                if (entrada[0] == 'x' || entrada[0] == 'X')
                {
                    printf("\nVoltando ao menu principal...\n");
                    sleep(1);
                    return 7;
                }
            }
            while (valor_pago < *valor_total);


            troco = valor_pago - *valor_total;
            printf("\nTroco: R$%.2f\n", troco);

            return 0;
        case 2:

            printf("\nPagamento a prazo selecionado.\n");
            int num_parcelas;
            do
            {
                printf("Digite o número de parcelas: ");
                if (fgets(entrada, sizeof(entrada), stdin) == NULL)
                {
                    printf("\nNÚMERO DE PARCELAS INVÁLIDO!\n");
                    printf("\n");
                    return 0;
                }
                if (entrada[0] == 'x' || entrada[0] == 'X')
                {
                    printf("\nVoltando ao menu principal...\n");
                    sleep(1.5);
                    return 7;
                }
                if (sscanf(entrada, "%d", &num_parcelas) != 1 || num_parcelas < 1)
                {
                    printf("\nNÚMERO DE PARCELAS INVÁLIDO, DIGITE UM VALOR IGUAL OU ACIMA DE 1 PARCELA.\n");
                    printf("\n");
                    continue;
                }
                break;
            }
            while (1);

            if (num_parcelas <= 3)
            {
                *valor_total =valor_total_sem_desconto * 1.05;
            }
            else
            {
                *valor_total = valor_total_sem_desconto * 1.08;
            }
            printf("\nValor total com acréscimo: R$%.2f\n", *valor_total);
            float valor_cada_parcela;
            valor_cada_parcela = *valor_total / num_parcelas;
            printf("Valor de cada parcela: R$%.2f\n",valor_cada_parcela);
            return 0;

        default:
            printf("\nOPÇÃO DE PAGAMENTO INVÁLIDA\n");
            printf("\n");
            continue;
        }
    }
    while (1);

    return 7;
}
void exibirCupomFiscal(int vendasRealizadas[], float valor_produto[], int codigos[])
{
    float valor_total_produto[NUM_PRODUTOS] = {0};
    int codigo_produto_vendido;
    float valor_total_venda;

    // Calcula o valor total de cada produto vendido
    for (int i = 0; i < NUM_PRODUTOS; i++)
    {
        if (vendasRealizadas[i] > 0)
        {
            valor_total_produto[i] = vendasRealizadas[i] * valor_produto[i];
        }
    }

    // Ordena o vetor valor_total_produto em ordem decrescente
    for (int i = 0; i < NUM_PRODUTOS - 1; i++)
    {
        for (int j = i + 1; j < NUM_PRODUTOS; j++)
        {
            if (valor_total_produto[i] < valor_total_produto[j])
            {
                float temp = valor_total_produto[i];
                valor_total_produto[i] = valor_total_produto[j];
                valor_total_produto[j] = temp;

                int temp2 = codigos[i];
                codigos[i] = codigos[j];
                codigos[j] = temp2;

                int temp3 = vendasRealizadas[i];
                vendasRealizadas[i] = vendasRealizadas[j];
                vendasRealizadas[j] = temp3;
            }
        }
    }
    printf("\nCupom Fiscal:\n");
    printf("|-----------------------|-------------|----------|\n");
    printf("  Produto                 Quantidade    Valor     \n");


// Exibe os produtos vendidos em ordem decrescente de valor total
    for (int i = 0; i < NUM_PRODUTOS; i++)
    {
        if (valor_total_produto[i] > 0)
        {
            codigo_produto_vendido = codigos[i];
            valor_total_venda = valor_total_produto[i];

            printf("  %-22s %10d     R$ %5.2f \n", produtos[i + 1].nome, vendasRealizadas[i], valor_total_venda);
        }
    }

    printf("|-----------------------|-------------|----------|\n\n");

}

int exibirOpcoes()
{
    char entrada[50];

    while (1)   // loop infinito para repetir até que o usuário digite uma entrada válida
    {
        printf("X - Voltar para o Menu\n");
        printf("F - Finaliza o programa\n");
        printf("R - Realizar nova Venda\n");

        if (fgets(entrada, sizeof(entrada), stdin) == NULL)
        {
            printf("ENTRADA INVALIDA\n");
            continue; // continue = loop para exibir as opções novamente
        }

        if (entrada[0] == 'x' || entrada[0] == 'X')
        {
            printf("\nVoltando ao menu principal...\n");
            sleep(1);
            return 7;
        }
        else if (entrada[0] == 'f' || entrada[0] == 'F')
        {
            system("cls");
            exibirRELATORIO(quantidadeVendidaRELATORIO, valorVendidoRELATORIO, valor_total_relatorio);
            exit (0);
        }
        else if (entrada[0] == 'r' || entrada[0] == 'R')
        {
            system("cls");
            printf("\nIniciando nova venda...\n");
            sleep(1);
            realizarVenda(estoque, valor_produto, codigos, quantidadeVendida);
            return 0;
        }
        else
        {
            printf("ENTRADA INVALIDA\n");
            continue; // continue a próxima iteração do loop para exibir as opções novamente
        }
    }
}

int realizarVenda(int estoque[], float valor_produto[], int codigos[], int quantidadeVendida[])
{
    int opcao = 0;
    int quantidade;
    float valor_total_sem_desconto = 0.0;
    int continua = 1;
    int vendasRealizadas[NUM_PRODUTOS] = {0};
    float valor_total = 0;


    printf("\nOpção selecionada: - REALIZAR VENDA -\n\n");

    do
    {
        exibirLista(estoque);
        int codigo = pedirCodigo();
        if (codigo == 7)
        {
            printf("\nvoltando ao menu\n");
            for (int i = 0; i < NUM_PRODUTOS; i++)
            {
                estoque[i] += vendasRealizadas[i];// Adiciona quantidades vendidas de volta ao estoque
                quantidadeVendidaRELATORIO[i] -= quantidadeVendida[i];
                valorVendidoRELATORIO[i] -= vendasRealizadas[i] * valor_produto[i];
            }
            return 7;
        }
        quantidade = pedirQuantidade(estoque, codigo, quantidadeVendida);
        if (quantidade == 7)
        {
            printf("\nvoltando ao menu\n");
            for (int i = 0; i < NUM_PRODUTOS; i++)
            {
                estoque[i] += vendasRealizadas[i]; // Adiciona quantidades vendidas de volta ao estoque
                quantidadeVendidaRELATORIO [i] -= quantidadeVendida[i];
                valorVendidoRELATORIO[i] -= vendasRealizadas[i] * valor_produto[i];
            }
            return 7;
        }
        if (estoque[codigo - 1] < quantidadeVendida[codigo - 1])
        {
            printf("\nQUANTIDADE INSUFICIENTE NO ESTOQUE!\n");
            continue;
        }
        else
        {
            estoque[codigo - 1] -= quantidadeVendida[codigo - 1];
            valor_total_sem_desconto += valor_produto[codigo - 1] * quantidadeVendida[codigo - 1];
            vendasRealizadas[codigo - 1] += quantidadeVendida[codigo - 1];
            quantidadeVendidaRELATORIO [codigo - 1] += quantidadeVendida[codigo - 1];
            valorVendidoRELATORIO[codigo - 1] += vendasRealizadas[codigo - 1] * valor_produto[codigo - 1];
        }

        int continuar;
        continuar = adicionarCompra(codigo, quantidadeVendida, valor_produto);

        if (continuar == 0)
        {
            break;
        }
        if (continuar == 7)
        {
            // Cancelar a venda e restaurar o estoque como antes da venda
            printf("\nVenda cancelada.\n");
            printf("\nvoltando ao menu\n");
            for (int i = 0; i < NUM_PRODUTOS; i++)
            {
                estoque[i] += vendasRealizadas[i]; // Adiciona quantidades vendidas de volta ao estoque
                quantidadeVendidaRELATORIO [i] -= quantidadeVendida[i];
                valorVendidoRELATORIO[i] -= vendasRealizadas[i] * valor_produto[i];
            }
            return 7;
        }
    }
    while (1);
    int pagamento;
    pagamento = pedirPagamento(valor_total_sem_desconto, &valor_total);
    if (pagamento == 7)
    {
        // Cancelar a venda e restaurar o estoque como antes da venda
        printf("\nVenda cancelada.\n");
        printf("\nvoltando ao menu\n");
        // Adiciona quantidades vendidas de volta ao estoque se a venda não foi cancelada
        for (int i = 0; i < NUM_PRODUTOS; i++)
        {
            estoque[i] += vendasRealizadas[i];
            quantidadeVendidaRELATORIO [i] -= quantidadeVendida[i];
            valorVendidoRELATORIO[i] -= vendasRealizadas[i] * valor_produto[i];
        }
        return 7;
    }


    exibirCupomFiscal(vendasRealizadas, valor_produto, codigos);

    printf("\n\nVALOR TOTAL(COM DESCONTO OU ACRESCIMO): R$%.2f\n\n",valor_total);

    valor_total_relatorio += valor_total;
    char entrada[50];
    exibirOpcoes();
    return 7;

}

void exibirRELATORIO(int quantidadeVendidaRELATORIO[], float valorVendidoRELATORIO[], float valor_total_relatorio)
{
    printf("\nRELATÓRIO DE VENDAS\n");
    printf("   |---------|--------------------|---------------|\n");
    printf("     Produto   Quantidade Vendida   Valor Vendido  \n");


    for (int i = 0; i < NUM_PRODUTOS; i++)
    {
        printf("       %2d              %2d              %.2f       \n", i + 1, quantidadeVendidaRELATORIO[i], valorVendidoRELATORIO[i]);
    }

    printf("   |---------|--------------------|---------------|\n");
    printf("Valor total dos produtos (COM DESCONTO E ACRESCIMO APLICADO): R$%.2f\n\n", valor_total_relatorio);
}


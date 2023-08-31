void realizar_venda();
void pagamento();
void relatorio();

void realizar_venda()
{
    if (lista == NULL)
    {
        printf("Lista vazia!\n");
        getchar();
        printf("Digite qualquer tecla para continuar");
        getchar();
        return;
    }
    int codigo_comparar = 0;
    int contador_nao_encontrado = 0;
    int escolha_estoque_ou_preco = 0;

    printf("Bem vindo a Padaria da Berenice.\n");
    mostrarlista();
    // fazer verificações
    printf("Digite o código do produto que se deseja vender.\n-> ");
    scanf("%d", &codigo_comparar); // fazer verificação completa
    getchar();

    node *ptr = lista;
    while (ptr->produto.codigo_item != codigo_comparar) // vai parar quando achar
    {
        ptr = ptr->proxima;
        if (ptr == NULL)
        {
            contador_nao_encontrado++;
            break;
        }
    }

    if (contador_nao_encontrado != 0)
    {
        printf("Produto não encontrado, tente novamente com outro código.\n");
        printf("Digite qualquer tecla para continuar");
        getchar();
        return;
    }

    printf("Item escolhido: %s \n", ptr->produto.nome_item);

    if (ptr->produto.quantidade_item < 1)
    {
        printf("\nNenhuma unidade deste item no estoque!\n");
        printf("Escolha outro item!\n");//se escolher outro item aqui e n tiver em estoque ele ta voltando pro menu
        getchar();
        return;
    }

    float preco_total = 0;

    printf("\nPreço unitário: R$%.2f.\n",ptr->produto.preco_item); // exibe o preço unitário.
    printf("Selecione a quantidade a ser vendida. Ps: estoque: %i\n-> ", ptr->produto.quantidade_item); // mostra o estoque para melhor nortear a venda.
    ptr->produto.quantidade_vendida = validar(ptr->produto.quantidade_vendida, 1, ptr->produto.quantidade_item); // garante que a quantidade escolhida seja maior que 0 e que esteja dentro do estoque
    preco_total = ptr->produto.preco_item * ptr->produto.quantidade_vendida; // calcula o preço total da compra

    ptr->produto.quantidade_item -= ptr->produto.quantidade_vendida;

    salvar_txt();

    FILE *ponteiro_vender = NULL;
    ponteiro_vender = fopen("venda.txt", "a"); // cria aqui e é apagado depois de selecioar o item
    if (ponteiro_vender == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    fprintf(ponteiro_vender, "%i\n", ptr->produto.codigo_item);
    fprintf(ponteiro_vender, "%s\n", ptr->produto.nome_item);
    fprintf(ponteiro_vender, "%.2f\n", ptr->produto.preco_item);
    fprintf(ponteiro_vender, "%i\n", ptr->produto.quantidade_item);
    fprintf(ponteiro_vender, "%i\n", ptr->produto.quantidade_vendida);

    fclose(ponteiro_vender);

    ponteiro_vender = fopen("relatorio.txt", "a"); // cria para o relatorio
    if (ponteiro_vender == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    fprintf(ponteiro_vender, "%i\n", ptr->produto.codigo_item);
    fprintf(ponteiro_vender, "%s\n", ptr->produto.nome_item);
    fprintf(ponteiro_vender, "%.2f\n", ptr->produto.preco_item);
    fprintf(ponteiro_vender, "%i\n", ptr->produto.quantidade_item);
    fprintf(ponteiro_vender, "%i\n", ptr->produto.quantidade_vendida);

    fclose(ponteiro_vender);

    printf("Preço total: R$%.2f\n", preco_total);
    printf("Deseja adicionar mais um produto para a compra?\n[1] para sim \n[2] para não.\n-> "); //precisa reescrever o txt caso seja add mais produto
    int continuar = 0;
    continuar = validar(continuar, 1, 2);
    if (continuar == 1)
    {
        realizar_venda();
    }
    else if (continuar == 2)
    {
        pagamento();
    }

    getchar();

    return;
}

void pagamento()
{
    node *carrinho_compra = NULL;
    carrinho_compra = (node*)malloc(sizeof(node));


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

    ponteiro_pagamento = fopen("venda.txt", "r");
    if (ponteiro_pagamento == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    while (0 != 1) // loop infinito que sera quebrado dentro da execução
    {
        node *leitor = (node*)malloc(sizeof(node));
        if (leitor == NULL)
        {
            printf("Erro ao alocar memória!\n");
            exit(1);
        }

        if (fscanf(ponteiro_pagamento, "%d", &leitor->produto.codigo_item) != 1)
        { // break quando não for possível ler o campo codigo_item. Isso evita a leitura quando o arquivo tem uma linha em branco no final
            free(leitor);
            break; // Se não conseguir ler o código_item, sai do loop
        }
        fgetc(ponteiro_pagamento);
        fgets(leitor->produto.nome_item, 25, ponteiro_pagamento);
        int n = strlen(leitor->produto.nome_item);
        leitor->produto.nome_item[n-1] = '\0'; // Remove o '\n'
        fscanf(ponteiro_pagamento, "%f %d %d", &leitor->produto.preco_item, &leitor->produto.quantidade_item,
                                        &leitor->produto.quantidade_vendida);
        fgetc(ponteiro_pagamento); // Pula para a próxima linha após o fscanf

        leitor->anterior = NULL;
        leitor->proxima = NULL;

        if (carrinho_compra == NULL) // Se for o primeiro nó da lista
        {
            carrinho_compra = leitor;
        }
        else // Adicionando no final da lista
        {
            node *atual = carrinho_compra;
            while (atual->proxima != NULL)
            {
                atual = atual->proxima;
            }

            leitor->anterior = atual;
            atual->proxima = leitor;
        }
        tamanho++;
    }
    fclose (ponteiro_pagamento);
    remove("venda.txt");

    printf("\t-- CUPOM FISCAL --\n"); // mostrar o recibo
    node *atual = carrinho_compra; // Inicia a partir do primeiro nó
    atual = atual->proxima;

    for (int i = 0; i < tamanho; i++)
    {
       printf("Item %i : %s  unitário: R$%.2f x %i: R$%.2f \n", i+1, atual->produto.nome_item,
                                                    atual->produto.preco_item, atual->produto.quantidade_vendida,
                                                    atual->produto.preco_item * atual->produto.quantidade_vendida);
        total_pagar += atual->produto.preco_item * atual->produto.quantidade_vendida;
        atual = atual->proxima;
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
                    return; // repensar aqui altos trampo
                    pagamento();
                }
            
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
    printf("Compra finalizada..\n");
    getchar();

    return;
}

void relatorio()
{
    node *carrinho_compra = NULL;
    carrinho_compra = (node*)malloc(sizeof(node));

    FILE *ponteiro_pagamento = NULL;
    int tamanho = 0;

    ponteiro_pagamento = fopen("relatorio.txt", "r");
    if (ponteiro_pagamento == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    while (0 != 1) // loop infinito que sera quebrado dentro da execução
    {
        node *leitor = (node*)malloc(sizeof(node));
        if (leitor == NULL)
        {
            printf("Erro ao alocar memória!\n");
            exit(1);
        }

        if (fscanf(ponteiro_pagamento, "%d", &leitor->produto.codigo_item) != 1)
        { // break quando não for possível ler o campo codigo_item. Isso evita a leitura quando o arquivo tem uma linha em branco no final
            free(leitor);
            break; // Se não conseguir ler o código_item, sai do loop
        }
        fgetc(ponteiro_pagamento);
        fgets(leitor->produto.nome_item, 25, ponteiro_pagamento);
        int n = strlen(leitor->produto.nome_item);
        leitor->produto.nome_item[n-1] = '\0'; // Remove o '\n'
        fscanf(ponteiro_pagamento, "%f %d %d", &leitor->produto.preco_item, &leitor->produto.quantidade_item,
                                        &leitor->produto.quantidade_vendida);
        fgetc(ponteiro_pagamento); // Pula para a próxima linha após o fscanf

        leitor->anterior = NULL;
        leitor->proxima = NULL;

        if (carrinho_compra == NULL) // Se for o primeiro nó da lista
        {
            carrinho_compra = leitor;
        }
        else // Adicionando no final da lista
        {
            node *atual = carrinho_compra;
            while (atual->proxima != NULL)
            {
                atual = atual->proxima;
            }

            leitor->anterior = atual;
            atual->proxima = leitor;
        }
        tamanho++;
    }
    fclose (ponteiro_pagamento);

    node *atual = carrinho_compra; // Inicia a partir do primeiro nó
    atual = atual->proxima;


    time_t current_time;
    char nome_data[100];
    struct tm* time_info; //

    // Obter a hora atual
    current_time = time(NULL);

    time_info = localtime(&current_time); // obter a struct tm para a hora atual

    // Formatar a data e hora atual como uma string
    strftime(nome_data, sizeof(nome_data), "arquivo_%Y-%m-%d_%H-%M-%S.txt", time_info);

    FILE* ponteiro_horario = fopen(nome_data, "w");

    printf("\t\t\t---RELATORIO DE VENDAS----\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("Item %5i :  %-25s \t  | Quantidade vendida: %-5i\t | Quantidade no estoque: %-10i\n", atual->produto.codigo_item, atual->produto.nome_item,
                                                                                                    atual->produto.quantidade_vendida, atual->produto.quantidade_item);
        fprintf(ponteiro_horario, "Item %i : %s  | Quantidade vendida: %i | Quantidade no estoque: %i\n", atual->produto.codigo_item, atual->produto.nome_item,
                                                                                                    atual->produto.quantidade_vendida, atual->produto.quantidade_item);
        atual = atual->proxima;
    }

    fclose(ponteiro_horario);

    printf("\nPressione qualquer tecla para retornar ao menu de vendas\n");
    char parada[1];
    scanf("%c", parada);
    getchar();


    return;
}
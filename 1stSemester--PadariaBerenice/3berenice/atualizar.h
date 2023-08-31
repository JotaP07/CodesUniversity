void atualizar()
{
    visualizar_estoque();

    int codigo_alterar_estoque = 0;
    int unidades = 0;
    int escolha_estoque_ou_preco = 0;
    int indice = 0;
    int max_produtos = descobrir_tamanho();
    FILE *ponteiro = NULL;
    printf("Digite o código do produto que se deseja alterar.\n");
    do
    {
        printf("Digite um código de produto existente.\n-> ");
        scanf("%d", &codigo_alterar_estoque); // fazer função pra verificar
        getchar();

        indice = verificar_cod_cadastro(codigo_alterar_estoque); // o retorno dessa função dá o índice caso sucesso
        if (indice == -1)
        {
            printf("Código não cadastrado.\n");
        }
    }
    while (indice == -1);

    estoque_global = aloca_vetor(max_produtos); // aloca
    ler_txt(estoque_global, max_produtos);  // prenche com o txt

    printf("Item escolhido: %s \nQuantidade disponível no momento: %i \nPreço atual R$%.2f\n", estoque_global[indice].nome_item,
                    estoque_global[indice].quantidade_item, estoque_global[indice].preco_item);
    printf("[1] Se deseja cadastrar unidades para o estoque.\n[2] Se deseja alterar o preço do item.\n-> ");
    escolha_estoque_ou_preco = validar (escolha_estoque_ou_preco, 1, 2);
    if (escolha_estoque_ou_preco == 1)
    {
        printf("Atualize o estoque de %s \nQuantidade atual: %i \n-> ", estoque_global[indice].nome_item,
                                                                estoque_global[indice].quantidade_item);
        unidades = validar(unidades, -estoque_global[indice].quantidade_item, 9999); // caso queira retirar sem vender 
        estoque_global[indice].quantidade_item += unidades; // linha onde o cadastro é efetivado
        reescrever_txt(max_produtos);
    }
    else if (escolha_estoque_ou_preco == 2)
    {
        int bool_verificador = 0;
        printf("Digite o novo preço do %s. Atualmente o preço é: R$%.2f\n-> ", estoque_global[indice].nome_item,
                                                                             estoque_global[indice].preco_item);
        do
        {
            bool_verificador = 0;
            scanf("%f", &estoque_global[indice].preco_item);
            getchar();
            if (estoque_global[indice].preco_item < 0)
            {
                printf("O valor não pode ser menor que 0!\n");
                bool_verificador++;
            }
        } while (bool_verificador != 0);
        reescrever_txt(max_produtos);
    }
    free(estoque_global); // libera depois de qualquer um dos if
    printf("Deseja fazer outra mudança?\n[1] para sim \n[2] para não.\n-> ");
    int continuar = 0;
    continuar = validar(continuar, 1, 2);

    if (continuar == 1)
    {
        atualizar();
    }
    else if (continuar == 2)
    {
        return;
    }
    return;
}
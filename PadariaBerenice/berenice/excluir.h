void excluir_produto() // candidato pra ir pra .h ou .c
{
    int produto_excluir = 0;
    int confirmar_excluir = 0;
    int max_produtos = descobrir_tamanho();
    int indice = 0;
    visualizar_estoque();
    printf("Qual produto deseja excluir?\n");
    do
    {
        printf("Digite o código de um produto existente.\n-> ");
        scanf("%d", &produto_excluir);
        getchar();
        indice = verificar_cod_cadastro(produto_excluir); // o retorno dessa função dá o ínice caso sucesso
        if (indice == -1)
        {
            printf("Código não cadastrado.\n");
        }
    }
    while (indice == -1);
    estoque_global = aloca_vetor(max_produtos);
    ler_txt(estoque_global, max_produtos);

    printf("%s escolhido. Tem certeza que deseja excluir?\n[1] Para sim\n[2] Para não\n-> ", estoque_global[indice].nome_item);
    confirmar_excluir = validar(confirmar_excluir, 1, 2);
    if (confirmar_excluir == 1)
    {
        for (int i = indice; i < max_produtos - 1; i++)
        {
            estoque_global[i] = estoque_global[i+1]; // retira o item excluído e passa os elementos subsequentes para preencher o espaço
        }
        max_produtos--; // o maximo diminuiu em 1
        reescrever_txt(max_produtos);
        ler_txt(estoque_global, max_produtos); // da pra remover eu acho
    }
    free(estoque_global);
    return;

}
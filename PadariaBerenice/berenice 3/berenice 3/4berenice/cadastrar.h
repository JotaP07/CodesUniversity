void cadastrar_estoque()
{
    system("clear");

    visualizar_estoque();
    printf("Opção escolhida: Cadastrar.\n");
    printf("Quantos produtos novos deseja cadastrar?\n-> ");
    int quantos_cadastros = 0;
    int quantidade_antiga = descobrir_tamanho();

    quantos_cadastros = validar(quantos_cadastros, 1, 10);

    for (int i = 0; i < quantos_cadastros; i++)
    {
        estoque_global = aloca_vetor(1); // 1 pq só precisa 1 espaço pois vai dar free logo (um item de c)
        printf("\nDigite os seguintes dados para o cadastrar o item:\n");
        printf("Código do item:\n-> ");
        do
        {
            scanf("%d", &estoque_global[0].codigo_item);
            getchar();
        }
        while (verificar_cod_cadastro(estoque_global[0].codigo_item) != -1); // -1 é o retorno da função em caso de nenhum cadastro igual

        printf("Nome do item:\n-> ");
        do
        {
            fgets(estoque_global[0].nome_item, 25, stdin); // fazer funçaõ pra verificar se isalpha ctype isalphabetic
            int n = strlen(estoque_global[0].nome_item); // isso tira o \n
            estoque_global[0].nome_item[n-1] = '\0';
        }
        while (verificar_nome_cadastro(estoque_global[0].nome_item) != -1);

        printf("Preço unitário do item\n-> ");
        do
        {
            scanf("%f", &estoque_global[0].preco_item); // maior que 0
            getchar();
            if (estoque_global[0].preco_item <= 0)
            {
                printf("O preço não pode ser 0 ou menor.\n-> ");
            }
        }
        while (estoque_global[0].preco_item <= 0);

        printf("Quantidade em estoque\n-> ");
        estoque_global[0].quantidade_item = validar(estoque_global[0].quantidade_item, 0, 9999); // nao pode ser < 0
        salvar_txt(1); // escreve a partir da ultima linha, sempre só adicionando
        free(estoque_global);
    }

    return;
}
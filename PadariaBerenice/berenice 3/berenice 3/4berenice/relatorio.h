void relatorio_vendas() // candidato pra ir pra .h ou .c
{
    FILE *ponteiro_relatorio = NULL;
    int tamanho = 0;
    int indice = 0;

    system("clear");// limpa a tela quando executado.
    const time_t timer = time(NULL);

    estoque *auxiliar_relatorio;

    ponteiro_relatorio = fopen("relatorio.txt", "r"); //tem que abrir o venda
    if (ponteiro_relatorio == NULL)
    {
        printf("Nenhuma venda feita! Retornando ao menu...\n");
        sleep(2);
        return;
    }

    for (int i = 0; feof(ponteiro_relatorio) == 0; i++)
    {
        char temp[25];
        fgets(temp, 25, ponteiro_relatorio); // só pra pular a linha
        tamanho = i;
    }

    tamanho = tamanho / 5;

    auxiliar_relatorio = aloca_vetor(tamanho);

    rewind(ponteiro_relatorio);

    while(!feof(ponteiro_relatorio))
    {
        fscanf(ponteiro_relatorio, "%i", &auxiliar_relatorio[indice].codigo_item);
        fgetc(ponteiro_relatorio);
        fgets(auxiliar_relatorio[indice].nome_item, 25, ponteiro_relatorio);
        int n = strlen(auxiliar_relatorio[indice].nome_item); // isso tira o \n
        auxiliar_relatorio[indice].nome_item[n-1] = '\0';
        fscanf(ponteiro_relatorio, "%f %d %d", &auxiliar_relatorio[indice].preco_item,
                                                &auxiliar_relatorio[indice].quantidade_item,
                                                &auxiliar_relatorio[indice].quantidade_vendida);
        fgetc(ponteiro_relatorio);
        indice++;
    }

    printf("\t\t\t---RELATORIO DE VENDAS----\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("Item %5i :  %-25s \t  | Quantidade vendida: %-5i\t | Quantidade no estoque: %-10i\n", auxiliar_relatorio[i].codigo_item, auxiliar_relatorio[i].nome_item,
                                            auxiliar_relatorio[i].quantidade_vendida, auxiliar_relatorio[i].quantidade_item);
    }

    fclose(ponteiro_relatorio);


    time_t current_time;
    char nome_data[100];
    struct tm* time_info; //

    // Obter a hora atual
    current_time = time(NULL);


    time_info = localtime(&current_time); // obter a struct tm para a hora atual

    // Formatar a data e hora atual como uma string
    strftime(nome_data, sizeof(nome_data), "arquivo_%Y-%m-%d_%H-%M-%S.txt", time_info);

    FILE* ponteiro_horario = fopen(nome_data, "w");
    for (int i = 0; i < tamanho; i++)
    {
        fprintf(ponteiro_horario, "Item %i : %s  | Quantidade vendida: %i | Quantidade no estoque: %i\n", auxiliar_relatorio[i].codigo_item, auxiliar_relatorio[i].nome_item,
                                            auxiliar_relatorio[i].quantidade_vendida, auxiliar_relatorio[i].quantidade_item);
    }
    fclose(ponteiro_horario);

    free(auxiliar_relatorio);

    printf("\nPressione qualquer tecla para retornar ao menu de vendas\n");
    char parada[1];
    scanf("%c", parada);
    getchar();

    return;
}
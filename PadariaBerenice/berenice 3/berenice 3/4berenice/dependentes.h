void cadastrar_estoque();
void visualizar_estoque();
int verificar_cod_cadastro(int codigo);
void binario();
void reescrever_txt(int cadastros_novos);


void visualizar_estoque()
{
    system("clear");
    printf("\t\t-- ESTOQUE --\n");
    printf("   Codigo  |          Nome                | Valor\t| Estoque\n");
    int quantos_produtos = 0;
    quantos_produtos = descobrir_tamanho();

    estoque_global = aloca_vetor(quantos_produtos);
    ler_txt(estoque_global, quantos_produtos);

for (int i = 0; i < quantos_produtos; i++)
{
    printf("   %-5i   | %-25s\t  | R$%.2f \t|   %-10i   \n", estoque_global[i].codigo_item, estoque_global[i].nome_item,
                                                    estoque_global[i].preco_item, estoque_global[i].quantidade_item);
}


    free(estoque_global);//para nao ficar memoria no vetor_global

    return;
}

int verificar_cod_cadastro(int codigo)
{
    int qntd_produtos = descobrir_tamanho();
    estoque *estoque_temporario = aloca_vetor(qntd_produtos);
    ler_txt(estoque_temporario, qntd_produtos);

    for(int i = 0; i < qntd_produtos; i++)
    {
        if (codigo == estoque_temporario[i].codigo_item)
        {
            printf("Código já cadastrado.\n-> ");
            free(estoque_temporario);
            return i; // retorna o índice que possuí o mesmo cadastro
        }
    }
    free(estoque_temporario);
    return -1; // para ser sempre diferente do i
}

int verificar_nome_cadastro(char nome_item[25])
{
    int qntd_produtos = descobrir_tamanho();
    estoque *estoque_temporario = aloca_vetor(qntd_produtos);
    ler_txt(estoque_temporario, qntd_produtos);
    if (nome_item[0] == '\0')
    {
        printf("Insira um nome.\n-> ");
        free(estoque_temporario);
        return 1;
    }

    for (int i = 0; i < qntd_produtos; i++)
    {
        if (strcmp(nome_item, estoque_temporario[i].nome_item) == 0)
        {
            printf("Nome já cadastrado.\n-> ");
            free(estoque_temporario);
            return i;
        }
    }
    for (int i = 0, n = strlen(nome_item); i < n; i++)
    {
        if (isdigit(nome_item[i]))
        {
            printf("O nome deve conter apenas letras.\n-> ");
            free(estoque_temporario);
            return i;
        }
    }
    for (int i = 0, n = strlen(nome_item), contador_espacos = 0; i < n; i++)
    {
        if (isspace(nome_item[i]))
        {
            contador_espacos++;
        }
        if (contador_espacos == n)
        {
            printf("O nome não pode conter apenas espaços.\n-> ");
            free(estoque_temporario);
            return i;
        }
    }
    free(estoque_temporario);
    return -1; // para ser sempre diferente do i
}

void binario()
{
    int tamanho = descobrir_tamanho();

    FILE* aquivobinario = fopen ("archivo.bin", "wb");
    if (aquivobinario == NULL)
    {
        printf("Erro ao abrir arquivo archivo.bin");
        exit(1);
    }

    ler_txt(estoque_global, tamanho);

    fwrite(&tamanho, sizeof(int), 1, aquivobinario ); //&tamanho serve para dar valor ao pontero que vai ser escrito

    fputc('\n', aquivobinario);
    for (int i = 0; i < tamanho; i++)
    {
        fwrite (&estoque_global[i].codigo_item , sizeof(int), 1 , aquivobinario );
        fputc('\n', aquivobinario );
        fwrite (estoque_global[i].nome_item, sizeof(char), strlen(estoque_global[i].nome_item) + 1, aquivobinario );
        fputc('\n', aquivobinario );
        fwrite (&estoque_global[i].preco_item, sizeof(int), 1 , aquivobinario );
        fputc('\n', aquivobinario );
        fwrite (&estoque_global[i].quantidade_vendida, sizeof(int), 1 , aquivobinario );
        fputc('\n', aquivobinario );
        fwrite (&estoque_global[i].quantidade_item, sizeof(int), 1, aquivobinario );
        fputc('\n', aquivobinario );
    }

    fclose(aquivobinario);

}

void reescrever_txt(int cadastros_novos)
{
    FILE *ponteiro_reescrever = NULL;
    int total_produtos = 0;
    total_produtos = cadastros_novos;
    ponteiro_reescrever = fopen("produtos.txt", "w");
    if (ponteiro_reescrever == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    fprintf(ponteiro_reescrever, "%i\n", total_produtos);
    for (int i = 0; i < cadastros_novos; i++)
    {
        fprintf(ponteiro_reescrever, "%i\n", estoque_global[i].codigo_item);
        fprintf(ponteiro_reescrever, "%s\n", estoque_global[i].nome_item);
        fprintf(ponteiro_reescrever, "%.2f\n", estoque_global[i].preco_item);
        fprintf(ponteiro_reescrever, "%i\n", estoque_global[i].quantidade_item);
        fprintf(ponteiro_reescrever, "%i\n", estoque_global[i].quantidade_vendida);
    }
    fclose(ponteiro_reescrever);

    binario(); // salva no binario tb

    return;
}
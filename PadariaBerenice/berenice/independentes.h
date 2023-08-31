typedef struct
{
    char nome_item[25];
    int codigo_item; // ver requisito pra ser unsigned long long
    float preco_item;
    int quantidade_item;
    float subtotal;
    int quantidade_vendida;
}   estoque;

estoque *estoque_global;

void ler_txt(estoque *vetor, int quantidade_produtos);
int descobrir_tamanho();
int validar(int opcao, int minimo, int maximo);
estoque *aloca_vetor(int tamanho);
void sair();
void salvar_txt(int cadastros_novos);

void ler_txt(estoque *vetor, int quantidade_produtos) // nao chama outra função
{
    FILE *ponteiro_ler = NULL;
    char aux[20];
    ponteiro_ler = fopen("produtos.txt", "r");
    if (ponteiro_ler == NULL)
    {
        printf("Erro ao abrir um arquivo!\n");
        exit(1);
    }
    fgets(aux, 20, ponteiro_ler); // pula a primeira linha
    for (int i = 0; i < quantidade_produtos; i++) // ou mudar pra pegar o tamanho
    {
        fscanf(ponteiro_ler, "%i", &vetor[i].codigo_item);
        fgetc(ponteiro_ler);
        fgets(vetor[i].nome_item, 25, ponteiro_ler);
        int n = strlen(vetor[i].nome_item);
        vetor[i].nome_item[n-1] = '\0'; // isso tira o \n
        fscanf(ponteiro_ler, "%f %d %d", &vetor[i].preco_item, &vetor[i].quantidade_item,
                                                            &vetor[i].quantidade_vendida);
        fgetc(ponteiro_ler); // pula para prox linha depois do fscanf
    }
    fclose(ponteiro_ler);
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
// seus argumentos sao: a variavel qual se quer atribuir um valor, o valor minimo permitido e o valor máximo permitido.


int descobrir_tamanho() // só do produtos.txt // nao chama outra funçao
{
    //descobrir quantidade de prod.
    int tamanho = 0;
    FILE *ponteiro = NULL;
    ponteiro = fopen("produtos.txt", "r");
    if (ponteiro == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
    for (int i = 0; feof(ponteiro) == 0; i++)
    {
        char temp[25];
        fgets(temp, 25, ponteiro); // só pra pular a linha
        tamanho = i;
    }
    fclose(ponteiro);
    tamanho = tamanho / 5; // tem 5 linhas de cada produto
    return tamanho;
}

estoque *aloca_vetor(int tamanho) // existe por causa do verificador de erro // nao chama outra funçao
{
    estoque *vetor;
    vetor = (estoque*) calloc(tamanho, sizeof(estoque));
    if (vetor == NULL)
    {
        printf("Memória não alocada, erro grave!\n");
        exit(1);
    }
    return vetor;
}

void sair() // nao chama outra funçao
{
    printf("Finalizando...\n");
    exit(0);
}

void salvar_txt(int cadastros_novos) // nao chama outra função
{
    FILE *ponteiro_salvar = NULL;
    ponteiro_salvar = fopen("produtos.txt", "a");
    if (ponteiro_salvar == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    //fprintf(ponteiro_salvar, "%i\n", total_de_produtos);
    for (int i = 0; i < cadastros_novos; i++)
    {
        fprintf(ponteiro_salvar, "%i\n", estoque_global[i].codigo_item);
        fprintf(ponteiro_salvar, "%s\n", estoque_global[i].nome_item);
        fprintf(ponteiro_salvar, "%.2f\n", estoque_global[i].preco_item);
        fprintf(ponteiro_salvar, "%i\n", estoque_global[i].quantidade_item);
        fprintf(ponteiro_salvar, "%i\n", estoque_global[i].quantidade_vendida);
    }

    fclose(ponteiro_salvar);

    return;
}
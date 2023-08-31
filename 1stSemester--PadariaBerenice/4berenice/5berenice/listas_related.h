 typedef struct
{
    char nome_item[25];
    int codigo_item;
    float preco_item;
    int quantidade_item;
    float subtotal;
    int quantidade_vendida;
}   estoque;

typedef struct lista
{
    estoque produto;
    struct lista *proxima;
    struct lista *anterior;
} node;

node *lista = NULL; // cabeça da lista

void adicionar_node();
void mostrarlista();
void destruirLista(node *cabeca);
void salvar_txt();
void ler_txt();
void alterar();
int verifica_cod(int codigo);
int verificar_nome_cadastro(char nome_item[25]);

void adicionar_node()
{
    node *temporario = (node *) malloc(sizeof(node));
    if (temporario == NULL)
    {
        printf("Erro de alocação!\n");
        exit(1);
    }

    printf("\nDigite os seguintes dados para o cadastrar o item:\n");
    do
    {
        printf("Código do item:\n-> ");
        scanf("%d", &temporario->produto.codigo_item);
        getchar();
    } while (verifica_cod(temporario->produto.codigo_item) == -1);

    do
    {
        printf("Nome do item:\n-> ");
        fgets(temporario->produto.nome_item, 25, stdin); // fazer funçaõ pra verificar se isalpha ctype isalphabetic
        int n = strlen(temporario->produto.nome_item); // isso tira o \n
        temporario->produto.nome_item[n-1] = '\0';
    } while (verificar_nome_cadastro(temporario->produto.nome_item) != -1);

    do
    {
        printf("Preço unitário do item\n-> ");
        scanf("%f", &temporario->produto.preco_item); // maior que 0
        getchar();
    } while (temporario->produto.preco_item < 0);

    do
    {
        printf("Quantidade em estoque\n-> ");
        scanf("%d", &temporario->produto.quantidade_item);
        getchar();
    } while (temporario->produto.quantidade_item < 0);

    temporario->produto.quantidade_vendida = 0;

    temporario->anterior = NULL;
    temporario->proxima = NULL;

    if (lista == NULL) // se for o começo da lista
    {
        lista = temporario;
    }
    else // adicionando no topo
    {
        temporario->proxima = lista;
        lista->anterior = temporario;
        lista = temporario;
    }
}

void mostrarlista()
{
    if (lista == NULL)
    {
        printf("Lista vazia!\n");
        getchar();
        printf("Digite qualquer tecla para continuar");
        getchar();
        return;
    }

    system("clear");
    printf("\t\t-- ESTOQUE --\n");
    printf("   Codigo  |          Nome                | Valor\t| Estoque\n");
    node *ptr = lista;
    while (ptr != NULL)
    {
         printf("   %-5i   | %-25s\t  | R$%.2f \t|   %-10i   \n",ptr->produto.codigo_item, ptr->produto.nome_item,
                                                    ptr->produto.preco_item, ptr->produto.quantidade_item);

        ptr = ptr->proxima;
    }

    printf("Digite qualquer tecla para continuar");
    getchar();
    getchar();

    return;
}

void destruirLista(node *cabeca) // recursiva e testada com valgrind
{
    if (cabeca == NULL)
    {
        return;
    }

    destruirLista(cabeca->proxima);
    free(cabeca);
}

void salvar_txt()
{
    if (lista == NULL)
    {
        return;
    }

    FILE *ponteiro_salvar = NULL;
    ponteiro_salvar = fopen("produtos.txt", "w");
    if (ponteiro_salvar == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    node *atual = lista;
    while (atual != NULL)
    {
        fprintf(ponteiro_salvar, "%i\n", atual->produto.codigo_item);
        fprintf(ponteiro_salvar, "%s\n", atual->produto.nome_item);
        fprintf(ponteiro_salvar, "%.2f\n", atual->produto.preco_item);
        fprintf(ponteiro_salvar, "%i\n", atual->produto.quantidade_item);
        fprintf(ponteiro_salvar, "%i\n", atual->produto.quantidade_vendida);

        atual = atual->proxima;
    }

    fclose(ponteiro_salvar);

    return;
}

void ler_txt()
{
    FILE *ponteiro_ler = NULL;
    ponteiro_ler = fopen("produtos.txt", "r");
    if (ponteiro_ler == NULL)
    {
        printf("Erro ao abrir um arquivo!\n");
        exit(1);
    }

    while (0 != 1) // loop infinito que sera quebrado dentro da execução
    {
        node *novo = (node*)malloc(sizeof(node));
        if (novo == NULL)
        {
            printf("Erro ao alocar memória!\n");
            exit(1);
        }

        if (fscanf(ponteiro_ler, "%d", &novo->produto.codigo_item) != 1)
        { // break quando não for possível ler o campo codigo_item. Isso evita a leitura quando o arquivo tem uma linha em branco no final
            free(novo);
            break; // Se não conseguir ler o código_item, sai do loop
        }
        fgetc(ponteiro_ler);
        fgets(novo->produto.nome_item, 25, ponteiro_ler);
        int n = strlen(novo->produto.nome_item);
        novo->produto.nome_item[n-1] = '\0'; // Remove o '\n'
        fscanf(ponteiro_ler, "%f %d %d", &novo->produto.preco_item, &novo->produto.quantidade_item,
                                        &novo->produto.quantidade_vendida);
        fgetc(ponteiro_ler); // Pula para a próxima linha após o fscanf

        novo->anterior = NULL;
        novo->proxima = NULL;

        if (lista == NULL) // Se for o primeiro nó da lista
        {
            lista = novo;
        }
        else // Adicionando no final da lista
        {
            node *atual = lista;
            while (atual->proxima != NULL)
            {
                atual = atual->proxima;
            }

            novo->anterior = atual;
            atual->proxima = novo;
        }
    }


    fclose(ponteiro_ler);
    return;
}

void alterar()
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

    mostrarlista();
    printf("Digite o código do produto que se deseja alterar.\n");
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

    printf("Item escolhido: %s \nQuantidade disponível no momento: %i \nPreço atual R$%.2f\n", ptr->produto.nome_item,
                                                                 ptr->produto.quantidade_item, ptr->produto.preco_item);
    printf("[1] Se deseja cadastrar unidades para o estoque.\n[2] Se deseja alterar o preço do item.\n-> ");
    escolha_estoque_ou_preco = validar (escolha_estoque_ou_preco, 1, 2);

    int unidades = 0;
    if (escolha_estoque_ou_preco == 1)
    {
        printf("Atualize o estoque de %s \nQuantidade atual: %i \n-> ", ptr->produto.nome_item,
                                                                        ptr->produto.quantidade_item);
        unidades = validar(unidades, -ptr->produto.quantidade_item, 9999); // caso queira retirar sem vender
        ptr->produto.quantidade_item += unidades; // linha onde o cadastro é efetivado
    }
    else if (escolha_estoque_ou_preco == 2)
    {
        int bool_verificador = 0;
        printf("Digite o novo preço do %s. Atualmente o preço é: R$%.2f\n-> ", ptr->produto.nome_item,
                                                                        ptr->produto.preco_item);
        do
        {
            bool_verificador = 0;
            scanf("%f", &ptr->produto.preco_item);
            getchar();
            if (ptr->produto.preco_item < 0)
            {
                printf("O valor não pode ser menor que 0!\nDigite o novo valor.\n-> ");
                bool_verificador++;
            }
        } while (bool_verificador != 0);

    }

    salvar_txt(); // mudança feita entao alterar txt

    printf("Deseja fazer outra mudança?\n[1] para sim \n[2] para não.\n-> ");
    int continuar = 0;
    continuar = validar(continuar, 1, 2);

    if (continuar == 1)
    {
        alterar();
    }
    else if (continuar == 2)
    {
        printf("Digite qualquer tecla para continuar");  //mudar pra um sleep
        getchar();
        getchar();
        return;
    }


    return;
}

void removerNode()
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

    mostrarlista();
    printf("Digite o código do produto que deseja excluir.\n");
    scanf("%d", &codigo_comparar); // fazer verificação completa
    getchar();

    node *ptr = lista;
    node *temp = NULL;
    while (ptr->produto.codigo_item != codigo_comparar) // vai parar quando achar
    {
        ptr = ptr->proxima;
        if (ptr == NULL) // se chegou no fim
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

    printf("%s escolhido.\n", ptr->produto.nome_item);
    printf("Deseja realmente excluir?\n[1] para sim \n[2] para não.\n-> ");
    int continuar = 0;
    continuar = validar(continuar, 1, 2);
    if (continuar == 1)
    {
        if (ptr == lista) // se é o primeiro nó
        {
            lista = ptr->proxima;
            if (lista != NULL)
            {
                lista->anterior = NULL;
            }
            free(ptr);
        }
        else
        {
            ptr->anterior->proxima = ptr->proxima;
            if (ptr->proxima != NULL)
            {
                ptr->proxima->anterior = ptr->anterior;
            }
            free(ptr);
        }
        salvar_txt(); // joga pro txt depois de mudar a lista
        printf("Produto removido com sucesso!\n");
        getchar();
        printf("Digite qualquer tecla para continuar");
        getchar();
    }
    else
    {
        return;
    }

}

int verifica_cod(int codigo)
{
    if (lista == NULL)
    {
        printf("Lista vazia!\n");
        getchar();
        printf("Digite qualquer tecla para continuar");
        getchar();
        return -2;
    }

    int contador_nao_encontrado = 0;

    node *ptr = lista;
    node *temp = NULL;
    while (ptr->produto.codigo_item != codigo) // vai parar quando achar
    {
        ptr = ptr->proxima;
        if (ptr == NULL) // se chegou no fim
        {
            contador_nao_encontrado++;
            break;
        }
    }

    if (contador_nao_encontrado != 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int verificar_nome_cadastro(char nome_item[25])
{

    if (nome_item[0] == '\0')
    {
        printf("Insira um nome.\n-> ");
        return 1;
    }

    for (int i = 0, n = strlen(nome_item); i < n; i++)
    {
        if (isdigit(nome_item[i]))
        {
            printf("O nome deve conter apenas letras.\n-> ");
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

            return i;
        }
    }

    return -1; // para ser sempre diferente do i
}
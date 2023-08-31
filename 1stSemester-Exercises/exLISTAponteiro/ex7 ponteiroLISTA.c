#include <stdio.h>

int ler_frase(char *string_UM, char *string_DOIS) {
    while (*string_UM != '\0') {
        if (*string_UM == ' ') {
            string_UM++;
            continue;
        }
        char *pUM = string_UM;
        char *pDOIS = string_DOIS;

        while (*pDOIS != '\0' && *pDOIS == *pUM) {
            if (*pDOIS == ' ') {
            pDOIS++;
            continue;
        }
            if (*pDOIS == '\0') {
                return 1;
            }
            pUM++;
            pDOIS++;
        }
        string_UM++;
    }
    return 0;
}

int main() {
    char string_UM[50];
    char string_DOIS[50];

    printf("Digite a primeira frase: ");
    fgets(string_UM, sizeof(string_UM), stdin);

    printf("Digite a segunda frase: ");
    fgets(string_DOIS, sizeof(string_DOIS), stdin);

    int resu = ler_frase(string_UM, string_DOIS);

    if (resu == 0) {
        printf("as frases sao iguais(OCORRE DENTRO)\n");
    }
    else {
        printf("as frases nao sao iguais(NAUM OCORRE DENTRO)\n");
    }

    return 0;
}

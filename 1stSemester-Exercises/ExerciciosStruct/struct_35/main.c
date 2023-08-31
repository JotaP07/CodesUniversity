#include <stdio.h>
#include <locale.h>

// Definindo a estrutura para representar uma hora
struct hora {
    int hora;
    int minuto;
    int segundo;
};

int main() {

    setlocale(LC_ALL, "Portuguese");

    struct hora vetorTEMPO[5]; // Vetor com 5 posições de estrutura Hora
    int i;

    // FAZ A LEITURA DAS CINCO HORAS.
    for (i = 0; i < 5; i++) {
        printf("Digite a hora %d (formato hh:mm:ss): ", i+1);
        scanf("%d:%d:%d", &vetorTEMPO[i].hora, &vetorTEMPO[i].minuto, &vetorTEMPO[i].segundo);
    }

    // ACHAR A MAIOR HORA
    struct hora maiorHora = vetorTEMPO[0];
    for (i = 1; i < 5; i++) {
        if (vetorTEMPO[i].hora > maiorHora.hora) {
            maiorHora = vetorTEMPO[i];
        } else if (vetorTEMPO[i].hora == maiorHora.hora && vetorTEMPO[i].minuto > maiorHora.minuto) {
            maiorHora = vetorTEMPO[i];
        } else if (vetorTEMPO[i].hora == maiorHora.hora && vetorTEMPO[i].minuto == maiorHora.minuto && vetorTEMPO[i].segundo > maiorHora.segundo) {
            maiorHora = vetorTEMPO[i];
        }
    }

    // IMPRIMI A MAIOR HORA
    printf("\nMaior hora encontrada: %02d:%02d:%02d", maiorHora.hora, maiorHora.minuto, maiorHora.segundo);
    printf("\n");
    return 0;
}

#include <stdio.h>
#include <locale.h>

typedef struct {
    int x;
    int y;
} Ponto;

typedef struct {
    Ponto superior_esquerdo;
    Ponto inferior_direito;
} Retangulo;

int ponto_dentro_retangulo(Ponto p, Retangulo r) {
    if (p.x >= r.superior_esquerdo.x && p.x <= r.inferior_direito.x &&
        p.y >= r.superior_esquerdo.y && p.y <= r.inferior_direito.y) {
        return 1;
    } else {
        return 0;
    }
}

int main() {

    setlocale(LC_ALL, "Portuguese");

    Retangulo r;
    printf("Digite as coordenadas do ponto superior esquerdo do retangulo:\n");
    scanf("%d %d", &r.superior_esquerdo.x, &r.superior_esquerdo.y);
    printf("\nDigite as coordenadas do ponto inferior direito do retangulo:\n");
    scanf("%d %d", &r.inferior_direito.x, &r.inferior_direito.y);

    Ponto p;
    printf("\nDigite as coordenadas do ponto a ser verificado:\n");
    scanf("%d %d", &p.x, &p.y);

    if (ponto_dentro_retangulo(p, r)) {
        printf("\nO ponto esta dentro do retangulo.\n");
    } else {
        printf("\nO ponto esta fora do retangulo.\n");
    }

    return 0;
}

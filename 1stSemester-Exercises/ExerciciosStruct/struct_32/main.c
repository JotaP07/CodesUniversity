#include <stdio.h>
#include <math.h>
#include <locale.h>

typedef struct {
    int x;
    int y;
} Ponto;

typedef struct {
    Ponto superior_esquerdo;
    Ponto inferior_direito;
} Retangulo;

float distancia_entre_pontos(Ponto p1, Ponto p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

int area_retangulo(Retangulo r) {
    int base = r.inferior_direito.x - r.superior_esquerdo.x;
    int altura = r.inferior_direito.y - r.superior_esquerdo.y;
    return base * altura;
}

float diagonal_retangulo(Retangulo r) {
    float base = r.inferior_direito.x - r.superior_esquerdo.x;
    float altura = r.inferior_direito.y - r.superior_esquerdo.y;
    return distancia_entre_pontos(r.superior_esquerdo, r.inferior_direito);
}

int perimetro_retangulo(Retangulo r) {
    int base = r.inferior_direito.x - r.superior_esquerdo.x;
    int altura = r.inferior_direito.y - r.superior_esquerdo.y;
    return 2 * (base + altura);
}

int main() {

    setlocale(LC_ALL, "Portuguese");

    Retangulo r;
    printf("Digite as coordenadas do ponto superior esquerdo do retangulo:\n");
    scanf("%d %d", &r.superior_esquerdo.x, &r.superior_esquerdo.y);
    printf("Digite as coordenadas do ponto inferior direito do retangulo:\n");
    scanf("%d %d", &r.inferior_direito.x, &r.inferior_direito.y);

    int area = area_retangulo(r);
    float diagonal = diagonal_retangulo(r);
    int perimetro = perimetro_retangulo(r);

    printf("Area do retangulo: %d\n", area);
    printf("Comprimento da diagonal: %.2f\n", diagonal);
    printf("Perimetro do retangulo: %d\n", perimetro);

    return 0;
}

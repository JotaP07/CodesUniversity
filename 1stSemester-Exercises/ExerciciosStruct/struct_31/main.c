#include <stdio.h>
#include <math.h>
#include <locale.h>

struct Ponto
{
    float x;
    float y;
};

int main()
{

    setlocale(LC_ALL, "Portuguese");

    struct Ponto p1, p2;

    printf("Digite as coordenadas X e Y do primeiro ponto: ");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Digite as coordenadas X e Y do segundo ponto: ");
    scanf("%f %f", &p2.x, &p2.y);

    float distancia = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

    printf("\nA distância entre os pontos (%.2f, %.2f) e (%.2f, %.2f) é %.2f\n", p1.x, p1.y, p2.x, p2.y, distancia);

    return 0;
}

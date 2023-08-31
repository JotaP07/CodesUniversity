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

    struct Ponto p;

    printf("Digite as coordenadas X e Y do ponto: ");
    scanf("%f %f", &p.x, &p.y);

    float distancia = sqrt(pow(p.x, 2) + pow(p.y, 2));

    printf("A dist�ncia do ponto (%.2f, %.2f) at� a origem das coordenadas � %.2f\n", p.x, p.y, distancia);

    return 0;
}

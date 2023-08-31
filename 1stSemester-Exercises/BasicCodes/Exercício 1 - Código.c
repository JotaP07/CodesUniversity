EXERCÍCIO 1	


#include <stdio.h>
#include<locale.h>

int main() {

    float raio, altu, v;

    setlocale(LC_ALL,"Portuguese");

    printf("Insira o raio do cilindro em cm: ");
    scanf("%f", &raio);
    printf("Insira a altura do cilindro em cm: ");
    scanf("%f", &altu);

    v = 3.14159 * raio * raio * altu;
    printf("O volume do cilindro eh: %.2f cm³\n", v);

    if (v >= 1000) {
        printf("\nSuficiente\n");
    } else {
        printf("\nInsuficiente\n");
    }
   return 0;
}
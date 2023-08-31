#include <stdio.h>

int main()
{



    int h, min, seg, total_s;
    char str[50];

    printf("Digite a hora: ");
    scanf("%d", &h);
    fgets(str,50,stdin);

    printf("Digite o minuto: ");
    scanf("%d", &min);
    fgets(str,50,stdin);

    printf("Digite o segundo: ");
    scanf("%d", &seg);
    fgets(str,50,stdin);

    total_s = h * 3600 + min * 60 + seg;

    printf("\t\t--- %d hora(s), %d minuto(s) e %d segundo(s) equivalem a %d segundos ---\n", h, min, seg, total_s);



    return 0;
}
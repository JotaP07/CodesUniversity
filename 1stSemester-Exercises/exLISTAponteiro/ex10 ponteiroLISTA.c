#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    int a = 0;
    int *b = &a;
    int **c = &b;
    int ***d = &c;

    printf("Insira um valor:\n-> ");
    scanf("%d", &a);
    getchar();
    printf("O dobro desse valor é: %d\n", (*b) * 2);
    printf("O triplo desse valor é: %d\n", (**c) * 3);
    printf("O quádruplo desse valor é: %d\n", (***d) * 4);
    return 0;
}

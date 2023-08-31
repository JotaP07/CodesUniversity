#include <stdio.h>

int main()
{
    int array[5];
    int *p = array;

    for(int i = 0; i < 5; i++){
        printf("Digite o valor %d: ", i + 1);
        scanf( "%d", p);
        p++;
    }

    p = array;
    for(int i = 0; i < 5; i++){
         printf("\nO dobro do valor %d eh: %d", i + 1, *p * 2);
         p++;
    }



    return 0;
}

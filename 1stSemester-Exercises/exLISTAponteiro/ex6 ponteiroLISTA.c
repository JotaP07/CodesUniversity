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
        if(*p % 2 == 0){
         printf("\nENDEREÇO DOS VALORES PARES %d: %p", i + 1, p);

        }
        p++;
    }
    return 0;
}

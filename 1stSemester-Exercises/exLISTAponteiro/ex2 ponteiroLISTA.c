#include <stdlib.h>
#include <stdio.h>

int main(){
    int x ;
    int y;

    printf("digite o valores de x e y: ");
    scanf("%d %d", &x,&y);

    int *px = x;
    int *py = y;

    printf("\nvalor de x: %d", px);
    printf("\nvalor de y: %d", py);

    if(px > py){
        printf("\npx - %p eh maior que py - %p", px, py);
    }
    else
    {
        printf("py - %p eh maior que px - %p", py, px);
    }



return 0;
}

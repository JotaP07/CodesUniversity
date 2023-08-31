#include <stdlib.h>
#include <stdio.h>

int main(){
    int x = 10;
    int y = 2;
    int *px = x;
    int *py = y;

    if(px > py){
        printf("px - %p eh maior que py - %p", px, py);
    }
    else
    {
        printf("py - %p eh maior que px - %p", py, px);
    }

return 0;
}

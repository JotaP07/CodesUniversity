assim? #include <stdlib.h>
#include <stdio.h>

int main(){
    float x[10];

    float *px = x;

    for( int i = 0; i < 10; i++){
    printf("endereco do elemento %d : %p",i+1,(void *) &px[i]);
    printf("\n");
    }


return 0;
}

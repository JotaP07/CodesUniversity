#include <stdio.h>

int main()
{
    float matriz[3][3];
    float *p = &matriz[0][0];

    for(int i = 0; i < 3; i++){
         printf("\nEndereço da linha %d da matriz: %p \n",i + 1, p);
         for(int j = 0; j < 3; j++){
            printf("\nEndereço da coluna %d da matriz: %p \n",j + 1, p);
            p++;
         }
    }


    return 0;
}

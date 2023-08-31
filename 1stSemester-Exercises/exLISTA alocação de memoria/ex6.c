#include <stdio.h>
#include <stdlib.h>

int **alocarMATRIZ(int linha, int coluna){
    int **matriz;
    matriz = (int**) malloc(linha * sizeof(int*));
    for(int i = 0; i < linha;i++){
    matriz[i] = (int*) malloc(coluna * sizeof(int*));
   
    }
return matriz;
   
}

int verificarVmatriz(int **matriz, int linha, int coluna, int valor){
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna;j++){
            if(matriz[i][j] == valor){
                return 1;
            }
        }
    }
return 0;
}

int main(){
   
    int linha, coluna;
    printf("Digite a quantiade de linhas para a matriz:\n --> ");
    scanf("%d", &linha);

   
    printf("Digite a quantiade de coluna para a matriz:\n --> ");
    scanf("%d", &coluna);


   
    int **matriz = alocarMATRIZ(linha, coluna);
   
    if (matriz == NULL) {
        printf("Erro ao alocar memoria para a matriz.");
        return 1;
    }
   
    printf("\n-- Digite os valores da matriz --\n\n");
    for(int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            printf("Digite o valor para a linha %d coluna %d:\n --> ", i+1,j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

       
    int valor;
   
    printf("\n");
    printf("        -.- \n");
    printf("       ´´ ``     ?\n");
    printf("      //   \\\\ ?\n");
    printf("     ((     ))    ?\n");
    printf("      \\\\   //  ?\n");
    printf("       `-.-´\n");
    printf("        | |\n");
    printf("        | |\n");
    printf("        |_| \n");
    printf("\n");
    printf("-- PROCURAR VALOR --\n");



    printf("Digite o valor que deseja procurar na matriz:\n --> ");
    scanf("%d", &valor);
   
    int verificar = verificarVmatriz(matriz, linha, coluna, valor);
   
    if(verificar == 1){
        printf("\n - O valor %d esta na matriz!!", valor);
    }else{
        printf("\n - O valor %d naum esta na matriz!!", valor);
    }
   
    for (int i = 0; i < linha; i++){
        free(matriz[i]);
    }
    free(matriz);
    printf("\n\n\tF i m");
    return 0;
   
}

#include <stdio.h>
#include <stdlib.h>


int main()
{
 int operacao;
 float total, valor_total;

  // PARTE 1
  printf("          BEM VINDO A PADARIA DA BERENICE \n"      );
  printf("\n");
  printf("                 MENU DE ITENS:                \n");
  printf("   |------------------------------------------|\n");
  printf("   |--COD-|------ITEM-------|--VALOR_(UND)----|\n");
  printf("   |--01--|--PAO DE FORMA---|--R$7,50---------|\n");
  printf("   |--02--|--PAO DE CENTEIO-|--R$8,69---------|\n");
  printf("   |--03--|--BROA DE MILHO--|--R$5,00---------|\n");
  printf("   |--04--|--SONHO----------|--R$4,50---------|\n");
  printf("   |--05--|--TUBAINA--------|--R$3,25---------|\n");
  printf("   |                                          |\n");
  // PARTE 2
  printf ("  DIGITE O CODIGO DO PRODUTO QUE DESEJA:  ");
    scanf("%d",&operacao);


switch(operacao){
  case 1:
      printf ("\nPAO DE FORMA\nPRECO: R$7,50:\n");
  valor_total = 7.5;
  break;
  case 2:
      printf ("\nPAO DE CENTEIO\nPRECO: R$8.69:\n");
    valor_total = 8.69;
    break;
  case 3:
      printf ("\nBROA DE MILHO \nPRECO: R$5.00:\n");
    valor_total = 5.00;
    break;
  case 4:
      valor_total = 4.50;
    printf ("\nSONHO \nPRECO: R$4.50:\n");
    break;
  case 5:
    valor_total = 3.25;
    printf ("\nTUBAINA \nPRECO: R$3.25:\n");
    break;
  default:
    printf ("\n\TOPCAO NAO ENCONTRADA\n");
}



return 0;
}
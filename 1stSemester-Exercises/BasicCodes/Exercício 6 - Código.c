#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

 int main()
 {
     int mes;


     setlocale (LC_ALL,"Portuguese");

     printf(" Digite o número do mês que deseja\n -(ex: 1 = Janeiro)- \n Número:  ");
     scanf("%d",&mes);

     switch(mes)
     {
         case 1:
         printf("\n\tMÊS: Janeiro\n    - Janeiro tem 31 dias -\n");
         break;

         case 2:
         printf("\n\tMÊS: Fevereiro\n    - Fevereiro tem 28 dias -\n");
         break;

         case 3:
         printf("\n\tMÊS: Março\n    - Março tem 31 dias -\n");
         break;

         case 4:
         printf("\n\tMÊS: Abril\n    - Abril tem 30 dias -\n");
         break;

         case 5:
         printf("\n\tMÊS: Maio\n    - Maio tem 31 dias -\n");
         break;

         case 6:
         printf("\n\tMÊS: Junho\n    - Junho tem 30 dias -\n");
         break;

         case 7:
         printf("\n\tMÊS: Julho\n    - Julho tem 31 dias -\n");
         break;

         case 8:
         printf("\n\tMÊS: Agosto\n    - Agosto tem 31 dias -\n");
         break;

         case 9:
         printf("\n\tMÊS: Setembro\n    - Setembro tem 30 dias -\n");
         break;

         case 10:
         printf("\n\tMÊS: Outubro\n    - Outubro tem 31 dias -\n");
         break;

         case 11:
         printf("\n\tMÊS: Novembro\n    - Novembro tem 30 dias -\n");
         break;

         case 12:
         printf("\n\tMÊS: Dezembro\n - Dezembro tem 31 dias -\n");
         break;

         default:
         printf("\n\tNumero Inválido\n ");
     }

     return 0;
 }
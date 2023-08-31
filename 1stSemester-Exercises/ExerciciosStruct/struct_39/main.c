#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

int dias_no_mes(int mes, int ano)
{
    int dias;

    switch (mes)
    {
    case 2:
        if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
            dias = 29;
        else
            dias = 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        dias = 30;
        break;
    default:
        dias = 31;
    }

    return dias;
}

int dias_decorridos(Data data1, Data data2)
{
    int dias = 0;

    if (data2.ano < data1.ano || (data2.ano == data1.ano && data2.mes < data1.mes) || (data2.ano == data1.ano && data2.mes == data1.mes && data2.dia < data1.dia))
    {
        Data tmp = data1;
        data1 = data2;
        data2 = tmp;
    }

    if (data1.ano == data2.ano && data1.mes == data2.mes)
    {
        dias = data2.dia - data1.dia;
    }
    else
    {
        dias += dias_no_mes(data1.mes, data1.ano) - data1.dia;
        for (int mes = data1.mes + 1; mes <= 12; mes++)
        {
            dias += dias_no_mes(mes, data1.ano);
        }
        for (int ano = data1.ano + 1; ano < data2.ano; ano++)
        {
            if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
            {
                dias += 366;
            }
            else
            {
                dias += 365;
            }
        }
        for (int mes = 1; mes < data2.mes; mes++)
        {
            dias += dias_no_mes(mes, data2.ano);
        }
        dias += data2.dia;
    }

    return dias;
}

int main()
{

    setlocale(LC_ALL, "Portuguese");

    Data data1, data2;

    printf("Digite a primeira data no formato dia/mes/ano: ");
    scanf("%d/%d/%d", &data1.dia, &data1.mes, &data1.ano);

    printf("Digite a segunda data no formato dia/mes/ano: ");
    scanf("%d/%d/%d", &data2.dia, &data2.mes, &data2.ano);

    int dias = dias_decorridos(data1, data2);
    printf("\nDias decorridos entre as duas datas: %d\n", dias);

    return 0;
}

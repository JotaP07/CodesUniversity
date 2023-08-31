EXERCICIO 4



int main() {
    int num1, num2, num3;



    setlocale(LC_ALL, "Portuguese");
    printf("\nDigite três números: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 > num2 && num1 > num3) {
        printf("\n%d é o MAIOR número.\n", num1);
    } else if (num2 > num1 && num2 > num3) {
        printf("\n%d é o MAIOR número.\n", num2);
    } else {
        printf("\n%d é o MAIOR número.\n", num3);
    }

    if (num1 < num2 && num1 < num3) {
        printf("\n%d é o MENOR número.\n", num1);
    } else if (num2 < num1 && num2 < num3) {
        printf("\n%d é o MENOR número.\n", num2);
    } else {
        printf("\n%d é o MENOR número.\n", num3);
    }


    return 0;
}
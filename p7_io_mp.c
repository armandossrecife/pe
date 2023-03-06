#include <stdio.h>

int main() {
    /* Más práticas */ 
    // Entrada e Saída de dados do tipo int:

    int idade;
    printf("Digite sua idade: ");
    scanf("%d", idade); // Erro: falta o "&" antes da variável "idade"
    printf("Sua idade é %d\n", idade);

    /* Neste exemplo, a função scanf é usada para ler o valor digitado pelo usuário e armazená-lo na variável idade. 
        No entanto, a variável idade não é passada por referência.*/

    return 0;
}
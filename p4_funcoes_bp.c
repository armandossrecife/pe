#include <stdio.h>

/* Exemplo de boa prática: */

// Função para calcular a área de um retângulo
float calcular_area(float altura, float largura) {
    float area = altura * largura;
    return area;
}

// Função principal
int main() {
    float altura = 2.5;
    float largura = 3.0;
    float area = calcular_area(altura, largura);
    printf("A área do retângulo é %.2f\n", area);
    return 0;
}
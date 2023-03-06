#include <stdio.h>
/* Exemplo de má prática: */
// Função para calcular a área de um retângulo (função sem parâmetros... e pegando dados I/O direto do usuário)
float calcular_area() {
    float altura, largura;
    printf("Digite a altura do retângulo: ");
    scanf("%f", &altura);
    printf("Digite a largura do retângulo: ");
    scanf("%f", &largura);
    float area = altura * largura;
    return area;
}

// Função principal
int main() {
    float area = calcular_area();
    printf("A área do retângulo é %.2f\n", area);
    return 0;
}

/* No exemplo de má prática, a função calcular_area() não recebe parâmetros 
    e pede para o usuário inserir os valores de altura e largura, tornando o código menos reutilizável 
    e mais propenso a erros de entrada do usuário. */

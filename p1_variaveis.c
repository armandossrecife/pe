#include <stdio.h>

/*  Boas práticas:
    - Usar nomes descritivos para as variáveis, para facilitar a leitura e entendimento do código. */

// Boa prática: nome descritivo para a variável
int numero_alunos;

// Má prática: nome pouco descritivo para a variável
int x;

/* Boa prática: 
    - Usar constantes ou enumerações para representar valores fixos no código, 
        para torná-los mais legíveis e evitar erros de digitação. Exemplo: */

// Boa prática: uso de constante para representar um valor fixo
const int TAMANHO_MAXIMO = 100;

// Má prática: uso de valor fixo diretamente no código
int vetor[TAMANHO_MAXIMO * 2];

/* Boa prática:
    - Usar tipos de dados apropriados para cada variável, para evitar desperdício de memória ou problemas de precisão. */

// Boa prática: uso de float para variáveis que representam números com casas decimais
float preco_produto;

// Má prática: uso de double para variáveis que não precisam de tanta precisão
double resultado;

// Má prática: uso de int para variáveis que representam tamanhos em bytes
int tamanho_arquivo;

int main(){
    /*  Más práticas:
        - Usar variáveis sem inicializá-las, o que pode causar erros no programa. */
    
    // Má prática: variável não inicializada
    int numero_alunos;
    printf("Digite o número de alunos: ");
    scanf("%d", &numero_alunos);

    /* Má prática:
        Usar tipos de dados com tamanho inadequado para as variáveis, 
        o que pode causar problemas de precisão ou estouro de memória. */

    // Má prática: uso de char para representar um número inteiro
    char idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    // Má prática: uso de int para variáveis que representam tamanhos em bytes
    int tamanho_arquivo;
    printf("Digite o tamanho do arquivo em bytes: ");
    scanf("%d", &tamanho_arquivo);

    /* Má prática:
        - Usar operadores de forma inadequada, o que pode causar erros ou comportamentos indesejados. */

    // Má prática: uso de operador de atribuição (=) em vez de operador de comparação (==)
    int nota;
    printf("Digite sua nota: ");
    scanf("%d", &nota);
    if (nota = 10) {
        printf("Parabéns, nota máxima!\n");
    }

    // Má prática: uso de operador de deslocamento (<<) em vez de operador de multiplicação (*)
    int x = 2;
    int resultado = x << 2; // resultado = x * 4

    return 0;
}
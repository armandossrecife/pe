#include <stdlib.h>

#define TAMANHO_ARRAY 10
#define LINHAS 3
#define COLUNAS 3

int main(){

    /* Exemplo de má prática no uso de arrays e matrizes em C: */

    int array[10];

    // preenchimento do array
    for (int i = 0; i <= 10; i++) {
        array[i] = i; // acessando posição de memória além do tamanho do array
    }

    // impressão do array
    for (int i = 0; i < 11; i++) {
        printf("%d\n", array[i]); // acessando posição de memória além do tamanho do array
    }

    /* Este código acima é uma má prática, pois há acesso a posições de memória além do tamanho do array, 
        o que pode causar comportamento indefinido ou até mesmo falha de segmentação. */ 

    int array[TAMANHO_ARRAY];

    // preenchimento do array
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        array[i] = i;
    }

    // impressão do array
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("%d\n", array[i]);
    }

    /* Este código acima é uma boa prática, pois utiliza uma constante definida com o tamanho do array, 
    evitando acessar posições de memória além do limite do array. */

    /* Exemplo de má prática no uso de matrizes em C: */

    int matriz[3][3];

    // preenchimento da matriz
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            matriz[i][j] = i + j; // acessando posição de memória além do tamanho da matriz
        }
    }

    // impressão da matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", matriz[i][j]); // acessando posição de memória além do tamanho da matriz
        }
        printf("\n");
    }

    /* Este código acima é uma má prática, pois há acesso a posições de memória além do tamanho da matriz, 
    o que pode causar comportamento indefinido ou até mesmo falha de segmentação. */

    /* Exemplo de boa prática: */
    int matriz[LINHAS][COLUNAS];

    // preenchimento da matriz
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            matriz[i][j] = i + j;
        }
    }

    // impressão da matriz
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    /* Este código acima é uma boa prática, pois utiliza constantes definidas para o número de linhas e colunas da matriz, 
        evitando acessar posições de memória além do limite da matriz. */
    return 0;
}
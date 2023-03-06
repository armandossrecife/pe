#include <stdio.h>

int main() {
    /* Entrada e Saída de dados do tipo int: */
    int idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Sua idade é %d\n", idade);

    /* Neste exemplo, a função scanf é usada para ler o valor digitado pelo usuário e armazená-lo na variável idade. 
        Em seguida, a função printf é usada para imprimir a idade na tela. */

    /* Entrada e Saída de dados do tipo float: */
    float altura;
    printf("Digite sua altura em metros: ");
    scanf("%f", &altura);
    printf("Sua altura é %.2f metros\n", altura);

    /* Neste exemplo, a função scanf é usada para ler o valor digitado pelo usuário e armazená-lo na variável altura. 
        O formato de impressão "%.2f" é usado na função printf para limitar o número de casas decimais da altura a 2.*/

    /* Entrada e Saída de dados do tipo char: */
    char letra;
    printf("Digite uma letra: ");
    scanf(" %c", &letra);
    printf("A letra digitada foi %c\n", letra);

    /* Neste exemplo, a função scanf é usada para ler o caractere digitado pelo usuário e armazená-lo na variável letra. 
        Note que há um espaço antes do %c na função scanf. Isso é necessário para evitar que a função capture um caractere 
        que tenha sido deixado no buffer de entrada. */

    /* Entrada e Saída de dados do tipo string: */
    char nome[100];
    printf("Digite seu nome: ");
    fgets(nome, 100, stdin);
    printf("Seu nome é %s", nome);

    /* Neste exemplo, a função fgets é usada para ler uma string de até 100 caracteres digitada pelo usuário e armazená-la 
        na variável nome. Note que o segundo argumento da função fgets é o tamanho máximo da string a ser lida. 
        O terceiro argumento é o stream de entrada, que no caso é o stdin. 
        O fgets lê também o caractere de quebra de linha, por isso é necessário remover 
        esse caractere da string para que a saída fique mais legível.*/

    return 0;
}
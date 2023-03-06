/* Exemplo de más práticas: */

#include <stdio.h>

int main() {
    FILE *arquivo;
    char nome[50];
    int idade;

    arquivo = fopen("dados.txt", "w");

    printf("Digite seu nome: ");
    gets(nome);

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    fprintf(arquivo, "Nome: %sIdade: %d\n", nome, idade);

    return 0;
}

/* Nesse exemplo, o código abre um arquivo chamado "dados.txt" para escrita, 
    porém não verifica se a abertura foi bem sucedida. 
    Além disso, utiliza a função não segura gets() para ler o nome do usuário, e não fecha o arquivo após a escrita.*/
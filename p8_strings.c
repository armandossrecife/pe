#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NOME 50
#define MAX_SOBRE_NOME 50
#define MAX_NOME_COMPLETO 100

int main() {
    char nome[MAX_NOME];
    char sobrenome[MAX_SOBRE_NOME];
    char nome_completo[MAX_NOME_COMPLETO];
    
    printf("Digite o nome: ");
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0'; 
    // remove o caractere de nova linha '\n' adicionado por fgets
    
    printf("Digite o sobrenome: ");
    fgets(sobrenome, MAX_SOBRE_NOME, stdin);
    sobrenome[strcspn(sobrenome, "\n")] = '\0'; 
    // remove o caractere de nova '\n' linha adicionado por fgets
    
    snprintf(nome_completo, sizeof(nome_completo), "%s %s", nome, sobrenome); 
    // crie a string com nome completo usando snprintf
    
    printf("Nome completo: %s\n", nome_completo);

    /* Este exemplo utiliza fgets para ler o nome e o sobrenome do usuário e, 
        em seguida, utiliza snprintf para criar uma string com o nome completo. 
        Ele também remove os caracteres de nova linha adicionados por fgets e 
        usa snprintf para garantir que a string nome_completo esteja devidamente 
        terminada. */
    
    return 0;
}
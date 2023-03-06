#include <stdio.h>
#include <string.h>

/*
typedef struct pessoa{
   char nome[50];
   int idade;
   float altura;
} Pessoa;
*/

/*
typedef struct pessoa{
   char nome[50];
   float altura;
} Pessoa;
*/

typedef struct data_nascimento{
    int dia;
    int mes;
    int ano;
} Nascimento;

typedef struct pessoa{
   char nome[50];
   Nascimento data_nascimento;
   float altura;
} Pessoa;

Pessoa *criar_pessoa(char *nome, int dia, int mes, int ano, float altura) {
   Pessoa *pessoa = (Pessoa *) malloc(sizeof(Pessoa));

   strcpy(pessoa->nome, nome);
   pessoa->data_nascimento.dia = dia;
   pessoa->data_nascimento.mes = mes;
   pessoa->data_nascimento.ano = ano;
   pessoa->altura = altura;
   return pessoa;
}

void exibir_pessoa(Pessoa *p) {
   printf("Nome: %s\n", p->nome);
   printf("Data de Nascimento: %d/%d/%d\n", p->data_nascimento.dia, p->data_nascimento.mes, p->data_nascimento.ano);
   printf("Altura: %f\n", p->altura);
}

void destruir_pessoa(Pessoa *p) {
   free(p);
}

int main(){

    /* Exemplo de má prática:
    Pessoa *pessoa;
    strcpy(p->nome, "João");

    /* Exemplo de boa prática:
    Pessoa *p = (Pessoa *) malloc(sizeof(Pessoa));
    strcpy(p->nome, "João");
    */

    /*
    Pessoa pessoas[2];
    strcpy(pessoas[0].nome, "Maria Joaquina");
    pessoas[0].data_nascimento.dia = 1;
    pessoas[0].data_nascimento.mes = 1;
    pessoas[0].data_nascimento.ano = 1997;
    pessoas[0].altura = 1.70;
    printf("Nome: %s, Nascimento: %d/%d/%d, altura: %.2f\n", pessoas[0].nome, pessoas[0].data_nascimento.dia, pessoas[0].data_nascimento.mes, pessoas[0].data_nascimento.ano, pessoas[0].altura);
    */
    return 0;
}
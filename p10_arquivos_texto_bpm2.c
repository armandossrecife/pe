#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 50
#define MAX_EMAIL 100

typedef struct pessoa{
  char nome[MAX_NAME];
  char email[MAX_EMAIL];
  int idade;
}Pessoa;

void salva_pessoa(char *file_name, Pessoa pessoa) {
    FILE *file;
    file = fopen(file_name, "a");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    fprintf(file, "%d, %s, %s", pessoa.idade, pessoa.nome, pessoa.email);
    fprintf(file, "\n");

    fclose(file);
}

void recupera_dados(char *file_name){
  FILE *file;
  char nome[MAX_NAME];
  char email[MAX_EMAIL]; 
  int idade;

  file = fopen(file_name, "r");

  if (file == NULL) { 
    printf("Erro: não pode abrir o arquivo.\n");
    exit(1);
  }

  while (fscanf(file, "%d, %[^\n], %[^\n]", &idade, nome, email) != EOF) {
    printf("Nome: %s, Idade: %d\n", nome, idade);
  }
  fclose(file);
}

int main() {
    char *file_name="dados.txt";
    Pessoa pessoa;

    for (int i=0; i<2; i++){
      printf("Digite seu nome: ");
      fgets(pessoa.nome, MAX_NAME, stdin);
      pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0';

      printf("Digite seu e-mail: ");
      fgets(pessoa.email, MAX_EMAIL, stdin);
      pessoa.email[strcspn(pessoa.email, "\n")] = '\0';

      printf("Digite sua idade: ");
      scanf("%d", &pessoa.idade);
      getchar();
      salva_pessoa(file_name, pessoa);
    }

    recupera_dados(file_name);

    return 0;
}
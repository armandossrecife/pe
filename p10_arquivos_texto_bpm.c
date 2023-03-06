#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 50

void salva_dado(char *file_name, char nome[MAX_NAME], int idade) {
    FILE *file;
    file = fopen(file_name, "a");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    fprintf(file, "%d, %s", idade, nome);
    fprintf(file, "\n");

    fclose(file);
}

void recupera_dados(char *file_name){
  FILE *file;
  char nome[MAX_NAME]; 
  int idade;

  file = fopen(file_name, "r");

  if (file == NULL) { 
    printf("Erro: não pode abrir o arquivo.\n");
    exit(1);
  }

  while (fscanf(file, "%d, %[^\n]", &idade, nome) != EOF) {
    printf("Nome: %s, Idade: %d\n", nome, idade);
  }
  fclose(file);
}

int main() {
    char *file_name="dados.txt";
    char nome[MAX_NAME];
    int idade;

    for (int i=0; i<2; i++){
      printf("Digite seu nome: ");
      fgets(nome, MAX_NAME, stdin);
      nome[strcspn(nome, "\n")] = '\0';

      printf("Digite sua idade: ");
      scanf("%d", &idade);
      getchar();
      salva_dado(file_name, nome,idade);
    }

    recupera_dados(file_name);

    return 0;
}
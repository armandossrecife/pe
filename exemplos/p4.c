#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu() {
  int response = 0;

  printf("---- Menu Principal --------\n\n");
  printf("1 - Checa uma nota válida.\n");
  printf("2 - Imprime números ímpares.\n");
  printf("3 - Palavra invertida.\n");
  printf("4 - Soma de matrizes.\n");
  printf("5 - Produto de matrizes.\n");
  printf("6 - Sair\n\n");
  printf("----------------------------\n");
  printf("O que deseja fazer? ");

  scanf("%i", &response);
  getchar();

  return response;
}

// Funcionalidade 1
void check_value() {
  float grade = 0;

  while (1) {
    printf("Insira uma nota de 0 a 10: ");
    scanf("%f", &grade);
    getchar();

    if (0 <= grade && grade <= 10) {
      system("clear");
      printf("Nota inserida com sucesso!\n\n");
      break; // Finaliza o looping
    } else {
      system("clear");
      printf("Valor inválido.\n");
    }
  }
}

// Funcionalidade 2
void print_odd_number() {
  int number = 0, count = 1, i = 1;

  printf("Insira um valor inteiro: ");
  scanf("%i", &number);
  getchar();

  system("clear");
  printf("Os dez números ímpares após %i são:\n", number);

  while (count <= 10) {
    if ((number + i) % 2 == 1) {
      count += 1;
      printf("%i  ", number + i);
    }
    ++i;
  }
  printf("\n\n");
}

// Funcionalidade 3
void reverse_word() {
  char word[12];
  int tamanho;

  while (1) {
    printf("Insira uma palavra com até 10 caracteres:\n");
    scanf("%[^\n]s", word);
    getchar();
    if (strlen(word) <= 10) { // Encerra o looping se a codição for "true"
      break;
    } else {
      system("clear");
      printf("Você excedeu o limite de caracteres. Tente novamente.\n");
    }
  }

  system("clear");
  printf("Palavra invertida: ");
  for (int i = strlen(word) - 1; i >= 0; i--) { // Inversor de palavra
    printf("%c", word[i]);
  }

  printf("\n\n");
}

/*
A função baixo lê matrizes bidimensionais de ordem m por n.

O endereço do primeiro elemento da matriz que desejamos
preencher é passado como parâmetro da função. Os demais endereços
são obtidos por aritmética de ponteiros com auxilio da variável "count".

O parâmetros "lines" e "columns" permiti-nos utilizar a função para
n matrizes bidimensionais.

Observação: os parâmetros "lines" e "columns" são configurados para
valores >= 2, visto que temos de considerar o '\0' (fim do array).
*/
void read_matrix(float *matrix, int lines, int columns) {
  int count = 0;

  for (int i = 0; i < lines - 1; i++) {
    for (int j = 0; j < columns - 1; j++) {
      printf("a%i%i: ", i + 1, j + 1);
      scanf("%f", (matrix + count));
      count += 1;
    }
    count += 1;
  }
  printf("\n");
}

// Funcionalidade 4
void sum_of_matrices() {
  int lines_M1 = 3, col_M1 = 4, lines_M2 = 3, col_M2 = 4;
  float matrix_1[lines_M1][col_M1], matrix_2[lines_M2][col_M2];

  printf("Insira os valores da matriz 1:\n");
  read_matrix(&matrix_1[0][0], lines_M1, col_M1);

  printf("Insira os valores da matriz 2:\n");
  read_matrix(&matrix_2[0][0], lines_M2, col_M2);

  system("clear");
  printf("Matriz soma: \n");
  for (int i = 0; i < lines_M1 - 1; i++) {
    for (int j = 0; j < col_M1 - 1; j++) {
      printf("%.1f ", matrix_1[i][j] + matrix_2[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Funcionalidade 5
// Note que o produto matricial nem sempre é comutativo.
// Dado o produto matricial matrix_1 por matrix_2, tem-se, por definição,
// que "col_M1" é igual a "lines_M2".
void product_of_matrices() {
  int lines_M1 = 3, col_M1 = 3, lines_M2 = 3, col_M2 = 3;
  float matrix_1[lines_M1][col_M1], matrix_2[lines_M2][col_M2];
  float product_matrix = 0;

  printf("Insira os valores da matriz 1:\n");
  read_matrix(&matrix_1[0][0], lines_M1, col_M1);

  printf("Insira os valores da matriz 2:\n");
  read_matrix(&matrix_2[0][0], lines_M2, col_M2);

  system("clear");
  printf("Matriz produto: \n");
  for (int i = 0; i < lines_M1 - 1; i++) {
    for (int j = 0; j < col_M2 - 1; j++) {
      for (int k = 0; k < col_M1 - 1; k++) {
        product_matrix += (matrix_1[i][k] * matrix_2[k][j]);
      }
      printf("%.1f ", product_matrix);
      product_matrix = 0;
    }
    printf("\n");
  }
  printf("\n");
}

int main(void) {
  setlocale(LC_ALL, "Portuguese");

  while (1) {

    switch (menu()) {
    case 1:
      check_value();
      break;
    case 2:
      print_odd_number();
      break;
    case 3:
      reverse_word();
      break;
    case 4:
      sum_of_matrices();
      break;
    case 5:
      product_of_matrices();
      break;
    case 6:
      printf("Sessão encerrada.\n");
      exit(0);
      break;
    default:
      break;
    }
  }

  return 0;
}
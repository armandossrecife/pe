/* Exemplo de boas práticas: */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50

/* Read the data from the file and display the information*/
void recupera_dados(char *file_name){
  FILE *file;
  char nome[MAX_NAME]; 
  int idade;

  /*Abre o arquivo em modo leitura */
  file = fopen(file_name, "r");

  if (file == NULL) { 
    printf("Erro: não pode abrir o arquivo.\n");
    exit(1); // encerra o programa
  }

  /*
    A funcao fscanf retorna a quantidade de itens lidos do arquivo
    Enquanto nao chegar no fim do arquivo, faz a leitura de uma linha
    Obs: 
      Apos cada linha lida, o fscan "pula" para a proxima linha do arquivo
  */
  while (fscanf(file, "%s,%d\n", nome, &idade) != EOF) {
    printf("Nome: %s, Idade: \n", nome, idade);
  }
  fclose(file);
}

int main() {
    FILE *arquivo;
    char nome[MAX_NAME];
    int idade;

    arquivo = fopen("dados.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    printf("Digite seu nome: ");
    fgets(nome, MAX_NAME, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    fprintf(arquivo, "Nome: %s, Idade: %d\n", nome, idade);

    fclose(arquivo);

    return 0;
}

/* 
    Nesse exemplo, o código abre um arquivo chamado "dados.txt" 
    para escrita, verifica se a abertura foi bem sucedida, 
    solicita ao usuário o nome e a idade, 
    no caso da variavel nome, remove o '\n' para gravar apenas os caracteres
    e escreve essas informações no arquivo de maneira segura utilizando 
    a função fprintf(). 
    Por fim, o arquivo é fechado após a escrita.
*/
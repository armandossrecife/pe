#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_EMAIL 50
#define MAX_PHONE 20
#define MAX_PEOPLE 100
#define MAX_LINHA 1000

// Definição da estrutura Pessoa
typedef struct Pessoa {
    int id;
    char nome[MAX_NAME];
    char email[MAX_EMAIL];
    char telefone[MAX_PHONE];
} Pessoa;

Pessoa criar_pessoa(int id, char nome[], char email[], char telefone[]) {
    Pessoa nova_pessoa;
    nova_pessoa.id = id;
    strcpy(nova_pessoa.nome, nome);
    strcpy(nova_pessoa.email, email);
    strcpy(nova_pessoa.telefone, telefone);
    return nova_pessoa;
}

Pessoa ler_pessoa(){
    int id;
    char nome[MAX_NAME];
    char email[MAX_EMAIL];
    char telefone[MAX_PHONE];

    // Lê os dados da nova pessoa a partir do teclado
    printf("Digite o id da pessoa: ");
    scanf("%d", &id);
    getchar(); // consome o \n deixado pelo scanf

    printf("Digite o nome da pessoa: ");
    fgets(nome, MAX_NAME, stdin);
    nome[strcspn(nome, "\n")] = '\0'; // remove o \n deixado pelo fgets

    printf("Digite o e-mail da pessoa: ");
    fgets(email, MAX_EMAIL, stdin);
    email[strcspn(email, "\n")] = '\0'; // remove o \n deixado pelo fgets

    printf("Digite o telefone da pessoa: ");
    fgets(telefone, MAX_PHONE, stdin);
    telefone[strcspn(telefone, "\n")] = '\0'; // remove o \n deixado pelo fgets

    return criar_pessoa(id, nome, email, telefone);
}

void cadastrar_pessoa(Pessoa pessoas[], int *num_pessoas) {
    // Adiciona a nova pessoa ao final do array de pessoas
    pessoas[*num_pessoas] = ler_pessoa();
    (*num_pessoas)++;
}

// Função para imprimir os dados de uma pessoa
void print_pessoa(Pessoa pessoa) {
    printf("ID: %d\n", pessoa.id);
    printf("Nome: %s\n", pessoa.nome);
    printf("E-mail: %s\n", pessoa.email);
    printf("Telefone: %s\n", pessoa.telefone);
    printf("\n");
}

// Função para listar todas as pessoas de um array de pessoas
void listar_pessoas(Pessoa pessoas[], int num_pessoas) {
    printf("Pessoas cadastradas:\n");
    for (int i = 0; i < num_pessoas; i++) {
        print_pessoa(pessoas[i]);
    }
}

void salvar_pessoas(char *file_name, Pessoa pessoas[], int num_pessoas) {
  FILE *file;
  file = fopen(file_name, "w");

  if (file == NULL){
    printf("Erro ao abrir o arquivo!\n");
    exit(1);
  }
  for (int i = 0; i < num_pessoas; i++) {
    fprintf(file, "%d,%s,%s,%s\n", pessoas[i].id, pessoas[i].nome, pessoas[i].email, pessoas[i].telefone);
  }
  fclose(file);
}

void recuperar_dados(char *file_name, Pessoa pessoas[], int *num_pessoas) {
    FILE *file;
    char linha[MAX_LINHA];
    int id;
    char nome[MAX_NAME];
    char email[MAX_EMAIL];
    char telefone[MAX_PHONE];

    file = fopen(file_name, "r");
    if (file == NULL){
      printf("Erro ao abrir o arquivo!\n");
      exit(1);
    }

    while (fgets(linha, MAX_LINHA, file) != NULL) {
        // Extrai os campos da linha lida do arquivo
        sscanf(linha, "%d,%[^,],%[^,],%s", &id, nome, email, telefone);

        // Cria uma nova Pessoa e adiciona ao array de pessoas
        pessoas[*num_pessoas] = criar_pessoa(id, nome, email, telefone);
        (*num_pessoas)++;
    }

    fclose(file);
}

// Função principal
int main() {
    FILE *file;
    char *file_name = "pessoas.txt";
    Pessoa pessoas[MAX_PEOPLE];
    int num_pessoas = 0;

    printf("Checa se arquivo %s já existe...\n", file_name);
    // Abre o arquivo para leitura
    file = fopen(file_name, "r");
    if (file != NULL) {
        fclose(file);
        // Se o arquivo existe, recupera as pessoas
        printf("Recuperando pessoas do arquivo %s\n", file_name);
        recuperar_dados("pessoas.txt", pessoas, &num_pessoas);
        printf("Pessoas recuperadas com sucesso!\n");
        listar_pessoas(pessoas, num_pessoas);
    }
    
    printf("Cadastra pessoas: \n");
    cadastrar_pessoa(pessoas, &num_pessoas);

    listar_pessoas(pessoas, num_pessoas);
    printf("Salva pessoas em %s\n", file_name);
    salvar_pessoas(file_name, pessoas, num_pessoas);
    printf("Pessoas salvas com sucesso em %s\n", file_name);

    return 0;
}
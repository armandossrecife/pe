// Bibliotecas utilizadas
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME 50
#define EMAIL 100
#define TEL 50
#define CONT 100

// Função menu
int menu() {
  int opcao;
  printf("\n----Menu Principal---------\n");
  printf("1. Inserir contato na agenda\n"
         "2. Buscar contato por nome\n"
         "3. Mostrar contatos salvos\n"
         "4. Mostrar contatos por ordem alfabética\n"
         "5. Remover um contato da agenda\n"
         "6. Salvar dados em arquivo\n"
        "7. SAIR\n");
  printf("------------------------------\n");
  printf("Escolha uma opção:\n");
  scanf("%d", &opcao);
  return opcao;
}
// Estrutura para armazenar os dados da agenda
typedef struct Agenda {
  char nome[NOME]; // Para armazenar os nomes
  char email[EMAIL]; // Para armazenas os e-mails
  char telefone[TEL]; // Para armazenar os telefones
} contatos_ag;

// Funcionalidade 1
void inserir_contatos(contatos_ag *agenda) {
 // Mensagem exibida ao usuário
  printf("Cadastre o contato:\n");
  printf("Insira o nome:\n");
  scanf(" %[^\n]", agenda->nome);
  printf("Insira o e-mail:\n");
  scanf(" %[^\n]", agenda->email);
  printf("Insira o número do telefone:\n");
  scanf(" %[^\n]", agenda->telefone);
  // O uso do %[^\n] é para tentar captar nomes compostos, mas nem utilizando ele o código consegue captar
}

// Funcionalidade 2
void pesquisar_contato(contatos_ag *agenda, int contatos_num) {
  // Variável para armazenar o nome pesquisado
  char pesquisa[NOME];
  // Variável do tipo inteiro para controlar o laço de repetição
  int i = 0;
  printf("Informe o nome do contato salvo:\n");
  scanf(" %[^\n]", pesquisa);
// Laço para comparar nome a nome e verificar se o nome digitado está na agenda
  for (i = 0; i < contatos_num; i++) {
    if (strcmp(agenda[i].nome, pesquisa) == 0) {
     // Se ele estiver, seus dados são impressos na tela
      printf("Nome - Email - Telefone\n");
      printf("%s, %s, %s", agenda[i].nome, agenda[i].email, agenda[i].telefone);
      return;
    }
  }
  // Se o contato não estiver na lista esta mensagem é exibida para o usuário
  printf("O contato não foi encontrado!\n");
}

// Funcionalidade 3
void mostrar_contatos(contatos_ag *agenda, int contatos_num) {
  int i;
  printf("Contatos registrados na agenda:\n");
  // Laço para imprimir todos os contatos cadastrados na agenda
  for (i = 0; i < contatos_num; i++) {
    printf("%s, %s, %s\n", agenda[i].nome, agenda[i].email, agenda[i].telefone);
  }
}

// Funcionalidade 4
void ordenar_alfabeto(contatos_ag *agenda, int contatos_num) {
  int i, j; // Para controlar os for's aninhados
  // Variáveis auxiliares para ajudar nas trocas durante a ordenação da agenda
  char telefone_auxiliar[TEL];
  char nome_auxiliar[NOME];
  char email_auxiliar[EMAIL];
// Laços for aninhados para fazer o bubbe short
  for (i = 0; i < contatos_num; i++) {
    for (j = i + 1; j < contatos_num; j++) {
      if (strcmp(agenda[i].nome, agenda[j].nome) > 0) {
        // Realiza as trocas de dados para ordenar
        strcpy(nome_auxiliar, agenda[i].nome);
        strcpy(email_auxiliar, agenda[i].email);
        strcpy(telefone_auxiliar, agenda[i].telefone);

        strcpy(agenda[i].nome, agenda[j].nome);
        strcpy(agenda[i].email, agenda[j].email);
        strcpy(agenda[i].telefone, agenda[j].telefone);

        strcpy(agenda[j].nome, nome_auxiliar);
        strcpy(agenda[j].email, email_auxiliar);
        strcpy(agenda[j].telefone, telefone_auxiliar);
      }
    }
  }
  // Para imprimir os contatos em ordem alfabética
  printf("\n---Contatos por ordem alfabética---\n");
  for (i = 0; i < contatos_num; i++) {
    printf("Nome -  Email -  Telefone\n");
    printf("%s, %s, %s\n", agenda[i].nome, agenda[i].email, agenda[i].telefone);
  }
}

// Funcionalidade 5
void remover_contato(contatos_ag *agenda, int *contatos_num) {
  // Variável do tipo char usada para armazenar o nome do contato a ser excluído
  char remover[NOME];
  int i;
  printf("Informe o nome do contato que deseja excluir:\n");
  scanf(" %[^\n]", remover);

  int indice = -1;
  for (i = 0; i < *contatos_num; i++) {
   // Se o nome estiver na lista ele será excluído aqui
    if (strcmp(agenda[i].nome, remover) == 0) {
      indice = i;
      break;
    }
  }
  // Se não estiver essa mensagem será exibida
  if (indice == -1) {
    printf("O contato não foi encontrado.\n");
    return;
  }
  // Reordenação da agenda a partir do contato removido, caso o contato seja removido
  for (i = indice; i < *contatos_num - 1; i++) {
    agenda[i] = agenda[i + 1];
  }
  (*contatos_num)--;
  // Mensagem exibida se o número for excluído
  printf("O contato foi removido da agenda!\n");
}

// Função para salvar o contato no arquivo
void recuperar_dados(contatos_ag *agenda, int contatos_num) {
  // Abertura do arquivo
  FILE *file = fopen("agenda.txt", "w");
// Se ele não for aberto, essa mensagem será exibida
  if (file == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }

  for (int i = 0; i < contatos_num; i++) {
    fprintf(file, "%s %s %s\n", agenda[i].nome, agenda[i].email,
            agenda[i].telefone);
  }
  // Mensagem exibida após salvar o contato na agenda
  fclose(file);
  printf("Conteúdo salvo em arquivo texto da agenda.txt\n");
}

// Funcão 6, usada para recuperar dados
void recuperarr_dados(contatos_ag *agenda, int *contatos_num) {
  FILE *file = fopen("agenda.txt", "r");
  contatos_ag Agenda;

  if (file == NULL) {
    printf("O arquivo não existe ou não pode ser aberto.\n");
    return;
  }

  while (fscanf(file, "%s %s %s\n", Agenda.nome, Agenda.email,
                Agenda.telefone) != EOF) {
    agenda[*contatos_num] = Agenda;
    (*contatos_num)++;
  }

  fclose(file);
  printf("Dados recuperados do arquivo agenda.txt!\n");
}

int main(int argc, char **argv) {
  // Para usar o PT-BR
  setlocale(LC_ALL, "Portuguese");
  contatos_ag agenda[CONT];
  int contatos_num = 0;
  int resp;
  // Para recuperar os dados
  recuperarr_dados(agenda, &contatos_num);
  // Laço do while
  do {
    resp = menu();
    switch (resp) {
    case 1:
      inserir_contatos(&agenda[contatos_num]);
      contatos_num++;
      break;
    case 2:
      pesquisar_contato(agenda, contatos_num);
      break;
    case 3:
      mostrar_contatos(agenda, contatos_num);
      break;
    case 4:
      ordenar_alfabeto(agenda, contatos_num);
      break;
    case 5:
      remover_contato(agenda, &contatos_num);
      break;
    case 6:
      recuperar_dados(agenda, contatos_num);
      break;
    case 7:
      exit(0);
    default:
      printf("Opção inválida, tente novamente.\n");
      break;
    }
  } while (resp != 7);

  return 0;
}
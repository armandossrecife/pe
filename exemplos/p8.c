#include <stdio.h>
#include <stdlib.h>

// Estrutura para lista encadeada
struct node{
  int info;
  struct node* proximo;
};
// Defini um novo tipos "Lista" a partir da estrutura node
typedef struct node Lista;

// Declaração da lista_de_inteiros
Lista* lista_de_inteiros = NULL;

// Função que inicializa a lista encadeada
Lista* cria_lista_vazia(){
  return NULL;
}

// Protótipos das funções
int menu();
int verifica(Lista* lista, int valor);
Lista* insere(Lista* lista, int valor);
void busca(Lista* lista);
void mostra_elementos(Lista *lista);
void ordem_cresc(Lista *lista);
void ordem_decres(Lista *lista);
Lista* libera_mem(Lista *lista);


int main(void) {
  // incialização da lista
  lista_de_inteiros = cria_lista_vazia();

  while(1){
     int valor = 0;
    
    switch(menu()){
      case 1:
        system("clear");
        printf("Insira um novo valor para a lista: ");
        scanf("%d", &valor);
        getchar();
        lista_de_inteiros = insere(lista_de_inteiros, valor);
        break;
      case 2:
        busca(lista_de_inteiros);
        break;
      case 3:
        system("clear");
        printf("Esses são os elementos das lista:\n");
        mostra_elementos(lista_de_inteiros);
        break;
      case 4:
        ordem_cresc(lista_de_inteiros);
        break;
      case 5:
        ordem_decres(lista_de_inteiros);
        break;
      case 6:
        system("clear");
        libera_mem(lista_de_inteiros);
        printf("Sessão encerrada.\n");
        exit(0);
        break;
      default:
        system("clear");
        printf("Opção inválida! Tente novamente.\n");
        break;
    }
  }
  
  return 0;
}

// Função de que mostra o menu princial
int menu(){
  int resposta = 0;
  
  printf("________ MENU PRINCIPAL ________\n\n");
  printf("1. Inserir elemento\n");
  printf("2. Buscar elemento\n");
  printf("3. Mostrar elementos\n");
  printf("4. Ordenação crescente dos elementos\n");
  printf("5. Ordenação decrescente dos elementos\n");
  printf("6. SAIR\n\n");
  printf("----------------------------\n");
  printf("> ");

  scanf("%i", &resposta);
  getchar();

  return resposta;
}

// Verifica se a lista está vazia e retorna "1", se estiver
int verifica(Lista* lista, int valor){
  Lista* aux = lista;

  if(aux == NULL){
    return 1;
  } else {
    for(aux = lista; aux != NULL; aux = aux->proximo){
      if(aux->info == valor){
        return 0;
      }
    }
  }
  
  return 1;
}

// Insere um novo elementos na lista
Lista* insere(Lista* lista, int valor){
  Lista* novo_no = lista;

  if(verifica(lista, valor)){
    novo_no = (Lista*) malloc(sizeof(Lista));
    novo_no->info = valor;
    novo_no->proximo = lista;
  } else{
    system("clear");
    printf("O número escolhido já existe na lista.\n");
  }

  return novo_no;
}

// Busca um valor especifico na lista
void busca(Lista* lista){
  int num;

  system("clear");
  printf("Insira o numero que deseja buscar: ");
  scanf("%d", &num);
  getchar();

  system("clear");
  if(verifica(lista, num)){
    printf("\"%d\" não está na lista\n", num);
  } else{
    printf("\"%d\" está na lista.\n", num);
  }
}

// Mostra todos os elementos da lista se ela não estiver vazia
void mostra_elementos(Lista *lista){
    Lista *aux;

    if(lista == NULL){
      printf("A lista está vazia!\n");
    } else{
      
      for (aux = lista; aux != NULL; aux = aux->proximo){
          printf("%d\n", aux->info);
      }
      
    }

    printf("\n");
}

void ordem_cresc(Lista *lista){
  Lista *aux = NULL, *aux2 = NULL;
  Lista* lista_aux = NULL;
  int valor_aux;
  
  system("clear");
  if(lista == NULL){
    printf("Lista está vazia.\n");
  } else{
      aux = lista;
    
      while(aux != NULL){
        // printf("valor de aux = %d\n", aux->info);
        lista_aux = insere(lista_aux, aux->info);
        aux = aux->proximo;
      }
      
      printf("Lista em ordem crescente.\n");
    
      for(aux = lista_aux; aux != NULL; aux = aux->proximo){
        for(aux2 = aux->proximo; aux2 != NULL; aux2 = aux2->proximo){
          if(aux->info > aux2->info){
            valor_aux = aux->info;
            aux->info = aux2->info;
            aux2->info = valor_aux;
          }
        }
      }
      mostra_elementos(lista_aux);
      libera_mem(lista_aux);
  }
}

void ordem_decres(Lista *lista){
  Lista *aux = NULL, *aux2 = NULL;
  Lista* lista_aux = NULL;
  int valor_aux;
  
  system("clear");
  if(lista == NULL){
    printf("Lista está vazia.\n");
  } else{
      aux = lista;
    
      while(aux != NULL){
        // printf("valor de aux = %d\n", aux->info);
        lista_aux = insere(lista_aux, aux->info);
        aux = aux->proximo;
      }
      
      printf("Lista em ordem decrescente.\n");
    
      for(aux = lista_aux; aux != NULL; aux = aux->proximo){
        for(aux2 = aux->proximo; aux2 != NULL; aux2 = aux2->proximo){
          if(aux->info < aux2->info){
            valor_aux = aux->info;
            aux->info = aux2->info;
            aux2->info = valor_aux;
          }
        }
      }
      mostra_elementos(lista_aux);
      libera_mem(lista_aux);
  }
}

Lista* libera_mem(Lista *lista){
    Lista *aux = lista;

  if(lista != NULL){
    while (aux != NULL){
        Lista *temp = aux->proximo; /* guarda a referencia par a proximo elemento */
        free(aux); /* libera memoria apontada por aux */
        aux = temp;
    }
    }
  return aux;
}
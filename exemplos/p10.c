#include <stdio.h>
#include <stdlib.h>

//STRUCT TIPO LISTA
struct node{
  int info;
  struct node* proximo;
};
typedef struct node Lista;

//DECLARAÇÃO E INICIALIZAÇÃO DA LISTA DE INTEIROS
Lista *lista_int=NULL;

//FUNÇÃO QUE CRIA UMA LISTA VAZIA
Lista *lista_vazia(){
  return NULL;
}

//FUNÇÃO QUE VALIDA UMA ENTRADA DE ACORDO COM OS PARAMETROS QUE SAO DADOS A ELA
int valida_num(int min, int max){
  int resp;

  printf("Digite a opção desejada entre %d e %d: ", min, max);
  scanf("%d", &resp);
  
  while(resp<min || resp>max){
    printf("Opção inválida. Digite novamente!\n");
    scanf("%d", &resp);
  }

  return resp;
}


//FUNÇÃO QUE INSERE UM ELEMENTO NO INICIO DA LISTA
Lista *insere_num(Lista *lista_int){
  int valor;
  int encontrou;
  Lista *p;
  Lista *novo;

  p=lista_int;

  //PARTE RESPONSAVEL POR IDENTIFICAR SE O ELEMENTO JA PERTENCE A LISTA
  do{
    encontrou=0;
    printf("Digite o valor do elemento desejado: ");
    scanf("%d", &valor);

    for (p = lista_int; p != NULL; p = p->proximo ){
      if (p->info == valor){
        encontrou=1;
        printf("Valor ja cadastrado!Por favor digite outro valor.\n");
        printf("\n");
      }
    }
  }while(encontrou==1);
  
  
  novo = (Lista *)malloc(sizeof(Lista));
  novo->info = valor;
  novo->proximo = lista_int;

  return novo;
}

//FUNÇÃO RESPONSAVEL POR IDENTIFICAR SE DETERMINADO ELEMENTO FAZ PARTE DA LISTA
Lista *busca_elemento(Lista *lista_int){
  Lista *p;
  int valor;

  printf("Digite o número que deseja procurar: ");
  scanf("%d", &valor);

  for (p = lista_int; p != NULL; p = p->proximo ){
    if (p->info == valor){
      return p;
    }
  }
  
return NULL;
}

//FUNÇÃO RESPONSAVEL POR MOSTRAR OS ELEMENTOS PERTENCENTES A LISTA
void mostra_elementos(Lista *lista_int){
  Lista *p;

  for (p = lista_int; p != NULL; p = p->proximo){
    printf("[%d] ->", p->info);
  }
  printf("\n");
}

//FUNÇÃO RESPONSAVEL POR ORDENAR OS ELEMENTOS DA LISTA EM ORDEM CRESCENTE
void ordem_crescente(Lista *lista_int){
  Lista *aux=lista_int;
  Lista *t;
  int c;

  if (lista_int == NULL || lista_int->proximo == NULL){
    printf("Lista não registrada. Por favor registrar!\n");
  }

  //ORDENANDO A LISTA
  while (aux != NULL){
      t = aux->proximo;
      while (t != NULL) {
          if (aux->info > t->info) {
              c = aux->info;
              aux->info = t->info;
              t->info = c;
          }
          t = t->proximo;
      }
      aux = aux->proximo;
  }

  Lista *p;

  //IMPRIMINDO A LISTA JA ORDENADA
  for (p = lista_int; p != NULL; p = p->proximo){
    printf("[%d] ->", p->info);
  }
  printf("\n");
}

//FUNÇÃO RESPONSAVEL POR ORDENAR A LISTA EM ORDEM DECRESCENTE
void ordem_decrescente(Lista *lista_int){
  Lista *aux = lista_int;
  Lista *t;
  int c;

  if (lista_int == NULL || lista_int->proximo == NULL){
    printf("Lista não registrada. Por favor registrar!\n");
  }

  //ORDENANDO A LISTA
  while (aux != NULL){
      t = aux->proximo;
      while (t != NULL) {
          if (aux->info < t->info) {
              c = aux->info;
              aux->info = t->info;
              t->info = c;
          }
          t = t->proximo;
      }
      aux = aux->proximo;
  }

  Lista *p;

  //IMPRIMINDO A LISTA JA ORDENADA
  for (p = lista_int; p != NULL; p = p->proximo){
    printf("[%d] ->", p->info);
  }
  printf("\n");
}

//FUNÇÃO RESPONSAVEL POR LIBERAR OS ELEMENTOS DA LISTA
Lista *libera_elementos_lista(Lista *lista_int){
  Lista *p = lista_int;

  while (p != NULL){
    Lista *temp = p->proximo; 
    free(p); 
    p = temp;
  }

  return NULL;
}

int main(){
  int opção;
  int cadastro=0; /*VARIAVEL RESPONSAVEL POR NAO DEIXAR QUE OUTRAS FUNÇÕES SEJAM INICIALIZADAS SEM QUE AS INFORMAÇÕES SEJAM INSERIDAS*/
  int resp;

  //MENU
  printf("-----MENU-----\n1.Inserir elemento\n2.Buscar elemento\n3.Mostrar elementos\n4.Ordenação crescente dos elementos\n5.Ordenação decrescente dos elementos\n6.Sair\n");
  printf("\n");
  opção=valida_num(1,6);
  
  do{
    switch(opção){
      case 1:
        lista_int=insere_num(lista_int);
        cadastro++;
        break;

      case 2:
        if(cadastro==0){
          printf("Lista não cadastrada ainda. Por favor realizar cadastro!\n");
          printf("\n");
          break;
        }else{
          if(busca_elemento(lista_int)!=NULL){
            printf("Elemento presente na lista.\n");
            printf("\n");
            break;
          }else{
            printf("O elemento não está presente na lista.\n");
            printf("\n");
            break;
          }
        }
      break;

      case 3:
        if(cadastro==0){
          printf("Lista não cadastrada ainda. Por favor realizar cadastro!\n");
          printf("\n");
          break;
        }else{
          mostra_elementos(lista_int);
          break;
        }
      break;

      case 4:
        if(cadastro==0){
          printf("Lista não cadastrada ainda. Por favor realizar cadastro!\n");
          printf("\n");
          break;
        }else{
          ordem_crescente(lista_int);
          break;
        }
      break;
  
  	  case 5:
  	  	if(cadastro==0){
          printf("Lista não cadastrada ainda. Por favor realizar cadastro!\n");
          printf("\n");
          break;
		    }else{
          ordem_decrescente(lista_int);
          break;
		    }
		  break;

      case 6:
        lista_int=libera_elementos_lista(lista_int);
        printf("Lista liberada!\n");
        return 0;
      break;
      
    }

  printf("-----MENU-----\n1.Inserir elemento\n2.Buscar elemento\n3.Mostrar elementos\n4.Ordenação crescente dos elementos\n5.Ordenação decrescente dos elementos\n6.Sair\n");
  printf("\n");
  opção=valida_num(1,6);
    
  }while(opção>=1 && opção<=6);


  return 0;
}
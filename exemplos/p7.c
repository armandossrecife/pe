// Adição das bibliotecas usadas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Estrutura 
struct node{
	int info;
	struct node *proximo;
};

// Renomeação da estrutura
typedef struct node Lista;

int num_inteiro;
// Variável global para armazenar os números da lista
Lista *lista_inteiros=NULL;

//Para criar uma lista vazia
Lista *criar_listavazia(){
	return NULL;
}
// Função para testar se a lista está vazia
int testar_listavz(Lista *lista){
	return (lista=NULL);
}

// Função usada para corrigir elementos digitados pelo usuário de forma repetida
int corrigir_elemento(int novo_int, Lista *p){
	printf("Informe o novo elemento:\n");
	scanf("%d", &novo_int);
	
	while(p->info==novo_int){
		printf("O número %d já está na lista. DIgite novamente:\n");
		scanf("%d", &novo_int);
	}
	if(p->info!=novo_int){
		printf("O número foi alterado.\n");
	}
	return novo_int;
}

// Funcionalidade 1
// Função para inserir um elemento no topo da lista
Lista *inserir_elemento(Lista *lista, int numero_int){
	Lista *novo = (Lista *)malloc(sizeof(Lista));
	Lista *p;
	Lista *falso;
	printf("Informe um valor inteiro:\n");
	scanf("%d", &numero_int);
	
	novo->info = numero_int;
	novo->proximo=lista;
	for(p=lista; p!=NULL; p=p->proximo){
		if(p->info==numero_int){
		printf("O número digitado já está na lista.\n");
		numero_int=corrigir_elemento(numero_int, p);
		novo->info=numero_int;
		novo->proximo=lista;
		}
	}
	return novo;
}
// Função para perguntar se o usuário deseja digitar +1 elemento
void perguntar_elemento(){
	int resp;
	do{
		printf("Gostaria de inserir outro elemento?\n1-Sim, qualquer outro valor - Não\n");
		scanf("%d", &resp);
		if(resp==1){
			printf("Inserindo novo elemento.\n");
			lista_inteiros=inserir_elemento(lista_inteiros, num_inteiro);
		}
		else{
			break;
		}
	}
	while(resp==1);
}

// Funcionalidade 2
void buscar_elementos(Lista *lista){
	Lista *p;
	int num_inteiro;
	printf("Informe um elemento da lista:\n");
	scanf("%d", &num_inteiro);
	for(p=lista; p!=NULL; p=p->proximo){
		if(p->info==num_inteiro){
			printf("O número digitado já está na lista.\n");
			return 0;
		}
	}
	printf("O número informado não está na lista\n");
}
// Para perguntar se o usuário deseja fazer outra busca
void perguntar(){
	int resp;
	do{
		printf("Deseja buscar por outro elemento?\n1-Sim, qualquer outro valor-Não\n");
		scanf("%d", &resp);
		if(resp==1){
			buscar_elementos(lista_inteiros);
		}
		else{
			break;
		}
	}
	while(resp==1);
}

// Funcionalidade 3, mostra os elmentos da lista
void mostrar_elementos(Lista *lista){
	Lista *p;
	// Laço para imprimir os elementos da lista 1 a 1
  for(p=lista; p!=NULL; p=p->proximo){
		printf("[%d]->", p->info);
	}
	printf("NULL\n");
}

// Funcionalidade 4, ordena os elementos de forma crescente
void ordenar_crescente(Lista *lista){
	Lista *p;
	Lista *a;
  // Variável auxiliar para realizar a ordenação dos elementos da lista
	int auxiliar;
	for(p=lista; p->proximo!=NULL; p=p->proximo){
		for(a=p->proximo; a!=NULL; a=a->proximo){
			if(p->info>a->info){
				auxiliar=p->info;
				p->info=a->info;
				a->info=auxiliar;
			}
		}
	}
  // Chamada da função de mostrar elementos para imprimir os mesmos na tela do usuário
	mostrar_elementos(lista);
}

// Função 5, ordena a lista de forma decrescente (oposto da funcionalidade 4)
void ordenar_descrescente(Lista *lista){
	Lista *p;
	Lista *a;
	// Variável para auxiliar na ordenação da lista
  int auxiliar;
	// Laço de repetição para fazer a ordenação
  for(p=lista; p->proximo!=NULL; p=p->proximo){
		for(a=p->proximo; a!= NULL; a=a->proximo){
			if(p->info<a->info){
				auxiliar=p->info;
				p->info=a->info;
				a->info=auxiliar;
			}
		}
	}
  // Chamada da função para imprimir os elementos na tela
	mostrar_elementos(lista);
}
// Função para eliminar a lista da memórimoa
void liberar_elementos(Lista *lista){
	Lista *p=lista;
	while(p!=NULL){
		Lista *t=p->proximo;
		free(p);
		p=t;
	}
}
// Função Menu
int menu(){
  int opcao;
  printf("-----------Menu Principal-------------\n"
         "(1). Inserir elemento.\n"
         "(2). Buscar elemento.\n" 
         "(3). Mostrar elemento.\n"
         "(4). Ordenação crescente dos elementos.\n"
         "(5). Ordenação decrescente dos elementos.\n" 
         "(6). Sair\n" );
  printf("-------------------------------------\n");
  printf("Qual opção deseja executar:\n");
  scanf("%d", &opcao);
  return opcao;
}

// Corpo principal
int main(int argc, char** argv)
{
	// Para usar a acentuação do PT-BR
  setlocale(LC_ALL, "Portuguese");
	// Variável para usada para chamar a função menu
  int resp;
  // Para criar uma lista vazia
	lista_inteiros=criar_listavazia();
	// Variável para controlar e obrigar o usuário a cadastrar elementos na lista antes de tentar fazer algum outro movimento
  int cadast=0;
	do{
		// Chamada da função menu
    resp=menu();
		switch(resp){
			case 1: // Se o usuário digitar 1
				printf("Inserir um novo elemento.\n");
				lista_inteiros=inserir_elemento(lista_inteiros, num_inteiro);
        // Função que pergunta ao usuário se ele quer procurar por algum elemento
				perguntar_elemento();
				// Altera o valor da variável que regula o cadastro para informar que a lista já possui elementos cadastrados
        cadast=1;
				break;
			case 2:
				// A função de mostrar elementos só é executada se a variável cadast já tiver assumido valor 1
        if(cadast==1){
					mostrar_elementos(lista_inteiros);
					perguntar();
				}
          // Caso ele não tenha cadastrado, essa mensagem será exibida para o usuário
				else{
					printf("Nenhum elemento foi adicionado a lista.\n");
				}
				break;
			case 3: // Aqui acontece o mesmo que já foi descrito no case 2
				if(cadast==1){
					mostrar_elementos(lista_inteiros);
					printf("A lista está vazia?\n");
					testar_listavz(lista_inteiros);
				}
				else{
					printf("Nenhum elemento foi adiconado a lista.\n");
				}
				break;
			case 4:
				// Só é acessada se a condição for 
        if(cadast==1){
					ordenar_crescente(lista_inteiros);
				}
				else{
					printf("Nenhum elemento foi adiconado a lista.\n");
				}
				break;
			case 5:
					if(cadast==1){
					ordenar_descrescente(lista_inteiros);
				}
				else{
					printf("Nenhum elemento foi adiconado a lista.\n");
				}
				break;
			case 6: 
				break;
			default:
				printf("Opção inválida.\n");
				break;
		}
	}
	while(resp!=6);
	// Função para esvaziar a lista após o código ser eencerrado
	liberar_elementos(lista_inteiros);
	
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Nó {
int valor;
struct Nó* sucessor;
} Nó;

Nó* valor_inicial = NULL;

void inserir_elemento(int valor) {
Nó* novo_nó = (Nó*) malloc(sizeof(Nó));
novo_nó->valor = valor;
novo_nó->sucessor = valor_inicial;
valor_inicial = novo_nó;
}

int buscar(int valor) {
Nó* atual = valor_inicial;
while (atual != NULL) {
if (atual->valor == valor) {
return 1;
}
atual = atual->sucessor;
}
return 0;
}

void imprimir_lista() {
if(valor_inicial == NULL){
printf("\nNenhum elemento foi adicionado à lista!\n");
} else {
Nó* atual = valor_inicial;
printf("\nLista:\n");
printf("\n");  
while (atual != NULL) {
printf("%d\t", atual->valor);
atual = atual->sucessor;
}
printf("\n");
}
}

void ordem_crescente() {
if(valor_inicial == NULL){
} else {
Nó* atual = valor_inicial;
Nó* sucessor = NULL;
int temp;
if (valor_inicial == NULL) {
return;
}
while (atual->sucessor != NULL) {
sucessor = atual->sucessor;
while (sucessor != NULL) {
if (atual->valor > sucessor->valor) {
temp = atual->valor;
atual->valor = sucessor->valor;
sucessor->valor = temp;
}
sucessor = sucessor->sucessor;
}
atual = atual->sucessor;
}
printf("\nElementos ordenados crescentemente!\n");
}
}

void ordem_decrescente() {
if(valor_inicial == NULL){
} else {
Nó* atual = valor_inicial;
Nó* sucessor = NULL;
int temp;
if (valor_inicial == NULL) {
return;
}
while (atual->sucessor != NULL) {
sucessor = atual->sucessor;
while (sucessor != NULL) {
if (atual->valor < sucessor->valor) {
temp = atual->valor;
atual->valor = sucessor->valor;
sucessor->valor = temp;
}
sucessor = sucessor->sucessor;
}
atual = atual->sucessor;
}
printf("\nElementos ordenados decrescentemente!\n");
}
}

void limpar_memória() {
Nó* atual = valor_inicial;
while (atual != NULL) {
Nó* sucessor = atual->sucessor;
free(atual);
atual = sucessor;
}
}

int main() {
int o, valor;
  
do{
printf("\n————————— Menu Principal —————————————\n");
printf("1. Inserir elemento\n");
printf("2. Buscar elemento\n");
printf("3. Mostrar elementos\n");
printf("4. Ordenação crescente dos elementos\n");
printf("5. Ordenação decrescente dos elementos\n");
printf("6. Sair\n");
printf("——————————————————————————————————————\n");
scanf("%d", &o);
switch (o) {
case 1:
printf("\nDigite o número a ser inserido:\n");
scanf("%d", &valor);
if (buscar(valor) == 1) {
printf("\nO elemento já existe na lista.\n");
} else {
inserir_elemento(valor);
printf("\nElemento inserido com êxito.\n");
}
break;
case 2:
printf("\nDigite o número a ser buscado:\n");
scanf("%d", &valor);
if (buscar(valor) == 1) {
printf("\nElemento encontrado na lista.\n");
} else {
printf("\nElemento não encontrado na lista.\n");
}
break;
case 3:
imprimir_lista();
break;
case 4:
ordem_crescente();
imprimir_lista();  
break;
case 5:
ordem_decrescente();
imprimir_lista();
break;
case 6:
limpar_memória();
printf("\nPrograma encerrado.\n");
break;
default:
printf("\nOpção inválida, escolha novamente.\n");
break;
}
}while (o!=6);
  
return 0;
}
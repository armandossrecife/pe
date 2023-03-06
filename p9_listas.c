/* Exemplo de código C que mostra boas práticas de programação na 
implementação de listas simplesmente encadeadas: */

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura nó da lista
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* new_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    node->value = value;
    node->next = NULL;
    return node;
}

// Função para adicionar um novo nó na lista
void add_node(Node** head, int value) {
    Node* node = new_node(value);
    node->next = *head;
    *head = node;
}

// Função para imprimir os valores da lista
void print_list(Node* head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

// Funcao para liberar a memoria alocada pela lista
void free_list(Node** head) {
    Node* current = *head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

// Função principal
int main() {
    Node* head = NULL;
    add_node(&head, 5);
    add_node(&head, 7);
    add_node(&head, 3);
    add_node(&head, 9);
    print_list(head);
    return 0;
}
/* Este código mostra algumas boas práticas na implementação de listas simplesmente encadeadas: 
    - Uso de typedef para a definição da estrutura Node, tornando o código mais legível e fácil de entender.
    - Uso da função new_node para criar um novo nó na lista, o que torna o código mais organizado e evita 
        repetições desnecessárias.
    - Uso de ponteiros duplos na função add_node, o que permite que o ponteiro da cabeça da lista seja modificado 
        mesmo quando a lista está vazia.
    - Uso de um loop while na função print_list para percorrer a lista, tornando o código mais flexível e capaz 
        de lidar com listas de diferentes tamanhos.
    - Uso de verificação de erros ao alocar memória dinamicamente, evitando problemas de memória e vazamentos.
    - Libera a memória alocada pela lista, eessa forma, é possível evitar vazamentos de memória e garantir que 
        todos os recursos alocados para a lista sejam liberados adequadamente, melhorando a performance e a 
        confiabilidade do programa como um todo.*/
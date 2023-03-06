#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura nó da lista
typedef struct Node {
    int value;
    struct Node* next;
} Node;

/* insere um novo elemento na lista */
Node *add_node(Node *lista, int valor){
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->value = valor;
    novo->next = lista;
    return novo;
}

// Função para imprimir os valores da lista
void print_list(Node* head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}
/* destroi a lista lista liberando todos os elementos da memoria */
void free_list(Node *lista){
    Node *p = lista;
    while (p != NULL)
    {
        Node *temp = p->next; /* guarda a referencia par a proximo elemento */
        free(p); /* libera memoria apontada por p */
        p = temp;
    }
}
// Função principal
int main() {
    Node* head = NULL;
    head = add_node(head, 5);
    head = add_node(head, 7);
    head = add_node(head, 3);
    head = add_node(head, 9);
    print_list(head);
    return 0;
}
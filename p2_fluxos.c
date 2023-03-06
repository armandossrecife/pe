#include <stdlib.h>
#define MAX_NAME 50

typedef struct aluno{
    int id;
    char name[MAX_NAME];
    Aluno *next;
}Aluno;

int main(){
    int x,y, size;
    int array[5];
    Aluno *current_student=NULL;

    /* Boas práticas: */

    // Usando um loop while para iterar uma lista de alunos
    while (current_student != NULL) {
        printf("%s\n", current_student->name);
        current_student = current_student->next;
    }

    // Usando o operador lógico && para evitar execuções desnecessárias
    if (x > 0 && y < 10) {
    // faz algo
    }

    // Usando nomes descritivos de variáveis
    for (int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }

    /* Más práticas: (depende do contexto do uso do controle de fluxo)*/

    // Usando múltiplas declarações if/else aninhadas em vez de switch
    if (x == 1) {
        // faz algo
    } else if (x == 2) {
        // faz algo diferente
    } else if (x == 3) {
        // faz algo ainda mais diferente
    }

    // Usando loops do tipo for quando um loop do tipo while é mais apropriado
    for (int i = 0; i < size; i++) {
        // faz algo
    }

    // Aninhando loops desnecessariamente
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // faz algo
        }
    }

    // Usando variáveis globais desnecessariamente
    int i = 0;
        while (i < 10) {
        int j = 0;
            while (j < 10) {
                // faz algo
                j++;
            }
        i++;
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char nome[50];
    float salario;
} Funcionario;

int main() {
    FILE *arquivo;
    Funcionario funcionarios[3] = {{1, "Joao", 1500.00},
                                   {2, "Maria", 2000.00},
                                   {3, "Jose", 1800.00}};

    // Abre o arquivo para escrita binária
    arquivo = fopen("funcionarios.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Escreve cada um dos funcionários no arquivo
    for (int i = 0; i < 3; i++) {
        fwrite(&funcionarios[i], sizeof(Funcionario), 1, arquivo);
    }

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}
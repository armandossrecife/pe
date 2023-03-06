/* Exemplo de más práticas para escrita em arquivos binários: */
#include <stdio.h>

typedef struct {
    int id;
    char nome[50];
    float preco;
} Produto;

int main() {
    FILE *arquivo;
    Produto produtos[3] = {
        {1, "Produto 1", 9.99},
        {2, "Produto 2", 19.99},
        {3, "Produto 3", 29.99}
    };

    // Abre o arquivo binário para escrita
    arquivo = fopen("produtos.bin", "wb");

    // Verifica se ocorreu algum erro na abertura do arquivo
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!");
        return 1;
    }

    // Grava os produtos no arquivo
    fwrite(produtos, sizeof(Produto), 3, arquivo);

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}

/* Nesse exemplo, utilizamos fwrite para escrever os dados de uma estrutura no arquivo binário, 
    sem verificar se a escrita foi bem-sucedida ou não. 
    Além disso, também não há verificação para garantir que a quantidade de dados escritos seja igual à quantidade de dados 
    que deveriam ser escritos. 
    
    Essas são más práticas que podem causar problemas na integridade dos dados e dificultar a leitura dos dados 
    em arquivos binários.*/
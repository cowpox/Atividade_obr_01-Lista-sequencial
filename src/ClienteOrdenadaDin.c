// main.c
#include "ListaOrdenadaDin.c"

int main() {
    LISTA lista;
    REGISTRO reg;

    // Inicializar a lista
    inicializarLista(&lista);

    // Exibir lista vazia
    printf("Lista vazia\n");
    exibirListaDetalhada(&lista);
    printf("\n");

    // Inserir elementos na lista.
    // Cada elemento será igual 2 x seu índice
    printf("Adicionando elementos\n");
    for (int i = 0; i < (2 * MAX + 1); i++) {
        reg.chave = 2 * i;
        inserirElemListaOrd(&lista, reg);
        exibirListaDetalhada(&lista);
    }
    printf("\n");

    // Remover elementos a partir do início
    printf("Excluindo elementos\n");
    for (int i = 0; i < (2 * MAX + 1); i++) {
        if (excluirElemLista(&lista, 2 * i))
            printf("Exclusao bem sucedida: %d.\n", 2 * i);
        exibirListaDetalhada(&lista);
    }
    printf("\n");

    return 0;
}

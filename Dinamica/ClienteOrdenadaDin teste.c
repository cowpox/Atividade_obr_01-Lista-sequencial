// main.c
#include "ListaOrdenadaDin.c"

int main() {
    LISTA lista;
    REGISTRO reg;

    // Inicializar a lista
    inicializarLista(&lista);

    // Exibir lista vazia
    exibirListaDetalhada(&lista);

    // Inserir elementos na lista
    reg.chave = 9;
    inserirElemListaOrd(&lista, reg);

    reg.chave = 3;
    inserirElemListaOrd(&lista, reg);

    // Exibir lista após inserções
    exibirListaDetalhada(&lista);

    reg.chave = 4;
    inserirElemListaOrd(&lista, reg);

    // Exibir lista após inserções
    exibirListaDetalhada(&lista);

    reg.chave = 1;
    inserirElemListaOrd(&lista, reg);
    reg.chave = 12;
    inserirElemListaOrd(&lista, reg);

    // Exibir lista após inserções
    exibirListaDetalhada(&lista);

    reg.chave = 15;
    inserirElemListaOrd(&lista, reg);
    reg.chave = 18;
    inserirElemListaOrd(&lista, reg);
    reg.chave = 23;
    inserirElemListaOrd(&lista, reg);
    reg.chave = 25;
    inserirElemListaOrd(&lista, reg);

    // Exibir lista após inserções
    exibirListaDetalhada(&lista);

    return 0;
}

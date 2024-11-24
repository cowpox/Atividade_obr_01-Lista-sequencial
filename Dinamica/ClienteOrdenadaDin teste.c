// main.c
#include "ListaOrdenadaDin.c"


int main() {
  LISTA lista;
  REGISTRO reg;

  // Inicializar a lista
  inicializarLista(&lista);

  // Exibir lista vazia
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));
  printf("Tamanho da lista em elementos: %d.\n", tamanhoEmElementos(&lista));
  printf("Calcula tamanho em bytes: %i.\n", calculaTamanhoEmBytes(tamanhoEmElementos(&lista)));

  // Inserir elementos na lista
  reg.chave = 9;
  inserirElemListaOrd(&lista, reg);



  reg.chave = 3;
  inserirElemListaOrd(&lista, reg);

    // Exibir lista após inserções
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));
  printf("Tamanho da lista em elementos: %d.\n", tamanhoEmElementos(&lista));
  printf("Calcula tamanho em bytes: %i.\n", calculaTamanhoEmBytes(tamanhoEmElementos(&lista)));

  reg.chave = 4;
  inserirElemListaOrd(&lista, reg);

    // Exibir lista após inserções
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));
  printf("Tamanho da lista em elementos: %d.\n", tamanhoEmElementos(&lista));
  printf("Calcula tamanho em bytes: %i.\n", calculaTamanhoEmBytes(tamanhoEmElementos(&lista)));


  reg.chave = 1;
  inserirElemListaOrd(&lista, reg);
  reg.chave = 12;
  inserirElemListaOrd(&lista, reg);

  // Exibir lista após inserções
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));
  printf("Tamanho da lista em elementos: %d.\n", tamanhoEmElementos(&lista));
  printf("Calcula tamanho em bytes: %i.\n", calculaTamanhoEmBytes(tamanhoEmElementos(&lista)));

  reg.chave = 15;
  inserirElemListaOrd(&lista, reg);
    reg.chave = 18;
  inserirElemListaOrd(&lista, reg);
    reg.chave = 23;
  inserirElemListaOrd(&lista, reg);
    reg.chave = 25;
  inserirElemListaOrd(&lista, reg);

   // Exibir lista após inserções
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista)); 
  printf("Tamanho da lista em elementos: %d.\n", tamanhoEmElementos(&lista));
  printf("Calcula tamanho em bytes: %i.\n", calculaTamanhoEmBytes(tamanhoEmElementos(&lista)));

  return 0;
}

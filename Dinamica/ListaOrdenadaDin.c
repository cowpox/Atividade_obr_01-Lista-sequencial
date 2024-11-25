// ListaOrdenada.c
#include "ListaOrdenadaDin.h"


/* Inicialização da lista sequencial (a lista já está criada e é apontada pelo endereço em l)
Adicionei a redefinição da variável maxLista para o valor MAX proposto inialmente */
// void inicializarLista(LISTA* l) {
//     l->nroElem = 0;
//     l->maxLista = MAX;
// }

void inicializarLista(LISTA* l) {
  //malloc(MAX + 1): inclui o registro sentinela
    l->A = (REGISTRO*)malloc((MAX + 1) * sizeof(REGISTRO));
    if (l->A == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    l->nroElem = 0;
    l->maxLista = MAX;
}






/* Retornar o tamanho da lista (numero de elementos "validos") */
int tamanho(LISTA* l) {
  return l->nroElem;
} /* tamanho */

/* Retornar o tamanho em bytes da lista. Neste caso, isto nao depende do numero
   de elementos que estao sendo usados, pois a alocacao de memoria eh estatica.
   A priori, nao precisariamos do ponteiro para a lista, vamos utiliza-lo apenas
   porque teremos as mesmas funcoes para listas ligadas.   
*/

int tamanhoEmBytes(LISTA* l) {
    return sizeof(LISTA);
} /* tamanhoEmBytes */


/* Retornar o tamanho da lista em elementos, ou seja, sua capacidade*/
int tamanhoEmElementos(LISTA* l){
  return l->maxLista;
}


int calculaTamanhoEmBytes(int nroElem) {
        //+1 => considerar o sentinela
        return (nroElem + 1) * sizeof(REGISTRO);
}


/* Exibição da lista sequencial */
void exibirLista(LISTA* l){
  int i;
  printf("Lista: \" ");
  for (i=0; i < l->nroElem; i++)
    printf("%i ", l->A[i].chave);
  printf("\"\n");
} /* exibirLista */ 



/* Exibição da lista sequencial com detalhes */
void exibirListaDetalhada(LISTA* l) {
    int i;
    printf("*****************************************\n");
    printf("Lista: \" ");
    for (i = 0; i < l->nroElem; i++) printf("%i ", l->A[i].chave);
    printf("\"\n");
    printf("-----------------------------------------\n");
    printf("Elementos (validos/máximo): %i/%d (%.1f%%)\n", tamanho(l),
           tamanhoEmElementos(l),
           100 * (float)tamanho(l) / tamanhoEmElementos(l));
    printf("Bytes (array/lista/total): %i/%i/%i\n",
           calculaTamanhoEmBytes(tamanhoEmElementos(l)), tamanhoEmBytes(l),
           calculaTamanhoEmBytes(tamanhoEmElementos(l)) + tamanhoEmBytes(l));
    printf("-----------------------------------------\n\n");
} /* exibirListaDetalhada */

/* Retornar a chave do primeiro elemento da lista sequencial (caso haja) e ERRO
   caso a lista esteja vazia */
TIPOCHAVE primeiroElem(LISTA* l){
  if(l->nroElem > 0) return l->A[0].chave;
  else return ERRO; // lista vazia
} /* primeiroElem */

/* Retornar a chave do ultimo elemento da lista sequencial (caso haja) e ERRO
   caso a lista esteja vazia */
TIPOCHAVE ultimoElem(LISTA* l) {
  if(l->nroElem > 0) return l->A[l->nroElem-1].chave;
  else return ERRO; // lista vazia
} /* ultimoElem */

/* Retornar a chave do elemento que está na posição n da LISTA. Lembre-se que as posicoes do
   arranjo A vao de 0 a MAX-1  */
TIPOCHAVE enesimoElem(LISTA* l, int n) {
  if( (n >= 0) && (n < l->nroElem)) return l->A[n].chave ;
  else return ERRO;
} /* enesimoElem */

/* Reinicializar a estrutura */
void reinicializarLista(LISTA* l) {
  l->nroElem = 0;
} /* reinicializarLista */


/* Busca sequencial em lista ordenada ou não SEM SENTINELA */
int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  while (i < l->nroElem){
    if(ch == l->A[i].chave) return i; // achou
    else i++;
  }
  return ERRO; // não achou
} /* buscaSequencial */


/* Busca sequencial em lista COM SENTINELA (vetor criado com MAX+1 posições) */
int buscaSentinela(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  l->A[l->nroElem].chave = ch; // sentinela
  while(l->A[i].chave != ch) i++;
  if (i > l->nroElem -1) return ERRO; // não achou
  else return i;
} /* buscaSentinela */

/* Busca sequencial em lista COM SENTINELA (vetor criado com MAX+1 posições) 
   considerando o arranjo ordenado */
int buscaSentinelaOrdenada(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  l->A[l->nroElem].chave = ch; // sentinela
  while(l->A[i].chave < ch) i++;
  if (i == l->nroElem || l->A[i].chave != ch) return ERRO; // não achou
  else return i;
} /* buscaSentinela */

/* Busca binaria em lista ordenada */
int buscaBinaria(LISTA* l, TIPOCHAVE ch){
  int esq, dir, meio;
  esq = 0;
  dir = l->nroElem-1;
  while(esq <= dir) {
    meio = ((esq + dir) / 2);
    if(l->A[meio].chave == ch) return meio; // achou
    else {
      if(l->A[meio].chave < ch) esq = meio + 1;
      else dir = meio - 1;
    }
  }
  return ERRO;
} /* buscaBinaria */


/* Redimensionamento da lista
se operacao = 1 => dobra
se operacao = -1 => reduz pela metade */
void resize(LISTA* l, int operacao) {
    if (operacao == 1) { // Operação para aumentar a capacidade
        int novoTamanhoElem = 2 * l->maxLista; // Dobrar a capacidade
        REGISTRO* novoArray = (REGISTRO*)realloc(l->A, (novoTamanhoElem + 1) * sizeof(REGISTRO));
        if (novoArray == NULL) {
            printf("Erro ao redimensionar o array.\n");
            return;
        }
        printf("Redimensionamento com sucesso: %d -> %d\n", l->maxLista, novoTamanhoElem);
        l->A = novoArray;        // Atualiza o ponteiro para o novo array
        l->maxLista = novoTamanhoElem; // Atualiza a capacidade máxima
    } else if (operacao == -1){
        int novoTamanhoElem = l->maxLista / 2; // Reduz em capacidade pela metade
        REGISTRO* novoArray = (REGISTRO*)realloc(l->A, (novoTamanhoElem + 1) * sizeof(REGISTRO));
        if (novoArray == NULL) {
            printf("Erro ao redimensionar o array.\n");
            return;
        }
        printf("Redimensionamento com sucesso: %d -> %d\n", l->maxLista, novoTamanhoElem);
        l->A = novoArray;        // Atualiza o ponteiro para o novo array
        l->maxLista = novoTamanhoElem; // Atualiza a capacidade máxima
    } else {
      printf("Operação inválida. Use 1 para aumentar ou -1 para reduzir a capacidade.\n");
    }
}


/* Exclusão do elemento cuja chave seja igual a ch */
bool excluirElemLista(LISTA* l, TIPOCHAVE ch) { 
  int pos, j;
  pos = buscaSequencial(l,ch);
  if(pos == ERRO) return false; // não existe
  for(j = pos; j < l->nroElem-1; j++) l->A[j] = l->A[j+1];
  l->nroElem--;
  /* chama a função resize para reduzir a lista pela metade (arg -1),
  caso o número de elementos seja no máximo 25% da capacidade total*/
  if (l->nroElem <= 0.25 * l->maxLista) resize(l, -1);
  return true;
} /* excluirElemLista */


/* Exclusão do elemento cuja chave seja igual a ch em lista ordenada*/
bool excluirElemListaOrd(LISTA* l, TIPOCHAVE ch) { 
  int pos, j;
  pos = buscaBinaria(l,ch);
  if(pos == ERRO) return false; // não existe
  for (j = pos; j < l->nroElem - 1; j++) l->A[j] = l->A[j + 1];
  l->nroElem--;
  /* chama a função resize para reduzir a lista pela metade (arg -1),
  caso o número de elementos seja no máximo 25% da capacidade total*/
  if (l->nroElem <= 0.25 * l->maxLista) resize(l, -1);
  return true;
} /* excluirElemListaOrd */





/* Inserção em lista ordenada usando busca binária permitindo duplicação */
bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
  if(l->nroElem >= l->maxLista) resize (l,1); /*chama a função de redimensionamento
  com o parâmetro 1 (duplicação) */
  int pos = l->nroElem;
  while(pos > 0 && l->A[pos-1].chave > reg.chave) {
    l->A[pos] = l->A[pos-1];
    pos--;
  }
  l->A[pos] = reg;
  l->nroElem++;
  return true;
} /* inserirElemListaOrd */


/* Inserção em lista ordenada usando busca binária sem duplicação */
bool inserirElemListaOrdSemDup(LISTA* l, REGISTRO reg) {
  if(l->nroElem >= l->maxLista) resize (l,1); /*chama a função de redimensionamento
  com o parâmetro 1 (duplicação) */
  int pos;
  pos = buscaBinaria(l,reg.chave);
  if(pos != ERRO) return false; // elemento já existe
  pos = l->nroElem-1;
  while(pos>0 && l->A[pos].chave > reg.chave) {
    l->A[pos+1] = l->A[pos];
    pos--;
  }
  l->A[pos+1] = reg;
  l->nroElem++;
  return true;
} /* inserirElemListaOrd */



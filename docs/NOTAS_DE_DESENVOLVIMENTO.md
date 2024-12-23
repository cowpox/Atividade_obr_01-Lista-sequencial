Objetivos gerais:
    Adicionar suporte ao redimensionamento dinâmico
        Capacidade de expandir o seu tamanho automaticamente
        Capacidade de reduzir o seu tamanho automaticamente

Objetivos específicos:
    Capacidade inicial: 50 elementos
    Se num_elem = capacidade => dobrar a capacidade
    Se num_elem <= 0.25 * capacidade => reduzir pela metade a capacidade

Dica:
    Utilizar a função realloc para redimensionar o vetor de forma dinâmica,
    alterando sua capacidade para o novo tamanho desejado sem perder os dados
    já armazenados.

Instrução:
    Criar uma função resize que aumente e reduza o tamanho

Meu plano:
para expandir => checar as condições nos métodos de inserção (no início)

para reduzir => checar as condições nos métodos de exclusão (ao final)

Mudanças:

1) Ajustar a declaração da estrutura LISTA para que o array A seja um ponteiro dinâmico
   typedef struct {
   REGISTRO* A;  // Ponteiro para o array dinâmico
   int nroElem;  // Número de elementos atualmente armazenados
   } LISTA;
2) Inserir o campo maxLista na estrutura da lista para monitorar o número máximo
   de elementos da lista (que mudará dinamicamente), pois a constante MAX definida
   em #define MAX 50 não pode ser mudada.
   typedef struct {
   REGISTRO* A;  // Ponteiro para o array dinâmico
   int nroElem;  // Número de elementos atualmente armazenados
   int maxLista; // Capacidade máxima da lista
   } LISTA;
3) Atualizar a função de inicialização da lista:
   Aloca dinamicamente para os registros
   Adicionei a redefinição da variável maxLista para o valor MAX proposto inialmente
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
4) Atualizar a função tamanhoEmBytes, pois agora a função como estava
   só retornaria o tamanho do ponteiro REGISTRO (e não o tamanho do array)
   int tamanhoEmBytes(LISTA* l) {
   return sizeof(LISTA) + ((l->maxLista + 1) * sizeof(REGISTRO));
   }

   update: retornei a função para o original, pois o tamanho da lista
   deve incluir apenas o tamanho de seus membros (e não do array para
   o qual o ponteiro aponta)

   int tamanhoEmBytes(LISTA* l) {
   return sizeof(LISTA);
   } /* tamanhoEmBytes */
5) Criar uma função para exibir a capacidade máxima da lista em elementos
   (não leva em conta o sentinela)
   int tamanhoEmElementos(LISTA* l){
   return l->maxLista;
   }
6) Criar uma função para calcular o tamanho do array registro em bytes
   necessários para conter x elementos. Esse valor será usado na função de
   redimensionamento
   int calculaTamanhoEmBytes(int nroElem) {
   //+1 => considerar o sentinela
   return (nroElem + 1) * sizeof(REGISTRO);
   }
7) Criar a função resize para o redimensionamento da lista. Ela recebe
   um argumento inteiro. Se for 1, ocorrerá duplicação de sua capacidade.
   Caso o valor seja -1, terá sua capacidade reduzida pela metade.
   O controle do número de elementos e do argumento a ser passado fica para
   a função que a chamar;
   void resize(LISTA* l, int operacao) {
   if (operacao == 1) { // Operação para aumentar a capacidade
   int novoTamanhoElem = 2 * l->maxLista; // Dobrar a capacidade
   REGISTRO* novoArray = (REGISTRO*)realloc(l->A, (novoTamanhoElem + 1) * sizeof(REGISTRO));
   if (novoArray == NULL) {
   printf("Erro ao redimensionar o array.\n");
   return;
   }
   l->A = novoArray;        // Atualiza o ponteiro para o novo array
   l->maxLista = novoTamanhoElem; // Atualiza a capacidade máxima
   } else if (operacao == -1){
   int novoTamanhoElem = l->maxLista / 2; // Reduz em capacidade pela metade
   REGISTRO* novoArray = (REGISTRO*)realloc(l->A, (novoTamanhoElem + 1) * sizeof(REGISTRO));
   if (novoArray == NULL) {
   printf("Erro ao redimensionar o array.\n");
   return;
   }
   l->A = novoArray;        // Atualiza o ponteiro para o novo array
   l->maxLista = novoTamanhoElem; // Atualiza a capacidade máxima
   } else {
   printf("Operação inválida. Use 1 para aumentar ou -1 para reduzir a capacidade.\n");
   }
   }

   update: inclui mensagem de redimensionamento (tamanho antigo -> tamanho novo), antes
   de atualizar a variável maxLista.
   printf("Redimensionamento com sucesso: %d -> %d\n", l->maxLista, novoTamanhoElem);
8) Atualizar a ação condicional nas funções de inserção
   No lugar de:
   if(l->nroElem >= MAX) return false; // lista cheia
   Colacado:
   if(l->nroElem >= l->maxLista) resize (l,1); /*chama a função de redimensionamento
   com o parâmetro 1 (duplicação) */
   Agora, sempre que atingir a capacidade máxima, ocorre o redimensionamento automático
   para o dobro da capacidade (primeiro objetivo específico cumprido - aumentar capacidade)
9) Incluir verificação condicional ao final das funções de exclusão.
   Sempre que o número de elementos válidos for menor ou igual a 25%
   da capacidade total, ocorre a chamada de redimensionamento com o
   argumento para reduzir o tamanho pela metade.
   /* chama a função resize para reduzir a lista pela metade (arg -1),
   caso o número de elementos seja no máximo 25% da capacidade total*/
   if (l->nroElem <= 0.25 * l->maxLista) resize(l, -1);
   Agora, sempre que o número de elementos atingir 25% ou menos da capacidade total, ocorre
   o redimensionamento automático para metade da capacidade (segundo objetivo específico
   cumprido - reduzir capacidade)
10) Criar uma função de visualização detalhada da lista, para
    facilitar os testes e demonstrações.
    Exibe os elementos da lista;
    Número de elementos válidos / capacidade total da lista;
    Tamanho em bytes do array que guarda os elementos da lista,
    de acordo com a fórmula: (numElem + 1) * 4, pois inclui um
    espaço a mais para o elemento sentinela;
    Tamanho em bytes da lista: 8 bytes para o ponteiro do array,
    4 bytes para cada variável (nroElem e maxLista);
    Tamanho total em bytes (soma dos dois anteriores).
    void exibirListaDetalhada(LISTA* l) {
    int i;
    printf("*****************************************\n");
    printf("Lista: \" ");
    for (i = 0; i < l->nroElem; i++) printf("%i ", l->A[i].chave);
    printf("\"\n");
    printf("-----------------------------------------\n");
    printf("Elementos (validos/máximo): %i/%d\n", tamanho(l),tamanhoEmElementos(l));
    printf("Bytes (array/lista/total): %i/%i/%i\n",
    calculaTamanhoEmBytes(tamanhoEmElementos(l)), tamanhoEmBytes(l),
    calculaTamanhoEmBytes(tamanhoEmElementos(l)) + tamanhoEmBytes(l));
    printf("-----------------------------------------\n");
    } /* exibirListaDetalhada */

    update: adicionei um mostrador porcentual do número de elementos,
    para facilitar a visualização de quando ocorrerá o redimensionamento (25 e 100%)
    printf("Elementos (validos/máximo): %i/%d (%.1f%%)\n", tamanho(l),
    tamanhoEmElementos(l),
    100 * (float)tamanho(l) / tamanhoEmElementos(l));
11) Automatizar, em ClienteOrdenadaDin.c, a inclusão e exclusão de elementos,
    bem como a exibição da lista e seus detalhes. Ao utilizar um contador até (2 * MAX + 1),
    é possível verificar 2 x o redimensionamento para cima.
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
12) Testes realizados com o MAX inicial de 1, 2, 4, 10 e 50 (como proposto).
    Todos com sucesso no redimensinamento para cima e para baixo, de acordo
    com os critérios estabelecidos.
13) Criar função para liberar a memória da lista e apontar o ponteiro para NULL.
    A função será chamada ao final de main().
    void liberarLista(LISTA* l) {
    if (l->A != NULL) { // Verifica se há memória alocada
    free(l->A);      // Libera a memória alocada
    l->A = NULL;     // Evita ponteiros pendentes
    }
    l->nroElem = 0;
    l->maxLista = 0;
    }
14) Declarar funções no arquivo header
    void exibirListaDetalhada(LISTA* l);
    void resize(LISTA* l, int operacao);
    int calculaTamanhoEmBytes(int nroElem);
    int tamanhoEmElementos(LISTA* l);
    void liberarLista(LISTA* l);
15) Organizar a estrutura dos arquivos
    ProjetoListaSequencial/
    ├── README.md              # Explicação do projeto
    ├── LICENSE                # Licença MIT
    ├── src/                   # Código-fonte principal
    │   ├── ListaOrdenadaDin.c
    │   ├── ClienteOrdenadaDin.c
    ├── include/               # Arquivos de cabeçalho
    │   ├── ListaOrdenadaDin.h
    ├── docs/                  # Documentação adicional (se aplicável)
    │   ├── Atividade_Lista_Sequencial.pdf
    │   ├── NOTAS_DE_DESENVOLVIMENTO.md
    └── .gitignore             # Para ignorar arquivos desnecessários no repositório
17) Criado arquivo README.md
18) Criado arquivo LICENSE

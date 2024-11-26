# Lista Sequencial Ordenada com Redimensionamento Dinâmico

Este projeto implementa uma **lista sequencial ordenada** em C, com suporte para **redimensionamento dinâmico**. A lista expande ou reduz automaticamente sua capacidade conforme elementos são inseridos ou removidos, garantindo eficiência no uso de memória.

---

## **Objetivos**

### Objetivo Geral

Adicionar suporte ao **redimensionamento dinâmico**, com capacidade para:

- Expandir automaticamente quando atingir a capacidade máxima.
- Reduzir automaticamente quando a ocupação cair abaixo de 25% da capacidade.

### Objetivos Específicos

- **Capacidade inicial**: 50 elementos.
- **Expansão**: Duplicar a capacidade ao atingir o limite máximo.
- **Redução**: Reduzir a capacidade pela metade quando o número de elementos cair para 25% ou menos.

---

## **Estrutura do Projeto**

ProjetoListaSequencial/
├── README.md              # Explicação do projeto
├── LICENSE                # Licença MIT
├── src/                   # Código-fonte principal
│   ├── ListaOrdenadaDin.c
│   ├── ClienteOrdenadaDin.c
├── include/               # Arquivos de cabeçalho
│   ├── ListaOrdenadaDin.h
├── docs/                  # Documentação adicional
│   ├── Atividade_Lista_Sequencial.pdf
│   ├── NOTAS_DE_DESENVOLVIMENTO.md # Registro das decisões e anotações técnicas
└── .gitignore             # Arquivos ignorados no repositório


## **Funcionalidades Principais**

1. **Inserção**:

   - Inserção ordenada de elementos na lista.
   - Expande a lista automaticamente quando atinge a capacidade máxima.
2. **Remoção**:

   - Exclusão de elementos com base em suas chaves.
   - Reduz automaticamente a capacidade da lista para economizar memória.
3. **Busca**:

   - Busca sequencial, com sentinela e binária para localizar elementos.
4. **Visualização**:

   - Exibição detalhada do estado atual da lista:
     - Número de elementos válidos.
     - Capacidade total da lista.
     - Uso de memória.
5. **Redimensionamento Automático**:

   - Implementado na função `resize`, chamada pelas funções de inserção e remoção.
6. **Liberação de Memória**:

   - Função específica para liberar a memória e evitar vazamentos.

## **Como Compilar e Executar**

1. **Requisitos**:

   - Compilador GCC.
   - Sistema operacional compatível com C (Linux, Windows, etc.).
2. **Passos**:

   - Clone o repositório:
     ```bash
     git clone https://github.com/cowpox/Atividade_obr_01-Lista-sequencial.git
     cd ProjetoListaSequencial
     ```
   - Compile o programa:
     ```bash
     gcc -o ClienteOrdenada src/ClienteOrdenadaDin.c src/ListaOrdenadaDin.c -Iinclude
     ```
   - Execute o programa:
     ```bash
     ./ClienteOrdenada
     ```

---

## **Testes Realizados**

1. **Inserção de Elementos**:

   - Testado para inserir até o dobro da capacidade inicial, verificando a expansão.
2. **Remoção de Elementos**:

   - Testado para remover até que a lista atinja 25% de sua capacidade, verificando a redução.
3. **Redimensionamento**:

   - Testado com valores de capacidade inicial de 1, 2, 4, 10 e 50 elementos.
4. **Casos Limite**:

   - Inserção e remoção repetida para validar consistência.

---

## **Detalhes Técnicos**

- **Estrutura da Lista**:

  - `REGISTRO* A`: Ponteiro dinâmico para os elementos.
  - `int nroElem`: Número de elementos válidos.
  - `int maxLista`: Capacidade máxima atual da lista.
- **Função `resize`**:

  - Responsável por redimensionar a lista dinamicamente.
  - Argumentos:
    - `1`: Expande a capacidade.
    - `-1`: Reduz a capacidade pela metade.
- **Função `exibirListaDetalhada`**:

  - Exibe o estado atual da lista, incluindo o uso de memória.

## Documentação Técnica

Para detalhes sobre as decisões de design e desenvolvimento, consulte [NOTAS_DE_DESENVOLVIMENTO.md](docs/NOTAS_DE_DESENVOLVIMENTO.md).

---

## **Licença**

Este projeto é disponibilizado sob a licença MIT. Consulte o arquivo `LICENSE` para mais detalhes.

---

## **Autor**

Desenvolvido por Adriano Brandão como parte de um projeto acadêmico da disciplina de Estrutura de Dados (Professor Anderson Paulo Avila Santos - Universidade Estadual de Londrina) para estudar listas sequenciais com redimensionamento dinâmico em C.

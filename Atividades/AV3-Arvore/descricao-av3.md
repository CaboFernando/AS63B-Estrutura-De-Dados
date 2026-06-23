# Árvore Binária de Busca - Sistema de Cadastro de Alunos

## Descrição

Este projeto implementa uma **Árvore Binária de Busca (ABB)** em C++ para gerenciar um sistema de cadastro de alunos. A árvore é organizada pelo nome do aluno, permitindo inserção, busca e visualização ordenada dos registros.

A escolha foi **Árvore Binária de Busca (ABB)** pela simplicidade e facilidade de implementação e adaptação, como exemplo essa que foi utilizada 100% baseada na implementação de Árvore Binária disponibilizado pelo Professor Clayton Kossoski.

## Estrutura do Projeto

O projeto é composto por dois arquivos principais:
- `arvore-binaria.cpp`: Implementação da árvore binária e suas operações
- `main.cpp`: Programa principal que demonstra o uso da estrutura

## Estruturas de Dados

### Aluno
```cpp
struct aluno {
    int matricula;    // Número de matrícula do aluno
    string nome;      // Nome completo (usado como chave de ordenação)
    string curso;     // Curso do aluno
};
```

### Nó da Árvore
```cpp
struct no {
    aluno info;       // Dados do aluno
    no* esq;         // Ponteiro para subárvore esquerda
    no* dir;         // Ponteiro para subárvore direita
};
```

## Funcionalidades

### 1. Criação da Árvore (`cria_ArvBin()`)
- Cria uma árvore binária vazia
- Retorna um ponteiro para a raiz da árvore
- Inicializa a raiz como `nullptr`

### 2. Inserção de Alunos (`insere_ArvBin()`)
- Insere um novo aluno na árvore
- **Critério de ordenação**: Nome do aluno (ordem alfabética)
- Nomes menores vão para a subárvore esquerda
- Nomes maiores vão para a subárvore direita
- Retorna `true` se a inserção for bem-sucedida

### 3. Busca por Nome (`buscaAlunoPorNome()`)
- Busca um aluno específico pelo nome
- Utiliza busca binária (eficiente)
- Exibe os dados do aluno se encontrado
- Mostra mensagem de erro se não encontrado

### 4. Percurso em Ordem (`emOrdem()`)
- Exibe todos os alunos em ordem alfabética
- Percurso: subárvore esquerda → raiz → subárvore direita
- Formato de saída: "Nome - Matrícula - Curso"

### 5. Informações da Árvore (`infoArvore()`)
- **Quantidade total de alunos**: Conta todos os nós da árvore
- **Altura da árvore**: Maior distância da raiz até uma folha
- Funciona mesmo com árvore vazia

### 6. Liberação de Memória (`libera_ArvBin()`)
- Libera toda a memória alocada pela árvore
- Percurso pós-ordem para liberar todos os nós
- Evita vazamentos de memória

## Como Usar

### Exemplo de Uso
```cpp
#include "arvore-binaria.cpp"

int main() {
    // Criar árvore
    ArvBin* raiz = cria_ArvBin();
    
    // Inserir alunos
    insere_ArvBin(raiz, Aluno{101, "John Smith", "Engenharia de Software"});
    insere_ArvBin(raiz, Aluno{102, "Alice Johnson", "Sistemas de Informação"});
    
    // Visualizar alunos em ordem
    emOrdem(*raiz);
    
    // Buscar aluno
    buscaAlunoPorNome(*raiz, "Alice Johnson");
    
    // Ver informações
    infoArvore(raiz);
    
    // Liberar memória
    libera_ArvBin(raiz);
    
    return 0;
}
```

## Complexidade das Operações

| Operação | Melhor Caso | Caso Médio | Pior Caso |
|----------|-------------|------------|-----------|
| Inserção | O(log n) | O(log n) | O(n) |
| Busca | O(log n) | O(log n) | O(n) |
| Percurso | O(n) | O(n) | O(n) |
| Info Árvore | O(n) | O(n) | O(n) |

> **Nota**: O pior caso O(n) ocorre quando a árvore está degenerada (como uma lista encadeada)

## Exemplo de Saída

```
Percurso em ordem: 
Alice Johnson - 102 - Sistemas de Informação
Emily - 104 - Engenharia de Software
John Smith - 101 - Engenharia de Software
Michael Brown - 103 - Ciência da Computação

Aluno encontrado: John Smith - 101 - Engenharia de Software

--- Informações da Árvore ---
Quantidade total de alunos cadastrados: 4
Altura da árvore: 3
```

## Características Técnicas

- **Linguagem**: C++
- **Tipo de Árvore**: Árvore Binária de Busca (não balanceada)
- **Chave de Busca**: Nome do aluno (string)
- **Alocação**: Dinâmica (uso de ponteiros e `new`/`delete`)
- **Percurso Principal**: Em-ordem (ordem alfabética)

## Licença

Este código foi desenvolvido para fins educacionais e está disponível para uso e modificação.
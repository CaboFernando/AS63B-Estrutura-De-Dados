# Respostas validadas — Lista de Atividades 2

Este arquivo apresenta as respostas corretas para a **Lista de Atividades 2** (Listas Encadeadas em C++), com breves justificativas e o gabarito final.

---

1) Resposta: B
- Justificativa: `elemento` representa um nó da lista encadeada (contém dados e o ponteiro `prox`).

2) Resposta: `no = no->prox;`
- Justificativa: essa instrução avança o ponteiro `no` para o próximo nó.

3) Resposta correta: V F V V
- Explicação: "Lista" normalmente é um ponteiro para `elemento` (V). `cria_lista()` retorna uma lista inicializada/vazia, não preenchida (F). `prox` guarda o endereço do próximo nó (V). `libera_lista()` libera cada nó para evitar vazamento de memória (V).

4) Resposta: Verifica se a lista (ou o ponteiro para ela) é nula; se for, indica lista vazia e evita acessar ponteiros inválidos (evita segfaults) — por isso retorna 0.

5) Resposta: C
- Justificativa: A estrutura `aluno` (ou equivalente) contém os campos de dados (matrícula, nome, etc.).

6) Resposta: 3 elementos
- Justificativa: foram feitas três chamadas de inserção final (assumindo o terceiro usa `li`), portanto a lista terá três nós.

7) Resposta: Representa o ponteiro para o nó anterior (o "anterior" usado para atualizar ligações ao remover o último nó).

8) Resposta: Diferença
- `insere_lista_final`: percorre até o fim e anexa o novo nó como último elemento (sem garantir ordenação).
- `insere_lista_ordenada`: percorre a lista para encontrar a posição correta mantendo a lista ordenada (inserção no meio ou no início possível).

9) Resposta: D
- Justificativa: ao remover o único elemento, a lista torna-se vazia (ponteiro cabeça passa a `nullptr`).

10) Desenho da lista após inserções (na ordem indicada):

Andre (2) -> Ricardo (4) -> Bianca (1) -> nullptr

Se a inserção fosse ordenada por matrícula, a ordem final seria: Bianca (1) -> Andre (2) -> Ricardo (4) -> nullptr

11) Resposta: "menor que"
- Frase completa: O laço continua enquanto a matrícula atual for menor que a matrícula do novo aluno.

12) Resposta: Para liberar a memória alocada de cada nó (`delete no`) enquanto percorre a lista, evitando vazamento de memória.

13) Resposta: C
- Justificativa: `imprime_lista()` e `tamanho_lista()` percorrem a lista nó a nó; `cria_lista()` apenas aloca e inicializa a estrutura (ex.: retorna `nullptr` ou estrutura vazia).

14) Resposta: 11
- Justificativa: inserção ordenada dos valores 20, 41, 11, 23 resulta na ordem 11, 20, 23, 41 — primeira matrícula exibida é 11.

15) Trecho em C++ (exemplo mínimo, auto-contido):

```cpp
#include <iostream>
#include <string>

struct Aluno { int matricula; std::string nome; };

struct No {
    Aluno dados;
    No* prox;
    No(const Aluno &a): dados(a), prox(nullptr) {}
};

No* cria_lista() { return nullptr; }

void insere_lista_final(No*& li, const Aluno &a) {
    No* no = new No(a);
    if (li == nullptr) { li = no; return; }
    No* aux = li;
    while (aux->prox) aux = aux->prox;
    aux->prox = no;
}

void imprime_lista(No* li) {
    for (No* p = li; p != nullptr; p = p->prox)
        std::cout << p->dados.matricula << " - " << p->dados.nome << std::endl;
}

int main() {
    No* li = cria_lista();
    Aluno a{123, "Joao"};
    insere_lista_final(li, a);
    imprime_lista(li);
    // liberar memória omitido por brevidade
    return 0;
}
```

16) Resposta: A principal vantagem é a flexibilidade (cresce/diminui dinamicamente; inserções/remoções sem realocar todo o vetor).

17) Implementação de `busca_matricula` (compatível com o exemplo acima):

```cpp
int busca_matricula(No* li, int mat) {
    for (No* p = li; p != nullptr; p = p->prox) {
        if (p->dados.matricula == mat) return 1;
    }
    return 0;
}
```

18) Questão sobre grande volume de alunos
1. Uma lista encadeada seria adequada dependendo do padrão de acesso: é boa quando se faz muitas inserções e remoções sequenciais ou em posições conhecidas; é menos adequada quando se precisa de acesso aleatório rápido.
2. Vantagens: crescimento dinâmico, inserções/remoções eficientes (O(1)) quando se tem o ponteiro/posição, baixo custo para redimensionamento.
3. Limitações: acesso aleatório lento (O(n)), maior overhead de memória por nó (ponteiro extra), menos adequada para buscas frequentes sem ordenação/índices.

---

GABARITO (resumo):

1) B
2) no = no->prox;
3) V F V V
4) Verificação de lista vazia / evita acesso nulo
5) C
6) 3
7) Ponteiro para nó anterior
8) ver explicação acima
9) D
10) Andre(2) -> Ricardo(4) -> Bianca(1) -> nullptr  (ou ordenada: Bianca -> Andre -> Ricardo)
11) menor que
12) Para liberar memória de cada nó (delete)
13) C
14) 11
15) Código exemplo acima
16) Flexibilidade (crescimento dinâmico)
17) Código exemplo acima (retorna 1 se encontrar, 0 caso contrário)
18) Ver respostas e justificativas acima

Arquivo gerado automaticamente: Respostas validadas e gabarito.

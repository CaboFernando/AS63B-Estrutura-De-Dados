# **LISTA DE ATIVIDADES 2**

### **Questão 1**

### Lista de Exercícios — Listas Encadeadas em C++

### A estrutura "elemento" possui qual finalidade principal?

### A) Armazenar apenas as notas dos alunos

### B) Representar um nó da lista encadeada

### C) Criar um vetor dinâmico

### D) Controlar o tamanho da lista

### ---

### **Questão 2**

### Complete o código

### Complete a instrução abaixo responsável por avançar para o próximo nó:

### no \= \_\_\_\_\_\_\_\_\_\_\_\_;

### ---

### **Questão 3**

### Analise as afirmações e assinale V para verdadeiro ou F para falso:

### ( ) "Lista" é um ponteiro para "elemento".

### ( ) A função "cria\_lista()" retorna uma lista já preenchida.

### ( ) O campo "prox" armazena o endereço do próximo nó.

### ( ) A função "libera\_lista()" evita vazamento de memória.

### ---

### **Questão 4**

### Interpretação de código

### Observe o trecho:

### if(li \== nullptr)

###     return 0;

### Explique com suas palavras por que essa verificação é importante.

### ---

### **Questão 5**

### Qual estrutura armazena os dados?

### A) "elemento"

### B) "Lista"

### C) "aluno"

### D) "prox"

### ---

### **Questão 6**

### Após as inserções abaixo:

### insere\_lista\_final(li, a\[0\]);

### insere\_lista\_final(li, a\[1\]);

### insere\_lista\_final(\*, a\[2\]);

### Quantos elementos existirão na lista?

### ---

### **Questão 7**

### Na função "remove\_lista\_final", o que o ponteiro "ant" representa?

### ---

### **Questão 8**

### Detalhe a diferença entre:

### \- inserção no final ("insere\_lista\_final")

### \- inserção ordenada ("insere\_lista\_ordenada")

### ---

### **Questão 9**

### O que acontece quando a lista possui apenas um elemento e "remove\_lista\_final()" é executada?

### A) O programa encerra

### B) O ponteiro "prox" recebe "nullptr"

### C) O nó é duplicado

### D) A lista torna-se vazia

### ---

### **Questão 10**

### Desenhe a lista após as seguintes inserções:

### {2,"Andre"}

### {4,"Ricardo"}

### {1,"Bianca"}

### Represente os ponteiros entre os nós seguindo uma lista encadeada.

### ---

### **Questão 11**

### Na inserção ordenada, o laço abaixo percorre a lista enquanto:

### while(atual \!= nullptr && atual-\>dados.matricula \< al.matricula)

### Complete:

### O laço continua enquanto a matrícula atual for \_\_\_\_\_\_\_\_\_\_\_\_\_ a matrícula do novo aluno.

### ---

### **Questão 12**

### Por que a função "libera\_lista()" utiliza "delete no" dentro do laço?

### ---

### **Questão 13**

### Considere as seguintes funções presentes no código da lista encadeada:

### imprime\_lista()

### remove\_lista\_meio()

### tamanho\_lista()

### cria\_lista()

### Agora analise o trecho abaixo:

| Lista\* li \= cria\_lista(); cout \<\< tamanho\_lista(li) \<\< endl; remove\_lista\_meio(li, 10); imprime\_lista(li); |
| :---- |

### Sobre as funções executadas nesse trecho, assinale a alternativa correta:

### A) Todas as funções apresentadas percorrem completamente a lista em qualquer situação.

### B) remove\_lista\_meio() nunca percorre a lista, pois a remoção é feita diretamente pelo ponteiro li.

### C) imprime\_lista() e tamanho\_lista() realizam percurso sequencial nó a nó, enquanto cria\_lista() apenas aloca e inicializa a estrutura da lista.

### D) Apenas tamanho\_lista() percorre toda a lista obrigatoriamente, independentemente da quantidade de elementos.

### E) cria\_lista() percorre a lista para inicializar os ponteiros com nullptr.

### ---

### **Questão 14**

### Qual será a primeira matrícula exibida após a inserção abaixo usando "insere\_lista\_ordenada()"?

### 20, 41, 11, 23

### ---

### **Questão 15**

### Escreva um trecho em C++ que:

### \- crie uma lista encadeada;

### \- insira um aluno;

### \- imprima a lista.

### ---

### **Questão 16**

### Qual é a principal vantagem de uma lista encadeada em relação a um vetor tradicional?

### ---

### **Questão 17**

### Implemente uma função chamada:

### int busca\_matricula(Lista\* li, int mat)

### A função deve:

### \- retornar "1" se a matrícula existir;

### \- retornar "0" caso contrário.

### ---

### **Questão 18**

### Uma universidade possui milhares de alunos sendo inseridos e removidos frequentemente do sistema.

### 1\. Uma lista encadeada seria uma boa escolha?

### 2\. Quais vantagens ela apresentaria?

### 3\. Quais seriam suas limitações?

### ---

**MATERIAIS COMPLEMENTARES**  
GEEKSFORGEEKS. Linked List in C++. \[S. l.\], 2025\. Disponível em: [https://www.geeksforgeeks.org/cpp/cpp-linked-list/](https://www.geeksforgeeks.org/cpp/cpp-linked-list/). Acesso em: 15 maio 2026\.

LEARN-CPP.ORG. *Linked lists*. \[S. l.\], \[202-\]. Disponível em: [https://www.learn-cpp.org/en/Linked\_lists](https://www.learn-cpp.org/en/Linked_lists). Acesso em: 15 maio 2026\.
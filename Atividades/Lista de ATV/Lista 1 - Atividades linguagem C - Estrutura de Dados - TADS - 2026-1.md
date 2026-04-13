# **LISTA DE ATIVIDADES 1**

---

### **Questão 1 \- Certo**

Em C/C++, uma variável pode ser entendida como:

 A) **Um local na memória identificado por um nome**  
 B) Um valor fixo armazenado diretamente no código-fonte  
 C) Um registrador da CPU acessado diretamente pelo programador  
 D) Um tipo de dado sem localização física bem definida

---

### **Questão 2 \- Certo**

Sobre a organização da memória em um computador, é correto afirmar que:

 A) A memória é composta por blocos de tamanhos variáveis sem ordem definida  
 B) **Cada célula de memória possui um endereço único**  
 C) Apenas variáveis inteiras possuem endereço na memória  
 D) A memória não possui sequência lógica de endereços

---

### **Questão 3 \- Certo**

Em relação às células de memória, assinale a alternativa correta:

 A) Cada célula armazena 4 bytes obrigatoriamente  
 B) Todas as células possuem o mesmo endereço  
 C) Cada célula pode armazenar apenas números inteiros  
 D) **Cada célula armazena 1 byte e possui um endereço único** 

---

### **Questão 4 \- Errado, resposta certa é C**

Considere os endereços de memória. Qual das afirmações é correta?

 A) O endereço 1776 vem antes de 1775  
 B) O endereço 1776 vem depois de 1777  
 C) O endereço 1776 está entre 1775 e 1777  
 D) **Os endereços não seguem ordem sequencial**

---

### **Questão 5 \- Certo**

Quando uma variável é declarada em C++, o que acontece?

 A) O programador escolhe manualmente o endereço de memória  
 B) Nenhum espaço na memória é reservado  
 C) **Um espaço na memória é alocado automaticamente**  
 D) A variável é armazenada apenas no disco rígido

---

### **Questão 6 \- Certo**

Quem geralmente é responsável por decidir o endereço de memória das variáveis em tempo de execução?

 A) O compilador exclusivamente  
 B) O programador  
 C) O processador manualmente  
 D) **O sistema operacional/ambiente de execução**

---

### **Questão 7 \- Errado, resposta certa é B**

Por que pode ser útil obter o endereço de uma variável em um programa?

 A) Para modificar o tipo da variável  
 B) Para acessar posições de memória relativas a ela  
 C) **Para eliminar a variável da memória**  
 D) Para evitar o uso de operadores

---

### **Questão 8 \- Certo**

A principal função de um ponteiro em C/C++ é:

 A) Armazenar valores inteiros apenas  
 B) Controlar a execução de loops  
 C) **Armazenar o endereço de memória de outra variável**  
 D) Substituir variáveis comuns

---

### **Questão 9 \- Certo**

O operador `&` em C/C++ é utilizado para:

 A) Multiplicar valores  
 B) Obter o conteúdo de uma variável  
 C) **Obter o endereço de memória de uma variável**  
 D) Comparar duas variáveis

---

### **Questão 10 \- Certo**

Considere o trecho:

```c++
 int myvar;
 int foo;
 foo = &myvar;
``` 

Após a execução, a variável `foo` contém:

 A) **O endereço de memória de `myvar`**  
 B) O valor de `myvar`  
 C) Um valor indefinido sempre  
 D) O tipo da variável `myvar`

---

### **Questão 11 \- Certo**

Qual é a principal diferença entre as instruções abaixo?

```c++
 foo = &myvar;
 bar = myvar;
``` 

 A) Ambas atribuem o endereço de `myvar`  
 B) Ambas atribuem o valor de `myvar`  
 C) **A primeira atribui o endereço, a segunda atribui o valor**  
 D) Não há diferença entre elas

---

### **Questão 12 \- Certo**

Suponha que `myvar` armazena o valor 25 e está no endereço 1776\. Após executar:

```c++
 foo = &myvar;
``` 

Qual será o valor de `foo`?

 A) 25  
 B) **1776**  
 C) &25  
 D) 0

---

### **Questão 13 \- Certo**

Considere o código:

```c++
 myvar = 25;
 foo = &myvar;
 bar = myvar;
``` 

Qual é o valor armazenado em `bar`?

 A) 1776  
 B) Endereço de `myvar`  
 C) Indefinido  
 D) **25**

---

### **Questão 14 \- Errado, resposta certa C**

Uma variável que armazena o endereço de outra variável é chamada de:

 A) **Referência**  
 B) Vetor  
 C) Ponteiro  
 D) Constante

---

### **Questão 15 \- Certo**

Sobre o operador `&`, é correto afirmar que:

 A) Ele altera o valor da variável  
 B) **Ele retorna o endereço da variável na memória**  
 C) Ele só pode ser usado com números inteiros  
 D) Ele remove a variável da memória

---

### **Questão 16 \- Certo**

Por que o endereço real de uma variável geralmente não é conhecido antes da execução do programa?

 A) Porque o compilador não funciona corretamente  
 B) Porque o programador define isso manualmente  
 C) **Porque o sistema operacional decide em tempo de execução**  
 D) Porque variáveis não possuem endereço fixo

---

### **Questão 17 \- Certo**

O operador `*` aplicado a um ponteiro é utilizado para:

 A) **Acessar o valor armazenado no endereço apontado**  
 B) Declarar uma variável comum  
 C) Obter o endereço da variável  
 D) Comparar dois ponteiros

---

### **Questão 18 \- Errado, resposta certa C**

Considere:

```c++
 int myvar = 25;
 int *foo = &myvar;
 int baz;
 baz = *foo;
``` 

Qual será o valor de `baz`?

 A) **Endereço de `myvar`**  
 B) 1776  
 C) 25  
 D) Indefinido

---

### **Questão 19 \- Certo**

Dada a instrução:

```c++
 baz = foo;
``` 

Sabendo que `foo` é um ponteiro que armazena o valor 1776, o valor de `baz` será:

 A) 25  
 B) **1776**  
 C) O conteúdo de `myvar`  
 D) 0

---

### **Questão 20 \- Certo**

Qual a diferença entre `foo` e `*foo`?

 A) Não há diferença  
 B) `foo` é o valor armazenado e `*foo` é o endereço  
 C) **`foo` é o endereço e `*foo` é o valor armazenado nesse endereço**  
 D) Ambos representam endereços

---

### **Questão 21 \- Errado, resposta certa D**

Considere que:

```c++
 myvar = 25
 foo = &myvar
``` 

Qual expressão retorna o valor 25?

 A) `foo`  
 B) `&foo`  
 C) **`**foo`**  
 D) `*foo`

---

### **Questão 22 \- Certo**

Sobre os operadores `&` e `*`, é correto afirmar:

 A) Ambos fazem exatamente a mesma operação  
 B) `&` obtém o valor e `*` obtém o endereço  
 C) **`&` retorna o endereço e `*` retorna o valor apontado**  
 D) Nenhum deles está relacionado a ponteiros

---

### **Questão 23 \- Errado, resposta certa C**

Após executar:

```c++
 myvar = 25;
 foo = &myvar;
``` 

Qual das alternativas é verdadeira?

 A) **`*foo == 1776`**  
 B) `foo == 25`  
 C) `*foo == 25`  
 D) `&foo == 25`

---

### **Questão 24 \- Certo**

Se o endereço armazenado em `foo` não mudar, qual expressão continuará sendo verdadeira?

 A) `foo == 25`  
 B) **`*foo == valor de myvar`**  
 C) `&foo == myvar`  
 D) `foo == *foo`

---

### **Questão 25 \- Certo**

A sintaxe correta para declarar um ponteiro em C/C++ é:

 A) **`type *name`**`;`  
 B) `type name*;`  
 C) `type &name;`  
 D) `pointer type name;`

---

### **Questão 26 \- Errado, resposta certa B**

Na declaração abaixo:

```c++
 int *number;
``` 

O que significa `int`?

 A) **É o tipo do ponteiro**  
 B) É o tipo do dado apontado pelo ponteiro  
 C) É o endereço do ponteiro  
 D) Não tem relação com o ponteiro

---

### **Questão 27 \- Errado, resposta certa B**

Considere as declarações:

```c++
 int *p1;
 char *p2;
 double *p3;
``` 

É correto afirmar que:

 A) Todos ocupam necessariamente tamanhos diferentes na memória  
 B) Todos são ponteiros, mas apontam para tipos diferentes  
 C) **Apenas `p1` é um ponteiro**  
 D) Apenas `p3` pode ser dereferenciado

---

### **Questão 28 \- Certo**

Sobre o operador `*` na declaração de ponteiros, é correto afirmar:

 A) Ele sempre significa dereferência  
 B) Ele faz multiplicação  
 C) Ele acessa o valor armazenado  
 D) **Ele indica que a variável é um ponteiro**

---

### **Questão 29 \- Certo**

Considere:

```c++
 int *p1, p2;
``` 

Qual alternativa está correta?

 A) `p1` e `p2` são ponteiros  
 B) Apenas `p2` é ponteiro  
 C) **Apenas `p1` é ponteiro**  
 D) Nenhuma das variáveis é ponteiro

---

### **Questão 30 \- Errado, resposta certa C**

No código:

```c++
 int firstvalue, secondvalue;
 int *mypointer;
 mypointer = &firstvalue;
 *mypointer = 10;
``` 

Após a execução, o valor de `firstvalue` será:

 A) **Indefinido**  
 B) 0  
 C) 10  
 D) Endereço de memória

---

### **Questão 31 \- Errado, resposta certa A**

Ainda no mesmo código, após:

```c++
 mypointer = &secondvalue;
 *mypointer = 20;
``` 

O valor de `secondvalue` será:

 A) 20  
 B) 10  
 C) Endereço de `mypointer`  
 D) **Indefinido**

---

### **Questão 32 \- Errado, resposta certa B**

Considere o código:

```c++
 int firstvalue = 5, secondvalue = 15;
 int *p1, *p2;
 p1 = &firstvalue;
 p2 = &secondvalue;
 *p1 = 10;
 *p2 = *p1;
``` 

Qual será o valor de `secondvalue` ao final?

 A) 5  
 B) 10  
 C) **15**  
 D) 20

---

### **Questão 33 \- Errado, resposta certa C**

Considere a continuação:

```c++
 p1 = p2;
 *p1 = 20;
``` 

Qual será o valor final de `secondvalue`?

 A) 10  
 B) **15**  
 C) 20  
 D) Indefinido

---

### **Questão 34 \- Errado, resposta certa D**

Após todas as operações do exemplo completo, qual será o valor de `firstvalue`?

 A) **5**  
 B) 20  
 C) 15  
 D) 10

---

### **Questão 35 \- Certo**

Qual alternativa melhor descreve a diferença entre usar `p1` e `*p1`?

 A) Não há diferença  
 B) `p1` é o valor e `*p1` é o tipo  
 C) **`p1` é o endereço, `*p1` é o valor apontado**  
 D) `p1` é o ponteiro e `*p1` é outro ponteiro

---

**Questão 36**

Implemente um programa em linguagem C para gerenciar os dados de um funcionário.

O programa deve:

1. Declarar uma struct chamada `Funcionario`, contendo:  
   * `nome` (string)  
   * `salario` (float)  
   * `idade` (int)  
2. Criar uma função chamada `atualizarDados` que receba como parâmetros:  
   * Um ponteiro para um `Funcionario`  
   * Um valor de aumento salarial (float)  
   * Um novo valor de idade (int)  
3. A função `atualizarDados` deve:  
   * Atualizar o salário do funcionário somando o aumento recebido  
   * Atualizar a idade do funcionário

⚠️ **Importante:** A atualização dos dados deve ser feita diretamente na struct original, utilizando **passagem de parâmetro por referência (ponteiros)**.

4. No `main`:  
   * Ler os dados de um funcionário  
   * Ler o valor de aumento salarial e a nova idade  
   * Chamar a função `atualizarDados`  
   * Exibir os dados atualizados do funcionário

---

### **Referências complementares**

###  CPLUSPLUS.COM. Pointers. Cplusplus.com. Disponível em: https://cplusplus.com/doc/tutorial/pointers/. Acesso em: 7 abr. 2026\.

### TUTORIALSPOINT. C Pointers. TutorialsPoint. Disponível em: https://www.tutorialspoint.com/cprogramming/c\_pointers.htm. Acesso em: 6 abr. 2026\.

### PROGRAMIZ. C Pointers. Programiz. Disponível em: https://www.programiz.com/c-programming/c-pointers. Acesso em: 8 abr. 2026\.
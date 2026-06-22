# **ATIVIDADE AVALIATIVA 3**

| Período de entrega | 22/jun a 30/jun |
| :---- | :---- |
| Número de integrantes | 1 a 2 |
| Tema | Implementar árvore que armazene um cadastro de alunos |
| Linguagens | C++ |
| Metodologia ativa | Aprendizagem ativa baseada em problema |
| Entrega | Apresentação ao professor |
| Valor | 1,0 ponto |

### **Atividade Prática: Sistema de Cadastro de Alunos Utilizando Estruturas de Árvores**

**Objetivo:**  
 Desenvolver um sistema simplificado de cadastro de alunos utilizando uma estrutura de dados baseada em árvores (**Árvore Binária de Busca, Árvore AVL ou Árvore Rubro-Negra**), aplicando os conceitos de inserção, busca e percurso em árvores.

---

### **Enunciado**

Uma instituição de ensino deseja armazenar os dados de seus alunos de forma eficiente, permitindo consultas rápidas e a geração de listagens em ordem alfabética.

Para isso, implemente um sistema de cadastro de alunos utilizando uma estrutura de árvore (Árvore Binária de Busca, AVL ou Rubro-Negra). Cada aluno deverá possuir, no mínimo, os seguintes atributos:

* Número de matrícula (inteiro);  
* Nome completo;  
* Curso.

O sistema deverá utilizar o **nome do aluno como chave de ordenação** da árvore.

---

### **Funcionalidades Obrigatórias**

1. **Inserir aluno**  
   * Cadastrar um novo aluno na árvore.  
2. **Buscar aluno**  
   * Localizar um aluno a partir do seu nome.  
3. **Exibir todos os alunos em ordem alfabética**  
   * Implementar um percurso adequado na árvore para apresentar os alunos em ordem crescente de nome.  
4. **Exibir informações da árvore**  
   * Quantidade total de alunos cadastrados.  
   * Altura da árvore.

---

### **Requisitos Técnicos**

* Utilizar uma das seguintes estruturas:  
  * Árvore Binária de Busca (ABB);  
  * Árvore AVL;  
  * Árvore Rubro-Negra.  
* Implementar a estrutura de nó e as operações necessárias de acordo com a árvore escolhida.  
* A listagem alfabética dos alunos deve ser obtida por meio de um percurso na árvore, sem utilizar métodos prontos de ordenação de listas ou vetores.  
* O código deve estar devidamente comentado.

**Exemplo de entrada**

| Matrícula | Nome | Curso |
| ----- | ----- | ----- |
| **101** | **John Smith** | **Engenharia de Software** |
| **102** | **Alice Johnson** | **Sistemas de Informação** |
| **103** | **Michael Brown** | **Ciência da Computação** |
| **104** | **Emily Davis** | **Engenharia de Software** |

### **Exemplo de Saída (Ordem Alfabética)**

Alice Johnson \- Matrícula: 102 \- Curso: Sistemas de Informação

Emily Davis \- Matrícula: 104 \- Curso: Engenharia de Software

John Smith \- Matrícula: 101 \- Curso: Engenharia de Software

Michael Brown \- Matrícula: 103 \- Curso: Ciência da Computação

---

### **Entrega**

O trabalho deverá conter:

1. Código-fonte completo.  
2. Relatório curto (1 a 2 páginas) descrevendo:  
   * A estrutura de árvore escolhida;  
   * As operações implementadas;  
3. Versionamento no Github


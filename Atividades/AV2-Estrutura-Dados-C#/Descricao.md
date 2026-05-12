# UNIVERSIDADE TECNOLÓGICA FEDERAL DO PARANÁ  
**Curso: Tecnologia em Análise e Desenvolvimento de Sistemas**  
**Disciplina: Estrutura de Dados – 2026/01**  
Professor: Clayton Kossoski | claytonkossoski@utfpr.edu.br  

---

# ATIVIDADE AVALIATIVA 2
| **Período de atividade** | 11/05 a 18/05 |
|------------------------|---------------|
| **Número de integrantes** | Entre 4 a 5 |
| **Tema** | Estrutura de dados em outra linguagem |
| **Linguagem** | C# |
| **Metodologia Ativa** | Baseada em projetos |
| **Entrega** | Apresentação em sala e Código fonte no repositório no github |
| **Valor** | 1,0 pontos |

---

# EQUIPE

| **Nome** | **RA** |
|------------------------|---------------|
| Carlos Fernando Dos Santos | 1692984 |
| Maria Carolyne Nogueira | 2706490  |
| Rayssa Da Silva Esparza Okamura | 2706547 |
| Fernando De Souza | 2623374 |

---

## 📌 Descrição da Atividade

Estrutura de dados em outras linguagens.
Estudar os conceitos fundamentais das linguagens de programação independentemente da tecnologia utilizada

Cada equipe deverá elaborar uma apresentação abordando os seguintes tópicos:
1. Configuração do ambiente de desenvolvimento necessário;
2. Sintaxe básica da linguagem;
3. Exemplo básico de utilização (ex: Hello World);
4. Exemplo de implementação de uma estrutura de dados do tipo pilha contendo métodos para - inserção, leitura, percorrimento, edição, e exclusão;
5. Compartilhamento do projeto funcional por meio de um repositório público no GitHub.

obs: Como pilha ainda não foi ensinado em sala de aula, devermos dar uma passagem pela teoria da mesma.

---

## 🧩 Estrutura do Projeto

```
├── 1 - configuracao-ambiente/
    └── Config.md
├── 2 - sintaxe-basica/
    └── Sintexe.md
├── 3 - exemplo-basico-hello-world/
    ├── exemplo-basico-hello-world.csproj
    └── Program.cs
├── 4 - exemplo-implementacao-pilha/
    ├── exemplo-implementacao-pilha.csproj
    ├── Aluno.cs
    ├── Pilha.cs
    └── Program.cs
├── Extra - exemplo-estrutura-pilha-c#/
    ├── Extra - exemplo-estrutura-pilha-c#.csproj
    └── Program.cs
└── Descricao.md
```

---

## 👋 Criação do Hello World

O exemplo Hello World foi criado dentro da pasta `3 - exemplo-basico-hello-world` (conteúdo em `3 - exemplo-basico-hello-world/hello-world.csproj`) usando o comando `dotnet new console`, que gera a estrutura inicial de um projeto de aplicação console em C#. Depois disso, o projeto é executado com `dotnet run`, e o código principal fica no arquivo `Program.cs`, onde é chamada a instrução `Console.WriteLine("Hello, World!")` para exibir a mensagem no terminal. Esse exemplo serve como uma introdução à estrutura básica de um programa em C# e mostra a execução inicial do projeto no ambiente .NET.

---

## 🔧 Compilação e Execução

Entre na pasta do projeto e execute com o SDK .NET:

```bash
cd "3 - exemplo-basico-hello-world"
dotnet build
dotnet run
```

---

**Data da entrega:** 18/05  
**Local:** Apresentação ao professor durante a aula
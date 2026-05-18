## Configuração do Ambiente C# (.NET)

Este documento explica de forma prática e direta, como preparar o ambiente para desenvolver e executar projetos C# com o SDK .NET no Windows e também no Ubuntu 24.04.

## Instruções para Windows

### 1) Instalar o .NET SDK
- Acesse: https://dotnet.microsoft.com/download
- Baixe o instalador do **.NET SDK** recomendado (ex.: .NET 10) e execute-o.
- Após a instalação, abra um terminal (PowerShell) e verifique:

```bash
dotnet --version
dotnet --info
```

Se retornar a versão e informações, o SDK está instalado corretamente.

### 2) Editor recomendado: Visual Studio Code
- Baixe e instale: https://code.visualstudio.com/
- Abra o VS Code e instale a extensão **C#** (publisher: Microsoft). Essa extensão provê IntelliSense, depuração e integração com OmniSharp.
- Ao abrir um projeto pela primeira vez, aceite a sugestão do VS Code para adicionar os assets de depuração (cria `launch.json` e `tasks.json`).

### 3) Criar e executar um projeto console exemplo
- No terminal execute:

```bash
dotnet new console -o MeuHelloWorld
cd MeuHelloWorld
dotnet run
```

Isso cria um projeto console com `Program.cs` e executa o aplicativo (saída do `Console.WriteLine`).

### 4) Comandos úteis
- Restaurar dependências: `dotnet restore`
- Compilar: `dotnet build`
- Executar: `dotnet run`
- Publicar (binário pronto): `dotnet publish -c Release -o ./out`

### 5) Depuração no VS Code
- Abra a pasta do projeto (`code .`).
- Configure breakpoints em `Program.cs` e pressione F5 para executar em modo debug.
- Se não existir, aceite a criação dos arquivos de configuração de execução/depuração.

### 6) Organização e boas práticas
- Separe exemplos em pastas (ex.: `3 - exemplo-basico-hello-world/`).
- Coloque classes em arquivos separados (`Pilha.cs`, `Program.cs`).
- Use `namespace` para evitar conflitos de nomes com tipos do BCL (por exemplo, `Stack<T>`).

### 7) Problemas comuns e soluções
- `dotnet: command not found` — verifique instalação e PATH; reinicie o terminal/sistema após instalação.
- CS8803 (top-level statements precisam preceder declarações de tipo) — não misture declarações de classes/namespaces com instruções top-level no mesmo arquivo; coloque código dentro de `static void Main()` ou remova declarações de tipo do arquivo.
- Conflito de nomes (ex.: `Stack<T>` vs `System.Collections.Generic.Stack<T>`) — use `namespace` ou renomeie sua classe (ex.: `Pilha<T>`).
- TargetFramework não encontrada — ajuste `<TargetFramework>` no `.csproj` ou instale a versão correspondente do SDK.

### 8) Exemplo rápido (passo a passo)

1. Abrir PowerShell e criar projeto:

```bash
dotnet new console -o exemplo-hello
cd exemplo-hello
code .
```

2. No VS Code, edite `Program.cs` e rode `dotnet run` no terminal integrado ou use F5.

3. Para adicionar outro exemplo (pilha) crie pasta separada e um `.csproj` próprio.



## Instruções para Ubuntu 24 (Ubuntu 24.04)

As etapas abaixo mostram como instalar o .NET SDK e o VS Code em Ubuntu 24.04. Você pode usar a mesma versão do Windows, por exemplo `dotnet-sdk-10.0`, se ela estiver disponível no repositório Microsoft.

### 1) Adicionar o repositório Microsoft e pré-requisitos

```bash
sudo apt update
sudo apt install -y wget ca-certificates apt-transport-https gnupg
wget https://packages.microsoft.com/config/ubuntu/24.04/packages-microsoft-prod.deb -O packages-microsoft-prod.deb
sudo dpkg -i packages-microsoft-prod.deb
sudo apt update
```

### 2) Instalar o .NET SDK

Verifique quais pacotes `dotnet-sdk-<versao>` estão disponíveis:

```bash
apt list -a 'dotnet-sdk-*'
```

Instale a mesma versão que você usa no Windows, quando ela estiver disponível (substitua `<versao>`):

```bash
sudo apt install -y dotnet-sdk-<versao>
# exemplo:
sudo apt install -y dotnet-sdk-10.0
```

Verifique a instalação:

```bash
dotnet --version
dotnet --info
```

### 3) Instalar VS Code (opção via snap)

```bash
sudo snap install --classic code
```

Abra o VS Code e instale a extensão **C#** (Microsoft).

### 4) Criar e executar projeto exemplo

```bash
dotnet new console -o MeuHelloWorld
cd MeuHelloWorld
dotnet run
```

### 5) Depuração e edição

- Use o VS Code para abrir a pasta do projeto (`code .`) e pressione F5 para depurar.

### 6) Problemas comuns no Linux

- Dependências nativas ausentes: instale as bibliotecas sugeridas na mensagem de erro (por exemplo `libssl` ou `libicu`). Um comando genérico:

```bash
sudo apt install -y libssl-dev libicu-dev
```

- `dotnet` não encontrado: confirme a instalação e reinicie o terminal; verifique `which dotnet`.

---

# Sintaxe Básica do C#

Esta seção apresenta, de forma simples, os elementos mais importantes da sintaxe básica da linguagem C#.

## 1. Estrutura inicial de um programa

Um programa em C# geralmente começa com a inclusão de bibliotecas e depois com a definição do ponto de entrada da aplicação. Em projetos simples, isso pode aparecer no arquivo `Program.cs`.

```csharp
using System;

class Program
{
	static void Main(string[] args)
	{
		Console.WriteLine("Olá, C#!");
	}
}
```

Neste exemplo:
- `using System;` permite usar classes do sistema, como `Console`.
- `class Program` define uma classe.
- `static void Main(string[] args)` é o ponto de entrada da aplicação.
- `Console.WriteLine(...)` escreve uma mensagem na tela.

## 2. Variáveis e tipos básicos

Variáveis servem para armazenar valores. Em C#, cada variável tem um tipo.

```csharp
int idade = 20;
double altura = 1.75;
char letra = 'A';
string nome = "Maria";
bool ativo = true;
```

Tipos comuns:
- `int` para números inteiros.
- `double` para números decimais.
- `char` para um único caractere.
- `string` para texto.
- `bool` para valores lógicos, `true` ou `false`.

## 3. Entrada e saída de dados

Para mostrar informações na tela, usa-se `Console.WriteLine`. Para ler dados digitados pelo usuário, usa-se `Console.ReadLine`.

```csharp
Console.Write("Digite seu nome: ");
string nome = Console.ReadLine();
Console.WriteLine("Olá, " + nome);
```

## 4. Operadores

Os operadores ajudam a fazer cálculos e comparações.

```csharp
int soma = 5 + 3;
int subtracao = 10 - 4;
int multiplicacao = 2 * 4;
int divisao = 8 / 2;

bool resultado = 10 > 5;
```

Operadores comuns:
- `+`, `-`, `*`, `/` para cálculos.
- `==`, `!=`, `>`, `<`, `>=`, `<=` para comparações.

## 5. Estruturas de decisão

As estruturas de decisão permitem escolher caminhos diferentes no programa.

```csharp
int nota = 7;

if (nota >= 6)
{
	Console.WriteLine("Aprovado");
}
else
{
	Console.WriteLine("Reprovado");
}
```

## 6. Laços de repetição

Os laços servem para repetir comandos várias vezes.

### `for`

```csharp
for (int i = 1; i <= 5; i++)
{
	Console.WriteLine(i);
}
```

### `while`

```csharp
int contador = 1;

while (contador <= 5)
{
	Console.WriteLine(contador);
	contador++;
}
```

## 7. Métodos

Métodos são blocos de código que realizam uma tarefa específica.

```csharp
static int Somar(int a, int b)
{
	return a + b;
}
```

Neste caso:
- `static` indica que o método pertence à classe.
- `int` é o tipo de retorno.
- `Somar` é o nome do método.
- `return` devolve o resultado.

## 8. Classes e objetos

C# é uma linguagem orientada a objetos. Uma classe funciona como um molde, e um objeto é uma instância dessa classe.

```csharp
class Pessoa
{
	public string Nome { get; set; }
	public int Idade { get; set; }
}

Pessoa pessoa = new Pessoa();
pessoa.Nome = "Ana";
pessoa.Idade = 21;
```

## 9. Exemplo completo

```csharp
using System;

class Program
{
	static void Main(string[] args)
	{
		Console.Write("Digite seu nome: ");
		string nome = Console.ReadLine();

		Console.Write("Digite sua idade: ");
		int idade = int.Parse(Console.ReadLine());

		Console.WriteLine($"Olá, {nome}. Você tem {idade} anos.");
	}
}
```

## 10. Resumo

Os pontos mais importantes da sintaxe básica de C# são:
- uso de `using` para importar bibliotecas;
- declaração de variáveis com tipos;
- entrada e saída com `Console`;
- uso de `if`, `for` e `while`;
- criação de métodos, classes e objetos.

Com esses elementos, já é possível criar programas simples e começar a praticar a linguagem.

---

# Apresentação: Pilhas

## Objetivo da aula

Entender o conceito de **pilha** usando o conhecimento já visto sobre **lista estática** e **lista dinâmica**.

Ao final, a turma deve conseguir responder:

- O que é uma pilha;
- Como ela funciona;
- Quais operações básicas ela oferece;
- Qual a diferença entre pilha, lista estática e lista dinâmica;
- Em que situações uma pilha é uma boa escolha.

## 1. Começando pela ideia mais simples

Imagine uma pilha de livros, pratos ou caixas.

- Você coloca um novo item sempre no topo;
- Você retira primeiro o item que está no topo;
- Não faz sentido pegar o item do meio sem tirar os de cima antes.

Essa é a essência da pilha em programação.

## 2. O que é uma pilha?

Uma **pilha** é uma estrutura de dados em que o último elemento que entra é o primeiro que sai.

Isso é chamado de **LIFO**:

- **L**ast
- **I**n
- **F**irst
- **O**ut

Em português, significa: **o último a entrar é o primeiro a sair**.

## 3. Onde a pilha aparece na prática?

Você já usa pilhas em várias situações:

- Histórico de navegação do navegador;
- Botão desfazer em editores de texto;
- Chamadas de funções na programação;
- Verificação de expressões matemáticas;
- Voltar etapas em um sistema.

## 4. Comparando com lista estática e lista dinâmica

Se a turma já conhece listas, a comparação ajuda bastante.

### Lista estática

- Tem tamanho fixo;
- Os elementos ficam em posições definidas no vetor;
- Pode haver limite máximo de armazenamento.

### Lista dinâmica

- Pode crescer e diminuir durante a execução;
- Não depende de um tamanho fixo pré-definido;
- Usa nós ligados por ponteiros ou referências.

### Pilha

- Também guarda vários elementos;
- Mas restringe o acesso apenas ao topo;
- Não permite manipular livremente qualquer posição como numa lista comum.

## 5. A diferença principal

Em uma lista, normalmente podemos acessar um elemento do meio, da frente ou do fim, dependendo da implementação.

Em uma pilha, o acesso é controlado:

- Só o topo pode receber novos elementos;
- Só o topo pode ser removido;
- Os demais ficam “guardados” abaixo dele.

Isso deixa a estrutura mais simples para problemas em que a ordem de saída importa.

## 6. Operações básicas da pilha

As operações mais importantes são:

### `push` ou empilhar

Insere um elemento no topo da pilha.

Exemplo:

- Pilha vazia
- Push 10
- Push 20
- Push 30

Topo atual: `30`

### `pop` ou desempilhar

Remove o elemento que está no topo.

Exemplo:

- Pilha: 10, 20, 30
- Pop
- Sai o `30`

### `peek` ou `top`

Mostra o elemento do topo sem removê-lo.

Exemplo:

- Pilha: 10, 20, 30
- Peek
- Retorna `30`

### `isEmpty`

Verifica se a pilha está vazia.

### `isFull`

Usada principalmente na pilha implementada com lista estática.

## 7. Exemplo visual

Considere a sequência:

1. Empilhar A
2. Empilhar B
3. Empilhar C

Representação:

```text
Topo -> C
	B
	A
```

Se removermos um elemento:

```text
Topo -> B
	A
```

O último que entrou foi o `C`, então ele sai primeiro.

## 8. Por que a pilha é útil?

A pilha é útil quando o problema precisa respeitar a ordem inversa de inserção.

Ela ajuda porque:

- Organiza o acesso de forma simples;
- Facilita o controle de chamadas e retornos;
- Evita manipulações desnecessárias no meio da estrutura;
- Resolve problemas com histórico e retorno.

## 9. Pilha com lista estática

Se a pilha for implementada com uma lista estática, normalmente usamos um vetor.

Ideia:

- Existe uma posição que representa o topo;
- Inserir é colocar no próximo espaço livre;
- Remover é voltar uma posição no topo.

Vantagens:

- Simples de implementar;
- Acesso rápido ao topo.

Limitações:

- Tamanho máximo definido;
- Se encher, não aceita novos elementos.

## 10. Pilha com lista dinâmica

Se a pilha for implementada com lista dinâmica, cada novo elemento pode ser criado quando necessário.

Ideia:

- Cada elemento aponta para o próximo;
- O topo aponta para o último elemento inserido;
- Ao remover, o topo passa a apontar para o próximo nó.

Vantagens:

- Cresce conforme a necessidade;
- Não depende de tamanho fixo.

Limitações:

- Usa mais estrutura interna;
- Exige mais cuidado com referências e memória.

## 11. Resumo comparativo

| Estrutura | Acesso | Crescimento | Melhor uso |
| --- | --- | --- | --- |
| Lista estática | Acesso por índice | Limitado | Quando o tamanho é conhecido |
| Lista dinâmica | Mais flexível | Cresce durante a execução | Quando o tamanho pode variar |
| Pilha | Apenas no topo | Depende da implementação | Quando o último a entrar deve sair primeiro |

## 12. Exemplo do dia a dia

Pense em uma pilha de bandejas em uma lanchonete:

- A próxima bandeja colocada vai para o topo;
- A bandeja retirada também sai do topo;
- Ninguém pega a bandeja de baixo sem reorganizar tudo.

Esse comportamento é exatamente o que queremos modelar.

## 13. Erros comuns

- Confundir pilha com fila;
- Tentar acessar elementos do meio diretamente;
- Esquecer de verificar se a pilha está vazia antes de remover;
- Esquecer o limite de uma pilha baseada em lista estática.

## 14. Ideia principal para guardar

A pilha é uma estrutura simples e muito útil quando a ordem importa.

Ela funciona com a regra:

**último que entra, primeiro que sai**.

## 15. Encerramento

Depois de entender listas estáticas e dinâmicas, a pilha fica fácil de visualizar:

- Ela é uma coleção de elementos;
- O acesso é restrito ao topo;
- Suas operações básicas são inserir, remover e consultar o topo.

---
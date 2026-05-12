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

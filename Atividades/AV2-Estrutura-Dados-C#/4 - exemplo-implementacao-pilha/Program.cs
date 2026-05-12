using System;
using System.Collections.Generic;

// =====================
// Definição de Aluno
// =====================
// Estrutura que representa os dados armazenados na pilha
class Aluno
{
	public int Matricula { get; set; }
	public string Nome { get; set; }
	public double N1 { get; set; }
	public double N2 { get; set; }
	public double N3 { get; set; }

	public override string ToString()
	{
		return $"Matrícula: {Matricula}\nNome: {Nome}\nNotas: {N1} {N2} {N3}";
	}
}

// =====================
// Definição da Pilha
// =====================
// Classe genérica que implementa uma pilha (Stack)
// com operações de inserção, remoção, leitura e edição
class Pilha<T>
{
	private List<T> elementos = new List<T>();

	// Retorna o número de elementos na pilha
	public int Tamanho()
	{
		return elementos.Count;
	}

	// Verifica se a pilha está vazia
	public bool EstaVazia()
	{
		return elementos.Count == 0;
	}

    // Insere um elemento no topo da pilha
	public void Push(T item)
	{
		elementos.Add(item);
		Console.WriteLine($"✓ Elemento inserido. Tamanho: {elementos.Count}");
	}

    // Remove e retorna o elemento do topo
	public T Pop()
	{
		if (EstaVazia())
		{
			Console.WriteLine("✗ Erro: pilha vazia!");
			return default(T);
		}

		T item = elementos[elementos.Count - 1];
		elementos.RemoveAt(elementos.Count - 1);
		Console.WriteLine($"✓ Elemento removido. Tamanho: {elementos.Count}");
		return item;
	}

    // Retorna o elemento do topo sem remover
	public T Peek()
	{
		if (EstaVazia())
		{
			Console.WriteLine("✗ Erro: pilha vazia!");
			return default(T);
		}

		return elementos[elementos.Count - 1];
	}

    // Percorre e exibe todos os elementos (do topo para a base)
	public void Exibir()
	{
		if (EstaVazia())
		{
			Console.WriteLine("Pilha vazia.");
			return;
		}

		Console.WriteLine("\n--- Conteúdo da Pilha (topo → base) ---");
		for (int i = elementos.Count - 1; i >= 0; i--)
		{
			Console.WriteLine(elementos[i]);
			Console.WriteLine("---");
		}
	}

    // Edita um elemento baseado em uma condição (exemplo: busca por matrícula)
	public void Editar(Func<T, bool> condicao, Action<T> atualizacao)
	{
		for (int i = 0; i < elementos.Count; i++)
		{
			if (condicao(elementos[i]))
			{
				atualizacao(elementos[i]);
				Console.WriteLine("✓ Elemento atualizado.");
				return;
			}
		}
		Console.WriteLine("✗ Elemento não encontrado.");
	}

    // Remove um elemento específico (simulando remoção de meio, típica de lista)
	public bool RemoverEspecifico(Func<T, bool> condicao)
	{
		for (int i = 0; i < elementos.Count; i++)
		{
			if (condicao(elementos[i]))
			{
				elementos.RemoveAt(i);
				Console.WriteLine($"✓ Elemento removido. Tamanho: {elementos.Count}");
				return true;
			}
		}
		Console.WriteLine("✗ Elemento não encontrado.");
		return false;
	}

    // Limpa toda a pilha
	public void Limpar()
	{
		elementos.Clear();
		Console.WriteLine("✓ Pilha limpa.");
	}
}

// =====================
// Programa Principal
// =====================
class Program
{
	static void Main(string[] args)
	{
		Console.WriteLine("=== Exemplo de Implementação de Pilha em C# ===\n");

		// Criação da pilha de alunos
		Pilha<Aluno> pilha = new Pilha<Aluno>();

		// Dados de entrada
		Aluno[] alunos = {
			new Aluno { Matricula = 2, Nome = "André", N1 = 9.5, N2 = 7.8, N3 = 8.5 },
			new Aluno { Matricula = 4, Nome = "Ricardo", N1 = 7.5, N2 = 8.7, N3 = 6.8 },
			new Aluno { Matricula = 1, Nome = "Bianca", N1 = 9.7, N2 = 6.7, N3 = 8.4 },
			new Aluno { Matricula = 3, Nome = "Ana", N1 = 5.7, N2 = 6.1, N3 = 7.4 }
		};

        // =====================
		// 1. Inserção (Push)
		// =====================
		Console.WriteLine("1. INSERÇÃO (Push)");
		Console.WriteLine("==================");
		for (int i = 0; i < alunos.Length; i++)
		{
			pilha.Push(alunos[i]);
		}

        // =====================
		// 2. Percorrimento (Exibir)
		// =====================
		Console.WriteLine("\n2. PERCORRIMENTO (Exibir)");
		Console.WriteLine("==========================");
		pilha.Exibir();
		Console.WriteLine($"Tamanho da pilha: {pilha.Tamanho()}");
	}
}

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
}


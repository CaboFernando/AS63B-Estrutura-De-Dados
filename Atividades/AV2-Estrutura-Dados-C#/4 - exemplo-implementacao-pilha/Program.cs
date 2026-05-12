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
}


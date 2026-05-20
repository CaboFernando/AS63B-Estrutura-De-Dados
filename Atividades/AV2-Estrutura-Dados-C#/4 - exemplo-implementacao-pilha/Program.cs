namespace ExemploPilha;

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
		pilha.Show();
		Console.WriteLine($"Tamanho da pilha: {pilha.Tamanho()}");

        // =====================
		// 3. Leitura (Peek)
		// =====================
		Console.WriteLine("\n3. LEITURA (Peek - topo)");
		Console.WriteLine("=========================");
		Aluno topo = pilha.Peek();
		if (topo != null)
			Console.WriteLine($"Topo: {topo.Nome} (Matrícula: {topo.Matricula})");

		// =====================
		// 4. Remoção (Pop)
		// =====================
		Console.WriteLine("\n5. REMOÇÃO (Pop - topo)");
		Console.WriteLine("=========================");
		Aluno removido = pilha.Pop();
		if (removido != null)
			Console.WriteLine($"Removido: {removido.Nome}");

		// =====================
		// 5. Estado final
		// =====================
		Console.WriteLine("\n7. ESTADO FINAL");
		Console.WriteLine("================");
		pilha.Show();
		Console.WriteLine($"Tamanho da pilha: {pilha.Tamanho()}");
        
        // =====================
		// 6. Removendo toda a pilha (Clear)
		// =====================
		Console.WriteLine("\n8. REMOVENDO TODA A PILHA (Clear)");
		Console.WriteLine("===========================================");
		pilha.Clear();
		Console.WriteLine("\n✓ Fim do programa.");
	}
}

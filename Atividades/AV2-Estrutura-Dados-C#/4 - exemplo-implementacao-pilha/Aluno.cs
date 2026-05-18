namespace ExemploPilha;

// =====================
// Definição de Aluno
// =====================
// Estrutura que representa os dados armazenados na pilha
class Aluno
{
	public int Matricula { get; set; }
	public string? Nome { get; set; }
	public double N1 { get; set; }
	public double N2 { get; set; }
	public double N3 { get; set; }

	public override string ToString()
	{
		return $"Matrícula: {Matricula}\nNome: {Nome}\nNotas: {N1} {N2} {N3}";
	}
}
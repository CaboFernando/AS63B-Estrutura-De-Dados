namespace ExemploPilha;

// =====================
// Definição da Pilha
// =====================
// Classe genérica que implementa uma pilha (Stack)
// com operações de inserção, remoção, leitura e edição
class Pilha<T>
{
    private Aluno[] elementos;      // Array para armazenar os elementos
    private int topo;            // Índice do topo da pilha
    private const int CAPACIDADE_PADRAO = 100;  // Capacidade inicial

    // Construtor com capacidade opcional
    public Pilha(int capacidade = CAPACIDADE_PADRAO)
    {
        elementos = new Aluno[capacidade];
        topo = -1;  // Pilha vazia
    }

    // Retorna o número de elementos na pilha
    public int Tamanho()
    {
        return topo + 1;
    }

    // Verifica se a pilha está vazia
    public bool IsEmpty()
    {
        return topo == -1;
    }

    // Verifica se a pilha está cheia
    private bool IsNotEmpty()
    {
        return topo == elementos.Length - 1;
    }

    // Insere um elemento no topo da pilha
    public void Push(Aluno item)
    {
        if (IsNotEmpty())
        {
            Console.WriteLine("✗ Erro: pilha cheia! Capacidade máxima atingida.");
            return;
        }
        
        elementos[++topo] = item;
        Console.WriteLine($"✓ Elemento inserido. Tamanho: {Tamanho()}");
    }

    // Remove e retorna o elemento do topo
    public Aluno Pop()
    {
        if (IsEmpty())
        {
            Console.WriteLine("✗ Erro: pilha vazia!");
            return default!;
        }

        Aluno item = elementos[topo];
        elementos[topo--] = default!;  // Libera referência para o GC
        Console.WriteLine($"✓ Elemento removido. Tamanho: {Tamanho()}");
        return item;
    }

    // Retorna o elemento do topo sem remover
    public Aluno Peek()
    {
        if (IsEmpty())
        {
            Console.WriteLine("✗ Erro: pilha vazia!");
            return default!;
        }

        return elementos[topo];
    }

    // Percorre e exibe todos os elementos (do topo para a base)
    public void Show()
    {
        if (IsEmpty())
        {
            Console.WriteLine("Pilha vazia.");
            return;
        }

        Console.WriteLine("\n--- Conteúdo da Pilha (topo → base) ---");
        for (int i = topo; i >= 0; i--)
        {
            Console.WriteLine(elementos[i].Get());
            Console.WriteLine("---");
        }
    }

    // Limpa toda a pilha
    public void Clear()
    {
        // Limpa as referências para o GC
        for (int i = 0; i <= topo; i++)
        {
            elementos[i] = default!;
        }
        topo = -1;
        Console.WriteLine("✓ Pilha limpa.");
    }
}
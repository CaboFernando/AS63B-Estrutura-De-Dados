namespace ExemploPilha;

// =====================
// Definição da Pilha
// =====================
// Classe genérica que implementa uma pilha (Stack)
// com operações de inserção, remoção, leitura e edição
class Pilha<T>
{
    private T[] elementos;      // Array para armazenar os elementos
    private int topo;            // Índice do topo da pilha
    private const int CAPACIDADE_PADRAO = 100;  // Capacidade inicial

    // Construtor com capacidade opcional
    public Pilha(int capacidade = CAPACIDADE_PADRAO)
    {
        elementos = new T[capacidade];
        topo = -1;  // Pilha vazia
    }

    // Retorna o número de elementos na pilha
    public int Tamanho()
    {
        return topo + 1;
    }

    // Verifica se a pilha está vazia
    public bool EstaVazia()
    {
        return topo == -1;
    }

    // Verifica se a pilha está cheia
    private bool EstaCheia()
    {
        return topo == elementos.Length - 1;
    }

    // Insere um elemento no topo da pilha
    public void Push(T item)
    {
        if (EstaCheia())
        {
            Console.WriteLine("✗ Erro: pilha cheia! Capacidade máxima atingida.");
            return;
        }
        
        elementos[++topo] = item;
        Console.WriteLine($"✓ Elemento inserido. Tamanho: {Tamanho()}");
    }

    // Remove e retorna o elemento do topo
    public T Pop()
    {
        if (EstaVazia())
        {
            Console.WriteLine("✗ Erro: pilha vazia!");
            return default(T);
        }

        T item = elementos[topo];
        elementos[topo--] = default(T);  // Libera referência para o GC
        Console.WriteLine($"✓ Elemento removido. Tamanho: {Tamanho()}");
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

        return elementos[topo];
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
        for (int i = topo; i >= 0; i--)
        {
            Console.WriteLine(elementos[i]);
            Console.WriteLine("---");
        }
    }

    // Edita um elemento baseado em uma condição (exemplo: busca por matrícula)
    // NOTA: Esta operação não é típica de pilha, mas foi implementada para atender ao enunciado
    public void Editar(Func<T, bool> condicao, Action<T> atualizacao)  // -> VALIDAR COM PROFESSOR SE DEVE IMPLEMENTAR (não é típico de pilha, mas pode ser feito)
    {
        for (int i = 0; i <= topo; i++)
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
    // NOTA: Esta operação NÃO é típica de pilha (viola o princípio LIFO).
    // Foi implementada apenas para atender ao enunciado que pedia "exclusão" genérica.
    // Em uma pilha real, a remoção deve ser sempre do topo (método Pop).
    public bool RemoverEspecifico(Func<T, bool> condicao) // -> VALIDAR COM PROFESSOR SE DEVE IMPLEMENTAR (não é típico de pilha, mas pode ser feito)
    {
        for (int i = 0; i <= topo; i++)
        {
            if (condicao(elementos[i]))
            {
                // Remove o elemento e desloca os demais
                for (int j = i; j < topo; j++)
                {
                    elementos[j] = elementos[j + 1];
                }
                elementos[topo--] = default(T);  // Libera referência
                Console.WriteLine($"✓ Elemento removido. Tamanho: {Tamanho()}");
                return true;
            }
        }
        Console.WriteLine("✗ Elemento não encontrado.");
        return false;
    }

    // Limpa toda a pilha
    public void Limpar()
    {
        // Limpa as referências para o GC
        for (int i = 0; i <= topo; i++)
        {
            elementos[i] = default(T);
        }
        topo = -1;
        Console.WriteLine("✓ Pilha limpa.");
    }
}
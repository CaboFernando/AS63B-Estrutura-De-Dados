using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        // Criando uma pilha de strings
        Stack<string> pilha = new Stack<string>();

        // Adicionando elementos (Push)
        pilha.Push("Primeiro");
        pilha.Push("Segundo");
        pilha.Push("Terceiro"); // Último a entrar

        Console.WriteLine($"Topo: {pilha.Peek()}"); // Saída: Terceiro

        // Removendo elementos (Pop)
        Console.WriteLine(pilha.Pop()); // Saída: Terceiro
        Console.WriteLine(pilha.Pop()); // Saída: Segundo
    }
}

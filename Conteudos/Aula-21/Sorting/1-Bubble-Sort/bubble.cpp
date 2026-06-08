/*
Como funciona

Percorre o vetor repetidamente comparando pares adjacentes e trocando-os se estiverem fora de ordem. 
Em cada passagem completa, o maior elemento "borbulha" para a posição final correta.

Simples de implementar, mas ineficiente para grandes conjuntos. Útil para fins didáticos e para 
vetores quase ordenados, onde sua versão otimizada atinge O(n).

Melhor: Ω(n) 
Médio: Θ(n²) 
Pior: O(n²) 
Espaço: O(1)
*/

// Bubble Sort — Prof. Clayton Kossoski / UTFPR
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;  // otimização
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // já ordenado
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    for (int x : arr) cout << x << " ";
    // Saída: 11 12 22 25 34 64
    return 0;
}

/*
Rastreamento — vetor [64, 34, 25, 12]
[64, 34, 25, 12]
→
[34, 64, 25, 12]
→
[34, 25, 64, 12]
→
[34, 25, 12, 64]
→ ... →
[12, 25, 34, 64]

*/
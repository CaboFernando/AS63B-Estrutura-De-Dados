/*
Como funciona

Divide o vetor em dois subconjuntos: ordenado (à esquerda) e não-ordenado (à direita). 
A cada iteração, encontra o menor elemento da parte não-ordenada e o move para a fronteira.

Realiza exatamente n−1 trocas, o que o torna interessante quando operações de escrita são custosas. 
Não é estável na forma padrão.

Melhor: Ω(n²) 
Médio: Θ(n²) 
Pior: O(n²) 
Espaço: O(1) 
*/

// Selection Sort — Prof. Clayton Kossoski / UTFPR
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (minIdx != i)
            swap(arr[minIdx], arr[i]);
    }
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    for (int x : arr) cout << x << " ";
    // Saída: 10 13 14 29 37
    return 0;
}

/*
Rastreamento — vetor [29, 10, 14, 37, 13]
[10, 29, 14, 37, 13]
→
[10, 13, 14, 37, 29]
→
[10, 13, 14, 37, 29]
→
[10, 13, 14, 29, 37]

*/
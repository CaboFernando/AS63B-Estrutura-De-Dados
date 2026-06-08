/*
Como funciona

Constrói o vetor ordenado um elemento por vez. Pega cada novo elemento e o insere na posição correta 
dentro da porção já ordenada, deslocando os maiores para a direita.

Excelente para dados quase ordenados (O(n) no melhor caso) e para vetores pequenos. É o algoritmo 
preferido como base recursiva do Timsort (usado em Python e Java).

Melhor: Ω(n) 
Médio: Θ(n²) 
Pior: O(n²) 
Espaço: O(1) 
*/

// Insertion Sort — Prof. Clayton Kossoski / UTFPR
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j   = i - 1;
        // desloca elementos maiores que key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // insere na posição correta
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    for (int x : arr) cout << x << " ";
    // Saída: 5 6 11 12 13
    return 0;
}

/*
Rastreamento — vetor [12, 11, 13, 5]
[11, 12, 13, 5]
→
[11, 12, 13, 5]
→
[5, 11, 12, 13]

*/
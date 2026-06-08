/*
Como funciona

Constrói um max-heap a partir do vetor. O maior elemento (raiz) é trocado com o último, o heap é 
reduzido em 1 e restaurado (heapify). O processo se repete até o vetor estar ordenado.

Combina o melhor do Selection Sort (in-place, O(1) extra) com a eficiência O(n log n) do Merge Sort 
em todos os casos. Ideal quando memória é crítica e pior caso deve ser controlado.

Melhor: Ω(n log n) 
Médio: Θ(n log n) 
Pior: O(n log n) 
Espaço: O(1) 
*/

// Heap Sort — Prof. Clayton Kossoski / UTFPR
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // 1. Construir max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // 2. Extrair raiz repetidamente
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    for (int x : arr) cout << x << " ";
    // Saída: 5 6 7 11 12 13
    return 0;
}

/*
Max-Heap construído de [12, 11, 13, 5, 6, 7]
Max-Heap: [13, 11, 12, 5, 6, 7] → swap raiz → [7, 11, 12, 5, 6, 13] → heapify → [12, 11, 7, 5, 6, 13] → ... → [5, 6, 7, 11, 12, 13] 
*/
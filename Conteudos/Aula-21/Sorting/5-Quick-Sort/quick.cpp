/*
Como funciona

Escolhe um elemento pivô e particiona o vetor de modo que todos os menores fiquem à esquerda e os 
maiores à direita. Aplica o processo recursivamente nas duas metades.

Na prática é o algoritmo de ordenação mais rápido para dados em memória. A escolha inteligente do 
pivô (mediana de 3, aleatório) evita o pior caso O(n²). Usado na std::sort do C++.

Melhor: Ω(n log n) 
Médio: Θ(n log n) 
Pior: O(n²) 
Espaço: O(log n) 
*/

// Quick Sort — Prof. Clayton Kossoski / UTFPR
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // último como pivô
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for (int x : arr) cout << x << " ";
    // Saída: 1 5 7 8 9 10
    return 0;
}

/*
Partição com pivô = 5 — [10, 7, 8, 9, 1, 5]
[10, 7, 8, 9, 1, 5] → particiona → [1, 5, 8, 9, 7, 10] → recursão → [1] [7, 8, 9, 10] → final → [1, 5, 7, 8, 9, 10] 
*/
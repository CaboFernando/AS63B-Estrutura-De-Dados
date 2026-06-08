/*
Como funciona

Usa a estratégia dividir e conquistar: divide o vetor ao meio recursivamente até ter subvetores de 
tamanho 1 (trivialmente ordenados), depois intercala (merge) os pares de subvetores já ordenados.

Garantia de O(n log n) em todos os casos. Preferido para ordenação de listas encadeadas e arquivos 
externos. O custo é o espaço auxiliar O(n).

Melhor: Ω(n log n) 
Médio: Θ(n log n) 
Pior: O(n log n) 
Espaço: O(n) 
*/

// Merge Sort — Prof. Clayton Kossoski / UTFPR
#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    for (int x : arr) cout << x << " ";
    // Saída: 3 9 27 38 43
    return 0;
}

/*
Divisão recursiva — [38, 27, 43, 3]
[38, 27, 43, 3] ÷ [38, 27] [43, 3] ÷ [38][27] [43][3] merge → [27,38] [3,43] merge → [3,27,38,43] 
*/
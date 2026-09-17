#include "../../include/algoritmos/selection_sort.hpp"

void selectionSort(int* vetor, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int menor = i; // guarda o menor elemento

        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[menor]) { // avança vetor procurando um elemento menor
                menor = j; // quando encontrar, marca ele
            }
        }

        // coloca o menor elemento na posição correta
        int temp = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = temp;
    }
}
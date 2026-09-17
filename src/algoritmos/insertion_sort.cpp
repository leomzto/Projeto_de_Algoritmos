#include "../../include/algoritmos/insertion_sort.hpp"

void insertionSort(int* vetor, int tamanho) {
    for (int i = 1; i < tamanho; i++) {

        int chave = vetor[i];
        int j = i - 1; // elemento anterior

        // enquanto ainda esta no raio do vetor e o elemento anterior for maior que a chave
        while (j >= 0 && vetor[j] > chave) {
            // copia o maior para uma pos. a direita
            vetor[j + 1] = vetor[j];
            j--; // volta um elemento
        }

        // posicao para reinserir a chave
        vetor[j + 1] = chave;
    }
}
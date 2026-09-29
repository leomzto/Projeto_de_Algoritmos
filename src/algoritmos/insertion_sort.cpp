#include "../../include/algoritmos/insertion_sort.hpp"

void insertionSort(int* vetor, int tamanho) {
    for (int i = 1; i < tamanho; i++) { // começa em i = 1 pois ja considera o primeiro ordenado

        int chave = vetor[i]; // chave (elemento da compraçao)
        int j = i - 1; // elemento anterior

        // enquanto ainda esta no raio do vetor e o elemento anterior for maior que a chave
        while (j >= 0 && vetor[j] > chave) {
            // desloca o maior para uma pos. a direita
            vetor[j + 1] = vetor[j];
            j--; // volta um elemento
        }

        // insere a chave na pos. correta
        vetor[j + 1] = chave;
    }
}
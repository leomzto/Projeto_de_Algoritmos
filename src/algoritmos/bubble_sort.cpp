#include "../../include/algoritmos/bubble_sort.hpp"

void bubbleSort(int* vetor, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) { // tamanho -1 : considera o ultimo ja ordenado
        bool trocou = false;

        for (int j = 0; j < tamanho - i - 1; j++) { // tamanho - i - 1 : reduz comparaçoes porque  final do vetor ja esta ordenado
            // verifica se o atual é maior ou nao, ou seja, se esta na pos correta
            if (vetor[j] > vetor[j + 1]) {
                // troca os valores de posiçoes
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                trocou = true; // marca como trocado
            }
        }
        if (!trocou)
            break; // se nao houve trocas, o vetor ja esta ordenado
    }
}
#include "../../include/algoritmos/shell_sort.hpp"

void shellSort(int* vetor, int tamanho, int divisor) { //divisor padrao = 2, definido no .hpp

    for (int gap = tamanho / divisor; gap > 0; gap /= divisor) { //começa com um gap igual ao tamanho / divisor e o reduz pelo divisor cada passo

        for (int i = gap; i < tamanho; i++) { //percorre os elementos a partir do intervalo

            int temp = vetor[i]; //guarda o elemento a ser inserido na pos. correta

            int j = i; //começa na pos. atual

            while (j >= gap && vetor[j - gap] > temp) { //compara com o elemento que está atras (gap vezes)

                vetor[j] = vetor[j - gap]; //desloca o elemento maior para a direita
                j -= gap; // Volta posicoes (gap vezes)
            }

            vetor[j] = temp; //insere temp na pos. correta.
        }
    }
}
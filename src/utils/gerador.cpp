#include "utils/gerador.hpp"
#include <cstdlib>
#include <string>

using namespace std;

int* gerarCrescente(int tamanho) {

    int* vetor = new int[tamanho];

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i + 1;
    }

    return vetor;
}

int* gerarDecrescente(int tamanho) {

    int* vetor = new int[tamanho];

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }

    return vetor;
}

int* gerarRandomico(int tamanho) {

    int* vetor = new int[tamanho];

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand();
    }

    return vetor;
}

int* gerarInstancia(int tipo, int tamanho) {
    switch (tipo) {
        case 1:
            return gerarCrescente(tamanho);
        case 2:
            return gerarDecrescente(tamanho);
        case 3:
            return gerarRandomico(tamanho);
        default:
            return nullptr;
    }
}

string obterNomeInstancia(int tipo) {
    switch (tipo) {
        case 1:
            return "Crescente";
        case 2:
            return "Decrescente";
        case 3:
            return "Randomico";
        default:
            return "null";
    }
}
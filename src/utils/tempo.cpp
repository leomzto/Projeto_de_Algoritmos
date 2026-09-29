#include "utils/tempo.hpp"
#include <chrono>

using namespace std;

// function<void(int*, int)> algoritmo : função que recebe um vetor e seu tamanho
double calcularTempo(void (*algoritmo)(int*, int), int* vetor, int tamanho) {
    // salvar tempo do inicio
    auto inicio = chrono::steady_clock::now();

    // executar o algoritmo
    algoritmo(vetor, tamanho);

    // salvar tempo do fim da execuçao
    auto fim = chrono::steady_clock::now();

    // calcular duração em segundos
   chrono::duration<double> tempo = fim - inicio;

    return tempo.count(); // retorna o valor numerico do duration<double>
}

#include "utils/tempo.hpp"
#include <chrono>
#include <filesystem>

using namespace std;

// (*algoritimo) -> ponteiro para a funçao, deixa passar ela como parametro
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

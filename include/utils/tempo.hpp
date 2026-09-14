#ifndef TEMPO_HPP
#define TEMPO_HPP

#include <string>

using namespace std;

double calcularTempo(void (*algoritmo)(int*, int), int* vetor, int tamanho);

#endif
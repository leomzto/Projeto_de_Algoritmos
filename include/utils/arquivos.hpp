#ifndef ARQUIVOS_HPP
#define ARQUIVOS_HPP

#include <string>

using namespace std;

void salvarVetor(const char* nomeArquivo, int* vetor, int tamanho);
void salvarTempo(const char* nomeArquivo, int tamanho, double tempo);
void salvarCSV(const string& caminho, int tamanho, const string& tipo, double tempo);

#endif
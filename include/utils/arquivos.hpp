#ifndef ARQUIVOS_HPP
#define ARQUIVOS_HPP

#include <string>
#include <filesystem>

using namespace std;

void salvarVetor(const string& nomeArquivo, int* vetor, int tamanho);
void salvarTempo(const string& nomeArquivo, int tamanho, double tempo);
void salvarCSV(const string& caminho, int tamanho, const string& tipo, double tempo);
void criarDiretorios(const string& caminhoEntrada, const string& caminhoSaida,
                    const string& caminhoTempo, const string& nomeInstancia);

#endif
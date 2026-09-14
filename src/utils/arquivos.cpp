#include "utils/arquivos.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>

using namespace std;

void salvarVetor(const char* nomeArquivo, int* vetor, int tamanho) {
    // cria e abre um arquivo para escrita
    ofstream arquivo(nomeArquivo);

    // verifica se abriu corretamente
    if (!arquivo.is_open()) {
        cout << "ERRO: nao foi possivel criar o arquivo: " << nomeArquivo << "\n";
        return;
    }

    // cabeçalho do arquivo com o tamanho da instancia
    arquivo << tamanho << "\n";

    // escreve os valores linha por linha ate o tamanho desejado
    for (int i = 0; i < tamanho; i++) {
        arquivo << vetor[i] << "\n";
    }

    // fecha o arquivo
    arquivo.close();
}

void salvarTempo(const char* nomeArquivo, int tamanho, double tempo) {

    // cria e abre um arquivo para escrita
    ofstream arquivo(nomeArquivo);

    // verifica se abriu corretamente
    if (!arquivo.is_open()) {
        cout << "ERRO: nao foi possivel criar o arquivo: " << nomeArquivo << "\n";
        return;
    }

    // escreve o tamanho da instancia e o tempo de execuçao
    arquivo << tamanho << "\n" << tempo << "\n";

    // fecha o arquivo
    arquivo.close();
}

// funçao para auxiliar gerar os graficos e tabelas
void salvarCSV(const string& caminho, int tamanho, const string& tipo, double tempo) {
    namespace fs = filesystem;

    // verificar o arquivo, se existe ou se ja esta escrito
    bool arquivoVazio = !fs::exists(caminho) || fs::file_size(caminho) == 0;

    // abre o arquivo no modo append
    ofstream arquivo(caminho, ios::app);

    // verifica se abriu corretamente
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir CSV.\n";
        return;
    }

    // se estiver vazio, escrever o cabeçalho  "tamanho,tipo,tempo"
    if (arquivoVazio) {
        arquivo << "tamanho,tipo,tempo\n";
    }

    // append dos dados
    arquivo << tamanho << "," << tipo << "," << tempo << "\n";

    // fecha o arquivo
    arquivo.close();
}
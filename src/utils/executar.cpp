#include "utils/menu.hpp"
#include "utils/gerador.hpp"
#include "utils/arquivos.hpp"
#include "utils/tempo.hpp"
#include <iostream>
#include <string>

using namespace std;

void executarAlgoritmo(void (*algoritmo)(int*, int), const string& nomeAlgoritmo,
                        const string& caminhoBase, const string& caminhoCSV) {

    int tipo = escolherTipoInstancia();
    int tamanho = escolherTamanhoInstancia();

    cout << "\nGerando instancia...\n";
    int* vetor = gerarInstancia(tipo, tamanho);

    if (vetor == nullptr) {
        cout << "Erro ao gerar instancia.\n";
        return;
    }

    string nomeInstancia = obterNomeInstancia(tipo);
    string nomeArquivo = nomeInstancia + "_" + to_string(tamanho) + ".txt";

    string caminhoEntradaBase = caminhoBase + "Arquivos de Entrada/";
    string caminhoSaidaBase = caminhoBase + "Arquivos de Saida/";
    string caminhoTempoBase = caminhoBase + "Arquivos de Tempo/";

    criarDiretorios(caminhoEntradaBase.c_str(),caminhoSaidaBase.c_str(),
                    caminhoTempoBase.c_str(), nomeInstancia);

    string caminhoEntrada =
        caminhoEntradaBase + nomeInstancia + "/" + nomeArquivo;

    string caminhoSaida =
        caminhoSaidaBase + nomeInstancia + "/" + nomeArquivo;

    string caminhoTempo =
        caminhoTempoBase + nomeInstancia + "/" + nomeArquivo;

    cout << "Salvando instancia de Arquivos de Entrada...\n";
    salvarVetor(caminhoEntrada.c_str(), vetor, tamanho);

    cout << "Executando " << nomeAlgoritmo << "...\n";
    double tempo = calcularTempo(algoritmo, vetor, tamanho);

    cout << "Salvando resultado...\n";
    salvarVetor(caminhoSaida.c_str(), vetor, tamanho);

    cout << "Salvando Arquivos de Tempo...\n";
    salvarTempo(caminhoTempo.c_str(), tamanho, tempo);
    salvarCSV(caminhoCSV, tamanho, nomeInstancia, tempo);

    cout << "\n===== EXECUCAO CONCLUIDA =====\n";
    cout << "Algoritmo: " << nomeAlgoritmo << "\n";
    cout << "Tipo: " << nomeInstancia << "\n";
    cout << "Tamanho: " << tamanho << "\n";
    cout << "Tempo: " << tempo << " segundos\n";

    cout << "\nArquivos gerados:\n";
    cout << "Entrada: " << caminhoEntrada << "\n";
    cout << "Saida:   " << caminhoSaida << "\n";
    cout << "Tempo:   " << caminhoTempo << "\n";

    delete[] vetor;
}
#include "utils/menu.hpp"
#include "utils/gerador.hpp"
#include "utils/arquivos.hpp"
#include "utils/tempo.hpp"

#include <iostream>

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

    const string nomeInstancia = obterNomeInstancia(tipo);
    const string nomeArquivo = nomeInstancia + "_" + to_string(tamanho) + ".txt";

    const string caminhoEntradaBase = caminhoBase + "Arquivos de Entrada/";
    const string caminhoSaidaBase = caminhoBase + "Arquivos de Saida/";
    const string caminhoTempoBase = caminhoBase + "Arquivos de Tempo/";

    criarDiretorios(caminhoEntradaBase, caminhoSaidaBase,
                    caminhoTempoBase, nomeInstancia);

    const string caminhoEntrada = caminhoEntradaBase + nomeInstancia + "/" + nomeArquivo;
    const string caminhoSaida = caminhoSaidaBase + nomeInstancia + "/" + nomeArquivo;
    const string caminhoTempo = caminhoTempoBase + nomeInstancia + "/" + nomeArquivo;

    cout << "Salvando instancia de Arquivos de Entrada...\n";
    salvarVetor(caminhoEntrada, vetor, tamanho);

    cout << "Executando " << nomeAlgoritmo << "...\n";
    double tempo = calcularTempo(algoritmo, vetor, tamanho);

    cout << "Salvando instancia de Arquivos de Saida...\n";
    salvarVetor(caminhoSaida, vetor, tamanho);

    cout << "Salvando Arquivos de Tempo...\n";
    salvarTempo(caminhoTempo, tamanho, tempo);
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
    cout << "CSV:     " << caminhoCSV << "\n";

    delete[] vetor;
}
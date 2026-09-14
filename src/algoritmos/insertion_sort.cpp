#include "../../include/algoritmos/insertion_sort.hpp"
#include "utils/menu.hpp"
#include "utils/gerador.hpp"
#include "utils/arquivos.hpp"
#include "utils/tempo.hpp"
#include <iostream>
#include <string>

#define CAMINHO_ENTRADA "Algoritmos/Insertion Sort/Arquivos de Entrada/"
#define CAMINHO_SAIDA "Algoritmos/Insertion Sort/Arquivos de Saida/"
#define CAMINHO_TEMPO "Algoritmos/Insertion Sort/Arquivos de Tempo/"
#define CAMINHO_CSV "Algoritmos/Tempos/insertion_sort.csv"

using namespace std;

void insertionSort(int* vetor, int tamanho) {
    for (int i = 1; i < tamanho; i++) {

        int chave = vetor[i];
        int j = i - 1; // elemento anterior

        // enquanto ainda esta no raio do vetor e o elemento anterior for maior que a chave
        while (j >= 0 && vetor[j] > chave) {
            // copia o maior para uma pos. a direita
            vetor[j + 1] = vetor[j];
            j--; // volta um elemento
        }

        // posicao para reinserir a chave
        vetor[j + 1] = chave;
    }
}

void executarInsertionSort() {
    int tipo = escolherTipoInstancia();
    int tamanho = escolherTamanhoInstancia();

    // gerar instancia desejada
    cout << "\nGerando instancia...\n";
    int* vetor = gerarInstancia(tipo, tamanho);

    // verificar vetor valido
    if (vetor == nullptr) {
        cout << "Erro ao gerar instancia.\n";
        return;
    }

    string nomeInstancia = obterNomeInstancia(tipo);
    string nomeArquivo = nomeInstancia + "_" + to_string(tamanho) + ".txt";

    // caminhos de salvamento dos arquivos
    string caminhoEntrada = CAMINHO_ENTRADA + nomeInstancia + "/" + nomeArquivo;
    string caminhoSaida = CAMINHO_SAIDA + nomeInstancia + "/" +  nomeArquivo;
    string caminhoTempo = CAMINHO_TEMPO + nomeInstancia + "/" +  nomeArquivo;
    string caminhoCSV = CAMINHO_CSV;

    // salvar o vetor de entrada no caminho correto
    cout << "Salvando instancia de Arquivos de Entrada...\n";
    salvarVetor(caminhoEntrada.c_str(), vetor, tamanho);

    // executar o algoritmo e calcular o tempo de execuçao
    cout << "Executando Insertion Sort...\n";
    double tempo = calcularTempo(insertionSort, vetor, tamanho);

    // salvar o vetor de saida pós execuçao no caminho correto
    cout << "Salvando resultado...\n";
    salvarVetor(caminhoSaida.c_str(), vetor, tamanho);

    // salvar os arquivos de tempo (de execuçao e o csv para gerar o grafico)
    cout << "Salvando Arquivos de Tempo...\n";
    salvarTempo(caminhoTempo.c_str(), tamanho, tempo);
    salvarCSV(caminhoCSV, tamanho, nomeInstancia, tempo);

    // exebir informaçoes da execuçao no terminal
    cout << "\n===== EXECUCAO CONCLUIDA =====\n";
    cout << "Tipo: " << nomeInstancia << "\n";
    cout << "Tamanho: " << tamanho << "\n";
    cout << "Tempo: " << tempo << " segundos\n";

    // indicar onde cada arquivo foi salvo
    cout << "\nArquivos gerados:\n";
    cout << "Entrada: " << caminhoEntrada << "\n";
    cout << "Saida:   " << caminhoSaida << "\n";
    cout << "Tempo:   " << caminhoTempo << "\n";

    // liberar memoria
    delete[] vetor;
}
#ifndef PROJETO_DE_ALGORITIMO_EXECUTAR_HPP
#define PROJETO_DE_ALGORITIMO_EXECUTAR_HPP

#include <string>

using namespace std;

void executarAlgoritmo(void (*algoritmo)(int*, int), const string& nomeAlgoritmo,
                        const string& caminhoBase, const string& caminhoCSV);
#endif

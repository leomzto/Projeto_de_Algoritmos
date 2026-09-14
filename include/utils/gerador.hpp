#ifndef GERADOR_HPP
#define GERADOR_HPP

#include <string>

using namespace std;

int* gerarCrescente(int tamanho);
int* gerarDecrescente(int tamanho);
int* gerarRandomico(int tamanho);
int* gerarInstancia(int tipo, int tamanho);
string obterNomeInstancia(int tipo);

#endif
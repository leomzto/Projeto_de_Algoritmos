#include "utils/menu.hpp"

#include "algoritmos/insertion_sort.hpp"
#include <iostream>

using namespace std;

int escolherTipoInstancia() {
    int opcao;

    do {
        cout << "\n===== TIPO DA INSTANCIA =====\n";
        cout << "1. Crescente\n";
        cout << "2. Decrescente\n";
        cout << "3. Randomica\n";
        cout << "Escolha uma opcao: ";

        cin >> opcao;

        if (opcao < 1 || opcao > 3)
            cout << "Opcao invalida. Tente novamente.\n";

    } while (opcao < 1 || opcao > 3);

    return opcao;
}

int escolherTamanhoInstancia() {
    int opcao;

    do {
        cout << "\n===== TAMANHO DA INSTANCIA =====\n";
        cout << "1. 10 (dez)\n";
        cout << "2. 100 (cem)\n";
        cout << "3. 1000 (mil)\n";
        cout << "4. 10000 (dez mil)\n";
        cout << "5. 100000 (cem mil)\n";
        cout << "6. 1000000 (um milhão)\n";
        cout << "Escolha uma opcao: ";

        cin >> opcao;

        if (opcao < 1 || opcao > 6)
            cout << "Opcao invalida. Tente novamente.\n";

    } while (opcao < 1 || opcao > 6);

    switch (opcao) {
        case 1:
            return 10;
        case 2:
            return 100;
        case 3:
            return 1000;
        case 4:
            return 10000;
        case 5:
            return 100000;
        case 6:
            return 1000000;
        default:
            return 10;
    }
}

void executarMenu()
{
    int opcao;

    do {
        cout << "\n====================================\n";
        cout << "       PROJETO DE ALGORITMOS\n";
        cout << "====================================\n";
        cout << "1. Executar Insertion Sort\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";

        cin >> opcao;

        switch (opcao) {
            case 1:
                executarInsertionSort();
                break;

            case 0:
                cout << "\nEncerrando programa...\n";
                break;

            default:
                cout << "\nOpcao invalida. Tente novamente.\n";
        }

    } while (opcao != 0);
}
#include "include/utils/menu.hpp"

#include <cstdlib>
#include <ctime>

int main() {
    // semente de aleatoriedade para o rand()
    srand(time(nullptr));

    executarMenu();

    return 0;
}
void merge(int* vetor, int esq, int meio, int dir) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    // vetores temp.
    int* E = new int[n1];
    int* D = new int[n2];

    // copia os dados para cada vetor temp.
    for (int i = 0; i < n1; i++)
        E[i] = vetor[esq + i];

    for (int j = 0; j < n2; j++)
        D[j] = vetor[meio + 1 + j];

    int i = 0, j = 0;
    int k = esq;

    // intercala em ordem crescente
    while (i < n1 && j < n2) {
        if (E[i] <= D[j]) {
            vetor[k] = E[i];
            i++;
        } else {
            vetor[k] = D[j];
            j++;
        }
        k++;
    }

    // copia os restantes de L
    while (i < n1) {
        vetor[k] = E[i];
        i++;
        k++;
    }

    // copia os restantes de R
    while (j < n2) {
        vetor[k] = D[j];
        j++;
        k++;
    }

    delete[] E;
    delete[] D;
}

void mergeSort(int* vetor, int tamanho, int esq = 0, int dir = -1) {
    if (dir == -1)
        dir = tamanho - 1;

    if (esq >= dir)
        return;

    int meio = esq + (dir - esq) / 2;

    mergeSort(vetor, tamanho, esq, meio);
    mergeSort(vetor, tamanho, meio + 1, dir);

    merge(vetor, esq, meio, dir);
}

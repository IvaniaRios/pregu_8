#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int i, j;
    int numVectors, numTerms;

    printf("Ingrese el número de vectores: ");
    scanf("%d", &numVectors);

    printf("Ingrese el número de términos: ");
    scanf("%d", &numTerms);

    int vectors[numVectors][numTerms];

    #pragma omp parallel for num_threads(numVectors)
    for (i = 0; i < numVectors; i++) {
        int start = 2 + i * numTerms * 2; // Cada vector comienza con un número mayor en secuencia

        for (j = 0; j < numTerms; j++) {
            vectors[i][j] = start + j * 2; // Generar los términos de la serie
        }
    }

    printf("Serie generada en %d vectores:\n", numVectors);
    for (i = 0; i < numVectors; i++) {
        printf("Vector %d: ", i);
        for (j = 0; j < numTerms; j++) {
            printf("%d ", vectors[i][j]);
        }
        printf("\n");
    }

    return 0;
}

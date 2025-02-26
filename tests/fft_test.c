#include "../include/libfft.h"

#include <stdlib.h>
#include <complex.h>

int main()
{

    int k = 4;

    double complex** temp = malloc(k * sizeof(double complex*));
    for(int i = 0; i < k; i++) {
        temp[i] = malloc(k * sizeof(double complex));
    }


    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            temp[i][j] = (rand() % 10) + (rand() % 10) * I;

        }
    }

    struct ComplexMatrix complex_matrix;

    complex_matrix.complex_matrix = temp;
    complex_matrix.m = k;
    complex_matrix.n = k;

    complex_matrix = fft2(complex_matrix);

    return 1;
}
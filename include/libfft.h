#ifndef FFT_H
#define FFT_H

#include <complex.h>

struct ComplexMatrix {
    double complex ** complex_matrix;
    int m;
    int n;
};

double complex* dft_core(double complex P[], int n);

double complex* fft_core(double complex P[], int n);

void transpose_complex_matrix(struct ComplexMatrix* complex_matrix);

void print_complex_matrix(struct ComplexMatrix* complex_matrix);

struct ComplexMatrix fft2(struct ComplexMatrix complex_matrix);

#endif

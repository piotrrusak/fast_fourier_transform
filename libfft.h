#ifndef FFT_H
#define FFT_H

#include <complex.h>

double complex* fft_core(double complex P[], int n);

double* fft(double P[], int n);

#endif
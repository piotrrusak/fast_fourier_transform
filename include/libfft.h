#ifndef FFT_H
#define FFT_H

#include <complex.h>

double complex* dft_core(double complex P[], int n);

double* dft(double P[], int n, int print_input, int print_output);

double complex* fft_core(double complex P[], int n);

double* fft(double P[], int n, int print_input, int print_output);

#endif
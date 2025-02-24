#ifndef FFT_H
#define FFT_H

#include <complex.h>

double complex* dft_core(double complex P[], int n);

double complex* fft_core(double complex P[], int n);

double* dft(double P[], int n, int print_input, int print_output);

double* fft(double P[], int n, int print_input, int print_output);

double* dft2(double P[], int n, int m, int print_input, int print_output);

double* fft2(double P[], int n, int m, int print_input, int print_output);

#endif
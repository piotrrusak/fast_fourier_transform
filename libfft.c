#include "libfft.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

double complex* dft_core(double complex P[], int n)
{
    double complex * y = malloc(n * sizeof(double complex));
    double complex temp;
    double complex wj;

    for(int k = 0; k < n; k++)
    {
        temp = 0 + 0 * I;
        for(int j = 0; j < n; j++)
        {
            wj = cexp(-2.0 * M_PI * I * j * k / n);
            temp = temp + wj * P[j];
        }
        y[k] = temp;
    }

    return y;
}

double* dft(double P_trunkated[], int n, int print_input, int print_output)
{
    double complex* P = malloc(n * sizeof(double complex));

    for(int i = 0; i < n; i++)
    {
        P[i] = P_trunkated[i] + P_trunkated[i + n] * I;
    }

    if(print_input)
    {

        printf("Input to dft core:\n");
        for(int i = 0; i < n; i++)
        {
            printf("(%lf, %lf)\n", creal(P[i]), cimag(P[i]));
        }

    }

    double complex *result = dft_core(P, n);

    for(int i = 0; i < n; i++)
    {
        P_trunkated[i] = creal(result[i]);
        P_trunkated[i + n] = cimag(result[i]);
    }

    if(print_output)
    {

        printf("Output from dft core:\n");
        for(int i = 0; i < n; i++)
        {
            printf("(%lf, %lf)\n", creal(result[i]), cimag(result[i]));
        }

    }

    return P_trunkated;
}

double complex* fft_core(double complex P[], int n)
{
    if(n == 1)
    {
        return P;
    }

    double complex wj;

    double complex* Pe = malloc((n / 2) * sizeof(double complex));
    double complex* Po = malloc((n / 2) * sizeof(double complex));

    for(int i = 0; i < n/2; i++)
    {
        Pe[i] = P[2*i];
        Po[i] = P[2*i+1];
    }

    double complex* ye = fft_core(Pe, n/2);
    double complex* yo = fft_core(Po, n/2);

    double complex* y = malloc((n) * sizeof(double complex));

    for(int j = 0; j < n/2; j++)
    {
        wj = cexp(-2.0 * M_PI * I * j / n);
        y[j] = ye[j] + wj * yo[j];
        y[j + n/2] = ye[j] - wj * yo[j];
    }

    return y;
}

double* fft(double P_trunkated[], int n, int print_input, int print_output)
{
    double complex* P = malloc(n * sizeof(double complex));

    for(int i = 0; i < n; i++)
    {
        P[i] = P_trunkated[i] + P_trunkated[i + n] * I;
    }

    if(print_input)
    {

        printf("Input to fft core:\n");
        for(int i = 0; i < n; i++)
        {
            printf("(%lf, %lf)\n", creal(P[i]), cimag(P[i]));
        }

    }

    double complex *result = fft_core(P, n);

    for(int i = 0; i < n; i++)
    {
        P_trunkated[i] = creal(result[i]);
        P_trunkated[i + n] = cimag(result[i]);
    }

    if(print_output)
    {

        printf("Output from fft core:\n");
        for(int i = 0; i < n; i++)
        {
            printf("(%lf, %lf)\n", creal(result[i]), cimag(result[i]));
        }

    }

    return P_trunkated;
}



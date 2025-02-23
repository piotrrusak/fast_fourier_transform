#include "libfft.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

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

double* fft(double P_trunkated[], int n)
{
    double complex* P = malloc(n * sizeof(double complex));

    printf("Input to fft:\n");
    for(int i = 0; i < 2 * n; i++)
    {
        printf("%lf\n", P_trunkated[i]);
    }

    for(int i = 0; i < n; i++)
    {
        P[i] = P_trunkated[i] + P_trunkated[i + n] * I;
    }

    printf("Input to core:\n");
    for(int i = 0; i < n; i++)
    {
        printf("(%lf, %lf)\n", creal(P[i]), cimag(P[i]));
    }

    double complex *result = fft_core(P, n);

    printf("Output from core:\n");
    for(int i = 0; i < n; i++)
    {
        printf("(%lf, %lf)\n", creal(result[i]), cimag(result[i]));
    }

    for(int i = 0; i < n; i++)
    {
        P_trunkated[i] = creal(result[i]);
        P_trunkated[i + n] = cimag(result[i]);
    }

    printf("Output from fft:\n");
    for(int i = 0; i < 2 * n; i++)
    {
        printf("%lf\n", P_trunkated[i]);
    }

    return P_trunkated;
}
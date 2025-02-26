#include "../include/libfft.h"

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
        Po[i] = P[(2*i+1)];
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

    if(print_output)
    {

        printf("Output from fft core:\n");
        for(int i = 0; i < n; i++)
        {
            printf("(%lf, %lf)\n", creal(result[i]), cimag(result[i]));
        }

    }

    for(int i = 0; i < n; i++)
    {
        P_trunkated[i] = creal(result[i]);
        P_trunkated[i + n] = cimag(result[i]);
    }

    return P_trunkated;
}

void transpose_complex_matrix(struct ComplexMatrix* complex_matrix)
{
    double complex temp;

    for(int i = 0; i < complex_matrix->m; i++)
    {
        for(int j = i+1; j < complex_matrix->n; j++)
        {
            temp = complex_matrix->complex_matrix[i][j];
            complex_matrix->complex_matrix[i][j] = complex_matrix->complex_matrix[j][i];
            complex_matrix->complex_matrix[j][i] = temp;
        }
    }
}

void print_complex_matrix(struct ComplexMatrix complex_matrix)
{

    printf("Shape: %d, %d\n", complex_matrix.m, complex_matrix.n);

    for(int i = 0; i < complex_matrix.m; i++)
    {
        for(int j = 0; j < complex_matrix.n; j++)
        {
            printf("%lf %lfi, ", creal(complex_matrix.complex_matrix[i][j]), cimag(complex_matrix.complex_matrix[i][j]));
        }
        printf("\n");
    }
}

struct ComplexMatrix fft2(struct ComplexMatrix complex_matrix)
{

    transpose_complex_matrix(&complex_matrix);

    for (int i = 0; i < complex_matrix.n; i++)
    {
        complex_matrix.complex_matrix[i] = fft_core(complex_matrix.complex_matrix[i], complex_matrix.m);
    }

    transpose_complex_matrix(&complex_matrix);

    for (int j = 0; j < complex_matrix.m; j++)
    {
        complex_matrix.complex_matrix[j] = fft_core(complex_matrix.complex_matrix[j], complex_matrix.n);
    }

    return complex_matrix;
}

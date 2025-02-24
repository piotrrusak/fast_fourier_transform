#include "../include/libfft.h"

#include <complex.h>
#include <stdio.h>


void main()
{
    double P1[8] = {3, 4, 5, 6, 0, 0, 0 ,0};
    double *temp1 = fft(P1, 4, 0, 1);
    double P2[8] = {3, 4, 5, 6, 0, 0, 0 ,0};
    double *temp2 = dft(P2, 4, 0, 1);
}
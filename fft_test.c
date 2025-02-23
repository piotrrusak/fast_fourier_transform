#include "libfft.h"

#include <complex.h>
#include <stdio.h>


void main()
{
    double P[8] = {3, 4, 5, 6, 0, 0, 0 ,0};
    double *temp = fft(P, 4);
}
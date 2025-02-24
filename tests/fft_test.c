#include "../include/libfft.h"

void main()
{
//    double P1[8] = {3, 4, 5, 6, 0, 0, 0 ,0};
//    double *temp1 = dft(P1, 4, 0, 0);
//    double P2[8] = {3, 4, 5, 6, 0, 0, 0 ,0};
//    double *temp2 = fft(P2, 4, 0, 0);
//    double P3[8] = {1, 2, 3, 4, 0, 0, 0, 0};
//    double *temp3 = dft2(P3, 2, 2, 0, 0);
    double P4[8] = {1, 2, 3, 4, 0, 0, 0, 0};
    double *temp4 = fft2(P4, 2, 2, 0, 0);
}
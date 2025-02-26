# Fast Fourier Transform

FT library written in C. Used mainly by ctypes in Python.

## Function fft2():

Input:

Matrix (two dimentional array)

Output:

Matrix (two dimentional array)

## How works?

Performs regular fft on columns, than transpose matrix, performs regular fft on columns and transpose matrix again.

# How fast is it?

fft2 has complexity of O(n^2 * log2(n^2))

## To Do:

Use strides in order to significantly improve efficiency.

Upgrade fft_core to make it work on other sizes than powers of two.
import ctypes
import os

import numpy as np

size = 2 ** 3

T = [i for i in range(size)]
ad = [0 for i in range(size)]

path = os.getcwd()
clibrary = ctypes.CDLL(os.path.join(path, '../build/libfft.so'))

n = size

values = (ctypes.c_double * (2*n))()

example = T + ad

for i in range(2*n):
    values[i] = example[i]

clibrary.fft.restype = ctypes.POINTER(ctypes.c_double)
result = clibrary.dft(values, n, 0, 1)

print(np.fft.fft(T))
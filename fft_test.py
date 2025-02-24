import ctypes
import os

import numpy as np

T = [i for i in range(2**5)]
ad = [0 for i in range(2**5)]

path = os.getcwd()
clibrary = ctypes.CDLL(os.path.join(path, 'libfft.so'))

n = 2 ** 5

values = (ctypes.c_double * (2*n))()

example = T + ad

for i in range(2*n):
    values[i] = example[i]

clibrary.fft.restype = ctypes.POINTER(ctypes.c_double)
result = clibrary.fft(values, n)

print("result in python:")
for i in range(n):
    print(result[i], result[i + int(n)])

print(np.fft.fft(T))
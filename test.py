import copy
import ctypes
import os
import random
import time

import numpy as np

class Complex(ctypes.Structure):
    _fields_ = [("real", ctypes.c_double), ("imag", ctypes.c_double)]

class ComplexMatrix(ctypes.Structure):
    _fields_ = [
        ("complex_matrix", ctypes.POINTER(ctypes.POINTER(Complex))),
        ("m", ctypes.c_int),
        ("n", ctypes.c_int),
    ]

    def __init__(self, complex_matrix, m, n):

        self.m = m
        self.n = n

        rows = len(complex_matrix)
        cols = len(complex_matrix[0]) if rows > 0 else 0

        one_dim_complex_array = Complex * cols
        two_dim_complex_array = ctypes.POINTER(Complex) * rows

        matrix = [one_dim_complex_array(*[Complex(complex(c).real, complex(c).imag) for c in row]) for row in complex_matrix]
        self.complex_matrix = two_dim_complex_array(*matrix)


complex_matrix = [
    [complex(1, 0), complex(2, 0), complex(3, 0), complex(4, 0)],
    [complex(1, 0), complex(2, 0), complex(3, 0), complex(4, 0)],
    [complex(1, 0), complex(2, 0), complex(3, 0), complex(4, 0)],
    [complex(1, 0), complex(2, 0), complex(3, 0), complex(4, 0)]
]

m = 16
n = 16

complex_matrix = [[complex(random.randint(0, 9), random.randint(0, 9)) for _ in range(n)] for _ in range(m)]

def complex_matrix_to_numpy(c_matrix):
    rows, cols = c_matrix.m, c_matrix.n

    result = np.zeros((rows, cols), dtype=np.complex128)

    for i in range(rows):
        row_pointer = c_matrix.complex_matrix[i]
        for j in range(cols):
            complex_val = row_pointer[j]
            result[i, j] = complex_val.real + 1j * complex_val.imag

    return result

start = time.time()
np.fft.fft2(complex_matrix)
end = time.time()
print(end - start)

def own_fft2(complex_matrix, m, n):
    path = os.getcwd()
    clibrary = ctypes.CDLL(os.path.join(path, 'build/libfft.so'))

    complex_matrix_obj = ComplexMatrix(complex_matrix, m, n)

    clibrary.fft2.restype = ComplexMatrix

    result = clibrary.fft2(complex_matrix_obj)

    return complex_matrix_to_numpy(result)

start = time.time()
own_fft2(complex_matrix, m, n)
end = time.time()
print(end - start)
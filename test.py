import ctypes
import os

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
    [complex(1, 2), complex(3, 4), complex(5, 6)],
    [complex(7, 8), complex(9, -10), complex(11, 12)],
    [complex(13, 14), complex(15, 16), complex(17, 18)],
    [complex(19, 20), complex(21, 22), complex(23, 24)]
]

path = os.getcwd()
clibrary = ctypes.CDLL(os.path.join(path, 'build/libfft.so'))

complex_matrix = ComplexMatrix(complex_matrix, 3, 3)

clibrary.print_complex_matrix(complex_matrix)
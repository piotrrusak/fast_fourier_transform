import ctypes
import os
import random
from time import time

import numpy as np

# def trunk_2_dim_array(T, m, n):
#     T_trunkated = []
#     for i in range(n):
#         for j in range(m):
#             T_trunkated.append(T[j][i].real)
#     for i in range(n):
#         for j in range(m):
#             T_trunkated.append(T[j][i].imag)
#     return T_trunkated
#
# def retrunk_2_dim_array(T_trunkated, m, n):
#     T = [[0 for _ in range(n)] for _ in range(m)]
#     k = 0
#
#     i = 0
#     while i < n:
#         j = 0
#         while j < m:
#             T[j][i] += T_trunkated[k]
#             j += 1
#             k += 1
#         i += 1
#
#     i = 0
#     while i < n:
#         j = 0
#         while j < m:
#             T[j][i] += 1j * T_trunkated[k]
#             j += 1
#             k += 1
#         i += 1
#
#     return T
#
# def extend_to_two_power(T, m, n):
#     new_size = 2 ** np.ceil(np.log2(max(m, n)))
#     return np.pad(T, pad_width=((0, int(new_size - m)), (0, int(new_size - n))), mode='constant', constant_values=0)
#
# def fft(T, m, n):
#     path = os.getcwd()
#     clibrary = ctypes.CDLL(os.path.join(path, '../build/libfft.so'))
#     T_trunkated = trunk_2_dim_array(T, m, n)
#     values = (ctypes.c_double * (m * n * 2))()
#     for i in range(m * n * 2):
#         values[i] = T_trunkated[i]
#     clibrary.fft2.restype = ctypes.POINTER(ctypes.c_double)
#     result = clibrary.fft2(values, n, m, 0, 0)
#     for i in range(m * n * 2):
#         T_trunkated[i] = result[i]
#     result = retrunk_2_dim_array(T_trunkated, m, n)
#
# m = 1024
# n = 1024
#
# T = [[random.randint(0, 9) for i in range(n)] for _ in range(m)]
# T = extend_to_two_power(T, m, n)
#
# new_size = int(2 ** np.ceil(np.log2(max(m, n))))
#
# m = new_size
# n = new_size
#
# start = time()
#
# result = np.fft.fft2(T)
#
# end = time()
#
# print(end - start)
#
# path = os.getcwd()
# clibrary = ctypes.CDLL(os.path.join(path, '../build/libfft.so'))
# T_trunkated = trunk_2_dim_array(T, m, n)
# values = (ctypes.c_double * (m * n * 2))()
# for i in range(m * n * 2):
#     values[i] = T_trunkated[i]
# clibrary.fft2.restype = ctypes.POINTER(ctypes.c_double)
# start = time()
# result = clibrary.fft2(values, n, m, 0, 0)
# end = time()
# for i in range(m * n * 2):
#     T_trunkated[i] = result[i]
# result = retrunk_2_dim_array(T_trunkated, m, n)
#
#
#
# print(end - start)

k = 9192

T_trunkated = [random.uniform(0, 9) for _ in range(k)]

ad = [0.0 for _ in range(k)]

example = T_trunkated + ad

start = time()

result = np.fft.fft(T_trunkated)

end = time()

print(end - start)

start = time()
path = os.getcwd()
clibrary = ctypes.CDLL(os.path.join(path, '../build/libfft.so'))
values = (ctypes.c_double * (k * 2))()
for i in range(k * 2):
    values[i] = example[i]
clibrary.fft.restype = ctypes.POINTER(ctypes.c_double)

result = clibrary.fft(values, k, 0, 0)

example = result[0: k * 2]
end = time()
print(end-start)
# print(T_trunkated)


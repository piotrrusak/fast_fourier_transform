from src import libfft

import random
import time
import numpy as np
import matplotlib.pyplot as plt

N = [2, 4, 8, 16, 32, 64, 128, 256, 512, 1024]

T1 = []
T2 = []

for i in N:
    m = i
    n = i

    complex_matrix = [[complex(random.randint(0, 9), random.randint(0, 9)) for _ in range(n)] for _ in range(m)]

    start = time.time()
    np.fft.fft2(complex_matrix)
    end = time.time()
    T1.append(end - start)

    start = time.time()
    libfft.fft2(complex_matrix, m, n)
    end = time.time()
    T2.append(end - start)

plt.plot(N, T1, marker='o', linestyle='-', color='b', label="Numpy FFT")
plt.plot(N, T2, marker='s', linestyle='--', color='r', label="Own FFT")

plt.xlabel("N")
plt.ylabel("Czas")

plt.title("Porównanie Numpy FFT vs Own FFT")

plt.legend()

plt.grid(True)

plt.show()

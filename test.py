import numpy as np

A = np.array([[1, 2, 3, 4, 5], [1, 2, 3, 4, 5]])

B = np.array([[1, 2, 3, 4, 5, 0], [1, 2, 3, 4, 5, 0]])

print(np.fft.fft2(B))

print(A.shape)

print(np.fft.fft2(A, s=(2,6)))
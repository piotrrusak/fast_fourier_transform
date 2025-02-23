import numpy as np

def fft(P):
    n = len(P)
    if n == 1:
        return P
    w = np.exp(-2 * np.pi * 1j / n)

    Pe = [P[n1] for n1 in range(0, n, 2)]
    Po = [P[n2] for n2 in range(1, n, 2)]

    ye, yo = fft(Pe), fft(Po)
    y = [0] * n
    for j in range(n//2):
        y[j] = ye[j] + w ** j * yo[j]
        y[j + n//2] = ye[j] - w ** j * yo[j]
    return y

T = [i for i in range(2**5)]

print(np.fft.fft(T))
print(fft(T))
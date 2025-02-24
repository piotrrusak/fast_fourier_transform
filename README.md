# fast_fourier_transform
FT library written in C. Used mainly by ctypes in Python.


# To Do:
Actually it works only for powers of 2. Because when i part polynominal to odd and even part, i'm loosing some coefficients. I don't want to fix it couse it will affect efficiency.
In python implemented API, I extend matrix to the closest power of two size.
CC = gcc
CFLAGS = -Wall -Wextra -fPIC
LDFLAGS = -shared
TARGET = fft_test

all: libfft.so $(TARGET)

libfft.so: libfft.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o libfft.so libfft.c

$(TARGET): fft_test.c
	$(CC) -o $(TARGET) fft_test.c -L. -lfft -Wl,-rpath,. -lm

clean:
	rm -f $(TARGET) libfft.so

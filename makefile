
all : libfft.so fft_test

libfft.so : src/libfft.c
	gcc -Wall -Wextra -fPIC -shared -o build/libfft.so src/libfft.c

fft_test : tests/fft_test.c
	gcc -o build/fft_test tests/fft_test.c build/libfft.so -Wl,-rpath,. -lm

clean:
	rm -f fft_test libfft.so

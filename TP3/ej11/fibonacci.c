#include <stdio.h>

int fibonacciASM(int n);
int fibonacci(int n);

int main(int argc, char *argv[]) {
	printf("%d\n", fibonacciASM(10));
}

int fibonacci(int n) {
	if (n == 0 || n == 1)
		return n;
	return fibonacci(n-1)+fibonacci(n-2);
}

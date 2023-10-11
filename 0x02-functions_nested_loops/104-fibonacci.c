#include <stdio.h>

/**
 * Prints the first n Fibonacci numbers.
 *
 * @param n The number of Fibonacci numbers to print.
 */
void print_fibonacci_sequence(int n) {
    int a = 1, b = 2;
    int i;

    printf("%d, %d, ", a, b);

    for (i = 3; i <= n; i++) {
        int c = a + b;
        printf("%d", c);

        if (i != n) {
            printf(", ");
        }

        a = b;
        b = c;
    }

    printf("\n");
}

int main() {
    print_fibonacci_sequence(98);

    return 0;
}


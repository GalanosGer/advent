#include <stdio.h>
#include <stdlib.h>

int count_digits(long long n){
    int counter = 0;
    do {
        n /= 10;
        counter++;
    } while (n != 0);
    return counter;
}

int main() {
    FILE* file;

    long long u = 0;
    long long h = 0;
    long long sum = 0;
    long long d = 10;

    file = fopen("input2.txt", "r");
    if (!file) return 1;

    while (fscanf(file, "%lld-%lld", &u, &h) == 2) {

        long long curr = u;

        while (curr <= h) {
            int k = count_digits(curr);

            if (k % 2 == 0) { // Only even-length numbers can be repeated
                int half = k / 2;

                // Compute 10^half
                d = 1;
                for (int i = 0; i < half; i++) {
                    d *= 10;
                }

                long long first = curr / d; // first half of digits
                long long second = curr % d; // second half

                if (first == second) { // repeated pattern
                    sum += curr;
                }
            }

            curr++;
        }

        // Skip comma between ranges
        int c = fgetc(file);
        if (c == EOF) break;
    }

    printf("Sum is: %lld\n", sum);

    fclose(file);
    return 0;
}

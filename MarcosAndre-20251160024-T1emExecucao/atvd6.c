#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "Functions.h"

// Achar quantas vezes certo número se repete em uma cadeia de números


int pot10(int n) {
    int r = 1;
    while (n--) r *= 10;
    return r;
}

int countDigits(int n) {
    int d = 0;
    if (n == 0) return 1;
    while (n > 0) {
        d++;
        n /= 10;
    }
    return d;
}

int countTimes(int number, int key) {

    int digits_key    = countDigits(key);
    int digits_number = countDigits(number);

    int ak[20], an[20];
    int temp, i = 0;

    // --- criar array de dígitos do KEY ---
    temp = key;
    for (int e = pot10(digits_key - 1); e > 0; e /= 10) {
        ak[i++] = temp / e;
        temp = temp % e;
    }
    int key_len = i;

    // --- criar array de dígitos do NUMBER ---
    i = 0;
    temp = number;
    for (int e = pot10(digits_number - 1); e > 0; e /= 10) {
        an[i++] = temp / e;
        temp = temp % e;
    }
    int num_len = i;

    // --- procurar padrão ---
    int count = 0;
    for (int start = 0; start <= num_len - key_len; start++) {
        
        int match = 1;
        for (int k = 0; k < key_len; k++) {
            if (an[start + k] != ak[k]) {
                match = 0;
                break;
            }
        }

        if (match) count++;
    }

    return count;
}

int main() {
    printf("%d\n", countTimes(2525, 25)); // imprime 2
    return 0;
}

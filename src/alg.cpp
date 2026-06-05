// Copyright 2026

#include "alg.h"

unsigned int collatzLen(uint64_t num) {
    unsigned int len = 1;

    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        ++len;
    }

    return len;
}

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t max_value = num;

    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }

        if (num > max_value) {
            max_value = num;
        }
    }

    return max_value;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    uint64_t best_num = lbound;
    unsigned int best_len = 0;

    for (uint64_t n = lbound; n <= rbound; ++n) {
        unsigned int len = collatzLen(n);

        if (len > best_len) {
            best_len = len;
            best_num = n;
        }
    }

    *maxlen = best_len;
    return static_cast<unsigned int>(best_num);
}

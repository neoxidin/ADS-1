// Copyright 2022 NNTU-CS

#include "alg.h"

#include <cmath>
#include <cstdint>
#include <iostream>


bool checkPrime(uint64_t value) {
    for (uint64_t i = 2; i <= static_cast<uint64_t>(std::sqrt(value)); ++i) {
        if (value % i == 0) {
            return false;
        }
    }

    return true;
}


uint64_t nPrime(uint64_t n) {
    uint64_t count = 0;
    uint64_t i = 2;

    while (true) {
        if (checkPrime(i)) {
            count++;
            if (count == n) {
                return i;
            }
        }
        i++;
    }

    return 2;
}


uint64_t nextPrime(uint64_t value) {
    if (checkPrime(value)) {
        value++;
    }

    while (true) {
        if (checkPrime(value)) {
            return value;
        }
        value++;
    }

    return 2;
}


uint64_t sumPrime(uint64_t hbound) {
    uint64_t i = 2;
    uint64_t sum = 0;

    while (i < hbound) {
        if (checkPrime(i)) {
            sum += i;
        }

        if (i + 1 == hbound) {
            return sum;
        }

        i++;
    }

    return 2;
}


uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    uint64_t count = 0;

    for (uint64_t i = lbound; i + 2 < hbound; i++) {
        if (checkPrime(i) && checkPrime(i + 2)) {
            count++;
        }
    }

    return count;
}
